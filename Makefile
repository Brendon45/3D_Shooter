#OBJS - Files to compile
OBJS = src/*.c

#CC - Compiler
CC = gcc

#INCLUDE_PATHS - Additional include paths
INCLUDE_PATHS = -ISDL2\include\SDL2

#LIBRARY_PATHS - Additional library paths
LIBRARY_PATHS = -LSDL2\lib

#COMPILER_FLAGS - Additional compilation flags
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -Wall -Werror -Wextra -pedantic

#LINKER_FLAGS - Libraries we're linking with
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2
LINUX_LINKER_FLAGS = -lSDL2

#OBJ_NAME - Name of our executable program
OBJ_NAME = main

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

#Linux SDL compiling
linux : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINUX_LINKER_FLAGS) -DLINUX -o $(OBJ_NAME)

#Linux SDL installation
linux_install :
	sudo apt-get install libsdl2-dev

#MAC SDL compiling
mac : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINUX_LINKER_FLAGS) -DMAC -o $(OBJ_NAME)

