//======== main.cpp ========

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

#define MAX_LOT_COUNT 100
//#define MAX_LOT_SIZE 100000
#define MAX_LOT_SIZE 20
#define MAX_MEMBER_ID 10000
#define MAX_CROP 100

enum DEMAND
{
    ASSIGN = 1,
    BACK = 2,
    GROW = 3
};

extern void init_member();
extern void assign_member(int member_id, int size);
extern void back_member(int member_id);
extern void grow_member(int member_id, int crop);

static int N;
static int lot[MAX_LOT_COUNT + 1][MAX_LOT_SIZE];
static int member[MAX_LOT_COUNT + 1][MAX_LOT_SIZE];
static int lot_cnt;
static int chk_sum;
static int chk_sum_res;
static int chk_size[MAX_MEMBER_ID + 1];
static int chk_crop[MAX_MEMBER_ID + 1];

int add_lot()
{
    int i;
    if (lot_cnt == MAX_LOT_COUNT)
        return MAX_LOT_COUNT;
    lot_cnt++;
    for (i = 0; i < MAX_LOT_SIZE; i++)
        lot[lot_cnt][i] = member[lot_cnt][i] = 0;
    return lot_cnt;
}

void assign(int lot_num, int s, int size, int member_id)
{
    int i;
    int end;
    if (lot_num < 1 || lot_num > lot_cnt || size < 0)
        return;
    if (s < 0)
        s = 0;
    end = s + size;
    if (end > MAX_LOT_SIZE)
        end = MAX_LOT_SIZE;
    for (i = s; i < end; i++)
    {
        chk_sum -= lot[lot_num][i];
        lot[lot_num][i] = 0;
        member[lot_num][i] = member_id;
    }
}

void back(int lot_num, int s, int size)
{
    int i;
    int end;
    if (lot_num < 1 || lot_num > lot_cnt || size < 0)
        return;
    if (s < 0)
        s = 0;
    end = s + size;
    if (end > MAX_LOT_SIZE)
        end = MAX_LOT_SIZE;
    for (i = s; i < end; i++)
    {
        chk_sum -= lot[lot_num][i];
        lot[lot_num][i] = 0;
        member[lot_num][i] = 0;
    }
}

void grow(int lot_num, int s, int size, int crop)
{
    int i;
    int end;
    if (lot_num < 1 || lot_num > lot_cnt || crop < 1 || crop > MAX_CROP || size < 0)
        return;
    if (s < 0)
        s = 0;
    end = s + size;
    if (end > MAX_LOT_SIZE)
        end = MAX_LOT_SIZE;
    for (i = s; i < end; i++)
    {
        chk_sum -= lot[lot_num][i];
        lot[lot_num][i] = crop;
        chk_sum += lot[lot_num][i];
    }
}

static void init()
{
    int i;
    lot_cnt = 0;
    chk_sum = 0;
    chk_sum_res = 0;
    for (i = 1; i <= MAX_MEMBER_ID; i++)
        chk_size[i] = chk_crop[i] = 0;
}

static int confirm()
{
    int i, j;
    for (i = 1; i <= lot_cnt; i++)
    {
        for (j = 0; j < MAX_LOT_SIZE; j++)
        {
            if (chk_crop[member[i][j]] != lot[i][j])
                return 0;
            chk_size[member[i][j]]--;
        }
    }
    for (i = 1; i <= MAX_MEMBER_ID; i++)
    {
        if (chk_size[i] != 0)
            return 0;
    }
    return 1;
}

static int run()
{
    int i;
    int demand;
    int member_id, size, crop;
    init_member();
    for (i = 0; i < N; i++)
    {
        scanf("%d", &demand);
        switch (demand)
        {
        case ASSIGN:
            scanf("%d %d", &member_id, &size);
            assign_member(member_id, size);
            chk_size[member_id] = size;
            break;
        case BACK:
            scanf("%d", &member_id);
            back_member(member_id);
            chk_sum_res -= chk_size[member_id] * chk_crop[member_id];
            chk_size[member_id] = chk_crop[member_id] = 0;
            break;
        case GROW:
            scanf("%d %d", &member_id, &crop);
            grow_member(member_id, crop);
            chk_sum_res -= chk_size[member_id] * chk_crop[member_id];
            chk_crop[member_id] = crop;
            chk_sum_res += chk_size[member_id] * chk_crop[member_id];
            break;
        }
        if (chk_sum != chk_sum_res)
            lot_cnt = MAX_LOT_COUNT;
    }
    if (confirm() == 0)
        lot_cnt = MAX_LOT_COUNT;
    return lot_cnt;
}

/*****************************************************************************************/

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

typedef struct userList
{
    int id;
    struct userList *next;
} USERLIST;

USERLIST *userHead = NULL;
USERLIST *userTail = NULL;

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
    USERLIST *tmpU = userHead;
    while (tmpU != NULL)
    {
        if (user[tmpU->id] != NULL)
        {
            AREA *tmp = user[tmpU -> id];
            while (tmp != NULL)
            {
                AREA *d = tmp;

                tmp = tmp->next;
                free(d);
            }

            user[tmpU -> id] = NULL;
            tail[tmpU -> id] = NULL;
        }
    }

    tmpU = userHead;
    while (tmpU != NULL)
    {
        USERLIST* d = tmpU;

        tmpU = tmpU->next;
        free(d);
    }
    userHead = NULL;
    userTail = NULL;

    for (int i = 1; i <= lotSize; ++i)
    {
        for (int j = 0; j < 100000; ++j)
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
        USERLIST *tmpU = userHead;
        while (tmpU != NULL)
        {
            AREA *tmp = user[tmpU->id];

            while (tmp != NULL)
            {
                marking(tmp->lotNum, tmp->start, tmp->size, true);
                tmp = tmp->next;
            }

            tmpU = tmpU->next;
        }
    }
    //

    // add user list
    USERLIST *newUser = (USERLIST *)malloc(sizeof(USERLIST));
    newUser->id = member_id;
    newUser->next = NULL;

    if (userHead == NULL)
    {
        userHead = newUser;
        userTail = newUser;
    }
    else
    {
        userTail->next = newUser;
        userTail = userTail->next;
    }

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
    USERLIST *tmpU = userHead;
    while (tmpU != NULL)
    {

        AREA *tmp = user[tmpU->id];

        while (tmp != NULL)
        {

            marking(tmp->lotNum, tmp->start, tmp->size, true);
            tmp = tmp->next;
        }

        tmpU = tmpU->next;
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

    USERLIST *tmpUser = userHead;

    if (tmpUser != NULL && tmpUser->id == member_id)
    {
        userHead = tmpUser->next;
        free(tmpUser);
    }
    else
    {
        while (tmpUser != NULL)
        {
            if (tmpUser->next != NULL)
                if (tmpUser->next->id == member_id)
                {

                    USERLIST *t = tmpUser->next;

                    tmpUser->next = tmpUser->next->next;
                    free(t);

                    break;
                }

            tmpUser = tmpUser->next;
        }
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

/**************************************************************************************/

int main()
{
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);
    int total_score = 0, T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc)
    {
        scanf("%d", &N);
        init();
        int score = run();
        printf("#%d %d\n", tc, score);
        total_score += score;
    }
    printf("Total score: %d\n", total_score);
    return 0;
}
