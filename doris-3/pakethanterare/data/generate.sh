#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../testdata_tools/gen.sh

use_solution zeke.py

compile gen.py

samplegroup
sample 1
sample 2
sample 3
sample 4

group g1 20
limits max_t=1
tc t_is_1_10 gen max_t=1 max_b=10
tc t_is_1_100 gen max_t=1 max_b=100
tc t_is_1_998 gen max_t=1 max_b=998
tc t_is_1_999 gen max_t=1 max_b=999
tc t_is_1_1000 gen max_t=1 max_b=1000

group g2 20
limits max_b=1
tc b_is_1_10 gen max_b=1 max_t=10
tc b_is_1_100 gen max_b=1 max_t=100
tc b_is_1_1000 gen max_b=1 max_t=1000
tc b_is_1_10000 gen max_b=1 max_t=10000
tc b_is_1_100000 gen max_b=1 max_t=100000
tc b_is_1_1000000 gen max_b=1 max_t=1000000

group g3 20
limits all_diff_1=1
tc all_diff_1_10 gen max_b=10 max_t=10 all_diff_1=1
tc all_diff_1_100 gen max_b=100 max_t=100 all_diff_1=1
tc all_diff_1_1000 gen max_b=1000 max_t=1000 all_diff_1=1
tc all_diff_1_10000 gen max_b=1000 max_t=10000 all_diff_1=1
tc all_diff_1_100000 gen max_b=1000 max_t=100000 all_diff_1=1
tc all_diff_1_1000000 gen max_b=1000 max_t=1000000 all_diff_1=1
tc all_diff_1_1000000_1 gen max_b=1 max_t=1000000 all_diff_1=1
tc all_diff_1_1000000_2 gen max_b=2 max_t=1000000 all_diff_1=1
tc all_diff_1_1000000_3 gen max_b=3 max_t=1000000 all_diff_1=1

group g4 20
limits max_t=100 max_b=100
tc small_t_b_0 gen max_b=100 max_t=100
tc small_t_b_1 gen max_b=100 max_t=100
tc small_t_b_2 gen max_b=100 max_t=100
tc small_t_b_3 gen max_b=100 max_t=100
tc small_t_b_4 gen max_b=100 max_t=100
tc small_t_b_5 gen max_b=100 max_t=100
tc small_t_b_6 gen max_b=100 max_t=100
tc small_t_b_7 gen max_b=100 max_t=100
tc small_t_b_8 gen max_b=100 max_t=100
tc small_t_b_9 gen max_b=100 max_t=100

group g5 20
include_group g1
include_group g2
include_group g3
include_group g4
include_group sample
tc full0 gen
tc full1 gen
tc full2 gen
tc full3 gen
tc small_b_0 gen max_b 4
tc small_b_1 gen max_b 4
tc small_b_2 gen max_b 4
tc small_b_3 gen max_b 4
tc small_b_4 gen max_b 4
