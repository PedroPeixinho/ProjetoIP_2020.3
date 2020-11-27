# game code directory name
GAMEDIR := src/Ameaças_Ocultas/MyClient

# binary output directory name
OUTPUTDIR := bin
LIBDIR := src/lib

# name for the output(binary) of the game code
GAMENAME := game

# if you want debug information about memory e.g. memory leaks use -fsanitize=address
# add C flags, like: CFLAGS := -Wall -Werror -Wconversion -Wextra
CFLAGS := 

# add load flags, others like -pthread
LDLIB := -lm -lallegro -lallegro_image -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec

CC := gcc -std=c17
RM := rm -f
MK := mkdir -p

EXT := c
INC := -I $(LIBDIR)

GAMESOURCES := $(shell find $(GAMEDIR) -type f -name *.$(EXT))
LIBSOURCES := $(shell find $(LIBDIR) -type f -name *.$(EXT))
GAMEOBJS := $(subst .$(EXT),.o,$(GAMESOURCES))
LIBOBJS := $(subst .$(EXT),.o,$(LIBSOURCES))

build: mkdirs buildGAME clean

all: mkdirs buildGAME clean runGAME

run: runGAME

buildGAME: $(LIBOBJS) $(GAMEOBJS) 
	@echo "\n  Linking $(GAMENAME)..."
	$(CC) -o $(OUTPUTDIR)/$(GAMENAME) $(LIBOBJS) $(GAMEOBJS) $(LDLIB) $(CFLAGS)
	@echo "\n"

%.o : %.$(EXT)	
	$(CC) -c $< -o $@ $(INC) $(CFLAGS)

mkdirs:
	$(MK) $(OUTPUTDIR)

clean:
	@echo "  Cleaning..."
	$(RM) $(LIBOBJS) $(GAMEOBJS) 

runGAME:
	@echo "\n  Starting to run $(GAMENAME)...\n"; ./$(OUTPUTDIR)/$(GAMENAME)
