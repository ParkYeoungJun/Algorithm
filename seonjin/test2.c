/*

주제 : 수동형 UHF RFID 데이터 기반 위치인식 프로그램
목표 : RFID Tag의 RSSI 및 KNN 알고리즘을 활용한 target 위치 인식 프로그램


1. File에서 Data 읽어오기 (fgets())
2. 읽어 온 문자열 나누기 -> 필요한 데이터만 추출 (strtok())
3. 연결리스트에 저장하기
4. 평균 RSSI 및 평균 인터벌 구하기
5. 위치 찾기

di : 선택된 i 번째 R.T의 RSSI와 T.T의 RSSI의 차이값(절댓값)
A = for(i=1;i<n;i++) 1/di^2;
가중치 : weighti = (1/di^2)/A
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *  tagID_positiion
 */

char targetID[27] = "0x35E0170044CF0D590000F5A5";
char referenceIDs[60][27] = {
    "0x35E0170044CF0D590000F544", "0x35E0170044CF0D590000F543", "0x35E0170044CF0D590000F542", "0x35E0170044CF0D590000F551", "0x35E0170044CF0D590000F550", "0x35E0170044CF0D590000F54F",
    "0x35E0170044CF0D590000F61D", "0x35E0170044CF0D590000F61C", "0x35E0170044CF0D590000F61B", "0x35E0170044CF0D590000F61A", "0x35E0170044CF0D590000F629", "0x35E0170044CF0D590000F628",
    "0x35E0170044CF0D590000F54E", "0x35E0170044CF0D590000F55D", "0x35E0170044CF0D590000F55C", "0x35E0170044CF0D590000F55B", "0x35E0170044CF0D590000F55A", "0x35E0170044CF0D590000F569",
    "0x35E0170044CF0D590000F627", "0x35E0170044CF0D590000F626", "0x35E0170044CF0D590000F635", "0x35E0170044CF0D590000F634", "0x35E0170044CF0D590000F633", "0x35E0170044CF0D590000F632",
    "0x35E0170044CF0D590000F568", "0x35E0170044CF0D590000F567", "0x35E0170044CF0D590000F566", "0x35E0170044CF0D590000F575", "0x35E0170044CF0D590000F574", "0x35E0170044CF0D590000F573",
    "0x35E0170044CF0D590000F641", "0x35E0170044CF0D590000F640", "0x35E0170044CF0D590000F63F", "0x35E0170044CF0D590000F63E", "0x35E0170044CF0D590000F64D", "0x35E0170044CF0D590000F64C",
    "0x35E0170044CF0D590000F572", "0x35E0170044CF0D590000F581", "0x35E0170044CF0D590000F580", "0x35E0170044CF0D590000F57F", "0x35E0170044CF0D590000F57E", "0x35E0170044CF0D590000F58D",
    "0x35E0170044CF0D590000F64B", "0x35E0170044CF0D590000F64A", "0x35E0170044CF0D590000F659", "0x35E0170044CF0D590000F658", "0x35E0170044CF0D590000F657", "0x35E0170044CF0D590000F656",
    "0x35E0170044CF0D590000F58C", "0x35E0170044CF0D590000F58B", "0x35E0170044CF0D590000F58A", "0x35E0170044CF0D590000F599", "0x35E0170044CF0D590000F598", "0x35E0170044CF0D590000F597",
    "0x35E0170044CF0D590000F603", "0x35E0170044CF0D590000F5F8", "0x35E0170044CF0D590000F5F7", "0x35E0170044CF0D590000F5F6", "0x35E0170044CF0D590000F605", "0x35E0170044CF0D590000F604"};
int referecePoints[60][2] = {
    {7, 1}, {22, 1}, {37, 1}, {52, 1}, {67, 1}, {81, 1}, {101, 1}, {116, 1}, {131, 1}, {146, 1}, {161, 1}, {176, 1}, {7, 41}, {22, 41}, {37, 41}, {52, 41}, {67, 41}, {81, 41}, {101, 41}, {116, 41}, {131, 41}, {146, 41}, {161, 41}, {176, 41}, {7, 80}, {22, 80}, {37, 80}, {52, 80}, {67, 80}, {81, 80}, {101, 80}, {116, 80}, {131, 80}, {146, 80}, {161, 80}, {176, 80}, {7, 115}, {22, 115}, {37, 115}, {52, 115}, {67, 115}, {81, 115}, {101, 115}, {116, 115}, {131, 115}, {146, 115}, {161, 115}, {176, 115}, {7, 144}, {22, 144}, {37, 144}, {52, 144}, {67, 144}, {81, 144}, {101, 144}, {116, 144}, {131, 144}, {146, 144}, {161, 144}, {176, 144}};

/*
 *
 */

//파일에서 읽어들인 RFID Tag 정보를 저장할 구조체
typedef struct taginfo
{
    char id[27];
    float rssi;
    double identifiedTime; // ms로 변환
    taginfo *next;

} taginfo;

typedef struct array
{
    char id[27];
    int points[2];
    taginfo *next;

} array;

array list[60];

int main()
{
    FILE *fp = fopen("C:\Users\이선진\Downloads\RFID_Data.txt", "r");

    int i;

    // tagID_position.txt 초기화
    for (i = 0; i < 60; i++)
    {
        strcpy(list[i].id, referenceIDs[i]);
        list[i].points[0] = referencePoints[i][0];
        list[i].points[1] = referencePoints[i][1];
    }

    while (!feof(fp))
    {
        int hour = 0, min = 0, sec = 0;
        char *tmp;

        newnode = (taginfo *)malloc(sizeof(taginfo));
        newnode->next = NULL;
        char line[150];
        fgets(line, 150, fp);

        // tag_id
        strtok(line, "=");
        strcpy(newnode->id, strtok(NULL, ","));
        // rssi
        strtok(NULL, "=");
        strtok(NULL, "=");
        strtok(NULL, "=");
        newnode.rssi = strtok(NULL, ",");
        // time
        strtok(NULL, "T");
        strtok(NULL, "\n");
        tmp = strtok(NULL, ":");

        // ms로 변환
        // ASCII -> int
        atoi(tmp);
        newnode.identifiedTime = tmp * 60 * 60 * 1000; // 시
        tmp = strtok(NULL, ":");
        atoi(tmp);
        newnode.identifiedTime += tmp * 60 * 1000; // 분
        tmp = strtok(NULL, ".");
        atoi(tmp);
        newnode.identifiedTime += tmp * 1000; // 초

        for(i=0;i<60;i++)
        {
            if(strcmp(list[i]->id,newnode->id)==0)
            {
                if(list[i]->next == NULL)
                {
                    list[i]->next = newnode;
                }
                else
                {
                    taginfo *temp = list[i]->next;

                    while(temp->next != NULL)   temp = temp->next;
                    
                    temp->next = newnode;
                }

                break;
            }
        }

        // if (head == NULL)
        // {
        //     head = newnode;
        // }
        // else
        // {
        //     taginfo temp = head;
        //     while (temp != NULL)
        //         temp = temp->next;
        //     temp
        // }
    }

    fclose(fp);
}