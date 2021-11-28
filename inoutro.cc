#include "inoutro.h"
#include "macros.h"
#include "draw.h"
#include "input.h"

string INTRO_MAP1[INOUTRO_HEIGHT] = 
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

string INTRO_MAP2[INOUTRO_HEIGHT] = 
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

string OUTRO_MAP[INOUTRO_HEIGHT] = 
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

Intro::Intro()
{
    intro_sel = 0;
}

Outro::Outro(int _score)
{
    outro_sel = 0;
    score = _score;
}

int Intro::Select()
{
    int frame = 0;
    while(1)
    {
        int input = Else;
        Render_Inoutro(frame);
        if(_kbhit())
            input = Get_Dir();
        switch(input)
        {
            case Up:
                intro_sel--;
                if(intro_sel < MENU_START)    intro_sel = MENU_QUIT;
                break;
            case Down:
                intro_sel++;
                if(intro_sel > MENU_QUIT)     intro_sel = MENU_START;
                break;
            case Space:
                return intro_sel;
                break;
            default:
                break;
        }
        usleep(FRAME_SPEED / 2);
        frame++;
    }
}

int Outro::Select()
{
    int frame = 0;
    while(1)
    {
        int input = Else;
        Render_Inoutro(frame);
        if(_kbhit())
            input = Get_Dir();
        switch(input)
        {
            case Up:
                outro_sel--;
                if(outro_sel < MENU_START)    outro_sel = MENU_QUIT;
                break;
            case Down:
                outro_sel++;
                if(outro_sel > MENU_QUIT)     outro_sel = MENU_START;
                break;
            case Space:
                return outro_sel;
                break;
            default:
                break;
        }
        usleep(FRAME_SPEED/10);
    }
}


void Intro::Render_Inoutro(int frame)
{
    clear();
    //printw("Render_INTRO\n");
    if(frame % 2 == 0)
    {
        for(int i = 0; i < INOUTRO_HEIGHT; i++)
        {
            intro_map[i] = INTRO_MAP1[i];
        }
    }
    else
    {
        for(int i = 0; i < INOUTRO_HEIGHT; i++)
        {
            intro_map[i] = INTRO_MAP2[i];
        }
    }

    switch (intro_sel)
    {
        case MENU_START:
            intro_map[20][32] = '-';
            intro_map[20][33] = '>';
            break;
        case MENU_RANK:
            intro_map[22][32] = '-';
            intro_map[22][33] = '>';
            break;
        case MENU_QUIT:
            intro_map[24][32] = '-';
            intro_map[24][33] = '>';
            break;
        default:
            break;
    }

    for(int i = 0; i < INOUTRO_HEIGHT; i++) {
        for(int j = 0; j < INOUTRO_WIDTH; j++)
        {
            printw("%c", intro_map[i][j]);
        }
        printw("\n");
    }
    printw("frame = %d\n",frame);
    refresh();
}

void Outro::Render_Inoutro(int frame)
{
    clear();
    for(int i = 0; i < INOUTRO_HEIGHT; i++)
        outro_map[i] = OUTRO_MAP[i];
    
    if(score < 10)
    {
        outro_map[19][42] = score + '0';
    }
    else
    {
        outro_map[19][42] = (score / 10) + '0';
        outro_map[19][43] = (score % 10) + '0';
    }

    switch (outro_sel)
    {
        case MENU_START:
            outro_map[21][32] = '-';
            outro_map[21][33] = '>';
            break;
        case MENU_RANK:
            outro_map[23][32] = '-';
            outro_map[23][33] = '>';
            break;
        case MENU_QUIT:
            outro_map[25][32] = '-';
            outro_map[25][33] = '>';
            break;
        defualt:
            break;
    }

    for(int i = 0; i < INOUTRO_HEIGHT; i++)
    {
        for(int j = 0; j < INOUTRO_WIDTH; j++)
        {
            printw("%c", outro_map[i][j]);
        }
        printw("\n");
    }
    refresh();
}

