IDIR=../include
CC=gcc
CXXFLAGS=-I$(IDIR) -std=gnu11 -O3 -Wall -Werror

ODIR=.
LDIR=../lib

LIBS=

_DEPS=
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=bloom.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: bloom clean

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

bloom: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) $(LIBS)

clean:
	rm -f $(ODIR)/*.o *~ core

