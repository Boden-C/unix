CC = g++
CFLAGS = -Wall -Wextra

all: myprog1 myprog2 myprog3 myshell

myprog1: myprog1.cpp
	$(CC) $(CFLAGS) -o $@ $^

myprog2: myprog2.cpp
	$(CC) $(CFLAGS) -o $@ $^

myprog3: myprog3.cpp
	$(CC) $(CFLAGS) -o $@ $^

myshell: myshell.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f myprog1 myprog2 myprog3 myshell
