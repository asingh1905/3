#!/bin/bash

echo "Enter number of terms: "
read n

a=0
b=1
echo "Fibonacci series:"
echo -n "$a $b"

i=2
while [ $i -lt $n ]
do
    c=$((a + b))
    echo -n " $c"
    a=$b
    b=$c
    i=$((i + 1))
done
echo
