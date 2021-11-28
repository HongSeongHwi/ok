//#include <stdio.h>
#include <stdlib.h>
#include "draw.h"
#include "input.h"
#include "snake.h"
#include "snake_map.h"
#include "inoutro.h"
#include "macros.h"
#include <iostream>

void operator delete(void * p, std::size_t) // or delete(void *, std::size_t)
{
    std::free(p); 
}

// ==============================
// global variables
bool        pause_flag = false;
bool        game_start_flag = true;
int         frame = 0;
int         intro_sel = MENU_START;
int         outro_sel = MENU_START;
int         Game_Status = GAME_INTRO;
Snake       *snake;
SnakeMap    *snake_map;
Intro       *intro;
Outro       *outro;

// ==============================

void Update()
{
    clear();
    switch(Game_Status)
    {
        case GAME_INTRO:
            intro_sel = intro->Select();
            if(intro_sel == MENU_START)      Game_Status = GAME_START;
            else if(intro_sel == MENU_RANK)  Game_Status = GAME_RANK;
            else if(intro_sel == MENU_QUIT)  Game_Status = GAME_QUIT;
            else                             Game_Status = GAME_INTRO;

        case GAME_START:
            if(game_start_flag)
            {
                clear();
                snake = new Snake();
                snake_map = new SnakeMap(snake);
                game_start_flag = false;
            }
            if(snake->Check_Dead())
            {
                outro = new Outro(snake->Get_Length());
                Game_Status = GAME_OUTRO;
                snake_map->Clear_Map();
            }
            snake->Update_Snake();
            snake_map->Update_Map(frame);
            break;

        case GAME_OUTRO:
            outro_sel = outro->Select();
            if(outro_sel == MENU_START)
            {
                Game_Status = GAME_START;
                game_start_flag = true;
            }
            else if(outro_sel == MENU_RANK)  Game_Status = GAME_RANK;
            else if(outro_sel == MENU_QUIT)  Game_Status = GAME_QUIT;
            break;

        case GAME_RANK:
            break;

        default:
            break;
    }
    refresh();
}

void Render()
{
    clear();
    switch(Game_Status)
    {
        case GAME_INTRO:
            intro->Render_Inoutro(frame);
            break;
        
        case GAME_START:
            snake_map->Render_Map(frame);
            //printw("frame = %d\n",frame);
            break;

        case GAME_OUTRO:
            outro->Render_Inoutro(frame);
            break;

        case GAME_RANK:
            break;

        default:
            break;
    }
    refresh();
}

int main()
{
    initscr();
    noecho();
    intro = new Intro();
    for(frame = 0; Game_Status != GAME_QUIT; frame++)
    {
        Update();
        Render();
        usleep(FRAME_SPEED / 2);
    }
    printw("THANK YOU FOR PLAYING!!");
    refresh();
    sleep(1);
    endwin();
    return 0;
}
