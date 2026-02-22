CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17 

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = app

SRCS = main.cpp particle.cpp simulation.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

%.o: %.cpp qrcode.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean