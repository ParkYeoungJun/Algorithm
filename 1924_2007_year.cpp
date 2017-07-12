#include<iostream>
#include<cstdio>

using namespace std;

string day[8] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main()
{
    int x,y;

    scanf("%d %d", &x, &y);

    int temp_x = 1, temp_y = 1, flag = 1;

    while(true)
    {
        if(x == temp_x && y == temp_y)
        {
            cout << day[flag];
            return 0;
        }

        if(temp_x == 1 || temp_x == 3 || temp_x == 5 || temp_x == 7
                || temp_x == 8 || temp_x == 10 || temp_x == 12)
        {
            if(temp_y == 31)
            {
                temp_x++;
                temp_y = 1;
                flag = (flag+1) % 7;

                continue;
            }
        }
        else if(temp_x == 4 || temp_x == 6 || temp_x == 9 || temp_x == 11)
        {
            if(temp_y == 30)
            {
                temp_x++;
                temp_y = 1;
                flag = (flag+1) % 7;

                continue;
            }
        }
        else
        {
            if(temp_y == 28)
            {
                temp_x++;
                temp_y = 1;
                flag = (flag+1) % 7;

                continue;
            }
        }

        temp_y++;
        flag = (flag+1) % 7;
    }
}
