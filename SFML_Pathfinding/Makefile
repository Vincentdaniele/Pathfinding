CFLAGS  = -g -I include -Wall -Wextra -pedantic 
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

PROJECT_NAME = souris

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))

all: $(PROJECT_NAME)

gdb:
	@gdb ./$(PROJECT_NAME) -ex run

$(PROJECT_NAME): $(OBJ)
	@g++ $(CFLAGS) -o $@ $^ $(LDFLAGS)

obj/%.o: src/%.cpp
	@mkdir -p obj
	@g++ $(CFLAGS) -c -o $@ $<

clean:
	rm -r obj/*.o
	rm $(PROJECT_NAME)
