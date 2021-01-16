CC = gcc 
FLAGS = -Wall -g

all: frequency

# Make trie
frequency: frequency.o trie.o
	$(CC) $(FLAGS) -o frequency frequency.o trie.o
	
frequency.o: frequency.c trie.h
	$(CC) $(FLAGS) -c frequency.c

trie.o: trie.c trie.h
	$(CC) $(FLAGS) -c trie.c
	

.PHONY: clean all

clean:
	rm -f *.o frequency