#include<cstdio>

void rotate(int *pa, int *pb, int *pc);

int main()
{
    int pa,pb,pc;
    char ch;
    
    scanf("%d %d %d", &pa, &pb, &pc);
    
    fflush(stdin);

    while(1)
    {

        printf("%d:%d:%d", pa, pb, pc);

        ch = getchar();

        rotate(&pa, &pb, &pc);

        if(ch != '\n')
            return 0;        
    }
}
void rotate(int *pa, int *pb, int *pc)
{
    int temp;

    temp = *pa;
    *pa = *pb;
    *pb = temp;

    temp = *pb;
    *pb = *pc;
    *pc = temp;
}