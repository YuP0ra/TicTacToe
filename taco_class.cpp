class Tico
{   private:
        short *evMatrix, *evDiagns, *wnSeq;
        int I, N, W, evMatrix_size, evDiagns_size;

    public:
        Tico(int row_size, int win_size)
        {
            I = 0;
            N = row_size;
            W = win_size;
            evMatrix_size = 4 * N;
            evDiagns_size = 4 * (1 + 2 * (row_size - win_size));

            wnSeq = new short[N * N];
            evMatrix = new short[evMatrix_size];
            evDiagns = new short[evDiagns_size];
        }

        void clearAllMatrix()
        {
            I = 0;

            for(int i= 0; i< evMatrix_size; i++)
                evMatrix[i] = 0;

            for(int i= 0; i< evDiagns_size; i++)
                evDiagns[i] = 0;

            for(int i= 0; i< N * N; i++)
                wnSeq[i] = 0;
        }

        int updateBoard(short* board, int pos, int color)
        {
            wnSeq[I++] = pos;

            int x = pos % N;
            int y = pos / N;
            int t = color > 0 ? 0 : 1;

            int matrix_row_pos = ((0 + t) * N) + y;
            int matrix_col_pos = ((2 + t) * N) + x;

            board[pos] = color;

            evMatrix[matrix_row_pos]++;
            evMatrix[matrix_col_pos]++;

            if(evMatrix[matrix_row_pos] >=  W){
                evMatrix[matrix_row_pos]--;

                if (evRow(board, y))
                    return 1;
            }

            if(evMatrix[matrix_col_pos] >= W){
                evMatrix[matrix_col_pos]--;

                if (evCol(board, x))
                    return 1;
            }

            return 0;
        }

        short *getWinSeq(){
            return wnSeq;
        }


    private:
        bool evRow(short* board, int row)
        {
            int total_sum;
            for(int i=0; i < (N - W + 1); i++){
                total_sum = 0;

                for(int j=0; j < W; j++)
                    total_sum += board[N * row + i + j];

                if(total_sum == W || total_sum == -W)
                    return true;
            }
            return false;
        }

        bool evCol(short* board, int col)
        {
            int total_sum;
            for(int i=0; i < (N - W + 1); i++){
                total_sum = 0;

                for(int j=0; j < W; j++)
                    total_sum += board[N * (i + j) + col];

                if(total_sum == W || total_sum == -W)
                    return true;
            }
            return false;
        }
};
