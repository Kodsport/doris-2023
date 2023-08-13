#!/usr/bin/env bash

PPATH=$(realpath ..)

. ../testdata_tools/gen.sh

use_solution joshua.cpp

compile gen.py

samplegroup
sample 1
sample 2
sample 3

MAXN=100000

group g1forest 20
limits acyclic=1
tc 3
tc forestyes1 gen maxn=$MAXN mode="tree"
tc forestyes2 gen maxn=$MAXN mode="tree"
tc forestyes3 gen maxn=$MAXN mode="tree"
tc forestno1  gen maxn=$MAXN mode="forest"
tc forestno2  gen maxn=$MAXN mode="forest"
tc forestno3  gen maxn=$MAXN mode="forest"

group g2small 40
limits n=1000 m=1000
tc 1
tc 2
tc randomsmall1 gen maxn=700 maxm=1000 mode="random"
tc randomsmall2 gen maxn=800 maxm=1000 mode="random"
tc randomsmall3 gen maxn=100 maxm=1000 mode="random"
tc cliquesmall1 gen maxm=1000 mode="cliques"
tc cliquesmall2 gen maxm=1000 mode="cliques"
tc cliquesmall3 gen maxm=1000 mode="cliques"
tc impossiblesmall1 gen maxn=1000 mode="impossible"
tc impossiblesmall2 gen maxn=1000 mode="impossible"
tc impossiblesmall3 gen maxn=1000 mode="impossible"
tc smallforestyes   gen maxn=1000 mode="tree"
tc smallforestno    gen maxn=1000 mode="forest"

group g3large 40
include_group g1forest
include_group g2small
tc randomlarge1 gen maxn=$MAXN maxm=$MAXN mode="random"
tc randomlarge2 gen maxn=$MAXN maxm=$MAXN mode="random"
tc randomlarge3 gen maxn=$MAXN maxm=$MAXN mode="random"
tc cliquelarge1 gen maxm=$MAXN mode="cliques"
tc cliquelarge2 gen maxm=$MAXN mode="cliques"
tc cliquelarge3 gen maxm=$MAXN mode="cliques"
tc impossiblelarge1 gen maxn=$MAXN mode="impossible"
tc impossiblelarge2 gen maxn=$MAXN mode="impossible"
tc impossiblelarge3 gen maxn=$MAXN mode="impossible"
tc largeforestyes   gen maxn=$MAXN mode="tree"
tc largeforestno    gen maxn=$MAXN mode="forest"
