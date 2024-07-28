# Makefile

# Variables
CC = gcc        
CFLAGS = -Wall -Wextra -std=c11
TARGET = tri
OBJECTS = listechainee.o statistiques.o main.o

.PHONY: all clean html test

all: $(TARGET)

# Build
# -----
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

listechainee.o: listechainee.c listechainee.h
	$(CC) $(CFLAGS) -c $< -o $@

statistiques.o: statistiques.c statistiques.h
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

# Test
# ----
test: $(TARGET)
	# TODO

# Clean
# -----
clean:
	rm -f $(OBJECTS) $(TARGET) README.html

# Documentation
# -------------
README.html: README.md
	pandoc -s README.md -o README.html --metadata title="README"
html: README.html

