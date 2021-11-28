#include "ranking.h"
#include "macros.h"
#include "draw.h"
#include "input.h"
#include <string>
#include <queue>

using namespace std;

string BOARD[RANK_HEIGHT] = 
{
    "------------------------------------------------------------------------------",
    "-                                                                            -",
    "-                                                                            -",
    "-                         === R A N K  B O A R D ===                         -",
    "-                                                                            -",
    "-                                                                            -",
    "-                                                                            -",
    "-                    =GOLD=                                                  -",
    "-                                                                            -",
    "-                                                                            -",
    "-                                                                            -",
    "-                                                                            -",
    "-                                                                            -",
    "-                   =SILVER=                                                 -",
    "-                                                                            -",
    "-                                                                            -",
    "-                                                                            -",
    "-                                                                            -",
    "-                                                                            -",
    "-                   =BRONZE=                                                 -",
    "-                                                                            -",
    "-                                                                            -",
    "-               P R E S S  'Q'  F O R  G O  B A C K  T O  M E N U            -",
    "-                                                                            -",
    "-                                                                            -",
    "-                  T H A N K  Y O U  F O R  P L A Y I N G ! ! !              -",
    "-                                                                            -",
    "-                                                                            -",
    "------------------------------------------------------------------------------"
};

Ranking::Ranking()
{
    for(int i = 0 ; i < 3; i++)
        scores.push_back(0);
}

int Ranking::Quit()
{
    char input;
    if(_kbhit())
    {
        input = _getch();
        if(input == 'q')    return 1;
    }
    return 0;
}

void Ranking::Render_Ranking()
{
    clear();
    string ranking_board[RANK_HEIGHT];
    priority_queue<int> PQ;

    for(size_t i = 0; i < scores.size(); i++)
    {
        PQ.push(scores[i]);
    }
   
    for(int i = 0; i < RANK_HEIGHT; i++)
    {
        ranking_board[i] = BOARD[i];
    }

    for(int i = 0; i < 3; i++)
    {
        int score_ = PQ.top();
        PQ.pop();

        if(score_ > 10)
        {
            ranking_board[7 + i * 6][45] = score_ / 10 + '0';
            ranking_board[7 + i * 6][47] = score_ % 10 + '0';
        }
        else
        {
            ranking_board[7 + i * 6][46] = score_ % 10 + '0';
        }
    }

    for(int i = 0; i < RANK_HEIGHT; i++)
    {
        for(int j = 0; j < RANK_WIDTH; j++)
        {
            printw("%c",ranking_board[i][j]);
        }
        printw("\n");
    }
}
