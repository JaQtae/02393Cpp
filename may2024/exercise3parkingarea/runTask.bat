@echo off
echo [DEBUG] Task = %1, Exercise = %2

SET TASK=%~1
SET EX=%~2

echo [INFO] Compiling Task%TASK% using ex0%EX%-library.cpp ...
g++ -o Task%TASK% tests\Task%TASK%.cpp ex0%EX%-library.cpp
IF ERRORLEVEL 1 (
  echo [ERROR] --- Compilation failed ---
  GOTO end
)

echo [INFO] Running Task%TASK%.exe ...
Task%TASK%.exe > Task%TASK%.out

echo [INFO] Comparing Task%TASK%.out with tests\Task%TASK%.out ...
fc Task%TASK%.out tests\Task%TASK%.out > nul
IF ERRORLEVEL 1 (
  echo [RESULT] Output mismatch!
choice /M "Do you want to see the difference?" /C YN
  IF ERRORLEVEL 2 (
    echo Skipping diff.
  ) ELSE (
    fc Task%TASK%.out tests\Task%TASK%.out
  )
) ELSE (
  echo [RESULT] All tests passed!
)

:end
pause
