#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

bool validCheck(int x1, int y1, int x2, int y2, vector<vector<int>> data,int n)
{
    int minX = min(x1, x2);
    int minY = min(y1, y2);
    int maxX = max(x1, x2);
    int maxY = max(y1, y2);

    for (int k = 0; k < n; ++k)
    {
        int data_x = data[k][0], data_y = data[k][1];

        if (data_x > minX && data_x < maxX && data_y > minY && data_y < maxY)
        {
            return false;
        }
    }

    return true;
}
int getDistance(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data)
{
    std::ios_base::sync_with_stdio(false);

    int answer = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (data[i][0] != data[j][0] && data[i][1] != data[j][1])
            {

                // if (getDistance(data[i][0], data[i][1], data[j][0], data[j][1]) >= 2)
                // {
                    if (validCheck(data[i][0], data[i][1], data[j][0], data[j][1], data, n))
                    {
                        answer++;
                    }
                // }
            }
        }
    }
    return answer;
}