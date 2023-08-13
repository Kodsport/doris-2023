#!/usr/bin/env bash

PPATH=$(realpath ..)


. ../../testdata_tools/gen.sh

use_solution jonathan.cpp

compile gen.py

samplegroup
limits maxN=10
sample 1
sample 2

# maxQ = int(cmdlinearg('maxQ', 10**5))
# maxN = int(cmdlinearg('maxN', 2*10**5))
# allOrOne = int(cmdlinearg('allOrOne', 0))

group g1 10
limits maxQ=1 maxN=10
tc g1_1 gen maxQ=1 maxN=10
tc g1_2 gen maxQ=1 maxN=10
tc g1_3 gen maxQ=1 maxN=10
tc g1_4 gen maxQ=1 maxN=10
tc g1_5 gen maxQ=1 N=10

group g2 25
limits maxQ=1000 maxN=100
include_group sample
include_group g1
tc g2_1 gen maxQ=10 maxN=10
tc g2_2 gen maxQ=1000 maxN=100
tc g2_3 gen maxQ=1000 maxN=100
tc g2_4 gen maxQ=1000 maxN=100
tc g2_5 gen maxQ=1000 maxN=100
tc g2_6 gen Q=1000 N=100
tc g2_7 gen Q=1000 N=100
tc g2_8 gen Q=100 N=100 spreadOut=1
tc g2_9 gen Q=100 N=100 spreadOut=1
tc g2_10 gen Q=1000 N=100 maximal=1




group g3 10
limits allOrOne=1
tc g3_1 gen allOrOne=1
tc g3_2 gen allOrOne=1
tc g3_3 gen allOrOne=1
tc g3_4 gen allOrOne=1
tc g3_5 gen allOrOne=1
tc g3_6 gen allOrOne=1
tc g3_7 gen allOrOne=1
tc g3_8 gen allOrOne=1
tc g3_9 gen allOrOne=1

group g4 20
limits maxQ=1000 maxN=10000
include_group g2
tc g4_1 gen maxQ=1000 maxN=10000
tc g4_2 gen maxQ=1000 maxN=10000
tc g4_3 gen maxQ=1000 maxN=10000
tc g4_4 gen maxQ=1000 maxN=10000
tc g4_5 gen maxQ=1000 maxN=10000
tc g4_6 gen maxQ=1000 maxN=10000
tc g4_7 gen maxQ=1000 maxN=10000
tc g4_8 gen maxQ=1000 maxN=10000
tc g4_9 gen Q=1000 N=10000
tc g4_10 gen Q=1000 N=10000 
tc g4_11 gen Q=1000 N=10000 spreadOut=1
tc g4_12 gen Q=1000 N=10000 spreadOut=1
tc g4_13 gen Q=1000 N=10000 maximal=1
tc g4_14 gen Q=1000 N=10000 maximal=1

group g5 35
limits maxN=200000 maxQ=100000
include_group g3
include_group g4
tc g5_1 gen
tc g5_2 gen
tc g5_3 gen
tc g5_4 gen
tc g5_5 gen
tc g5_6 gen
tc g5_7 gen
tc g5_8 gen 
tc g5_9 gen N=100000 Q=100000 spreadOut=1
tc g5_10 gen N=200000 Q=100000
tc g5_11 gen N=200000 Q=100000 spreadOut=1
tc g5_12 gen N=200000 Q=100000 spreadOut=1
tc g5_13 gen N=200000 Q=100000 maximal=1
