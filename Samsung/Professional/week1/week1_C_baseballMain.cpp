
#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define MAX 4

#define MAX_COUNT 2520

#define _CRT_SECURE_NO_WARNINGS

static int baseballNumbers[MAX];

static int numbersCheck[10];

static int T;

extern void tryBest(int suppose[]); ////************

static int queryCallCount;

static const int queryLimit = 110;

static int scoreTable[MAX_COUNT + 5];

typedef struct Data
{

    int strike;

    int ball;

} Data;

static bool isAble(int suppose[])
{

    int supposeCheck[10];

    for (int count = 0; count < 10; ++count)
        supposeCheck[count] = 0;

    for (int idx = 0; idx < MAX; ++idx)
    {

        if (suppose[idx] < 0 || suppose[idx] >= 10 || supposeCheck[suppose[idx]] > 0)
            return false;

        supposeCheck[suppose[idx]]++;
    }

    return true;
}

Data query(int suppose[])
{

    Data result;

    if (queryCallCount > MAX_COUNT)
    {

        result.strike = -1;

        result.ball = -1;

        return result;
    }

    queryCallCount++;

    if (!isAble(suppose))
    {

        result.strike = -1;

        result.ball = -1;

        return result;
    }

    result.strike = 0;

    result.ball = 0;

    for (int idx = 0; idx < MAX; ++idx)

        if (suppose[idx] == baseballNumbers[idx])

            result.strike++;

        else if (numbersCheck[suppose[idx]] > 0)

            result.ball++;

    return result;
}

static void initialize()
{

    for (int count = 0; count < 10; ++count)
        numbersCheck[count] = 0;

    for (int idx = 0; idx < MAX;)
    {

        int c = rand() % 10;

        if (numbersCheck[c] == 0)

        {

            baseballNumbers[idx] = c;

            numbersCheck[c]++;

            idx++;
        }
    }

    queryCallCount = 0;
}

static bool check(int suppose[])
{

    for (int idx = 0; idx < MAX; ++idx)

    {

        if (suppose[idx] != baseballNumbers[idx])

            return false;
    }

    return true;
}

void initScoreTable()
{

    int i;

    for (i = 0; i <= 10; ++i)
        scoreTable[i] = 100;

    for (; i <= queryLimit; ++i)
        scoreTable[i] = 110 - i;
}

int main()
{

    int total_score = 0;

    //freopen("sample_input.txt", "r", stdin);

    setbuf(stdout, NULL);

    //scanf("%d", &T);

    T = 50;

    initScoreTable();

    srand((unsigned int)time(NULL));

    for (int testcase = 1; testcase <= T; ++testcase)
    {

        initialize();

        int suppose[MAX];

        tryBest(suppose);

        if (!check(suppose))
        {

            queryCallCount = MAX_COUNT;

            total_score = 0;

            break;
        }

        printf("#%d %d : ", testcase, queryCallCount);

        for (int i = 0; i < 4; ++i)
            printf("%d", suppose[i]);

        puts("");

        if (queryCallCount > queryLimit)

            queryCallCount = queryLimit;

        total_score += scoreTable[queryCallCount];
    }

    printf("Total Score = %d\n", total_score / T);

    return 0;
}

/*********************************************/

/*
소거법으로 풀어도 될듯
*/

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