#include "snake.h"
#include <iostream>
#include <vector>
#include <utility>
#include "snake_map.h"
#include "macros.h"
#include "intro.h"

using namespace std;

Snake::Snake(){
    direction = Right;
    next_direction = direction;
    food_eaten = false;
    garbage_eaten = false;
    is_dead = false;
    length = INITIAL_SNAKE_LENGTH;
    Clear_Snake_World();
    Initialize_Snake();
}

Snake::~Snake(){
    delete[] Snake;
}

void Snake::Clear_Snake_World(){
    for(int i=0; i<MAP_HEIGHT; i++){
        for(int j=0; j<MAP_WIDTH; j++){
            snake_world_array[i][j] = 0;
        }
    }
}

void Snake::Initialize_Snake(){
    for(int i=0; i<INITIAL_SNAKE_LENGTH; i++){
        pair<int ,int> snake_part = make_pair(MAP_HEIGHT/2, MAP_WIDTH/2+i);
        snake_parts.push_back(snake_part);
        snake_exist[snake_part.first][snake_part.second] = 1;
        
    }
    snake_head = snake_parts[snake_parts.size()-1];
}

void Snake::Snake_Direction(){
    enum Direction input = Error;

    switch(input){
        case Up:
            if(this->direction != Down)
                this->direction = input;
            break;

         case Down:
            if(this->direction != Up)
                this->direction = input;
            break;

        case Left:
            if(this->direction != Right)
                this->direction = input;
            break;

        case Right:
            if(this->direction != Left)
                this->direction = input;
            break;
        default:
            break;
    }
}

enum Direction Snake::Get_Direction(){
    return this->direction;
}

void Snake::Snake_Movement(){
    
    pair<int, int> movement;
    enum Direction direction = Get_Direction();
    switch(direction){
        case Up:
            movement = make_pair(snake_head.first-1, snake_head.second);
            if(snake_head.first==1){
                is_dead = true;
            }
            break;
        
        case Down:
            movement = make_pair(snake_head.first+1, snake_head.second);
            if(snake_head.first==MAP_HEIGHT-2){
                is_dead = true;
            }
            break;
        
        case Left:
            movement = make_pair(snake_head.first, snake_head.second-1);
            if(snake_head.second==1){
                is_dead = true;
            }
            break;
        
        case Right:
            movement = make_pair(snake_head.first, snake_head.second+1);
            if(snake_head.second == MAP_WIDTH-2){
                is_dead = true;
            }
            break;
        default : 
            break;
    }
    if(is_dead == false){
        snake_head = movement;
        snake_parts.push_back(movement);
        food_eaten = (snake_head.first == snake_food.first) && (snake_head.second == snake_food.second);
        garbage_eaten = (snake_head.first == snake_garbage.first) && (snake_head.second == snake_garbage.second);
        if(food_eaten)
            length++;
        if(garbage_eaten){
            pair<int, int> tail = snake_parts.front();
            snake_exist_array[tail.first][tail.second]--;
            snake_parts.erase(snake_parts.begin());
            length--;
        }

        int head_value = snake_exist_array[snake_head.first][snake_head.second]+1;
        if(head_value > 1)
            is_dead = true;

    }


}

void Snake::Set_Snake_Food(pair<int, int> snake_food){
    this -> snake_food = snake_food;
}

void Snake::Set_Snake_Garbage(pair<int, int> snake_garbage){
    this -> snake_garbage = snake_garbage;
}

