TARGET = mrsa
CC = gcc
CLFAGS = -I$(IDIR)

SRCDIR = ./src
IDIR = ./include
SOURCES = $(SRCDIR)/*.c

FEN=?

all: make

make:
	@$(CC) $(SOURCES) $(CLFAGS) -o $(TARGET)

deploy:
	@sudo cp $(TARGET) /usr/local/bin/$(TARGET)

run:
	@./$(TARGET) $(FEN)

clean:
	@rm $(TARGET)