#pragma once

#include "Direction.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel {

    class Board {

        private:
        uint rows, cols;
        vector<vector<char>> board;
        void resizeBoard(uint row, uint col);

        public:
            Board(){
                board=vector<vector<char>>(5, vector<char>(5,'_'));
                rows=5;
                cols=5;
             };
            void post(uint row, uint col, Direction d, string message);
            string read(uint row, uint col,Direction d, uint num);
            void show();
    };
}
