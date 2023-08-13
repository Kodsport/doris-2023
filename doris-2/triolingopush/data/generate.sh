#!/usr/bin/env bash

PPATH=$(realpath ..)


. ../../testdata_tools/gen.sh

use_solution jonathan.cpp

compile gen.py

samplegroup
limits nMax=100
sample 1
sample 2
sample 3

group g1 20
limits nMax=3
tc g1_1 gen N=2
tc g1_2 gen N=3

group g2 20
limits nMax=25
include_group g1
tc g2_1 gen maximum=25 minimum=4
tc g2_2 gen maximum=25 minimum=4
tc g2_4 gen maximum=25 minimum=4
tc g2_5 gen maximum=25 minimum=4
tc g2_6 gen maximum=25 minimum=6
tc g2_7 gen maximum=25 minimum=15
tc g2_8 gen maximum=25 minimum=15
tc g2_9 gen maximum=25 minimum=20

group g3 60
limits nMax=1000000
include_group sample
include_group g2
tc g3_1 gen maximum=1000000 minimum=1001
tc g3_2 gen maximum=1000000 minimum=1001
tc g3_3 gen maximum=1000000 minimum=1001
tc g3_4 gen maximum=1000000 minimum=1001
tc g3_5 gen maximum=1000000 minimum=1001
tc g3_6 gen maximum=1000000 minimum=100000
tc g3_7 gen maximum=1000000 minimum=100000
tc g3_8 gen maximum=1000000 minimum=100000
tc g3_9 gen maximum=1000000 minimum=100000
tc g3_10 gen maximum=1000000 minimum=100000
tc g3_11 gen maximum=1000000 minimum=100000
tc g3_12 gen maximum=1000000 minimum=100000
tc g3_13 gen maximum=1000000 minimum=100000
tc g3_14 gen maximum=1000000 minimum=100000
tc g3_15 gen maximum=1000000 minimum=100000
tc g3_16 gen maximum=1000000 minimum=100000
tc g3_17 gen maximum=1000000 minimum=100000
tc g3_18 gen maximum=1000000 minimum=100000
tc g3_19 gen maximum=1000000 minimum=100000
tc g3_20 gen maximum=1000000 minimum=100000
tc g3_21 gen N=1000000

group g4 1
limits nMax=1000000000000000000
include_group g3
tc g4_1 gen minimum=100000000000000000
tc g4_2 gen minimum=100000000000000000
tc g4_3 gen minimum=100000000000000000
tc g4_4 gen minimum=100000000000000000
tc g4_5 gen minimum=100000000000000000
tc g4_6 gen minimum=100000000000000000
tc g4_7 gen minimum=100000000000000000
tc g4_8 gen minimum=100000000000000000
tc g4_9 gen minimum=100000000000000000
tc g4_10 gen minimum=100000000000000000
tc g4_11 gen minimum=100000000000000000
tc g4_12 gen minimum=100000000000000000
tc g4_13 gen minimum=100000000000000000
tc g4_14 gen minimum=100000000000000000
tc g4_15 gen minimum=100000000000000000
tc g4_16 gen minimum=100000000000000000
tc g4_17 gen minimum=100000000000000000
tc g4_18 gen minimum=100000000000000000
tc g4_19 gen minimum=100000000000000000
tc g4_20 gen minimum=100000000000000000
tc g4_21 gen minimum=100000000000000000
tc g4_22 gen minimum=100000000000000000
tc g4_23 gen minimum=100000000000000000
tc g4_24 gen minimum=100000000000000000
tc g4_25 gen minimum=100000000000000000
tc g4_26 gen minimum=100000000000000000
tc g4_27 gen minimum=100000000000000000
tc g4_28 gen minimum=100000000000000000
tc g4_29 gen minimum=100000000000000000
tc g4_30 gen minimum=100000000000000000
tc g4_31 gen minimum=100000000000000000
tc g4_32 gen minimum=100000000000000000
tc g4_33 gen N=1000000000000000000