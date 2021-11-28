#include <iostream>
#include <vector>
#include <memory.h>
#include "snake.h"
#include "snake_map.h"
#include "macros.h"
#include "input.h"

using namespace std;

Snake::Snake(){
    direction = Right;
    food_eaten = false;
    //garbage_eaten = false;
    is_dead = false;
    length = INITIAL_SNAKE_LENGTH;
    memset(snake_exist, 0, sizeof(snake_exist));
    Initialize_Snake();
}

Snake::~Snake(){
}

void Snake::Initialize_Snake(){
    for(int i=0; i<INITIAL_SNAKE_LENGTH; i++){
        pair<int ,int> snake_ = make_pair(1, MAP_WIDTH/2+i);
        snake_body.push_back(snake_);
        snake_exist[snake_.first][snake_.second] = 1; 
    }
    snake_head = snake_body[snake_body.size()-1];
}

void Snake::Set_Direction(){
    enum Direction input = Else;
    if(_kbhit())
        input = Get_Dir();
    //enum Direction input = Get_Dir();

    switch(input){
        case Up:
            if(direction != Down)
                direction = input;
            break;

         case Down:
            if(direction != Up)
                direction = input;
            break;

        case Left:
            if(direction != Right)
                direction = input;
            break;

        case Right:
            if(direction != Left)
                direction = input;
            break;
        default:
            break;
    }
}

void Snake::Update_Snake(){
    
    pair<int, int> next_head;
    Set_Direction();

    switch(direction){
        case Up:
            if(snake_head.first==1){
                is_dead = true;
            }
            next_head = make_pair(snake_head.first-1, snake_head.second);
            break;
        
        case Down:
            if(snake_head.first==MAP_HEIGHT-2){
                is_dead = true;
            }
            next_head = make_pair(snake_head.first+1, snake_head.second);
            break;
        
        case Left:
            if(snake_head.second==1){
                is_dead = true;
            }
            next_head = make_pair(snake_head.first, snake_head.second-1);
            break;
        
        case Right:
            if(snake_head.second == MAP_WIDTH-2){
                is_dead = true;
            }
            next_head = make_pair(snake_head.first, snake_head.second+1);
            break;
        default : 
            break;
    }

    if(is_dead == false){
        snake_head = next_head;
        snake_body.push_back(next_head);
        food_eaten = (snake_head.first == snake_food.first) && (snake_head.second == snake_food.second);
        if(food_eaten)
        {
            length++;
        }
        else
        {
            pair<int, int> tail = snake_body.front();
            snake_exist[tail.first][tail.second]--;
            snake_body.erase(snake_body.begin());
        }
        
        for(size_t i = 0; i < snake_body.size() - 1; i++)
        {
            if(snake_body[i].first == snake_head.first && snake_body[i].second == snake_head.second)
            {
                is_dead = true;
                break;
            }
        }
        
        
    }


}

void Snake::Set_Snake_Food(pair<int, int> _snake_food){
    snake_food = _snake_food;
}

/*void Snake::Set_Snake_Garbage(pair<int, int> _snake_garbage){
    snake_garbage = snake_garbage;
}*/
