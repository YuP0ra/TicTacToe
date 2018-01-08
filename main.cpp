#include <algorithm>
#include <iostream>
#include "taco_class.cpp"
using namespace std;

int main()
{
    int N = 9;
    short *board = new short[N * N];

    Tico myTicTacToe(N, 5);

    long c = 1000000L;

    int *range = new int[N*N];
    for(int i =0; i<N*N; i++){
        range[i] = i;
    }

    while(c--){
        myTicTacToe.clearAllMatrix();
        random_shuffle(range, range + N*N);

        for(int i =0,j = 1; i<N*N; i++, j*=-1){
            int x = myTicTacToe.updateBoard(board, range[i], j);
            if(x == 1) break;
        }

    }

    return 0;
}
