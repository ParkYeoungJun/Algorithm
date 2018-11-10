

///===== main.cpp =====

#include <stdio.h>
#include <iostream>

using namespace std;

extern void initUser();
extern void addSurveyResult(int stdID, int cnt, char celebID[][11]);
extern void cancelSurveyResult(int stdID);
extern void blindCelebID(char celebID[]);
extern void recoverCelebID(char celebID[]);
extern int query(int mode, char celebID[][11]);

static int queryNum;
static char name[4][11];

enum MODE
{
    MODE0 = 0,
    MODE1 = 1,
    MODE2 = 2,
    SAVE = 3,
    CANCEL = 4,
    BLIND = 5,
    RECOVER = 6
};

static int process()
{

    initUser();

    scanf("%d", &queryNum);

    int order, ans, userans, id, num;

    for (int i = 0; i < queryNum; ++i)
    {
        scanf("%d", &order);

        switch (order)
        {
        case MODE0:
            scanf("%s %d", name[0], &ans);
            if (query(0, name) != ans)
                return 0;
            break;
        case MODE1:
            scanf("%s %s %d", name[0], name[1], &ans);
            if (query(1, name) != ans)
                return 0;
            break;
        case MODE2:
            scanf("%s %s %d", name[0], name[1], &ans);
            if (query(2, name) != ans)
                return 0;
            break;
        case SAVE:
            scanf("%d %d", &id, &num);
            for (int j = 0; j < num; ++j)
                scanf("%s", name[j]);
            addSurveyResult(id, num, name);
            break;
        case CANCEL:
            scanf("%d", &id);
            cancelSurveyResult(id);
            break;
        case BLIND:
            scanf("%s", name[0]);
            blindCelebID(name[0]);
            break;
        case RECOVER:
            scanf("%s", name[0]);
            recoverCelebID(name[0]);
            break;
        }
    }
    return 100;
}

int main()
{
    int tc = 1, sc = 100;
    scanf("%d", &tc);
    for (int i = 0; i < tc; ++i)
    {
        if (process() != 100)
        {
            sc = 0;
            break;
        }
    }
    printf("%d\n", sc);

    return 0;
}

//====================================

///===== user.cpp =====
#ifndef NULL
#define NULL 0
#endif

typedef unsigned int UI;

const int LM = 50005;
const int SIZE = (int)3e6 + 3;

typedef struct userInHash
{
    int id;
    char str[15];
    struct userInHash *prev;
    struct userInHash *next;

    void init(int i)
    {
        id = i;
        prev = NULL;
        next = NULL;
    }
} _USERINHASH;

typedef struct user
{
    int hash;
    _USERINHASH *link;

    void init(int h)
    {
        hash = h;
        link = NULL;
    }
} _USER;

_USERINHASH hashHeap[SIZE];
int hashHeapSize = 0;

_USER userArr[LM][5];
_USERINHASH *hashTable[SIZE];
_USERINHASH *hashTableTail[SIZE];

int blindList[SIZE];


void strcpy(char*dest, char*src){
	while ((*dest++ = *src++));
}

int strcmp(char*s, char*t){
	while (*s && *s == *t) ++s, ++t;
	return *s - *t;
}


// string to hashing integer
UI djb2(char *s)
{
    UI hash = 5381;
    for (int i = 0; s[i]; ++i)
        hash = ((hash << 5) + hash + s[i]) % SIZE;
    return hash;
}

int probing(int hashing, char* c) {
    for(;hashTable[hashing] != NULL && strcmp(hashTable[hashing]->str, c) != 0; hashing = (hashing+1) % SIZE);

    return hashing;
}

/// 새로운 설문조사 시작을 위한 초기화
void initUser()
{
    // user init
    for (int i = 0; i < LM; ++i)
        for (int j = 0; j < 5; ++j)
            userArr[i][j].init(-1);

    for (int i = 0; i < SIZE; ++i) {
        hashTable[i] = hashTableTail[i] = NULL;
        blindList[i] = 0;
    }

    //for (int i = 0; i < hashHeapSize; ++i) {
    //   strcpy(hashHeap[i].str, "");
    //    hashHeap[i].init(0);
    //}
    hashHeapSize = 0;
}

/**********************************************************************/

_USERINHASH *insertToHash(int stdID, int hashing, char* c)
{
    _USERINHASH *newNode = &hashHeap[hashHeapSize++];
    newNode->init(stdID);
    strcpy(newNode->str, c);

    if (hashTable[hashing] == NULL)
    {
        hashTable[hashing] = newNode;
        hashTableTail[hashing] = newNode;
    }
    else
    {
        hashTableTail[hashing]->next = newNode;
        newNode->prev = hashTableTail[hashing];
        hashTableTail[hashing] = newNode;
    }

    return newNode;
}
void insertToUser(_USERINHASH *node, int id, int index, int hashing)
{
    userArr[id][index].hash = hashing;
    userArr[id][index].link = node;
}

/**********************************************************************/

/// 설문조사 결과를 저장
void addSurveyResult(int stdID, int cnt, char celebID[][11])
{
    for (int i = 0; i < cnt; ++i)
    {   
        int hashing = djb2(celebID[i]);
        int prob = probing(hashing, celebID[i]);
       _USERINHASH *node = insertToHash(stdID, prob, celebID[i]);
        insertToUser(node, stdID, i, prob);
    }
}

/**********************************************************************/

void delUserInHash(_USERINHASH *node, int hashing)
{

    // only one
    if (node->prev == NULL && node->next == NULL)
    {
        hashTable[hashing] = NULL;
        hashTableTail[hashing] = NULL;
    } // first
    else if (node->prev == NULL)
    {
        hashTable[hashing] = node->next;
        node->next->prev = NULL;
    } // last
    else if (node->next == NULL)
    {
        hashTableTail[hashing] = node->prev;
        node->prev->next = NULL;
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
}

/**********************************************************************/

/// 설문조사 결과 등록을 취소
void cancelSurveyResult(int stdID)
{
    for (int i = 0; i < 4 && userArr[stdID][i].hash != -1; ++i)
    {
        delUserInHash(userArr[stdID][i].link, userArr[stdID][i].hash);
        userArr[stdID][i].hash = -1;
        userArr[stdID][i].link = NULL;
    }
}

/// 특정 유명 인물에 대한 모든 선호도 기록을 제외시키기
void blindCelebID(char celebID[])
{
    int hashing = djb2(celebID);
    int prob = probing(hashing, celebID);
    blindList[prob] = 1;
}

/// 특정 유명 인물에 대한 모든 선호도 기록이 제외되어 있다면 다시 복원
void recoverCelebID(char celebID[])
{
    int hashing = djb2(celebID);
    int prob = probing(hashing, celebID);
    blindList[prob] = 0;
}

/// 특정인물을 선호하는 학생수를 리턴한다.
/// 단, blind 처리된 인물을 선정하지 않은 학생이 대상이 된다.
/// mode == 0 : 단일 인물을 선호하는 학생 수
/// mode == 1 : 두 인물 모두를 선호하는 학생 수
/// mode == 2 : 둘 중 하나 이상을 선호하는 학생 수
bool inBlind(int stdID)
{
    for (int i = 0; i < 4 && userArr[stdID][i].hash != -1; ++i) {
        if (blindList[userArr[stdID][i].hash] == 1) return true;
    }
    return false;
}

int modeZero(int hashing)
{
    int rtn = 0;

    _USERINHASH *tmp = hashTable[hashing];

    while (tmp != NULL)
    {
        if (!inBlind(tmp->id)) rtn++;
        
        tmp = tmp->next;
    }

    return rtn;
}
int modeOne(int hashing1, int hashing2)
{
    int rtn = 0;

    _USERINHASH *tmp1 = hashTable[hashing1];

    while (tmp1 != NULL)
    {

        if (!inBlind(tmp1->id))
        {

            _USERINHASH *tmp2 = hashTable[hashing2];

            while (tmp2 != NULL)
            {

                if (tmp1->id == tmp2->id)
                {
                    rtn++;
                    break;
                }

                tmp2 = tmp2->next;
            }
        }

        tmp1 = tmp1->next;
    }

    return rtn;
}
int modeTwo(int hashing1, int hashing2)
{
    int rtn = 0;

    _USERINHASH *tmp1 = hashTable[hashing1];

    while (tmp1 != NULL)
    {

        if (!inBlind(tmp1->id))  rtn++;

        tmp1 = tmp1->next;
    }

    _USERINHASH *tmp2 = hashTable[hashing2];

    while (tmp2 != NULL)
    {

        if (!inBlind(tmp2->id))  rtn++;

        tmp2 = tmp2->next;
    }

    rtn -= modeOne(hashing1, hashing2);

    return rtn;
}

int query(int mode, char celebID[][11])
{
    int rtn;

    if (mode == 0)
    { // 1
        int hashing = djb2(celebID[0]);
        int prob = probing(hashing, celebID[0]);
        rtn = modeZero(prob);
    }
    else if (mode == 1)
    { // 2
        int hashing1 = djb2(celebID[0]);
        int hashing2 = djb2(celebID[1]);
        int prob1 = probing(hashing1, celebID[0]);
        int prob2 = probing(hashing2, celebID[1]);
        rtn = modeOne(prob1, prob2);
    }
    else if (mode == 2)
    { // 2
        int hashing1 = djb2(celebID[0]);
        int hashing2 = djb2(celebID[1]);
        int prob1 = probing(hashing1, celebID[0]);
        int prob2 = probing(hashing2, celebID[1]);
        rtn = modeTwo(prob1, prob2);
    }

    return rtn;
}