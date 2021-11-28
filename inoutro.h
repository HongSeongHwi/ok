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

/*string INTRO_MAP1[INTRO_HEIGHT] = 
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
};

string INTRO_MAP2[INTRO_HEIGHT] = 
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
};

string OUTRO_MAP[OUTRO_HEIGHT] = 
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
    "-  S          SSSSSS            OOOOOOOO   VV    VV  EEEEEEEEE  RRRRRRR      -",
    "-  SS           SSSSSS         OO      OO  VV    VV  EE         RR    RR     -",
    "-  SSS        SSSSSS           OO      OO  VV    VV  EEEEEEEEE  RRRRRRR      -",
    "-   SSS     SSSSSS             OO      OO  VV    VV  EE         RR  RR       -",
    "-    SSSSSSSSSSS               OO      OO   V    V   EE         RR   RR      -",
    "-      SSSSSSS                  OOOOOOOO     VVVV    EEEEEEEEE  RR    RR     -",
    "-                                                                            -",
    "-                        ****************************                        -",
    "-                        *        SCROE:            *                        -",
    "-                        *                          *                        -",
    "-                        *          RETRY?          *                        -",
    "-                        *                          *                        -",
    "-                        *           RANK           *                        -",
    "-                        *                          *                        -",
    "-                        *           QUIT           *                        -",
    "-                        ****************************                        -",
    "-                                                                            -",
    "------------------------------------------------------------------------------"
};
*/
#endif
