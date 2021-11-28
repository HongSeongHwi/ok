#include "snake_map.h"
#include "draw.h"
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

SnakeMap::SnakeMap(Snake *_snake){
    snake = _snake;
    Clear_Map();
    Update_Snake_Food(true);
    mouth_change = false;
}

SnakeMap::~SnakeMap(){
    //delete[] snake;
}

void SnakeMap::Clear_Map(){
    for(int i=0;i<MAP_HEIGHT;i++){
        map_array[i][0]=MAP_COL_WALL;
        map_array[i][MAP_WIDTH-1]=MAP_COL_WALL;
    }
    for(int i=1;i<MAP_WIDTH-1;i++){
        map_array[0][i]=MAP_ROW_WALL;
        map_array[MAP_HEIGHT-1][i]=MAP_ROW_WALL;
    }
    for(int i=1 ; i<MAP_HEIGHT-1;i++){
        for(int j=1; j<MAP_WIDTH-1;j++){
            map_array[i][j]=MAP_IN;
        }
    }
}

void SnakeMap::Update_Snake_Head(int frame){
    char snake_head_char;
    enum Direction direction = snake->Get_Direction();
    if(frame % 2 == 0){
        switch(direction){
            case Up:
                snake_head_char = SNAKE_HEAD_UP;
                break;
            case Down:
                snake_head_char = SNAKE_HEAD_DOWN;
                break;
            case Left:
                snake_head_char = SNAKE_HEAD_LEFT;
                break;
            case Right:
                snake_head_char = SNAKE_HEAD_RIGHT;
                break;
            default:
                break;
        }
    }
    else{
        switch(direction){
            case Up:
                snake_head_char = SNAKE_HEAD_CHANGE_VERTICAL;
                break;
            case Down:
                snake_head_char = SNAKE_HEAD_CHANGE_VERTICAL;
                break;
            case Left:
                snake_head_char = SNAKE_HEAD_CHANGE_HORIZANTAL;
                break;
            case Right:
                snake_head_char = SNAKE_HEAD_CHANGE_HORIZANTAL;
                break;
            default:
                break;
        }
    }
    pair<int,int> _head = snake->Get_Head();
    map_array[_head.first][_head.second] = snake_head_char;
}

void SnakeMap::Update_Snake_Body()
{
    vector<pair<int, int>> body = snake->Get_Body();
    for(size_t i = 0; i < body.size(); i++)
    {
        map_array[body[i].first][body[i].second] = SNAKE_BODY;
    }
}

void SnakeMap::Update_Map(int frame)
{
    Clear_Map();
    Update_Snake_Head(frame);
    Update_Snake_Body();
    Update_Snake_Food(false);
}

void SnakeMap::Render_Map(int frame)
{
    map_array[snake_food.first][snake_food.second] = SNAKE_FOOD_CHAR;
    Update_Snake_Head(frame);
    printw("score: %d\n",snake->Get_Length());
    for(int i = 0; i < MAP_HEIGHT; i++)
    {
        for(int j = 0; j < MAP_WIDTH; j++)
            printw("%c ", map_array[i][j]);
        printw("\n");
    }
}


void SnakeMap::Update_Snake_Food(bool initial_update){
    srand(time(NULL));
    if(snake->Get_Food_Eaten() || initial_update){
        //printw("FOOD UPDATE\n");
        while(true){
            int i = rand() % MAP_HEIGHT;
            int j = rand() % MAP_WIDTH;
            if(map_array[i][j] == MAP_IN){
                snake_food = make_pair(i, j);
                snake->Set_Snake_Food(snake_food);
                snake->Set_Food_Eaten(false);
                map_array[i][j] = SNAKE_FOOD_CHAR;
                break;
            }
        }
    }
}

/*void SnakeMap::Update_Snake_Garbage(bool initial_update){
    srand(time(NULL));
    if(snake->garbage_eaten || initial_update){
        while(true){
            int i = rand() % MAP_HEIGHT;
            int j = rand() % MAP_WIDTH;
            if(map_array[i][j] == MAP_IN){
                snake_garbage = make_pair(i, j);
                snake->Set_Snake_Garbage(snake_garbage);
                snake->garbage_eaten = false;
                break;
            }
        }
    }
}*/
