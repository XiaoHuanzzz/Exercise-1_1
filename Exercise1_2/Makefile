# Makefile for NumericalErrorCalculator

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# Source files
SRCS = NumericalErrorCalculator.cpp decimalToBaseN.cpp baseNToDecimal.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
TARGET = main

# Build target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(TARGET)
