

#CC = gcc
#CFLAGS = -Wall -Wextra -pedantic -std=c90 -Wfloat-equal
CC = clang
CFLAGS = -Weverything -pedantic -std=c89
LIBS = -lm
SOURCE = roman.c
OUTFILE = roman.exe

build: $(SOURCE)
	$(CC) $(SOURCE) -o $(OUTFILE) $(CFLAGS) $(LIBS)

run: $(OUTFILE)
	.\$(OUTFILE)

clean:
	del .\$(OUTFILE)
