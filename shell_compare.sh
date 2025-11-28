#!/bin/bash

echo "Enter first string: "
read str1

echo "Enter second string: "
read str2

if [ "$str1" = "$str2" ]; then
    echo "Strings are EQUAL"
elif [ "$str1" \> "$str2" ]; then
    echo "'$str1' is GREATER"
else
    echo "'$str2' is GREATER"
fi
