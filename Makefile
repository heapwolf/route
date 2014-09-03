CXX ?= g++
export CXXFLAGS

CXXFLAGS += -std=c++1y

all: ./test

./test: test.cc
	$(CXX) -o test ./route.cc ./test.cc $(CXXFLAGS)
	./test

.PHONY: test
