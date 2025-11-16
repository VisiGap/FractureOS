CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -O2 -ffreestanding -nostdlib -I../../lib/libfracture/include
LDFLAGS := -nostdlib -static

TARGET := init
OBJS := main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
