#!/usr/bin/env bash

PPATH=$(realpath ..)


. ../../testdata_tools/gen.sh

use_solution gustav.py

compile gen.py

samplegroup
limits nMax=11
sample 1
sample 2
sample 3

group g1 30
limits nMax=1
tc g1_1 gen N=1 single=2
tc g1_2 gen N=1 single=3
tc g1_3 gen N=1 single=4
tc g1_4 gen N=1 single=5
tc g1_5 gen N=1 single=6
tc g1_7 gen N=1 single=8
tc g1_8 gen N=1 single=9
tc g1_9 gen N=1 single=10
tc g1_10 gen N=1 single=11
tc g1_11 gen N=1 single=12


group g2 70
limits nMax=11
include_group sample
include_group g1
tc g2_1 gen N=2
tc g2_2 gen N=3
tc g2_3 gen N=6
tc g2_4 gen N=6
tc g2_5 gen N=8
tc g2_7 gen N=2
tc g2_8 gen N=2
tc g2_9 gen N=2
tc g2_10 gen N=2
tc g2_12 gen N=5
tc g2_13 gen N=5
tc g2_14 gen N=5
tc g2_15 gen N=5
tc g2_16 gen N=5
tc g2_18 gen N=5
tc g2_19 gen N=5
tc g2_21 gen N=5
tc g2_24 gen N=4
tc g2_25 gen N=5
tc g2_26 gen N=6
tc g2_27 gen N=7
tc g2_28 gen N=8
tc g2_29 gen N=9
tc g2_30 gen N=10
tc g2_31 gen N=10
tc g2_33 gen N=3
tc g2_34 gen N=4
tc g2_35 gen N=5
tc g2_36 gen N=6
tc g2_37 gen N=7
tc g2_39 gen N=9
tc g2_40 gen N=10
tc g2_41 gen N=10
tc g2_42 gen N=2
tc g2_43 gen N=3
tc g2_44 gen N=4
tc g2_45 gen N=5
tc g2_46 gen N=6
tc g2_47 gen N=7
tc g2_48 gen N=8
tc g2_49 gen N=9
tc g2_50 gen N=10
tc g2_51 gen N=10
