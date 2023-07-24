# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source files
SOURCES = functions.cpp findZero.cpp 

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
