#include "snake_map.h"
#include "draw.h"
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

char HEAD_ch[4] = {'v', '^', '>', '<'};

SnakeMap::SnakeMap(Snake *_snake){
    snake = _snake;
    Clear_Map();
    Update_Snake_Food(0);
    Update_Snake_Garbage(0);
}

SnakeMap::~SnakeMap(){

}

void SnakeMap::Clear_Map(){
    for(int i=0;i<MAP_HEIGHT;i++){
        map_[i][0]=MAP_COL_WALL;
        map_[i][MAP_WIDTH-1]=MAP_COL_WALL;
    }
    for(int i=1;i<MAP_WIDTH-1;i++){
        map_[0][i]=MAP_ROW_WALL;
        map_[MAP_HEIGHT-1][i]=MAP_ROW_WALL;
    }
    for(int i=1 ; i<MAP_HEIGHT-1;i++){
        for(int j=1; j<MAP_WIDTH-1;j++){
            map_[i][j]=MAP_IN;
        }
    }
}

void SnakeMap::Update_Snake_Head(int frame){
    char snake_head_char;
    int direction = snake->Get_Direction();
    if(frame % 2 == 0){
        snake_head_char = HEAD_ch[direction];
    }
    else{
        if(direction == Down || direction == Up)    snake_head_char = SNAKE_HEAD_VER;
        else                                        snake_head_char = SNAKE_HEAD_HOR;
    }
    map_[snake->Get_Head().first][snake->Get_Head().second] = snake_head_char;
}

void SnakeMap::Update_Snake_Body()
{
    vector<pair<int, int>> body = snake->Get_Body();
    for(size_t i = 0; i < body.size(); i++)
    {
        map_[body[i].first][body[i].second] = SNAKE_BODY;
    }
}

void SnakeMap::Update_Map(int frame)
{
    Clear_Map();
    Update_Snake_Head(frame);
    Update_Snake_Body();
    Update_Snake_Food(frame);
    Update_Snake_Garbage(frame);
}

void SnakeMap::Render_Map(int frame)
{
    map_[snake_food.first][snake_food.second] = SNAKE_FOOD_CHAR;
    map_[snake_garbage.first][snake_garbage.second] = SNAKE_GARBAGE_CHAR;
    Update_Snake_Head(frame);
    printw("score: %d\n",snake->Get_Length());
    for(int i = 0; i < MAP_HEIGHT; i++)
    {
        for(int j = 0; j < MAP_WIDTH; j++)
            printw("%c ", map_[i][j]);
        printw("\n");
    }
}


void SnakeMap::Update_Snake_Food(int frame){
    srand(time(NULL));
    pair<int, int> food_coor;
    int i = rand() % MAP_HEIGHT, j = rand() % MAP_WIDTH;
    for(;;)
    {
        if(map_[i][j] == MAP_IN && i != snake_garbage.first && j != snake_garbage.second)
        {
            food_coor = make_pair(i, j);
            break;
        }
        i = rand() % MAP_HEIGHT;
        j = rand() % MAP_WIDTH;
    }
    if(snake->Get_Food_Flag() || frame == 0){
        snake_food = food_coor;
        snake->Set_Snake_Food(snake_food);
        snake->Set_Food_Flag(false);
        map_[i][j] = SNAKE_FOOD_CHAR;
    }
}

void SnakeMap::Update_Snake_Garbage(int frame){
    srand(time(NULL));
    pair<int, int> garbage_coor;
    int i = rand() % MAP_HEIGHT, j = rand() % MAP_WIDTH;
    for(;;)
    {
        if(map_[i][j] == MAP_IN && i != snake_food.first && j != snake_food.second)
        {
            garbage_coor = make_pair(i, j);
            break;
        }
        i = rand() % MAP_HEIGHT;
        j = rand() % MAP_WIDTH;
    }
    if(snake->Get_Garbage_Flag() || frame % 20 == 0){
        snake_garbage = garbage_coor;
        snake->Set_Snake_Garbage(snake_garbage);
        snake->Set_Garbage_Flag(false);
        map_[i][j] = SNAKE_GARBAGE_CHAR;
    }
}
