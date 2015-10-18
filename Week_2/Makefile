

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c90 -Wfloat-equal
LIBS = -lm
SOURCE = roman.c
OUTFILE = roman
EXTENSION = .exe

build: $(SOURCE)
	$(CC) $(SOURCE) -o $(OUTFILE) $(CFLAGS) $(LIBS)

run: $(SOURCE)
	.\$(OUTFILE)

clean:
	del .\$(OUTFILE)$(EXTENSION)
