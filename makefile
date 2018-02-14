# generic crap makefile for C++ trash projects

CC = g++
CFLAGS = -g -Wall -std=c++11 -I$(INCDIR) -L$(LIBDIR)
LIBS = 

SRCDIR = src/
INCDIR = include/
BINDIR = bin/
OBJDIR = obj/
LIBDIR = lib/

OUTFILE = $(BINDIR)main
OUTSRCFILE = $(SRCDIR)main.cpp

OBJFILES_NODIR =

OBJFILES = $(addprefix $(OBJDIR),$(OBJFILES_NODIR:=.o))

.PHONY: all clean init

all: $(OUTFILE)

$(OUTFILE): $(OUTSRCFILE) $(OBJFILES)
	$(CC) $(CFLAGS) $< $(OBJFILES) $(LIBS) -o $@

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm obj/* bin/*

init:
	mkdir src bin include lib obj
