@echo off

:: Ask for birth year
set /p birthYear=Enter your birth year:

:: Get the current year from system date
for /f "tokens=2 delims==" %%A in ('wmic os get localdatetime /value ^| find "LocalDateTime"') do set datetime=%%A
set currentYear=%datetime:~0,4%

:: Calculate age
set /a age=%currentYear% - %birthYear%

:: Display age
echo You are %age% years old.

pause

