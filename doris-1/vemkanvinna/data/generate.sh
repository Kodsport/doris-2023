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

group g1 5
limits all_filled=1
tc all_filled1 gen all_filled=1
tc all_filled2 gen all_filled=1
tc all_filled3 gen all_filled=1
tc all_filled4 gen all_filled=1


group g2 65
limits one_winner=1
include_group g1
tc one_winner1 gen one_winner=1
tc one_winner2 gen one_winner=1
tc one_winner3 gen one_winner=1
tc one_winner4 gen one_winner=1
tc one_winner5 gen one_winner=1
tc one_winner6 gen one_winner=1
tc one_winner7 gen one_winner=1
tc one_winner8 gen one_winner=1
tc one_winner9 gen one_winner=1
tc one_winner10 gen one_winner=1
tc one_winner11 gen one_winner=1
tc one_winner12 gen one_winner=1
tc one_winner13 gen one_winner=1
tc one_winner14 gen one_winner=1
tc one_winner15 gen one_winner=1
tc one_winner18 gen one_winner=1
tc one_winner19 gen one_winner=1
tc one_winner20 gen one_winner=1
tc one_winner21 gen one_winner=1
tc one_winner22 gen one_winner=1
tc one_winner23 gen one_winner=1
tc one_winner24 gen one_winner=1
tc one_winner25 gen one_winner=1
tc one_winner26 gen one_winner=1
tc one_winner28 gen one_winner=1
tc one_winner29 gen one_winner=1
tc one_winner30 gen one_winner=1
tc one_winner31 gen one_winner=1
tc one_winner33 gen one_winner=1
tc one_winner34 gen one_winner=1
tc one_winner35 gen one_winner=1
tc one_winner37 gen one_winner=1
tc one_winner38 gen one_winner=1
tc one_winner39 gen one_winner=1


group g3 30
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
tc full25 gen
tc full26 gen
tc full27 gen
tc full28 gen
tc full29 gen
tc_manual ../manual_testdata/manual1.in
tc_manual ../manual_testdata/manual2.in
tc_manual ../manual_testdata/manual3.in
tc_manual ../manual_testdata/manual4.in
