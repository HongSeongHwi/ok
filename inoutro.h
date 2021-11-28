#ifndef _intro_h_
#define _intro_h_

#include "macros.h"
#include <string>

using namespace std;

class Inoutro
{
    public:
        virtual void Render(int frame) = 0;
        virtual int Select() = 0;
    private:
};

class Intro : public Inoutro
{
    public:
        Intro();
        void Render(int frame);
        int Select();
    private:
        string intro_map[INOUTRO_HEIGHT];
        int intro_sel;
        int level_sel;

};

class Outro : public Inoutro
{
    public:
        Outro(int _score);
        void Render(int frame);
        int Select();
    private:
        string outro_map[INOUTRO_HEIGHT];
        int score;
        int outro_sel;
};


#endif
