#!/bin/bash

(( 0 && 1 ))
echo "0 && 1 = " $?     # 1

let "num = (( 0 && 1 ))"    # let returns same exit status as the double paren arithmetic expansion
echo $num               # 0
let "num = (( 0 && 1 ))"
echo $?                 # 1

(( 200 || 11 ))
echo $?         # 0     the previous operation was successful NOT false
let "num = (( 200 || 11 ))"
echo $num       # 1     num now holds true
let "num = (( 200 || 11 ))"
echo $?         # 0     previous op successful

(( 200 | 11 ))
echo $?     # 0
let "num = (( 200 | 11 ))"
echo $num       # 203
let "num = (( 200 | 11 ))"
echo $?         # 0

