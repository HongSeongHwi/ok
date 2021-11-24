C = g++
CFLAGS = -O2
TARGET = main.out
OBJS = 

$(TARGET) : $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

%.o : %.cc
		$(CC) $(CFLAGS) -c $<

clean:
		rm -f *.o main.out
