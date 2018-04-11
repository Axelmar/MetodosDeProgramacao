IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =lib

LIBS=-lm

_DEPS = arvoreBinaria.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = testa_arvore.o arvoreBinaria.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(OBJ): $(ODIR)/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

arvoreBinaria: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS) -ftest-coverage -fprofile-arcs

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 


# CC=gcc
# CFLAGS=-I.

# arvoreBinaria: testa_arvore.o arvoreBinaria.o
# 	$(CC) -o arvoreBinaria testa_arvore.o arvoreBinaria.o -I.