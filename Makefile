C = g++
CFLAGS = -O2 -lncurses -ltinfo -lstdc++
TARGET = snake.out
OBJS = input.o inoutro.o main.o snake.o snake_map.o ranking.o

$(TARGET) : $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

%.o : %.cc
		$(CC) $(CFLAGS) -c $<

clean:
		rm -f *.o snake.out
