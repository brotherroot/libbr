INC_PATH = include
SRC_PATH = src
OBJ_PATH = obj
LIB_PATH = lib
BIN_PATH = bin

MATH_PATH = math

CPPFLAGS = -Weffc++ -Wall -I$(INC_PATH) -std=c++0x

.PHONY: build
build: test

test: $(BIN_PATH)/test_Dual.exe $(BIN_PATH)/test_Vector2D.exe

$(BIN_PATH)/test_Vector2D.exe: $(SRC_PATH)/test/test_Vector2D.cpp $(INC_PATH)/math/Vector2D.hpp
	g++ $(CPPFLAGS) $^ -o $@

$(BIN_PATH)/test_Dual.exe: $(SRC_PATH)/test/test_Dual.cpp $(INC_PATH)/math/Dual.hpp
	g++ $(CPPFLAGS) $^ -o $@

#$(OBJ_PATH)/Vector2D.o: $(SRC_PATH)/$(MATH_PATH)Vector2D.cc $(INC_PATH)$(MATH_PATH)Vector2D.h 
#	g++ $(CPPFLAGS) -c $< -o $@

#$(OBJ_PATH)Point2D.o: $(SRC_PATH)Point2D.cc $(INC_PATH)Point2D.h $(INL_PATH)Point2D.inl
#	g++ $(CPPFLAGS) -c $< -o $@

#$(OBJ_PATH)/$(MATH_PATH)/Bignum.o: $(SRC_PATH)/$(MATH_PATH)/Bignum.cc $(INC_PATH)/$(MATH_PATH)/Bignum.h
#	g++ $(CPPFLAGS) -c $^ -o $@

.PHONY: rebuild
rebuild: clean build

.PHONY: clean
clean:
	-rm $(OBJ_PATH)/*
	-rm $(BIN_PATH)/*
