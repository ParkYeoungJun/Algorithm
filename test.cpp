#include<stdio.h>

int main()
{
    int player[3]; //플레이어 3명
    int num[50];
    int i,j=0;

    printf("Game start\n");

    for(i=1;i<=3;i++)
    {
        if(i==4) i=1;

        scanf("%d", &num[j]); //i번째 플레이어 숫자 입력

		printf("asdf\n");


        if(num[j] == 30)
        {
            if(i==3) i-=2;
            printf("player %d lose !\n",i);
            break;
        }
        if(num[j] == 31)
        {
            printf("player %d lose !\n",i);
            break;
        }

		printf("asdf\n");

        if(num[j]-num[j-1] >3 || num[0]>3)
        {
            --i;
            continue;
        }


		printf("asdf\n");

        printf("player %d : %d ",i+1,num[j]); //1번 플레이어
        j++;
    }

}