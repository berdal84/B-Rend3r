#Compiles and link
g++ -std=c++11 ../src/*.cpp ../main.cpp -o '../bin/linux64/B-Rend3r.out' -I../includes ../lib/linux64/libGLEW.a -lGL -lSDL2main -lSDL2


