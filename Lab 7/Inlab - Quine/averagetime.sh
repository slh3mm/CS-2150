#!/bin/bash

echo "Enter e (exponent): "
read e

if [[ $e == "quit" ]]; then
    exit 0
    fi

numberOfRuns=5
totalRuns=0
for ((i=1; i<=numberOfRuns; i++))
do
    run=`./a.out ${e}`
    totalRuns=`expr $totalRuns + $run`
    echo "Running iteration ${i}..."
    echo "time taken: ${run} ms"
done

averageTime=`expr $totalRuns / $numberOfRuns`

echo "Average time was ${averageTime} ms"
