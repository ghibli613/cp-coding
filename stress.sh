#!/usr/bin/env bash
 
read -p 'The number of test cases: ' num_tests

for ((testNum=0;testNum<$num_tests;testNum++))
do
    $1 > _in.txt
    $3 < _in.txt > _ans.txt
    $2 < _in.txt > _out.txt
    H1=`md5sum _out.txt`
    H2=`md5sum _ans.txt`
    if !(cmp -s "_out.txt" "_ans.txt")
    then
        echo "Error found!"
        exit
    fi
done
echo Passed $num_tests test cases!
