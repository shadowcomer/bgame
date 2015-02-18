CCX=clang++
FLAGS=-std=c++11
SRC=Source/
HDRS=Source/
DEPS=*.h
LIBS=-lGL -lX11 -lglfw3 -lXxf86vm -pthread -lXrandr -lXi -lXcursor -lXinerama
BUILD=Build/

EXE=$(BUILD)battleGame

all: clean default

clean:
	rm -fr Build/*

default:
	$(CXX) $(FLAGS) $(SRC)main.cpp -o $(EXE) $(LIBS)


test:
