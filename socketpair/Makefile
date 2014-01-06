GCC=gcc

SRC=$(wildcard *.cpp)
OBJS=$(addsuffix .o $(basename $(SRC)))
all:mycat openfile
	echo "$(addsuffix .o, $(basename $(SRC)))"
mycat:mycat.o myopen.o readfd.o
	g++ -o $@ $^
openfile: openfile.o write_fd.o
	g++ -o $@ $^
	
%.o:%.cpp
	$(GCC) -g -c -o $@ $^

