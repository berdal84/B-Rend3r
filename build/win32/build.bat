:: setting environment variables...
set MinGW=C:\MinGW
set root=%cd%\..\..
set output=%root%\bin
set includes=%root%\includes
set libs=%root%\libs
cd %MinGW%\bin\
:: Win32 compilation started with G++
g++.exe %root%\src\*.cpp %root%\main.cpp -o %output%\win32\Nodable.exe -L%MinGW%\bin;%libs% -I%includes%
:: DONE !
pause
