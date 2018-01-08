#include <iostream>
#include "taco_class.cpp"
using namespace std;


int main()
{
    int N = 3;
    short *board = new short[N * N];

    Tico myTicTacToe(N, 3);

    long c = 10000000L;

    while(c--){
        myTicTacToe.clearAllMatrix();

        for(int i =0, j =1; i<N*N; i++, j*=-1){
            int x = myTicTacToe.updateBoard(board, i, j);
            if(x == 1) break;
        }
    }

    return 0;
}
