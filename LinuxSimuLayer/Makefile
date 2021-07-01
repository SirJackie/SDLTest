# Target and Object Declarations
Target = CrossBufferForLinux
Objects = ../CrossBufferLayer/FrameBuffer.o
Objects += ../CrossBufferLayer/CrossBuffer.o
Objects += ../CrossBufferLayer/KeyboardSupport.o
Objects += ../CrossBufferLayer/BasicDataTypeDeclarations.o
Objects += ../CrossBufferLayer/FPSCalculator.o
Objects += ../CrossBufferLayer/FontSupport.o
Objects += ../LinuxSimuLayer/SDLHelper.o
Objects += ../LinuxSimuLayer/main.o

TargetGeneratingArguments = `sdl2-config --libs`
ObjectGeneratingArguments = `sdl2-config --cflags`

Compiler := g++
RMRF := rm -rf

$(Target):$(Objects)
	$(Compiler) $^ -o $@ $(TargetGeneratingArguments)

%.o:%.cpp
	$(Compiler) -c $^ -o $@ $(ObjectGeneratingArguments)

.PHONY:
clear:
	$(RMRF) $(Target) $(Objects)

run:
	make
	chmod 777 $(Target)
	./$(Target)

installDependencies:
	sudo apt-get install g++
	sudo apt-get install libsdl2-2.0
	sudo apt-get install libsdl2-dev
	sudo apt-get install libsdl2-mixer-dev
	sudo apt-get install libsdl2-image-dev
	sudo apt-get install libsdl2-ttf-dev
	sudo apt-get install libsdl2-gfx-dev
