#ifndef _macros_h_
#define _macros_h_

// DIRECTION
#define Up      0
#define Down    1
#define Left    2
#define Right   3
#define Space   10
#define Else    -1

// GAME STATUS MACROS
#define GAME_INTRO      0
#define GAME_START      1
#define GAME_OUTRO      2
#define GAME_RANK_INTRO 3
#define GAME_RANK_OUTRO 4
#define GAME_QUIT       5

// GAME LEVEL
#define GAME_EASY   0
#define GAME_HARD   1

// GAME MENU SELECTION
#define MENU_START  0
#define MENU_RANK   1
#define MENU_QUIT   2
#define MENU_LEVEL  5
#define MENU_EASY   6
#define MENU_HARD   7

// DRAW SIZE
#define MAP_WIDTH       20
#define MAP_HEIGHT      20
#define INOUTRO_HEIGHT  28
#define INOUTRO_WIDTH   78
#define RANK_HEIGHT     29
#define RANK_WIDTH      78

// MAP DRAW CHAR
#define MAP_IN                          '.'
#define MAP_ROW_WALL                    '-'
#define MAP_COL_WALL                    '|'
#define SNAKE_BODY                      'O'
#define SNAKE_FOOD_CHAR                 '*'
#define SNAKE_GARBAGE_CHAR              '@'
#define SNAKE_HEAD_VER                  '_'
#define SNAKE_HEAD_HOR                  '|'

// SANKE FIRST LENGTH
#define INITIAL_LENGTH 5

// SLEEP & USLEEP VAL
#define FRAME_SPEED     500000  // 0.5 sec

#endif
