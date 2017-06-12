#include<iostream>
#include<stdlib.h>

using namespace std;

void divide(int **arr, int size, string* binary, int bi_size, int c_start,int r_start, int c_finish,int r_finish)
{
    int k = 0;
    bool whe = true;

    if(size == 1)
    {
        if(arr[c_start][r_start] == 1)
        {
            binary[bi_size-1] += "01";
        }
        else
        {
            binary[bi_size-1] += "00";
        }

        return;
    }
    else
    {
        int col  = c_start,row = r_start;

        int i = size;

        while(1)
        {
            i = i/2;

            if(i != 1)
                ++k;
            else
            {
                k+=2;
                break;
            }
        }

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
                    ++col;
                    if(col == c_finish)
                        break;
                    row = r_start;
                }
            }
        }
    }

    if(whe == false)
    {
        binary[bi_size-k] += "1";

        size = size >> 1;

        divide(arr, size, binary, bi_size, c_start, r_start, c_start+size, r_start+size);
        divide(arr, size, binary, bi_size, c_start, r_start+size, c_start+size, r_start+(size*2));
        divide(arr, size, binary, bi_size, c_start+size, r_start, c_start+(size*2), r_start+size);
        divide(arr, size, binary, bi_size, c_start+size, r_start+size, c_start+(size*2), r_start+(size*2));
    }
    else
    {
        if(arr[c_start][r_start] == 1)
            binary[bi_size-k] += "01";
        else
            binary[bi_size-k] += "00";
    }

    return;
}

int main(void)
{
    std::ios::sync_with_stdio(false);

    int size = 0;
    int bi_size = 0;
    string *binary = 0;
    int **arr;

    cin >> size;

    arr = new int*[size];

    for(int i = 0 ; i < size ; ++i)
        arr[i] = new int[size];

    for(int i = 0 ; i < size ; ++i)
        for(int j = 0 ; j < size ; ++j)
            cin >> arr[i][j];

    int i = size;

    while(1)
    {
        i = i >> 1;
        if(i != 1)
            ++bi_size;
        else
        {
            bi_size += 2;
            break;
        }
    }

    binary = new string[bi_size];

    divide(arr, size, binary, bi_size, 0, 0, size, size);

    string re;

    for(int j = 0 ; j < bi_size ; ++j)
        re += binary[j];

    int result = 0;

    result = strtol(re.c_str(), NULL, 2);

    cout.setf(ios::uppercase);

    cout << hex << result;
}
