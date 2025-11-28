#!/bin/bash

# Read two strings from user
echo "Enter first string: "
read str1

echo "Enter second string: "
read str2

# Concatenate using simple juxtaposition
result="$str1$str2"

# Display result
echo "Concatenated string: $result"

# Alternative methods (commented)
# result="${str1}${str2}"     # same as above
# result=`echo $str1 $str2`   # with space between
