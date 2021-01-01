#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves)
{
    // answer
    int answer = 0;

    // basket
    vector<int> basket;

    // get moves
    for (int i = 0; i < moves.size(); ++i)
    {
        int flag = moves[i];
        // get top stack
        for (int j = 0; j < board.size(); ++j)
        {
            // cout << board[j][flag - 1] << " ";
            if (board[j][flag - 1] != 0)
            {
                // move to basket
                basket.push_back(board[j][flag - 1]);
                board[j][flag - 1] = 0;

                // check basket has same item
                if (basket.size() > 1)
                {
                    if(basket[basket.size() - 1] == basket[basket.size() - 2]) {
                        // delete end and end - 1 items
                        // cout << "\nsame items !" << "\t[end] " << basket[basket.size() - 1] << "\t[end -1] " << basket[basket.size() - 2] << endl;
                        answer+=2;
                        basket.pop_back();
                        basket.pop_back();
                    }
                }
                break;
            }
        }
    }

    return answer;
}

int main()
{

    vector<vector<int> > board;
    vector<int> moves;

    int initBoard[5][5] = {{0, 0, 0, 0, 0},
                           {0, 0, 1, 0, 3},
                           {0, 2, 5, 0, 1},
                           {4, 2, 4, 4, 2},
                           {3, 5, 1, 3, 1}};
    int initMoves[8] = {1, 5, 3, 5, 1, 2, 1, 4};

    // init example input - board
    for (int i = 0; i < sizeof(initBoard[0]) / sizeof(int); ++i)
    {
        vector<int> initBoardRow;
        for (int j = 0; j < sizeof(initBoard) / sizeof(initBoard[0]); ++j)
        {
            initBoardRow.push_back(initBoard[i][j]);
        }
        board.push_back(initBoardRow);
    }
    // init example input - moves
    for (int i = 0; i < sizeof(initMoves) / sizeof(int); ++i)
    {
        moves.push_back(initMoves[i]);
    }

    solution(board, moves);

    return 0;
}