C = g++
CFLAGS = -O2 -lncurses -ltinfo -lstdc++
TARGET = test.out
OBJS = input.o

$(TARGET) : $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

%.o : %.cc
		$(CC) $(CFLAGS) -c $<

clean:
		rm -f *.o main.out
