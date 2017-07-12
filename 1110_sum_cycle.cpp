#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int input, past, cnt = 0, result, temp;

    cin >> input;

	result = input;

	past = input;

	while (true)
	{
		if (cnt != 0 && result == input)
		{
			printf("%d", cnt);
		
			return 0;
		}

        temp = input / 10 + input % 10;

        if(temp < 10)
        {
            input = ((input % 10) * 10) + temp;
            cnt++;
        }
        else
        {
            input = ((input % 10) * 10) + (temp % 10);
            cnt++;
        }
	}
}
