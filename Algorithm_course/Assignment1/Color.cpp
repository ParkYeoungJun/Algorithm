#include<iostream>

using namespace std;

void divide(int **arr, int size,int c_start,int r_start, int c_finish,int r_finish, int &pink, int& white)
{
    if(size == 2)
    {
        if(arr[c_start][r_start] == arr[c_start][r_start+1] && arr[c_start][r_start] == arr[c_start+1][r_start] && arr[c_start][r_start] == arr[c_start+1][r_start+1])
            if(arr[c_start][r_start] == 1)
                ++pink;
            else
                ++white;
        else
        {
            if(arr[c_start][r_start] == 1)
                ++pink;
            else
                ++white;
            if(arr[c_start][r_start+1] == 1)
                ++pink;
            else
                ++white;
            if(arr[c_start+1][r_start] == 1)
                ++pink;
            else
                ++white;
            if(arr[c_start+1][r_start+1] == 1)
                ++pink;
            else
                ++white;
        }

        return;
    }
    else
    {
        int col  = c_start,row = r_start;
        bool whe = true;

        while(1)
        {
            if(arr[col][row] != arr[c_start][r_start])
            {
                whe = false;
                break;
            }
            else
            {
                if(++row == r_finish)
                {

                    if(++col == c_finish)
                        break;
                    row = r_start;
                }
            }
        }

        if(whe == false)
        {
            size = size >> 1;

            divide(arr, size, c_start, r_start, c_start+size, r_start+size, pink, white);
            divide(arr, size, c_start, r_start+size, c_start+size, r_start+(size*2), pink, white);
            divide(arr, size, c_start+size, r_start, c_start+(size*2), r_start+size, pink, white);
            divide(arr, size, c_start+size, r_start+size, c_start+(size*2), r_start+(size*2), pink, white);
        }
        else
        {
            if(arr[c_start][r_start] == 1)
                ++pink;
            else
                ++white;
        }

        return;
    }
}



int main(void)
{
    std::ios::sync_with_stdio(false);

    int num_col = 0;
    int pink = 0, white = 0;
    int **arr;

    cin >> num_col;

    arr = new int*[num_col];

    for(int i = 0 ; i < num_col ; ++i)
        arr[i] = new int[num_col];

    for(int i = 0 ; i < num_col ; ++i)
        for(int j = 0 ; j < num_col ; ++j)
            cin >> arr[i][j];

    divide(arr, num_col, 0, 0, num_col, num_col, pink, white);

    cout << white << endl << pink;
}
