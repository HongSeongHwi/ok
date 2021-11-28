#include <iostream>
#include <vector>
#include <memory.h>
#include "snake.h"
#include "snake_map.h"
#include "macros.h"
#include "input.h"
#include "draw.h"

using namespace std;

int next_head_arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


Snake::Snake(){
    Initialize_Snake();
}

Snake::~Snake(){
}

void Snake::Initialize_Snake()
{
    direction = Right;
    food_flag = false;
    garbage_flag = false;
    is_dead = false;
    length = INITIAL_LENGTH;
    memset(snake_exist, 0, sizeof(snake_exist));
    snake_body.resize(0);
    for(int i = 0; i < INITIAL_LENGTH; i++)
    {
        pair<int, int> snake_ = make_pair(1, 1 + i);
        snake_body.push_back(snake_);
        snake_exist[snake_.first][snake_.second]++;
    }
    snake_head = snake_body[snake_body.size() - 1];
}

void Snake::Set_Direction(){
    int input = Else;
    bool input_flag = false;
    if(_kbhit())
        input = Get_Dir();

    if(input == Up || input == Down)
        if(direction != Up && direction != Down)    direction = input;
    if(input == Left || input == Right)
        if(direction != Left && direction != Right) direction = input;
}

bool Snake::Check_Dead()
{
    if(length == 0)                                                 return true;
    if(snake_head.first < 1 || snake_head.first > MAP_HEIGHT - 2)   return true;
    if(snake_head.second < 1 || snake_head.second > MAP_WIDTH - 2)  return true;
    for(size_t i = 0; i < snake_body.size() - 1; i++)
    {
        if(snake_body[i].first == snake_head.first && snake_body[i].second == snake_head.second)
        {
            return true;
        }
    }   
    return false;
}

void Snake::Update_Snake(){
    
    pair<int, int> next_head;
    Set_Direction();

    next_head = make_pair(snake_head.first + next_head_arr[direction][0], snake_head.second + next_head_arr[direction][1]);
    snake_head = next_head;
    snake_body.push_back(snake_head);
    if(snake_head.first == snake_food.first && snake_head.second == snake_food.second)
        food_flag = true;
    if(snake_head.first == snake_garbage.first && snake_head.second == snake_garbage.second)
        garbage_flag = true;
    if(food_flag)
    {
        length++;
    }
    else
    {
        pair<int, int> tail = snake_body[0];
        snake_exist[tail.first][tail.second]--;
        snake_body.erase(snake_body.begin());
    }
    if(garbage_flag)
    {
        length--;
        pair<int, int> tail = snake_body[0];
        snake_exist[tail.first][tail.second]--;
        snake_body.erase(snake_body.begin());
    }
    is_dead = Check_Dead();
}
