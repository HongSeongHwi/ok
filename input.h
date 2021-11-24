#ifndef _input_h_
#define _input_h_

#include <iostream>
//#include <ncurses.h>
#include <termio.h>

int _getch(void) 
{  
    int ch;

    struct termios old_;
    struct termios new_;
    
    tcgetattr(0, &old_);
    
    new_ = old_;
    new_.c_lflag &= ~(ICANON|ECHO);
    new_.c_cc[VMIN] = 1;
    new_.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &new_);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &old_);

    return ch;
}

enum Direction
{
    Up = 0,
    Left = 1,
    Down = 2,
    Right = 3,
    Space = 4,
    Else = -1
};

enum Direction Get_Dir(void);

#endif
