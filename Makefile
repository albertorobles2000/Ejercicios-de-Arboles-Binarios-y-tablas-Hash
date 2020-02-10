INCLUDE = include
LIB     = lib
OBJ     = obj
SRC = src
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -c 

all: clean $(BIN)/ejercicio01 $(BIN)/ejercicio02 $(BIN)/ejercicio03 $(BIN)/ejercicio05 \
	$(BIN)/ejercicio06 $(BIN)/ejercicio07 $(BIN)/ejercicio08 \
	$(BIN)/ejercicio09 

$(BIN)/ejercicio01: $(SRC)/ejercicio01.cpp
	$(CXX) -o $(BIN)/ejercicio01 $(SRC)/ejercicio01.cpp

$(BIN)/ejercicio02: $(SRC)/ejercicio02.cpp
	$(CXX) -o $(BIN)/ejercicio02 $(SRC)/ejercicio02.cpp

$(BIN)/ejercicio03: $(SRC)/ejercicio03.cpp
	$(CXX) -o $(BIN)/ejercicio03 $(SRC)/ejercicio03.cpp

$(BIN)/ejercicio05: $(SRC)/ejercicio05.cpp
	$(CXX) -o $(BIN)/ejercicio05 $(SRC)/ejercicio05.cpp

$(BIN)/ejercicio06: $(SRC)/ejercicio06.cpp
	$(CXX) -o $(BIN)/ejercicio06 $(SRC)/ejercicio06.cpp

$(BIN)/ejercicio07: $(SRC)/ejercicio07.cpp
	$(CXX) -o $(BIN)/ejercicio07 $(SRC)/ejercicio07.cpp

$(BIN)/ejercicio08: $(SRC)/ejercicio08.cpp
	$(CXX) -o $(BIN)/ejercicio08 $(SRC)/ejercicio08.cpp

$(BIN)/ejercicio09: $(SRC)/ejercicio09.cpp
	$(CXX) -o $(BIN)/ejercicio09 $(SRC)/ejercicio09.cpp

# ************ Limpieza ************
clean :
	-rm $(BIN)/*

