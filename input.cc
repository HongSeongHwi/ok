#include "input.h"

#include <unistd.h>

using namespace std;

enum Direction Get_Dir()
{
    enum Direction dir = Right;
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

int main() {

}

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
            mvwprintw(game_win, 1, 2, "dir = Right");
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
