#ifndef _snake_map_h_
#define _snake_map_h_

#include "snake.h"
#include "macros.h"


class SnakeMap
{
    public:
         SnakeMap(Snake *snake);
         ~SnakeMap();
         void Initialize_Map(Snake *snake);
         void Update_Snake_Food(int frame);
         void Update_Snake_Garbage(int frame);
         pair<int, int> Get_Food() {return snake_food;}
         void Update_Snake_Head(int frame);
         void Update_Snake_Body();
         void Update_Map(int frame);
         void Clear_Map();
         void Render_Map(int frame);

    private:
         char map_[MAP_HEIGHT][MAP_WIDTH];
         Snake *snake;
         pair<int, int> snake_food;
         pair<int, int> snake_garbage;
};


#endif

