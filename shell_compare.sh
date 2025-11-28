#!/bin/bash

# Read two strings from user
echo "Enter first string: "
read str1

echo "Enter second string: "
read str2

# 1. Check if equal
if [ "$str1" = "$str2" ]; then
    echo "1. Strings are EQUAL"
else
    echo "1. Strings are NOT equal"
fi

# 2. Check if first is greater (lexicographically)
if [ "$str1" \> "$str2" ]; then
    echo "2. '$str1' > '$str2'"
elif [ "$str1" \< "$str2" ]; then
    echo "2. '$str1' < '$str2'"
else
    echo "2. Strings are equal"
fi

# 3. Check lengths
len1=${#str1}
len2=${#str2}
echo "3. Length of '$str1' = $len1"
echo "   Length of '$str2' = $len2"

if [ $len1 -gt $len2 ]; then
    echo "   '$str1' is longer"
elif [ $len1 -lt $len2 ]; then
    echo "   '$str2' is longer"
else
    echo "   Both strings have same length"
fi

# 4. Case insensitive comparison (convert to lowercase first)
str1_lower=$(echo "$str1" | tr '[:upper:]' '[:lower:]')
str2_lower=$(echo "$str2" | tr '[:upper:]' '[:lower:]')

if [ "$str1_lower" = "$str2_lower" ]; then
    echo "4. Strings are EQUAL (case insensitive)"
else
    echo "4. Strings are different (case insensitive)"
fi
