#ifndef _intro_h_
#define _intro_h_

#include "macros.h"
#include <string>

using namespace std;

class Intro
{
    public:
        Intro();
        ~Intro();
        virtual void Render_Inoutro(int frame);
        virtual int Select();
    private:
        string intro_map[INOUTRO_HEIGHT];
        int intro_sel;
        int level_sel;
};

class Outro : public Intro
{
    public:
        Outro(int _score);
        void Render_Inoutro(int frame);
        int Select();
    private:
        string outro_map[INOUTRO_HEIGHT];
        int score;
        int outro_sel;
};


#endif
