#include <cstdio>
#include <cstdlib>

using namespace std;

int N, count;
int arr[16];

int promising(int line)
{
    for (int i = 0; i < line; i++)
    {
        if (arr[i] == arr[line] || abs(arr[line] - arr[i]) == line - i)
            return 0;
    }
    return 1;
}
 
void nQueen(int line)
{
    if (line == N - 1)
    {
        count++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        arr[line + 1] = i;

        if (promising(line + 1))
        {
            nQueen(line + 1);
        }
    }
}
 
int main()
{
    scanf("%d", &N);
    nQueen(-1);
    printf("%d", count);
}
