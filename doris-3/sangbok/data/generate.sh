#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../testdata_tools/gen.sh

use_solution sangbok.py

compile gen.py

samplegroup
sample 1
sample 2
sample 3

group g1 20
limits all_s_same=1
tc same_s_max_10 gen max_n=10 max_t=10 all_s_same=1
tc same_s_max_100 gen max_n=100 max_t=100 all_s_same=1
tc same_s_max_1000 gen max_n=1000 max_t=1000 all_s_same=1
tc same_s_max_10000 gen max_n=10000 max_t=10000 all_s_same=1
tc same_s_max_100000 gen max_n=100000 max_t=100000 all_s_same=1

group g2 40
limits max_n=16
tc small_n_max_t_100 gen max_n=16 max_t=100
tc small_n_max_t_1000 gen max_n=16 max_t=1000
tc small_n_max_t_10000 gen max_n=16 max_t=10000
tc small_n_max_t_100000 gen max_n=16 max_t=100000

group g3 40
include_group g1
include_group g2
include_group sample
tc full1 gen
tc full2 gen
tc full3 gen
tc full4 gen
tc full5 gen
tc full6 gen
tc full7 gen
tc full8 gen
tc full9 gen
tc full10 gen
tc full11 gen
tc full12 gen
tc full13 gen
tc full14 gen
tc full15 gen
tc full16 gen
tc full17 gen
tc full18 gen
tc full19 gen
tc full20 gen
tc full21 gen
tc full22 gen
tc full23 gen
tc full24 gen
