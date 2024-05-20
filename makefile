CXX = g++
CXXFLAGS = -Wall -g

OBJ = main.o pathfinder.o map_generator.o maps_data.o map_text_drawer.o
EXEC = pathfinder

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: clean all
