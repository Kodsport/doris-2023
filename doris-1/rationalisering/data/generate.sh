#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../testdata_tools/gen.sh

use_solution fraction.py

compile gen.py

samplegroup
sample 1
sample 2
sample 3

group g1 20
limits b_is_1000=1
tc b_is_1000_1 gen b_is_1000=1
tc b_is_1000_2 gen b_is_1000=1
tc b_is_1000_3 gen b_is_1000=1 dec_f_exp_by=1
tc b_is_1000_4 gen b_is_1000=1 dec_f_exp_by=1
tc b_is_1000_5 gen b_is_1000=1 dec_f_exp_by=2
tc b_is_1000_6 gen b_is_1000=1 dec_f_exp_by=2
tc b_is_1000_7 gen b_is_1000=1 dec_f_exp_by=3
tc b_is_1000_8 gen b_is_1000=1 dec_f_exp_by=3

group g2 40
limits max_val=1000
tc max1000_1 gen max_val=1000
tc max1000_2 gen max_val=1000
tc max1000_3 gen max_val=1000 dec_f_exp_by=1
tc max1000_4 gen max_val=1000 dec_f_exp_by=1
tc max1000_5 gen max_val=1000 dec_f_exp_by=2
tc max1000_6 gen max_val=1000 dec_f_exp_by=2
tc max1000_7 gen max_val=1000 dec_f_exp_by=3
tc max1000_8 gen max_val=1000 dec_f_exp_by=3
tc max1000_9 gen max_val=1000 dec_f_exp_by=4
tc max1000_10 gen max_val=1000 dec_f_exp_by=4
tc max1000_11 gen max_val=1000 dec_f_exp_by=5
tc max1000_12 gen max_val=1000 dec_f_exp_by=5
tc max1000_13 gen max_val=1000 dec_f_exp_by=6
tc max1000_14 gen max_val=1000 dec_f_exp_by=6
tc max1000_15 gen max_val=1000 dec_f_exp_by=6
tc max1000_16 gen max_val=1000 dec_f_exp_by=6
tc max1000_17 gen max_val=1000 dec_f_exp_by=6
tc max1000_18 gen max_val=1000 dec_f_exp_by=6
tc max1000_19 gen max_val=1000 dec_f_exp_by=6
tc max1000_20 gen max_val=1000 dec_f_exp_by=6
tc max1000_21 gen max_val=1000 dec_f_exp_by=6
tc max1000_22 gen max_val=1000 dec_f_exp_by=6
tc max1000_23 gen max_val=1000 dec_f_exp_by=6
tc max1000_24 gen max_val=1000 dec_f_exp_by=6

group g3 40
limits max_val=1000000
include_group g1
include_group g2
include_group sample
tc full1 gen
tc full2 gen
tc full3 gen dec_f_exp_by=2
tc full4 gen dec_f_exp_by=2
tc full5 gen dec_f_exp_by=4
tc full6 gen dec_f_exp_by=4
tc full7 gen dec_f_exp_by=6
tc full8 gen dec_f_exp_by=6
tc full9 gen dec_f_exp_by=6
tc full10 gen dec_f_exp_by=6
tc full11 gen dec_f_exp_by=6
tc full12 gen dec_f_exp_by=6
tc full13 gen dec_f_exp_by=6
tc full14 gen dec_f_exp_by=6
tc full15 gen dec_f_exp_by=6
tc full16 gen dec_f_exp_by=6
tc full17 gen dec_f_exp_by=6
tc full18 gen dec_f_exp_by=6
tc full19 gen dec_f_exp_by=6
tc full20 gen dec_f_exp_by=6
tc full21 gen dec_f_exp_by=6
tc full22 gen dec_f_exp_by=6
tc full23 gen dec_f_exp_by=6
tc full24 gen dec_f_exp_by=6
