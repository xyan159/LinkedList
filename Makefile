TARGET=main.o
SOURCES=main.cpp LinkedList.cpp Node.cpp
CXX=g++

all: $(TARGET)
	$(CXX) -o $(TARGET) $(SOURCES)

	
debug:
	$(CXX) -D_DEBUG -o $(TARGET) $(SOURCES)
	
clean:
	$(RM) -rf $(TARGET)
