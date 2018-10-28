#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct taginfo{		//파일에서 읽어들인 RFID Tag 정보를 저장할 구조체
	char id[27];
	float rssi;
	double identifiedTime;
    taginfo *next;
}TAGINFO;

TAGINFO *head, *tail;

int main()
{
    FILE *fp = fopen("C:\Users\Park\Downloads\RFID_Data.txt","r");

    head = (TAGINFO *)malloc(sizeof(TAGINFO));
    tail = (TAGINFO *)malloc(sizeof(TAGINFO));

    


}