#include <algorithm>
#include <iostream>
#include <fstream>
#include "taco_class.cpp"
using namespace std;

int main()
{
    int N = 9, patchSize = 100000;
    short *board = new short[N * N];
    short *buffer = new short[N * N * patchSize];

    Tico myTicTacToe(N, 5);


    int *range = new int[N*N];
    for(int i =0; i<N*N; i++){
        range[i] = i;
    }

    long c = 100000000L;
    long index = 0;
    while(c--){
        myTicTacToe.clearAllMatrix();
        random_shuffle(range, range + N*N);

        for(int i =0,j = 1; i<N*N; i++, j*=-1){
            int x = myTicTacToe.updateBoard(board, range[i], j);
            if(x == 1) break;
        }

        short *temp = myTicTacToe.getWinSeq();
        for(int i =0; i < N * N; i++)
            buffer[index++] = temp[i];

        if(index >= patchSize){
            //********************
            index = 0;
            /// Write to a file.
            //********************
        }

    }

    return 0;
}
