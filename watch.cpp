#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int hour, miniute;
	int per_miniute, per_hour;
	float angle_miniute, angle_hour;


	printf("please insert hour and miniutes : ");

	scanf("%d %d", &hour, &miniute);

	per_miniute = (360 / 12) / 5;

	per_hour = (360 / 12);

	angle_miniute = per_miniute * miniute;

	angle_hour = per_hour * hour + (360 / 12) / 60 * miniute;

	printf("angle is %.1f", max(angle_hour, angle_miniute) - min(angle_hour, angle_miniute));

	return 0;

}