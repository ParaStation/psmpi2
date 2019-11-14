dnl generated by ./maint/gen_subcfg_m4 at Thu Nov 14 14:30:20 2019
dnl DO NOT EDIT BY HAND!!!
dnl re-run ./maint/updatefiles instead

m4_include([src/mpid/ch3/subconfigure.m4])
m4_include([src/mpid/ch3/channels/nemesis/subconfigure.m4])
m4_include([src/mpid/ch3/channels/nemesis/netmod/ofi/subconfigure.m4])
m4_include([src/mpid/ch3/channels/nemesis/netmod/portals4/subconfigure.m4])
m4_include([src/pm/subconfigure.m4])
m4_include([src/mpid/psp/subconfigure.m4])
m4_include([src/mpid/ch3/channels/nemesis/netmod/mxm/subconfigure.m4])
m4_include([src/binding/fortran/use_mpi/subconfigure.m4])
m4_include([src/mpid/ch3/channels/sock/subconfigure.m4])
m4_include([src/mpid/ch3/util/sock/subconfigure.m4])
m4_include([src/mpid/common/hcoll/subconfigure.m4])
m4_include([src/mpid/ch3/channels/nemesis/netmod/tcp/subconfigure.m4])
m4_include([src/mpid/ch3/channels/nemesis/netmod/llc/subconfigure.m4])
m4_include([src/pmi/subconfigure.m4])
m4_include([src/pmi/pmi2/subconfigure.m4])
m4_include([src/pmi/cray/subconfigure.m4])
m4_include([src/pmi/bgq/subconfigure.m4])
m4_include([src/pmi/simple/subconfigure.m4])
m4_include([src/pmi/pmi2/simple/subconfigure.m4])
m4_include([src/pm/remshell/subconfigure.m4])
m4_include([src/pm/gforker/subconfigure.m4])
m4_include([src/pm/util/subconfigure.m4])
m4_include([src/mpid/ch4/subconfigure.m4])
m4_include([src/mpid/common/sched/subconfigure.m4])
m4_include([src/mpid/common/bc/subconfigure.m4])
m4_include([src/mpid/ch4/shm/posix/subconfigure.m4])
m4_include([src/mpid/common/shm/subconfigure.m4])
m4_include([src/mpid/ch4/netmod/portals4/subconfigure.m4])
m4_include([src/mpid/ch4/shm/stubshm/subconfigure.m4])
m4_include([src/mpid/common/thread/subconfigure.m4])
m4_include([src/mpid/ch4/netmod/stubnm/subconfigure.m4])
m4_include([src/mpid/ch4/netmod/ofi/subconfigure.m4])
m4_include([src/mpid/ch4/netmod/ucx/subconfigure.m4])
m4_include([src/pmi/slurm/subconfigure.m4])

dnl a macro suitable for use as m4_map([some_unary_macro],[PAC_SUBCFG_MODULE_LIST])
m4_define([PAC_SUBCFG_MODULE_LIST],
m4_dquote(
[src_mpid_ch3],
[src_mpid_ch3_channels_nemesis],
[src_mpid_ch3_channels_nemesis_netmod_ofi],
[src_mpid_ch3_channels_nemesis_netmod_portals4],
[src_pm],
[src_mpid_psp],
[src_mpid_ch3_channels_nemesis_netmod_mxm],
[src_binding_fortran_use_mpi],
[src_mpid_ch3_channels_sock],
[src_mpid_ch3_util_sock],
[src_mpid_common_hcoll],
[src_mpid_ch3_channels_nemesis_netmod_tcp],
[src_mpid_ch3_channels_nemesis_netmod_llc],
[src_pmi],
[src_pmi_pmi2],
[src_pmi_cray],
[src_pmi_bgq],
[src_pmi_simple],
[src_pmi_pmi2_simple],
[src_pm_remshell],
[src_pm_gforker],
[src_pm_util],
[src_mpid_ch4],
[src_mpid_common_sched],
[src_mpid_common_bc],
[src_mpid_ch4_shm_posix],
[src_mpid_common_shm],
[src_mpid_ch4_netmod_portals4],
[src_mpid_ch4_shm_stubshm],
[src_mpid_common_thread],
[src_mpid_ch4_netmod_stubnm],
[src_mpid_ch4_netmod_ofi],
[src_mpid_ch4_netmod_ucx],
[src_pmi_slurm]dnl <--- this dnl is important
))

