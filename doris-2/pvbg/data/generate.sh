#!/usr/bin/env bash

PPATH=$(realpath ..)


. ../../testdata_tools/gen.sh

use_solution harry.py

compile gen.py

samplegroup
limits maxN=5
sample 1
sample 2
sample 3



group g1 10
limits maxN=5 
tc g1_01 gen N=5 maxR=9 
tc g1_02 gen N=5 maxR=9
tc g1_03 gen N=5 maxR=9
tc g1_04 gen N=5 maxR=4 minR=4
tc g1_05 gen N=5 maxR=9 minR=5
tc g1_06 gen N=5 maxR=9 minR=6
tc g1_07 gen N=5 maxR=9 minR=7
tc g1_08 gen N=5 maxR=9 minR=8
tc g1_09 gen N=5 maxR=9 minR=9
tc g1_10 gen N=5 maxR=9 
tc g1_11 gen N=5 maxR=9 
tc g1_12 gen N=5 maxR=9
tc g1_13 gen N=5 maxR=9
tc g1_14 gen N=5 maxR=9 
tc g1_15 gen N=5 maxR=9
tc g1_16 gen N=5 maxR=9
tc g1_17 gen N=5 maxR=9 
tc g1_18 gen N=5 maxR=9
tc g1_19 gen N=5 maxR=9



group g2 40
limits maxN=1000
include_group g1
include_group sample
tc g2_1 gen maxN=1000 maxR=1000 minR=100
tc g2_2 gen maxN=1000 maxR=1000 minR=100
tc g2_3 gen maxN=1000 maxR=1000 minR=250
tc g2_4 gen maxN=1000 maxR=1000 minR=500
tc g2_5 gen maxN=1000 maxR=1000 minR=999
tc g2_6 gen maxN=1000 maxR=1000 minR=1000
tc g2_7 gen N=1000 maxR=1000 minR=900
tc g2_8 gen N=1000 maxR=1000 minR=950
tc g2_9 gen N=1000 maxR=1000 minR=1000

group g3 50
limits maxN=1000000
include_group g2
tc g3_1 gen 
tc g3_2 gen 
tc g3_3 gen 
tc g3_4 gen 
tc g3_5 gen N=1000000 minR=100000000
tc g3_6 gen N=1000000 minR=100000000
tc g3_7 gen N=1000000 minR=100000000
tc g3_8 gen N=1000000 minR=100000000
tc g3_9 gen N=1000000 minR=100000000
