@echo off
setlocal enabledelayedexpansion

set /p num_tests="The number of test cases: "

for /L %%i in (0,1,%num_tests%) do (
    %1 > _in.txt
    %3 < _in.txt > _ans.txt
    %2 < _in.txt > _out.txt

    set "H1="
    for /f "tokens=1" %%a in ('certutil -hashfile _out.txt MD5 ^| find /v ":"') do set "H1=%%a"

    set "H2="
    for /f "tokens=1" %%b in ('certutil -hashfile _ans.txt MD5 ^| find /v ":"') do set "H2=%%b"

    if not !H1! equ !H2! (
        echo Error found!
        exit /b
    )
)

echo Passed %num_tests% test cases!
