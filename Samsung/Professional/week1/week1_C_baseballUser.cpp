/*
소거법으로 풀어도 될듯
*/

typedef struct Data
{
    int strike;
    int ball;
} Data;

extern Data query(int supose[]);

int CNT = 0;
bool visit[10];
int store[4], TEMP[4];
bool num[10][10][10][10];
void dfs(int x, int store[], int suppose[], Data data)
{

    if (x == 4)
    {
        Data result;
        result.strike = 0;
        result.ball = 0;

        int check[10] = {
            0,
        };

        for (int idx = 0; idx < 4; ++idx)
            check[suppose[idx]]++;

        for (int idx = 0; idx < 4; ++idx)

            if (store[idx] == suppose[idx])

                result.strike++;

            else if (check[store[idx]] > 0)

                result.ball++;

        if (!num[store[0]][store[1]][store[2]][store[3]])
        {

            if (result.strike == data.strike && result.ball == data.ball)
            {

                TEMP[0] = store[0];
                TEMP[1] = store[1];
                TEMP[2] = store[2];
                TEMP[3] = store[3];
                CNT++;
            }
            else
            {
                num[store[0]][store[1]][store[2]][store[3]] = true;
            }
        }

        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        if (!visit[i])
        {
            store[x] = i;
            visit[i] = true;
            dfs(x + 1, store, suppose, data);
            visit[i] = false;
        }
    }
}

void tryBest(int suppose[])
{

    suppose[0] = 0;
    suppose[1] = 1;
    suppose[2] = 2;
    suppose[3] = 3;

    while (1)
    {
        Data first = query(suppose);

        dfs(0, store, suppose, first);

        if (CNT == 1)
        {
            suppose[0] = TEMP[0];
            suppose[1] = TEMP[1];
            suppose[2] = TEMP[2];
            suppose[3] = TEMP[3];

            query(suppose);

            break;
        }
        else
        {

            suppose[0] = TEMP[0];
            suppose[1] = TEMP[1];
            suppose[2] = TEMP[2];
            suppose[3] = TEMP[3];

            CNT = 0;
        }
    }

    for(int i = 0 ; i < 10 ; ++i) {
        visit[i] = false;
        for(int j = 0 ; j < 10 ; ++j)
            for(int k = 0 ; k < 10 ; ++k)
                for(int h = 0 ; h < 10 ; ++h)
                    num[i][j][k][h] = false;
    }
}