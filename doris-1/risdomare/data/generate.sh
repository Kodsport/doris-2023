#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../testdata_tools/gen.sh

use_solution ellinor.cpp

compile gen.py

samplegroup
sample 1
sample 2


group g1 20
limits maxn=100
tc_manual manual_1
tc_manual manual_2
tc_manual manual_3
tc tinyn1 gen n=1
tc tinyn2 gen n=10
tc tinyn3 gen n=100
tc tinyn4 gen n=69

group g2 30
limits uniquesums=1
tc unique_sums1 gen unique_sums=1
tc unique_sums2 gen unique_sums=1
tc unique_sums3 gen unique_sums=1
tc unique_sums4 gen unique_sums=1
tc unique_sums5 gen unique_sums=1
tc unique_sums6 gen unique_sums=1
tc unique_sums7 gen unique_sums=1
tc unique_sums8 gen unique_sums=1

group g3 20
limits preferamount=1
tc manual_2
tc manual_3
tc c_is_a1 gen c_is_a=1
tc c_is_a2 gen c_is_a=1
tc c_is_a3 gen c_is_a=1
tc c_is_a4 gen c_is_a=1
tc c_is_a5 gen c_is_a=1
tc c_is_a6 gen c_is_a=1
tc c_is_a7 gen c_is_a=1
tc c_is_a8 gen c_is_a=1
tc c_is_a9 gen c_is_a=1
tc c_is_a10 gen c_is_a=1
tc c_is_a11 gen c_is_a=1
tc c_is_a12 gen c_is_a=1
tc c_is_a13 gen c_is_a=1
tc c_is_a14 gen c_is_a=1
tc c_is_a15 gen c_is_a=1
tc c_is_a16 gen c_is_a=1

group g4 30
include_group g1
include_group g2
include_group g3
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
tc max_ai_bi1 gen
tc max_ai_bi2 gen
tc max_ai_bi3 gen
tc max_ai_bi4 gen
tc max_ai_bi5 gen
tc max_ai_bi6 gen
tc max_ai_bi7 gen
tc max_ai_bi8 gen
tc max_ai_bi9 gen
tc max_ai_bi10 gen max_ai_bi=1000000
tc max_ai_bi11 gen max_ai_bi=1000000
tc max_ai_bi12 gen max_ai_bi=100000
tc max_ai_bi13 gen max_ai_bi=100000
tc max_ai_bi14 gen max_ai_bi=100000
tc max_ai_bi15 gen max_ai_bi=1000000
tc max_ai_bi16 gen max_ai_bi=100000
