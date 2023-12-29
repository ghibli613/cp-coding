#!/bin/bash

for i in {1..100}; do
    echo $i

    $1 $i 4 5 > _in.txt
    $2 < _in.txt > _out.txt
    $3 < _in.txt > _ans.txt

    diff _out.txt _ans.txt || exit 1
done

echo "Finished"
