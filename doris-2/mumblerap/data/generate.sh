#!/usr/bin/env bash

PPATH=$(realpath ..)


. ../../testdata_tools/gen.sh

use_solution harry_regex.py

compile gen.py

samplegroup
limits maxN=1000
sample 1
sample 2
sample 3



group g1 20
limits maxN=1000000 
tc g1_1 gen AMaxDigits=1 maxN=10 N=10 maxDigit=2
tc g1_2 gen AMaxDigits=1 maxN=100 
tc g1_3 gen AMaxDigits=1 maxN=100 
tc g1_4 gen AMaxDigits=1 maxN=100 maxDigit=3
tc g1_5 gen AMaxDigits=1 maxN=1000 N=1000 maxDigit=4
tc g1_6 gen AMaxDigits=1 maxN=10000 maxDigit=5
tc g1_7 gen AMaxDigits=1 maxN=100000 
tc g1_8 gen AMaxDigits=1 maxN=1000000 N=1000000 maxDigit=7
tc g1_9 gen AMaxDigits=1 maxN=1000000 N=1000000 maxDigit=8
tc g1_10 gen AMaxDigits=1 maxN=1000000 N=1000000 maxDigit=9
tc g1_11 gen AMaxDigits=1 maxN=1000000 N=1000000 maxDigit=6
tc g1_12 gen AMaxDigits=1 maxN=1000000 N=1000000 maxDigit=5
tc g1_13 gen AMaxDigits=1 maxN=1000000 N=1000000 maxDigit=4
tc g1_14 gen AMaxDigits=1 maxN=1000000 N=1000000 maxDigit=3
tc g1_15 gen AMaxDigits=1 maxN=1000000 N=1000000 maxDigit=2
tc g1_16 gen AMaxDigits=1 maxN=1000000 N=1000000 maxDigit=1
tc g1_17 gen AMaxDigits=1 maxN=1000000 N=1000000 maxDigit=0

group g2 20
limits maxN=1000000 
tc g2_1 gen last=1 maxN=10
tc g2_2 gen last=1 maxN=100 N=69
tc g2_3 gen last=1 maxN=1000
tc g2_4 gen last=1 maxN=1000000 
tc g2_5 gen last=1 maxN=1000000 maxDigit=5
tc g2_6 gen last=1 maxN=1000000
tc g2_7 gen last=1 maxN=1000000 N=1000000

group g3 30
limits maxN=1000 
tc g3_1 gen maxN=10
tc g3_2 gen maxN=50
tc g3_3 gen maxN=100
tc g3_4 gen maxN=333
tc g3_5 gen maxN=500 maxDigit=5
tc g3_6 gen maxN=750
tc g3_7 gen maxN=1000
tc g3_8 gen maxN=1000 
tc g3_9 gen maxN=1000 N=1000

group g4 30
limits maxN=1000000 
include_group sample
include_group g1
include_group g2
include_group g3
tc g4_1 gen 
tc g4_2 gen
tc g4_3 gen
tc g4_4 gen
tc g4_5 gen maxDigit=5
tc g4_6 gen
tc g4_7 gen
tc g4_8 gen N=123456
tc g4_9 gen N=999999
tc g4_10 gen N=1000000
