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
         int Get_Direction() {return direction;}
         void Update_Snake();
         void Set_Snake_Food(pair<int, int> data_) {snake_food = data_;}
         void Set_Snake_Garbage(pair<int, int> data_) {snake_garbage = data_;}
         bool Get_Food_Flag() {return food_flag;}
         void Set_Food_Flag(bool data_) {food_flag = data_;}
         bool Get_Garbage_Flag() {return garbage_flag;}
         void Set_Garbage_Flag(bool data_) {garbage_flag = data_;}
         bool Get_Dead() {return is_dead;}
         void Set_Length(int data_) {length = data_;}
         int  Get_Length() {return length;}
         bool Check_Dead();
         pair<int, int> Get_Head() {return snake_head;}
         vector<pair<int, int>> Get_Body() {return snake_body;}
         pair<int, int> Get_Food() {return snake_food;}

         int Get_Size() {return snake_body.size();}
         //vector<pair<int, int>> Get_Body() {return snake_body;}
    private:
         int direction;
         pair<int, int> snake_head;
         vector<pair<int, int>> snake_body;
         pair<int, int> snake_food;
         pair<int, int> snake_garbage;
         int snake_exist[MAP_HEIGHT][MAP_WIDTH];
         int length;
         bool is_dead;
         bool food_flag;
         bool garbage_flag;
};

#endif
