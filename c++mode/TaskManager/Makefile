CXX=g++

CXXFLAGS=-std=c++17 -Wall


TARGET=task


SRC=$(wildcard src/*.cpp)


OBJ=$(SRC:.cpp=.o)


INCLUDE=-Iinclude



$(TARGET):$(OBJ)

	$(CXX) $(OBJ) -o $(TARGET)



%.o:%.cpp

	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@



clean:

	rm -f src/*.o $(TARGET)
