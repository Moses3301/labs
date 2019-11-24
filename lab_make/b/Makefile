# Makefile for lab03 assignment no. #2
OS := $(shell uname)

ifneq (,$(findstring CYGWIN_NT,$(OS)))
  EXT = .exe
else
  EXT =
endif

OUTPUT = myhello$(EXT)
INPUT = input.txt
CC = gcc
CFLAGS = -g -Wall
ECHO = @echo going to build $@
OBJFILES	= hello.o \
						first.o \
						last.o \
						color.o

all: $(OUTPUT)

%.o: %.c
		$(ECHO)
		$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT): $(OBJFILES)
	$(ECHO)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -vf *.o $(OUTPUT)

test:
	echo $(OUTPUT) < $(INPUT) 
