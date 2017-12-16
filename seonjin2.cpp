#include<cstdio>

void swap(double *pa, double * pb);
void line_up(double *maxp, double *midp, double *minp);

int main()
{
    double max, mid, min;

    printf("float 3 : ");
    scanf("%lf %lf %lf", &max, &mid, &min);

    line_up(&max, &mid, &min);
    printf("sorting : %.1lf, %.1lf, %.1lf", max, mid, min);

    return 0;
}

void swap(double *pa, double *pb){
    double temp;

    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void line_up(double *maxp, double *midp, double *minp){
    if(*midp > *maxp)
        swap(maxp, midp);

    if(*minp > *maxp)
        swap(maxp, minp);

    if(*minp > *midp)
        swap(midp, minp);
}
