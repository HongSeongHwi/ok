#ifndef _rank_h_
#define _rank_h_

#include <vector>

class Ranking
{
        public:
             Ranking();
             void Set_Score(int score) {scores.push_back(score);};
             int Quit();
             void Render_Ranking();
        
        private:
             std::vector<int> scores;
                                                    
};

#endif
