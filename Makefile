# Makefile

# Variables
CC = gcc        
CFLAGS = -Wall -Wextra -std=c11 -fprofile-arcs -ftest-coverage
LDFLAGS = -lcunit
TARGET = tri
OBJECTS = listechainee.o statistiques.o main.o helper.o
TEST_OBJECTS = listechainee.o statistiques.o helper.o test.o

.PHONY: all clean html test coverage

all: $(TARGET)

# Build
# -----
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

listechainee.o: listechainee.c listechainee.h
	$(CC) $(CFLAGS) -c $< -o $@

statistiques.o: statistiques.c statistiques.h
	$(CC) $(CFLAGS) -c $< -o $@

helper.o: helper.c helper.h
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.c main.h
	$(CC) $(CFLAGS) -c $< -o $@

test.o: test.c
	$(CC) $(CFLAGS) -c $< -o $@

# Test
# ----
test: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o test $(TEST_OBJECTS) $(LDFLAGS)

# Clean
# -----
clean:
	rm -f $(OBJECTS) test.o $(TARGET) *.gcda *.gcno *.gcov test README.html

# Coverage
# --------
coverage: test
	./test
	gcov listechainee.c statistiques.c helper.c

# Documentation
# -------------
README.html: README.md
	pandoc -s README.md -o README.html --metadata title="README"
html: README.html

