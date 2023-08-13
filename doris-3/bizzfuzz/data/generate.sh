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
limits max_range=999
tc small_range_10 gen max_b=10 max_range=999
tc small_range_100 gen max_b=100 max_range=999
tc small_range_1000 gen max_b=1000 max_range=999
tc small_range_10000 gen max_b=10000 max_range=999
tc small_range_100000 gen max_b=100000 max_range=999
tc small_range_1000000 gen max_b=1000000 max_range=999
tc small_range_10000000 gen max_b=10000000 max_range=999
tc small_range_100000000 gen max_b=100000000 max_range=999
tc small_range_1000000000 gen max_b=1000000000 max_range=999
tc small_range_10000000000 gen max_b=10000000000 max_range=999
tc small_range_100000000000 gen max_b=100000000000 max_range=999
tc small_range_1000000000000 gen max_b=1000000000000 max_range=999
tc small_range_10000000000000 gen max_b=10000000000000 max_range=999
tc small_range_100000000000000 gen max_b=100000000000000 max_range=999
tc small_range_1000000000000000 gen max_b=1000000000000000 max_range=999
tc small_range_10000000000000000 gen max_b=10000000000000000 max_range=999
tc small_range_100000000000000000 gen max_b=100000000000000000 max_range=999
tc small_range_1000000000000000000 gen max_b=1000000000000000000 max_range=999

group g2 20
limits ac_is_1=1
tc ac_is_1_10 gen max_b=10 ac_is_1=1
tc ac_is_1_100 gen max_b=100 ac_is_1=1
tc ac_is_1_1000 gen max_b=1000 ac_is_1=1
tc ac_is_1_10000 gen max_b=10000 ac_is_1=1
tc ac_is_1_100000 gen max_b=100000 ac_is_1=1
tc ac_is_1_1000000 gen max_b=1000000 ac_is_1=1
tc ac_is_1_10000000 gen max_b=10000000 ac_is_1=1
tc ac_is_1_100000000 gen max_b=100000000 ac_is_1=1
tc ac_is_1_1000000000 gen max_b=1000000000 ac_is_1=1
tc ac_is_1_10000000000 gen max_b=10000000000 ac_is_1=1
tc ac_is_1_100000000000 gen max_b=100000000000 ac_is_1=1
tc ac_is_1_1000000000000 gen max_b=1000000000000 ac_is_1=1
tc ac_is_1_10000000000000 gen max_b=10000000000000 ac_is_1=1
tc ac_is_1_100000000000000 gen max_b=100000000000000 ac_is_1=1
tc ac_is_1_1000000000000000 gen max_b=1000000000000000 ac_is_1=1
tc ac_is_1_10000000000000000 gen max_b=10000000000000000 ac_is_1=1
tc ac_is_1_100000000000000000 gen max_b=100000000000000000 ac_is_1=1
tc ac_is_1_1000000000000000000 gen max_b=1000000000000000000 ac_is_1=1

group g3 20
limits d_is_2_c=1
tc d_is_2_c_10 gen max_b=10 d_is_2_c=1
tc d_is_2_c_100 gen max_b=100 d_is_2_c=1
tc d_is_2_c_1000 gen max_b=1000 d_is_2_c=1
tc d_is_2_c_10000 gen max_b=10000 d_is_2_c=1
tc d_is_2_c_100000 gen max_b=100000 d_is_2_c=1
tc d_is_2_c_1000000 gen max_b=1000000 d_is_2_c=1
tc d_is_2_c_10000000 gen max_b=10000000 d_is_2_c=1
tc d_is_2_c_100000000 gen max_b=100000000 d_is_2_c=1
tc d_is_2_c_1000000000 gen max_b=1000000000 d_is_2_c=1
tc d_is_2_c_10000000000 gen max_b=10000000000 d_is_2_c=1
tc d_is_2_c_100000000000 gen max_b=100000000000 d_is_2_c=1
tc d_is_2_c_1000000000000 gen max_b=1000000000000 d_is_2_c=1
tc d_is_2_c_10000000000000 gen max_b=10000000000000 d_is_2_c=1
tc d_is_2_c_100000000000000 gen max_b=100000000000000 d_is_2_c=1
tc d_is_2_c_1000000000000000 gen max_b=1000000000000000 d_is_2_c=1
tc d_is_2_c_10000000000000000 gen max_b=10000000000000000 d_is_2_c=1
tc d_is_2_c_100000000000000000 gen max_b=100000000000000000 d_is_2_c=1
tc d_is_2_c_1000000000000000000 gen max_b=1000000000000000000 d_is_2_c=1

group g4 40
include_group g1
include_group g2
include_group g3
include_group sample
tc full_10 gen max_b=10
tc full_100 gen max_b=100
tc full_1000 gen max_b=1000
tc full_10000 gen max_b=10000
tc full_100000 gen max_b=100000
tc full_1000000 gen max_b=1000000
tc full_10000000 gen max_b=10000000
tc full_100000000 gen max_b=100000000
tc full_1000000000 gen max_b=1000000000
tc full_10000000000 gen max_b=10000000000
tc full_100000000000 gen max_b=100000000000
tc full_1000000000000 gen max_b=1000000000000
tc full_10000000000000 gen max_b=10000000000000
tc full_100000000000000 gen max_b=100000000000000
tc full_1000000000000000 gen max_b=1000000000000000
tc full_10000000000000000 gen max_b=10000000000000000
tc full_100000000000000000 gen max_b=100000000000000000
tc full_1000000000000000000 gen max_b=1000000000000000000
