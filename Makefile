# -I /usr/include/SDL2     Header Files
# -D_REENTRANT
# -l SDL2

sdltest:main.cpp
	g++ main.cpp -o sdltest -I /usr/include/SDL2 -D_REENTRANT -l SDL2

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
