CC = gcc -c
INCLUDE_DIRS=../pathfinderfilereader
CFLAGS = -I$(INCLUDE_DIRS)
SOURCES = $(wildcard *.c) $(wildcard $(INCLUDE_DIRS)/*.c)
INCLUDES = $(wildcard $(INCLUDE_DIRS)/*.h)
OBJECTS = $(notdir $(SOURCES:.c=.o))
LINKER = gcc -o
TARGET = astar.out

$(TARGET): obj
	@$(LINKER) $(TARGET) $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

obj: $(SOURCES) $(INCLUDES)
	$(CC) $(CFLAGS) $(SOURCES)
	@echo "Compiled."

clean:
	@rm -f $(TARGET) $(OBJECTS)
