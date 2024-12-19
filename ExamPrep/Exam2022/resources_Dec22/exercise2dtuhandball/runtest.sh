#!/bin/bash

# driver.sh - The simplest autograder we could think of. It checks
#   that students can write a C program that compiles, and then
#   executes with an exit status of zero.
#   Usage: ./driver.sh

print_test_outcome() {
	if [ ${!1} -eq 0 ]; then
		echo "passes tests: yes"
	else
		echo "passes tests: no"
		if [ ${!1} -eq 124 ]; then
			echo -n "reason: Program took more than ${Maxtime} seconds to complete execution"
		else
			echo -n "reason: $1 was expected to return the following output: "
			cat $1.out
			echo ""
			echo "Instead, it returned the following output:"
			if test -f $1.ret; then
				cat $1.ret
			fi
		fi
	fi
		
}

print_feedback() {
	argv=("$@")
	
	echo ""
	echo "tests completed!"
	echo ""
	echo "results: "
	
	for ((j=0; j<$#; j++)); do
		echo "---------------------------------------------------------------------"
		echo -n "${argv[j]}: compiles: "
		if [ ${!argv[j]} -eq 2 ]; then
			echo "no"
		else
			echo -n "yes, "
			print_test_outcome ${argv[j]}
		fi
		
	done
	
}

compute_score() {
	score=0
	argv=("$@")
	# adjust based on number of tests
	
	for ((j=0; j<$#; j++)); do
		if [ ${!argv[j]} -eq 0 ]; then
			score=$(expr $score + 1)
		fi
	done
	
	echo "---------------------------------------------------------------------"
	echo -n "total score: "
	echo -n $(($score * 100 / $#))
	echo "%"	
}

compile() {
	echo "Compiling " $1
	g++ $1.cpp $Library -o $1 --std=c++17
	status=$?
	if [ ${status} -ne 0 ]; then
		echo "Failure: Unable to compile " $1 ": (return status = ${status})"
		return 2
	fi
	return 0
}

run_test() {
	echo "Running " $1
	./$1 > ./$2.ret
	status=$?
	if [ ${status} -eq 124 ]; then
#		echo "Failure:" $1 "took more than ${Maxtime} seconds to complete execution"
		return 124
	fi
	
	diff -w ./$2.ret ./$2.out -q
	status=$?
	
	if [ ${status} -eq 0 ]; then
		local test=$(diff -w ./$2.ret ./$2.out -q)	
		if [ -z "$test" ]; then
#			echo "Success:" $1 "passed" $2
			return 0
		fi
	fi
#	echo "Failure: "
#	echo $1 "was expected to return the following output:"
#	cat $2.out
#	echo ""
#	echo "Instead, it returned the following output:"
#	if test -f $2.ret; then
#		cat $2.ret
#	fi
#	echo ""
	return 1
}

Maxtime=10
Library="ex02-library.cpp"

if test -f tests/$Library; then
	rm tests/$Library
fi
cp $Library tests/$Library
cd tests

# Run the preliminary test
compile Example
Example=$?
if [ ${Example} -eq 0 ]; then
	run_test Example Example
	Example=$?
fi

compile TaskA
TaskA=$?
if [ ${TaskA} -eq 0 ]; then
	run_test TaskA TaskA
	TaskA=$?
fi

compile TaskB
TaskB=$?
if [ ${TaskB} -eq 0 ]; then
	run_test TaskB TaskB
	TaskB=$?
fi

compile TaskC
TaskC=$?
if [ ${TaskC} -eq 0 ]; then
	run_test TaskC TaskC
	TaskC=$?
fi

compile TaskD
TaskD=$?
if [ ${TaskD} -eq 0 ]; then
	run_test TaskD TaskD
	TaskD=$?
fi

print_feedback Example TaskA TaskB TaskC TaskD
compute_score Example TaskA TaskB TaskC TaskD
print_feedback Example TaskA TaskB TaskC TaskD > ../results.txt
compute_score Example TaskA TaskB TaskC TaskD >> ../results.txt
cd ..
if test -f tests/$Library; then
	rm tests/$Library
fi
rm tests/*.ret

exit

