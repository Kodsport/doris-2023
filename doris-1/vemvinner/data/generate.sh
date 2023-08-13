#!/usr/bin/env bash

PPATH=$(realpath ..)

REQUIRE_SAMPLE_REUSE=0
. ../../testdata_tools/gen.sh

use_solution jonathan.cpp

compile gen.py

samplegroup
sample 1
sample 2
sample 3

group g1 20
limits no_diag=1
tc no_diag1 gen no_diag=1
tc no_diag2 gen no_diag=1
tc no_diag3 gen no_diag=1
tc no_diag4 gen no_diag=1
tc no_diag5 gen no_diag=1
tc no_diag6 gen no_diag=1
tc no_diag7 gen no_diag=1
tc no_diag8 gen no_diag=1
tc no_diag9 gen no_diag=1
tc no_diag10 gen no_diag=1
tc no_diag11 gen no_diag=1
tc no_diag12 gen no_diag=1

group g2 40
limits abdullah_loses=1
tc abdullah_loses1 gen abdullah_loses=1
tc abdullah_loses2 gen abdullah_loses=1
tc abdullah_loses3 gen abdullah_loses=1
tc abdullah_loses4 gen abdullah_loses=1
tc abdullah_loses5 gen abdullah_loses=1
tc abdullah_loses6 gen abdullah_loses=1
tc abdullah_loses7 gen abdullah_loses=1
tc abdullah_loses8 gen abdullah_loses=1
tc abdullah_loses9 gen abdullah_loses=1
tc abdullah_loses10 gen abdullah_loses=1
tc abdullah_loses11 gen abdullah_loses=1
tc abdullah_loses12 gen abdullah_loses=1

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
