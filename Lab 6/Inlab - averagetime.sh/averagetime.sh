#!/bin/bash
#averagetime.sh
#Spencer Hernandez

echo "Enter dictionary"
read dict
echo "Enter grid"
read grid
RUNTIME1=`./a.out $dict $grid | tail -1`
RUNTIME2=`./a.out $dict $grid | tail -1`
RUNTIME3=`./a.out $dict $grid | tail -1`
RUNTIME4=`./a.out $dict $grid | tail -1`
RUNTIME5=`./a.out $dict $grid | tail -1`

sum=$(($RUNTIME1+$RUNTIME2+$RUNTIME3+$RUNTIME4+$RUNTIME5))
average=$((sum / 5))

echo "AVERAGE:" 
echo $average
