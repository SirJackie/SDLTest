sdltest:main.cpp
	g++ main.cpp -o sdltest `sdl2-config --cflags --libs`

.PHONY:
clear:
	rm -rf sdltest

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
