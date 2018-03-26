#include <stdio.h> //주석 꼭 달기 !!
#include <stdlib.h>

struct localCon{
    char num[10];
    char region[30];
};
struct subLocalCon{
    char region[60];
    char num[10];
};

int main()
{
    char localName[100], subLocalName[100];
    int i = 0;

    struct localCon localList[20];

    // 읽어올 파일 생성
    FILE *fLocalNum = fopen("LocalNumberList.txt", "r");
    FILE *fSubNum = fopen("SubLocalNumberList.txt", "r");

    while(!feof(fLocalNum)) {
        fscanf(fLocalNum, "%s %s", localList[i].num, localList[i].region);
        i++;
    }

    // for(i = 0 ; i < 17 ; ++i) {
    //     printf("%s %s", localList[i].num, localList[i].region);
    //     printf("\n");
    // } // 지워도됌

    fclose(fLocalNum);
    fclose(fSubNum);

    while (1) // 주소입력>지역번호 국번호 자동할당 > 랜덤번호 4자리
    {
        // FILE *fp = fopen("ExistingPhoneNumber.txt","r"); //파일을 읽기모드로 열기
        printf("address : ");
        gets(localName);
        gets(subLocalName);
    }
}