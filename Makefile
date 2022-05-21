all: wrapper

wrapper: api.o using.o
	g++ api.o using.o -o test

api.o: api.cpp
	g++ -c api.cpp

using.o: using.cpp
	g++ -c using.cpp

clean:
	rm -rf *.o test
