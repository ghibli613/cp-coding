@echo off

for /l %%i in (1, 1, 100) do (
    echo %%i

    %1 %%i 4 5 > _test.in
    %2 < _in.txt > _out.txt
    %3 < _in.txt > _ans.txt

    fc _test.out _test.ans || goto :out
)

:out