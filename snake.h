#ifndef _snake_h_
#define _snake_h_

#include "input.h"
#include <vector>
#include <utility>
#include "macros.h"

using namespace std;

class Snake
{
    public:
         Snake();
         ~Snake();
         void Update_Direction();
         enum Direction Get_Direction();
         vector<pair<int, int>> snake_parts;
         pair<int, int> snake_head;
         void Snake_Movement();
         void Set_Snake_Food(pair<int, int> snake_food);
         bool food_eaten;
         bool garbage_eaten;
         bool is_dead;
         int length;
    private:
         enum Direction direction;
         enum Direction next_direction;
         pair<int, int> snake_food;
         pairt<int, int> snake_garbage;
         int snake_exist[MAP_HEIGHT][MAP_WIDTH];
         void Clear_Snake_World();
         void Initialize_Snake();
                                          
};

#endif
