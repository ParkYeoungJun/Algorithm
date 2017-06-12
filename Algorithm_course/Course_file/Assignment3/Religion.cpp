#include<iostream>

using namespace std;

int func(int* stu, int i)
{
	if(stu[i] != i)
		stu[i] = func(stu, stu[i]);
	return stu[i];
}

int main(void)
{
	 std::ios::sync_with_stdio(false);

	 int num;

	 cin >> num;

	 int group_size;

	 cin >> group_size;

	 int* student;
	 student = new int[num+1];

	 for(int i = 1 ; i <= num ; ++i)
		 student[i] = i;

	 int a,b;
	 int x,y;

	 int count = num;

	 for(int i = 0 ; i < group_size ; ++i)
	 {
		cin >> a >> b;

		x = func(student, a);
		y = func(student, b);

		if(x != y)
		{
			student[x]= y;
			--count;
		}
	 }

	 cout << count;
}
