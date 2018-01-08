class Tico
{   private:
        char *evMatrix, *evDiagns, *wnSeq;
        int I, N, W, evMatrix_size, evDiagns_size, seq_size;

    public:
        Tico(int row_size, int win_size)
        {
            N = row_size;
            W = win_size;
            evMatrix_size = 4 * N;
            seq_size = 1 + ((N * N) / 2);
            evDiagns_size = 1 + 2 * (row_size - win_size);

            wnSeq = new char[seq_size];
            evMatrix = new char[evMatrix_size];
            evDiagns = new char[evDiagns_size];
        }

        void clearAllMatrix()
        {
            I = 0;

            for(int i= 0; i< evMatrix_size; i++)
                evMatrix[i] = 0;

            for(int i= 0; i< evDiagns_size; i++)
                evDiagns[i] = 0;

            for(int i= 0; i< seq_size; i++)
                wnSeq[i] = 0;
        }

        int updateBoard(char* board, int pos, int color)
        {
            wnSeq[I++] = char(pos);

            int x = pos % N;
            int y = pos / N;
            int t = color > 0 ? 1 : 2;

            int x_m_p = t * x;
            int y_m_p = (2 * N) + (t * y);

            evMatrix[x_m_p]++;
            evMatrix[y_m_p]++;

            if(evMatrix[x_m_p] >= N){
                evMatrix[x_m_p]--;

                if (evRow(board, x) != 0)
                    return 1;
            }

            if(evMatrix[y_m_p] >= N){
                evMatrix[y_m_p]--;

                if (evCol(board, y) != 0)
                    return 1;
            }

            return 0;
        }

        char *getWinSeq(){
            return wnSeq;
        }


    private:
        int evRow(char* board, int row)
        {
            int total_sum;

            for(int i=0; i < (N - W + 1); i++){
                total_sum = 0;

                for(int j=i; i < W; j++)
                    total_sum += board[N * row + j];

                if(total_sum == W || total_sum == -W)
                    return 1;

            }

            return 0;
        }

        int evCol(char* board, int col)
        {
            int total_sum;

            for(int i=0; i < (N - W + 1); i++){
                total_sum = 0;

                for(int j=i; i < W; j++)
                    total_sum += board[N * j + col];

                if(total_sum == W || total_sum == -W)
                    return 1;

            }

            return 0;
        }
};
