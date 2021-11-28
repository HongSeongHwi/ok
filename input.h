#ifndef _input_h
#define _input_h

#include <iostream>
#include <termio.h>
#include <unistd.h>

enum Direction
{
    Up = 0,
    Left = 1,
    Down = 2,
    Right = 3,
    Space = 4,
    Else = -1
};

int _kbhit(void);
int _getch(void);
enum Direction Get_Dir(void);

#endif
