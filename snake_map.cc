#include "snake_map.h"
#include <iostream>
#include <vector>
#include <utility>
#include <time.h>
#include "macros.h"

using namespace std;

SnakeMap::SnakeMap(Snake *snake){
    this->snake = snake;
    Clear_Map(this->map_array);
    Update_Snake_Food(true);
    Update_Snake_Garbage(true);
    this->mouth_change = false;
}

SnakeMap::~SnakeMap(){
    delete[] snake;
}

void Clear_Map(char map_array[MAP_HEIGHT][MAP_WIDTH]){
    for(int i=0;i<MAP_HEIGHT;i++){
        map_array[i][0]=MAP_COL_WALL;
        map_array[i][MAP_WIDTH-1]=MAP_COL_WALL_CHAR;
    }
    for(int i=1;i<MAP_WIDTH-1;i++){
        map_array[0][i]=MAP_ROW_WALL;
        map_array[MAP_HEIGHT-1][i]=MAP_ROW_WALL_CHAR;
    }
    for(int i=1 ; i<MAP_HEIGHT-1;i++){
        for(int j=1; j<MAP_WIDTH-1;j++){
            map_array[i][j]=MAP_IN_CHAR;
        }
    }
}

void SnakeMap::drawing(){
   Clear_Map(this->map_array);
   vector<pair<int,int>> snake_parts = snake->snake_parts;
   for(int i=0; i<snake_parts.size(); i++){
       pair<int, int> tmp = snake_parts[i];
       map_array[tmp.first][tmp.second] = SNAKE_CHAR;
   }
   Update_Snake_Head(map_array, snake);
   Update_Snake_Food(false);
   Update_Snake_Garbage(false);
   map_array[snake_food.first][snake_food.second] = SNAKE_FOOD_CHAR;
   map_array[snake_garbage.first][snake_garbage.second] = SNAKE_GARBAGE_CHAR;
   for(int i=0; i<MAP_HEIGHT; i++){
       for(int j=0; j<MAP_WIDTH; j++){
           cout << map_array[i][j] << " ";
       }
       cout << endl;
   }

}

void SnakeMap::Update_Snake_Head(char map_array[MAP_HEIGHT][MAP_WIDTH], Snake *snake){
    char snake_head_char;
    enum Direction direction = snake->Get_Direction();
    if(this->cnt==0){
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
        this->mouth_change = 1;
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
        this->mouth_change = 0;
    }
    pair<int,int> snake_head = snake->snake_head;
    map_array[snake_head.first][snake_head.second] = snake_head_char;
}


void SnakeMap::Update_Snake_Food(char map_array[MAP_HEIGHT][MAP_WIDTH], bool force_update){
    if(snake->food_eaten || force_update){
        while(true){
            int i = rand() % MAP_HEIGHT;
            int j = rand() % MAP_WIDTH;
            if(map_array[i][j] == MAP_IN_CHAR){
                snake_food = make_pair(i, j);
                snake->Set_Snake_Food(snake_food);
                snake->food_eaten = false;
                break;
            }
        }
    }
}

void SnakeMap::Update_Snake_Garbage(bool force_update2){
    
    if(snake->garbage_eaten || force_update2){
        while(true){
            int i = rand() % MAP_HEIGHT;
            int j = rand() % MAP_WIDTH;
            if(map_array[i][j] == MAP_IN_CHAR){
                snake_garbage = make_pair(i, j);
                snake->Set_Snake_Garbage(snake_garbage);
                snake->garbage_eaten = false;
                break;
            }
        }
    }
}
