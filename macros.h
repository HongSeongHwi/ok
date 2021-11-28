#ifndef _macros_h_
#define _macros_h_

// GAME STATUS MACROS
#define GAME_INTRO  0
#define GAME_START  1
#define GAME_OUTRO  2
#define GAME_RANK   3
#define GAME_QUIT   4

// GAME MENU SELECTION
#define MENU_START  0
#define MENU_RANK   1
#define MENU_QUIT   2

// DRAW SIZE
#define MAP_WIDTH       20
#define MAP_HEIGHT      20
#define INOUTRO_HEIGHT  29
#define INOUTRO_WIDTH   78
#define RANK_HEIGHT     30

// MAP DRAW CHAR
#define MAP_IN                          '.'
#define MAP_ROW_WALL                    '-'
#define MAP_COL_WALL                    '|'
#define SNAKE_BODY                      'O'
#define SNAKE_HEAD_LEFT                 '>'
#define SNAKE_HEAD_UP                   'v'
#define SNAKE_HEAD_RIGHT                '<'
#define SNAKE_HEAD_DOWN                 '^'
#define SNAKE_FOOD_CHAR                 '*'
#define SNAKE_GARBAGE_CHAR              '@'
#define SNAKE_HEAD_CHANGE_VERTICAL      '_'
#define SNAKE_HEAD_CHANGE_HORIZANTAL    '|'

// SANKE FIRST LENGTH
#define INITIAL_SNAKE_LENGTH 3

// SLEEP & USLEEP VAL
#define PAUSE_LENGTH    1
#define FRAME_SPEED     500000  // 0.5 sec

#endif
