#include<iostream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    int i,j,num,compare,temp;
    

    cin >> num; 

    if(num == 0)
        return 0;

    int* input = new int[num];

    for(i = 0 ; i < num ; ++i)
    {
        cin >> input[i];
    }

    for(i = num-1 ; i >= 0; --i) 
    {
        for(j = 0 ; j < i ; ++j)
        {
            compare = j+1;

            if(input[j] > input[compare])
            {
                temp = input[j];
                input[j] = input[compare];
                input[compare] = temp;
            }
        }
    }

    for(i = 0 ; i < num ; ++i)
        cout << input[i] << endl;

    return 0;
}
