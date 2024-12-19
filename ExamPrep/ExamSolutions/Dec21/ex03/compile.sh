#!/bin/sh

PWD=`pwd`
N="0`basename ${PWD} | cut -d 0 -f 2`"
TESTS_CPP=`ls ex${N}-test-*.cpp`

TESTS=""
for T in ${TESTS_CPP}; do
  TESTS="${TESTS} `basename $T .cpp`"
done

set -x
g++ --pedantic -Wall ex$N-library-solutions.cpp ex${N}-main.cpp -o ex${N}-main

for T in $TESTS; do
    g++ --pedantic -Wall ex$N-library-solutions.cpp $T.cpp -o $T
done
