CC = gcc 
CXX = g++
CFLAGS = -Wall -Wextra -O2 -g
CXXFLAGS = -Wall -Wextra -O2 -std=c++11 -g

INCFLAGS = 
LDFLAGS = -ldl
RM = rm -f

SRCS=$(shell ls *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
 
.PHONY: all
all: main
 
main: $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) 

%.o: %.cpp
	-$(CXX) ${CXXFLAGS} $(INCFLAGS) -c -o $@ $^
 
.PHONY: clean
clean:
	-${RM} *.o
