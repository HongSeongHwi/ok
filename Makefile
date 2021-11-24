C = g++
CFLAGS = -O2 -lncurses
TARGET = main.out
OBJS = snake.o map.o 

$(TARGET) : $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

%.o : %.cc
		$(CC) $(CFLAGS) -c $<

clean:
		rm -f *.o main.out
