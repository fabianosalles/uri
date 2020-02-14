CC=gcc
PDIR=./problems
ODIR=./bin

all: clear 1022 1024 1039

clear: 
	rm -rfd $(ODIR)/*

1022: $(PDIR)/1022/1022.c
	$(CC) $(PDIR)/1022/1022.c -o $(ODIR)/1022

1024: $(PDIR)/1024/1024.c
	$(CC) $(PDIR)/1024/1024.c -o $(ODIR)/1024

1039: $(PDIR)/1039/1039.c
	$(CC) $(PDIR)/1039/1039.c -o $(ODIR)/1039 -lm
