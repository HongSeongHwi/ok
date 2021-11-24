#ifndef _intro_h_
#define _intro_h_

#include "macros.h"

using namespace std;

class Intro
{
    public:
        Intro();
        ~Intro();
        virtual void Draw_Inoutro(int sel, int frame);
        int Select_Menu();
    private:
        string intro_map[INTRO_HEIGHT];
}

class Outro : public Intro
{
    public:
        Outro(int _score);
        void Draw_Inoutro(int sel, int frame);
    private:
        string outro_map[OUTRO_HEIGHT];
        int score;
}

string first_intro_map[INTRO_HEIGHT] = 
{
    "                                                                              ",
    "------------------------------------------------------------------------------",
    "-                                                                            -",
    "-               SSSSSSSSS                                                    -",
    "-             SSSSS(O)SSSS        NN     NN  AAAAAAAA  KK     KK  EEEEEEEE   -",
    "-             SSSSSSSSSSS---<     NNNN   NN  AA    AA  KK  KKK    EE         -",
    "-               SSSSSSSS          NN NN  NN  AA    AA  KKKK       EEEEEEEE   -",
    "-              SSSSSS             NN  NN NN  AAAAAAAA  KK  KKK    EE         -",
    "-            SSSSSS               NN   NNNN  AA    AA  KK    KK   EE         -",
    "-          SSSSSS                 NN     NN  AA    AA  KK     KK  EEEEEEEE   -",
    "-            SSSSSS                                                          -",
    "-   S          SSSSSS              GGGGGGG   AAAAAAAA  MM     MM  EEEEEEEE   -",
    "-   SS           SSSSSS           GG     GG  AA    AA  MMMM MMMM  EE         -",
    "-   SSS        SSSSSS            GG          AA    AA  MM MMM MM  EEEEEEEE   -",
    "-    SSS     SSSSSS              GG    GGGG  AAAAAAAA  MM  M  MM  EE         -",
    "-     SSSSSSSSSSS                 GG      G  AA    AA  MM     MM  EE         -",
    "-       SSSSSSS                    GGGGGGGG  AA    AA  MM     MM  EEEEEEEE   -",
    "-                                                                            -",
    "-                        ****************************                        -",
    "-                        *                          *                        -",
    "-                        *        GAME START        *                        -",
    "-                        *                          *                        -",
    "-                        *           RANK           *                        -",
    "-                        *                          *                        -",
    "-                        *           QUIT           *                        -",
    "-                        *                          *                        -",
    "-                        ****************************                        -",
    "-                                                                            -",
    "------------------------------------------------------------------------------" 
}
string second_intro_map[INTRO_HEIGHT] = 
{
    "                                                                              ",
    "------------------------------------------------------------------------------",
    "-                                                                            -",
    "-                 SSSSSSSSS                                                  -",
    "-                SSSSS(O)SSSS     NN     NN  AAAAAAAA  KK     KK  EEEEEEEE   -",
    "-                SSSSSSSSSSS---<  NNNN   NN  AA    AA  KK  KKK    EE         -",
    "-                 SSSSSSSSS       NN NN  NN  AA    AA  KKKK       EEEEEEEE   -",
    "-                 SSSSSS          NN  NN NN  AAAAAAAA  KK  KKK    EE         -",
    "-                 SSSSSS          NN   NNNN  AA    AA  KK    KK   EE         -",
    "-                SSSSSS           NN     NN  AA    AA  KK     KK  EEEEEEEE   -",
    "-               SSSSSS                                                       -",
    "-              SSSSSS              GGGGGGG   AAAAAAAA  MM     MM  EEEEEEEE   -",
    "-  S          SSSSSS              GG     GG  AA    AA  MMMM MMMM  EE         -",
    "-   SS       SSSSSS              GG          AA    AA  MM MMM MM  EEEEEEEE   -",
    "-    SS     SSSSSS               GG    GGGG  AAAAAAAA  MM  M  MM  EE         -",
    "-     SSSSSSSSSSS                 GG      G  AA    AA  MM     MM  EE         -",
    "-       SSSSSSS                    GGGGGGGG  AA    AA  MM     MM  EEEEEEEE   -",
    "-                                                                            -",
    "-                        ****************************                        -",
    "-                        *                          *                        -",
    "-                        *        GAME START        *                        -",
    "-                        *                          *                        -",
    "-                        *           RANK           *                        -",
    "-                        *                          *                        -",
    "-                        *           QUIT           *                        -",
    "-                        *                          *                        -",
    "-                        ****************************                        -",
    "-                                                                            -",
    "------------------------------------------------------------------------------" 
}

string first_outro_map[OUTRO_HEIGHT] = 
{
    "                                                                              ",
    "------------------------------------------------------------------------------",
    "-                -----                                                       -",
    "-              SSSSSSSSS                                                     -",
    "-            SSSSS(X)SSSS        GGGGGGG   AAAAAAAA  MM     MM  EEEEEEEE     -",
    "-            SSSSSSSSSSS        GG     GG  AA    AA  MMMM MMMM  EE           -",
    "-              SSSSSSSS        GG          AA    AA  MM MMM MM  EEEEEEEE     -",
    "-     --------SSSSSS           GG    GGGG  AAAAAAAA  MM  M  MM  EE           -",
    "-     |    -- SSSSSS            GG      G  AA    AA  MM     MM  EE           -",
    "-     |  -- SSSSSS               GGGGGGGG  AA    AA  MM     MM  EEEEEEEE     -",
    "-     |--    SSSSSS                                                          -",
    "-  S          SSSSSS              OOOOOO   VV    VV  EEEEEEEEE  RRRRRRR      -",
    "-  SS           SSSSSS           OO    OO  VV    VV  EE         RR    RR     -",
    "-  SSS        SSSSSS             OO    OO  VV    VV  EEEEEEEEE  RRRRRRR      -",
    "-   SSS     SSSSSS               OO    OO  VV    VV  EE         RR  RR       -",
    "-    SSSSSSSSSSS                 OO    OO   V    V   EE         RR   RR      -",
    "-      SSSSSSS                    OOOOOO     VVVV    EEEEEEEEE  RR    RR     -",
    "-                                                                            -",
    "-                        ****************************                        -",
    "-                        *                          *                        -",
    "-                        *          RETRY?          *                        -",
    "-                        *                          *                        -",
    "-                        *           RANK           *                        -",
    "-                        *                          *                        -",
    "-                        *           QUIT           *                        -",
    "-                        *                          *                        -",
    "-                        ****************************                        -",
    "-                                                                            -",
    "------------------------------------------------------------------------------"
}

#endif
