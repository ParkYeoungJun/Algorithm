#include<iostream>
#include<cstdio>
#include<string>
#include<stack>

using namespace std;

int dp[1002][1002];
stack<int> result;

void track(int size1, int size2, int track_i, int track_j)
{
	if (result.size() == dp[size1 - 1][size2 - 1] || (track_i == 0 && track_j == 0))
	{
		return;
	}

	if (dp[track_i][track_j] > dp[track_i - 1][track_j] && dp[track_i][track_j] > dp[track_i][track_j - 1])
	{
		result.push(track_i);

		track(size1, size2, track_i - 1, track_j - 1);
	}
	else if(dp[track_i][track_j] == dp[track_i - 1][track_j])
	{
		track(size1, size2, track_i - 1, track_j);
	}
	else
	{
		track(size1, size2, track_i, track_j - 1);
	}

}

int main()
{
    int size1, size2;
    string input1, input2;

    cin >> input1 >> input2;

    input1 = '0' + input1;
    input2 = '0' + input2;

    size1 = input1.size();
    size2 = input2.size();

    for(int i = 1 ; i < size1 ; ++i)
    {
        for(int j = 1 ; j < size2 ; ++j)
        {
            if(input1.at(i) == input2.at(j))
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
	
	/*
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	*/

    printf("%d\n", dp[size1 - 1][size2 - 1]);

	track(size1, size2, size1-1, size2-1);

	while (!result.empty())
	{
		int temp = result.top();
		result.pop();

		printf("%c", input1.at(temp));
	}

    return 0;
}
