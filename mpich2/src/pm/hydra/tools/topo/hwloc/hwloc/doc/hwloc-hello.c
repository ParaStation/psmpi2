/* Example hwloc API program.
 *
 * Copyright © 2009-2010 inria.  All rights reserved.
 * Copyright © 2009-2011 Université Bordeaux 1
 * Copyright © 2009-2010 Cisco Systems, Inc.  All rights reserved.
 * See COPYING in top-level directory.
 *
 * hwloc-hello.c
 */

#include <hwloc.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

static void print_children(hwloc_topology_t topology, hwloc_obj_t obj, 
                           int depth)
{
    char string[128];
    unsigned i;

    hwloc_obj_snprintf(string, sizeof(string), topology, obj, "#", 0);
    printf("%*s%s\n", 2*depth, "", string);
    for (i = 0; i < obj->arity; i++) {
        print_children(topology, obj->children[i], depth + 1);
    }
}

int main(void)
{
    int depth;
    unsigned i, n;
    unsigned long size;
    int levels;
    char string[128];
    int topodepth;
    hwloc_topology_t topology;
    hwloc_cpuset_t cpuset;
    hwloc_obj_t obj;

    /* Allocate and initialize topology object. */
    hwloc_topology_init(&topology);

    /* ... Optionally, put detection configuration here to ignore
       some objects types, define a synthetic topology, etc....  

       The default is to detect all the objects of the machine that
       the caller is allowed to access.  See Configure Topology
       Detection. */

    /* Perform the topology detection. */
    hwloc_topology_load(topology);

    /* Optionally, get some additional topology information
       in case we need the topology depth later. */
    topodepth = hwloc_topology_get_depth(topology);

    /*****************************************************************
     * First example:
     * Walk the topology with an array style, from level 0 (always
     * the system level) to the lowest level (always the proc level).
     *****************************************************************/
    for (depth = 0; depth < topodepth; depth++) {
        printf("*** Objects at level %d\n", depth);
        for (i = 0; i < hwloc_get_nbobjs_by_depth(topology, depth); 
             i++) {
            hwloc_obj_snprintf(string, sizeof(string), topology,
                       hwloc_get_obj_by_depth(topology, depth, i),
                       "#", 0);
            printf("Index %u: %s\n", i, string);
        }
    }

    /*****************************************************************
     * Second example:
     * Walk the topology with a tree style.
     *****************************************************************/
    printf("*** Printing overall tree\n");
    print_children(topology, hwloc_get_root_obj(topology), 0);

    /*****************************************************************
     * Third example:
     * Print the number of sockets.
     *****************************************************************/
    depth = hwloc_get_type_depth(topology, HWLOC_OBJ_SOCKET);
    if (depth == HWLOC_TYPE_DEPTH_UNKNOWN) {
        printf("*** The number of sockets is unknown\n");
    } else {
        printf("*** %u socket(s)\n", 
               hwloc_get_nbobjs_by_depth(topology, depth));
    }

    /*****************************************************************
     * Fourth example:
     * Compute the amount of cache that the first logical processor
     * has above it.
     *****************************************************************/
    levels = 0;
    size = 0;
    for (obj = hwloc_get_obj_by_type(topology, HWLOC_OBJ_PU, 0);
         obj;
         obj = obj->parent)
      if (obj->type == HWLOC_OBJ_CACHE) {
        levels++;
        size += obj->attr->cache.size;
      }
    printf("*** Logical processor 0 has %d caches totaling %luKB\n", 
           levels, size / 1024);

    /*****************************************************************
     * Fifth example:
     * Bind to only one thread of the last core of the machine.
     *
     * First find out where cores are, or else smaller sets of CPUs if
     * the OS doesn't have the notion of a "core".
     *****************************************************************/
    depth = hwloc_get_type_or_below_depth(topology, HWLOC_OBJ_CORE);

    /* Get last core. */
    obj = hwloc_get_obj_by_depth(topology, depth,
                   hwloc_get_nbobjs_by_depth(topology, depth) - 1);
    if (obj) {
        /* Get a copy of its cpuset that we may modify. */
        cpuset = hwloc_bitmap_dup(obj->cpuset);

        /* Get only one logical processor (in case the core is
           SMT/hyperthreaded). */
        hwloc_bitmap_singlify(cpuset);

        /* And try to bind ourself there. */
        if (hwloc_set_cpubind(topology, cpuset, 0)) {
            char *str;
            int error = errno;
            hwloc_bitmap_asprintf(&str, obj->cpuset);
            printf("Couldn't bind to cpuset %s: %s\n", str, strerror(error));
            free(str);
        }

        /* Free our cpuset copy */
        hwloc_bitmap_free(cpuset);
    }

    /*****************************************************************
     * Sixth example:
     * Allocate some memory on the last NUMA node, bind some existing
     * memory to the last NUMA node.
     *****************************************************************/
    /* Get last node. */
    n = hwloc_get_nbobjs_by_type(topology, HWLOC_OBJ_NODE);
    if (n) {
        void *m;
        size = 1024*1024;

        obj = hwloc_get_obj_by_type(topology, HWLOC_OBJ_NODE, n - 1);
        m = hwloc_alloc_membind_nodeset(topology, size, obj->nodeset,
                HWLOC_MEMBIND_DEFAULT, 0);
        hwloc_free(topology, m, size);

        m = malloc(size);
        hwloc_set_area_membind_nodeset(topology, m, size, obj->nodeset,
                HWLOC_MEMBIND_DEFAULT, 0);
        free(m);
    }

    /* Destroy topology object. */
    hwloc_topology_destroy(topology);

    return 0;
}
