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
         void Initialize_Snake();
         void Set_Direction();
         enum Direction Get_Direction() {return direction;}
         void Update_Snake();
         void Set_Snake_Food(pair<int, int> snake_food);
         bool Get_Food_Eaten() {return food_eaten;}
         void Set_Food_Eaten(bool _fe) {food_eaten = _fe;}
         bool Check_Dead() {return is_dead;}
         int  Get_Length() {return length;}
         pair<int, int> Get_Head() {return snake_head;}
         vector<pair<int, int>> Get_Body() {return snake_body;}
         pair<int, int> Get_Food() {return snake_food;}
    private:
         enum Direction direction;
         pair<int, int> snake_head;
         vector<pair<int, int>> snake_body;
         pair<int, int> snake_food;
         pair<int, int> snake_garbage;
         int snake_exist[MAP_HEIGHT][MAP_WIDTH];
         int length;
         bool is_dead;
         bool food_eaten;
};

#endif
