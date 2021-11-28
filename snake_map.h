#ifndef _snake_map_h_
#define _snake_map_h_

#include "snake.h"
#include "macros.h"


class SnakeMap
{
    public:
         SnakeMap(Snake *snake);
         ~SnakeMap();
         void Update_Snake_Food(bool initial_update);
         pair<int, int> Get_Food() {return snake_food;}
         void Update_Snake_Head(int frame);
         void Update_Snake_Body();
         void Update_Map(int frame);
         void Clear_Map();
         void Render_Map(int frame);

    private:
         char map_array[MAP_HEIGHT][MAP_WIDTH];
         Snake *snake;
         bool mouth_change;
         pair<int, int> snake_food;
};


#endif

