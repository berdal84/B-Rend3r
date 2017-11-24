:: Compiles and link
g++ -std=c++11 ../../src/*.cpp ../../main.cpp -o ../../bin/win32/B-Rend3r.exe -Wall -mwindows ../../lib/glew32.lib -lopengl32 -lmingw32 -lSDL2main -lSDL2
:: Copy last version of shaders
ROBOCOPY /MIR "../../shaders/" "../../bin/win32/shaders/"
pause