sdltest:main.o SDLHelper.o
	g++ main.o SDLHelper.o -o sdltest `sdl2-config --libs`

main.o:main.cpp
	g++ -c main.cpp -o main.o `sdl2-config --cflags`

SDLHelper.o:SDLHelper.cpp
	g++ -c SDLHelper.cpp -o SDLHelper.o `sdl2-config --cflags`

.PHONY:
clear:
	rm -rf sdltest main.o SDLHelper.o

run:
	make
	chmod 777 sdltest
	./sdltest

installDependencies:
	sudo apt-get install g++
	sudo apt-get install libsdl2-2.0
	sudo apt-get install libsdl2-dev
	sudo apt-get install libsdl2-mixer-dev
	sudo apt-get install libsdl2-image-dev
	sudo apt-get install libsdl2-ttf-dev
	sudo apt-get install libsdl2-gfx-dev
