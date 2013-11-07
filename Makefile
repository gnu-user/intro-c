# MAKEFILE TEMPLATE
SOURCE_FILES := example.c useful.c other_stuff.c
HEADER_FILES := useful.h other_stuff.h
OBJECT_FILES := main.o useful.o other_stuff.o
FLAGS := -Wall -O0 -g3 -std=c99
EXEC_NAME := example
INSTALL_DIR := /usr/bin/
RM := rm -rf

default: example
debug: example-debug
all: example

example: $(SOURCE_FILES) $(HEADER_FILES)
    @echo 'Building target: $@'
    gcc $(FLAGS) $(SOURCE_FILES) -o $(EXEC_NAME)
    @echo 'Finished building target: $@'

example-debug: $(SOURCE_FILES) $(HEADER_FILES)
    @echo 'Building target: $@'
    gcc $(FLAGS) -DDEBUG $(SOURCE_FILES) -o $(EXEC_NAME)
    @echo 'Finished building target: $@'

install:
    @cp $(EXEC_NAME) $(INSTALL_DIR)

clean:
    @$(RM) $(OBJECT_FILES) $(EXEC_NAME)

