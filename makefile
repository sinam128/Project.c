TARGET = main.exe

SRC = main.c

INCLUDE = -IC:/raylib/include
LIBPATH = -LC:/raylib/lib

LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

all: $(TARGET)
	@echo Building and running $(TARGET)
	./$(TARGET)

$(TARGET): $(SRC)
	gcc $(SRC) $(INCLUDE) $(LIBPATH) $(LIBS) -o $(TARGET)

clean:
	del $(TARGET)
