//#include <stdio.h>
#include <stdlib.h>
#include "draw.h"
#include "input.h"
#include "snake.h"
#include "snake_map.h"
#include "inoutro.h"
#include "macros.h"
#include "ranking.h"
#include <iostream>

void operator delete(void * p, std::size_t) // or delete(void *, std::size_t)
{
    std::free(p); 
}

// ==============================
// Game Metadata
class Game
{
    public:
        Game();
        int Get_Status()            {return status;}
        int Get_Level()             {return level;}
        void Set_Status(int data_)  {status = data_;}
        void Set_Level(int data_)   {level = data_;}
    private:
        int status;
        int level;
};

Game::Game()
{
    status = GAME_INTRO;
    level = GAME_EASY;
}

// ==============================
// global variables
bool        pause_flag = false;
bool        game_start_flag = true;
int         frame = 0;
int         intro_sel = MENU_START;
int         outro_sel = MENU_START;
Snake       snake;
SnakeMap    snake_map(&snake);
Intro       *intro;
Outro       *outro;
Ranking     ranking;
Game        game;

// ==============================


void Update()
{
    clear();
    switch(game.Get_Status())
    {
        case GAME_INTRO:
            intro_sel = intro->Select();
            if(intro_sel == MENU_EASY)
            {
                game.Set_Status(GAME_START);
                game.Set_Level(GAME_EASY);
            }
            else if(intro_sel == MENU_HARD)
            {
                game.Set_Status(GAME_START);
                game.Set_Level(GAME_HARD);
            }
            else if(intro_sel == MENU_RANK)  game.Set_Status(GAME_RANK_INTRO);
            else if(intro_sel == MENU_QUIT)  game.Set_Status(GAME_QUIT);

        case GAME_START:
            if(game_start_flag)
            {
                clear();
                game_start_flag = false;
            }
            if(snake.Get_Dead())
            {
                outro = new Outro(snake.Get_Length());
                game.Set_Status(GAME_OUTRO);
                ranking.Set_Score(snake.Get_Length());
                snake.Initialize_Snake();
                snake_map.Initialize_Map(&snake);
            }
            snake.Update_Snake();
            snake_map.Update_Map(frame);
            break;

        case GAME_OUTRO:
            outro_sel = outro->Select();
            if(outro_sel == MENU_START)
            {
                game.Set_Status(GAME_START);
                game_start_flag = true;
            }
            else if(outro_sel == MENU_RANK)  game.Set_Status(GAME_RANK_OUTRO);
            else if(outro_sel == MENU_QUIT)  game.Set_Status(GAME_QUIT);
            break;

        case GAME_RANK_INTRO:
            if(ranking.Quit())  game.Set_Status(GAME_INTRO);
            break;

        case GAME_RANK_OUTRO:
            if(ranking.Quit())  game.Set_Status(GAME_OUTRO);

        default:
            break;
    }
    refresh();
}

void Render()
{
    clear();
    switch(game.Get_Status())
    {
        case GAME_INTRO:
            intro->Render_Inoutro(frame);
            break;
        
        case GAME_START:
            snake_map.Render_Map(frame);
            if(game.Get_Level() == GAME_EASY)
                printw("GAME LEVEL = EASY\n");
            if(game.Get_Level() == GAME_HARD)
                printw("GAME LEVEL = HARD\n");
            printw("*: FOOD // @: GARBAGE\n");
            printw("MOVE WITH w, a, s, d\n");
            break;

        case GAME_OUTRO:
            outro->Render_Inoutro(frame);
            break;

        case GAME_RANK_INTRO:
            ranking.Render_Ranking();
            break;

        case GAME_RANK_OUTRO:
            ranking.Render_Ranking();
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
    for(frame = 0; game.Get_Status() != GAME_QUIT; frame++)
    {
        Update();
        Render();
        if(game.Get_Level() == GAME_EASY) usleep(FRAME_SPEED / 3);
        if(game.Get_Level() == GAME_HARD) usleep(FRAME_SPEED / (3 + snake.Get_Length() / 10));
    }
    printw("THANK YOU FOR PLAYING!!");
    refresh();
    sleep(1);
    endwin();
    return 0;
}
