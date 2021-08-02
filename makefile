CC = gcc
CFLAGS = -Wall -O
LDFLAGS =

MODULES = .

EXEC = server.exe

SRC = $(foreach sdir, $(MODULES), $(wildcard $(sdir)/*.c))
OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

clean:
	rm -fr $(OBJ)
	rm -fr $(EXEC)
	rm -fr *.stackdump

run:
	make clean
	make all
	./$(EXEC)