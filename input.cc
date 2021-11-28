#include "macros.h"
#include "input.h"
#include "draw.h"
#include <fcntl.h>

using namespace std;

int _kbhit(void)
{
    struct termios old_, new_;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &old_);
    new_ = old_;
    new_.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &old_);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int _getch(void) 
{  
    int ch;

    struct termios old_, new_;
    
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

int Get_Dir()
{
    int dir = Right;
    char _input = _getch();

    switch(_input)
    {
        case 'w' :
            dir = Up;
            break;
        case 'a' :
            dir = Left;
            break;
        case 's' :
            dir = Down;
            break;
        case 'd' : 
            dir = Right;
            break;
        case ' ' :
            dir = Space;
            break;
        default :
            dir = Else;
            break;
    }
    return dir;
}

/*
// for input test && print test
int main() {
    WINDOW *game_win;
    initscr();
    noecho();

    game_win = newwin(20, 20, 1, 0);
    //wborder(game_win, '*','*','*','*','*','*','*','*');
    //wrefresh(game_win);

    for(int i = 0; i < 10; i++) {
        //wclear(game_win);
        box(game_win, 0, 0);
        wrefresh(game_win);
        enum Direction dir = Get_Dir();
        wclear(game_win);
        
        if(dir == Right)
        {
            //wprintw(game_win, "dir = Right");
            mvwprintw(game_win, 3, 5, "dir = Right");
        }
        else if(dir == Left)
        {
            //wprintw(game_win, "dir = Left");
            mvwprintw(game_win, 1, 2, "dir = Left");
        }
        else if(dir == Up)
        {
            //wprintw(game_win, "dir = Up");
            mvwprintw(game_win, 1, 2, "dir = Up");
        }
        else if(dir == Down)
        {
            //wprintw(game_win, "dir = Down");
            mvwprintw(game_win, 1, 2, "dir = Down");
        }
        else if(dir == Space)
        {
            //wprintw(game_win, "dir = SPace");
            mvwprintw(game_win, 1, 2,  "dir = Space");
        }
        else
        {
            //wprintw(game_win, "dir = Else");
            mvwprintw(game_win, 1, 2,  "dir = Else");
        }
        wrefresh(game_win);
        //sleep(1);
        //wclear(game_win);
    }
    //sleep(2);
    delwin(game_win);
    sleep(1);
    endwin();

    return 0;
}
*/
