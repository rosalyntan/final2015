CMP = g++
MAIN = RunND
FUNC = LTexture
FUNC2 = Background
FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

all: $(MAIN)

$(MAIN): $(MAIN).o $(FUNC).o $(FUNC2).o 
	$(CMP) $(MAIN).o $(FUNC).o $(FUNC2).o -o $(MAIN) $(FLAGS)

$(MAIN).o: $(MAIN).cpp
	$(CMP) -c $(MAIN).cpp $(FLAGS)

$(FUNC).o: $(FUNC).cpp
	$(CMP) -c $(FUNC).cpp $(FLAGS)

$(FUNC2).o: $(FUNC2).cpp
	$(CMP) -c $(FUNC2).cpp $(FLAGS)

clean:
	rm *.o $(MAIN) *~
