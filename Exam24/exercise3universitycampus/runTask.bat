@echo off
echo [DEBUG] Received args: Task=%1, Exercise=%2

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
) ELSE (
  echo [RESULT] All tests passed!
)

:end
pause
