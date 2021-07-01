import os

def FindAllTheCpp():
    cpps = []
    for root,dirs,files in os.walk("../"):
        for file in files:
            if file[-4:] == ".cpp":
                cpps.append(os.path.join(root,file))
    return cpps

def GenerateMakefile(middleContent):
    topContent = '''# Target and Object Declarations
Target = CrossBufferForLinux
'''

    bottomContent = '''
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
'''

    final = topContent + middleContent + bottomContent
    return final

def GenerateMiddleContent(cppList):
    middleConetnt = ""
    middleConetnt += "Objects = " + cppList[0][:-4] + ".o" + "\n"
    for i in range(1, len(cppList)):
        middleConetnt += "Objects += " + cppList[i][:-4] + ".o" + "\n"
    return middleConetnt

if __name__ == "__main__":
    makefile = GenerateMakefile(GenerateMiddleContent(FindAllTheCpp()))
    with open("Makefile", mode="w") as f:
        f.write(makefile)
