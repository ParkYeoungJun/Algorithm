//======== user.cpp ========
#ifndef NULL
#define NULL 0
#endif
 
extern int add_lot();
extern void assign(int lot_num, int s, int size, int member_id);
extern void back(int lot_num, int s, int size);
extern void grow(int lot_num, int s, int size, int crop);
 
/*
static value
*/
typedef struct area
{
    int lotNum;
    int start;
    int size;
    struct area *next;
} AREA;
 
AREA *user[10005];
AREA *tail[10005];
 
bool crob[100][100000]; // 영역 저장 배열
 
int lotSize = 0;
 
/*
 */
 
// lot 영역 마킹
void marking(int lotNum, int start, int size, bool flag)
{
    for (int i = start; i < start + size; ++i)
    {
        crob[lotNum][i] = flag;
    }
}
 
void insert(int id, int lotNum, int start, int size)
{
    AREA *newNode = (AREA *)malloc(sizeof(AREA));
    newNode->lotNum = lotNum;
    newNode->start = start;
    newNode->size = size;
    newNode->next = NULL;
 
    if (user[id] == NULL)
    {
        user[id] = newNode;
        tail[id] = newNode;
    }
    else
    {
        tail[id]->next = newNode;
        tail[id] = newNode;
    }
}
 
/*
*/
 
// 각 테스트 케이스마다 초기화
void init_member()
{
    for(int i = 1 ; i <= 10000 ; ++i ){
    if (user[i] != NULL)
    {
        AREA *tmp = user[i];
        while (tmp != NULL)
        {
            AREA *d = tmp;
 
            tmp = tmp->next;
            free(d);
        }
 
        user[i] = NULL;
        tail[i] = NULL;
    }
    }
 
    for(int i = 1 ; i <= lotSize ; ++i) {
        for(int j = 0 ; j < 100000 ;++j)
            crob[i][j] = false;
    }
}
 
//member_id에게 size 크기의 구역을 할당한다. 만약 현재까지의 필지에서 남은 구역이 회원이 요청하는 크기보다 작으면 새로운 필지를 추가한 후 할당한다​
void assign_member(int member_id, int size)
{
    // 초기 설정
    if (lotSize == 0)
        lotSize = add_lot();
    else
    {
        // 구역 마킹
        for (int i = 1; i <= 10000; ++i)
            if (user[i] != NULL)
            {
 
                AREA *tmp = user[i];
 
                while (tmp != NULL)
                {
                    marking(tmp->lotNum, tmp->start, tmp->size, true);
                    tmp = tmp->next;
                }
            }
    }
    //
 
    // 채우기
    bool doneFlag = false;
    for (int i = 1; i <= lotSize; ++i)
    {
        int sIndex = 0, cnt = 0;
        bool sFlag = false;
        for (int j = 0; j < 100000; ++j)
        {
            if (!crob[i][j])
            {
                if (!sFlag)
                    sIndex = j;
                cnt++;
                crob[i][j] = true;
 
                if (cnt >= size)
                {
                    doneFlag = true;
                    size -= cnt;
 
                    break;
                }
 
                sFlag = true;
            }
            else
            {
                if (sFlag)
                {
                    sFlag = false;
 
                    assign(i, sIndex, cnt, member_id);
                    insert(member_id, i, sIndex, cnt);
 
                    size -= cnt;
                    cnt = 0;
                }
            }
        }
 
        if (doneFlag)
        {
            assign(i, sIndex, cnt, member_id);
            insert(member_id, i, sIndex, cnt);
 
            break;
        }
 
        if (sFlag)
        {
            sFlag = false;
 
            assign(i, sIndex, cnt, member_id);
            insert(member_id, i, sIndex, cnt);
 
            size -= cnt;
            cnt = 0;
        }
    }
 
    // 다 채워도 안될 때
    if (size > 0)
    {
        lotSize = add_lot();
        assign(lotSize, 0, size, member_id);
        insert(member_id, lotSize, 0, size);
    }
 
    // 구역 마킹
    for (int i = 1; i <= 10000; ++i)
        if (user[i] != NULL)
        {
 
            AREA *tmp = user[i];
 
            while (tmp != NULL)
            {
                marking(tmp->lotNum, tmp->start, tmp->size, true);
                tmp = tmp->next;
            }
        }
}
 
// member_id에게 할당된 구역을 모두 해제한다. 작물을 해제하면 해당 구역에 채워진 작물도 모두 초기화된다.​
void back_member(int member_id)
{
    // 할당 되어있을 때
    if (user[member_id] != NULL)
    {
        AREA *tmp = user[member_id];
        while (tmp != NULL)
        {
            AREA *d = tmp;
 
            marking(d->lotNum, d->start, d->size, false);
            back(d->lotNum, d->start, d->size);
 
            tmp = tmp->next;
            free(d);
        }
 
        user[member_id] = NULL;
        tail[member_id] = NULL;
    }
}
 
// member_id에게 할당된 구역에 작물 번호 crop으로 모두 채워 넣는다.​
void grow_member(int member_id, int crop)
{
    if (user[member_id] != NULL)
    {
        AREA *tmp = user[member_id];
 
        while (tmp != NULL)
        {
 
            grow(tmp->lotNum, tmp->start, tmp->size, crop);
 
            tmp = tmp->next;
        }
    }
}