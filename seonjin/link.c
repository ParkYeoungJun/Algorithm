#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node
{
    int data;
    struct _node *next;
} node;

node *head, *tail;

// 초기화
void init_list()
{
    head = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));
    head->next = tail;
    tail->next = tail;
}

node *ordered_insert(int k)
{
    node *tmp = (node *)malloc(sizeof(node));
    tmp->data = k;

    // 자동적으로 마지막이 tail이 됨

    // 위치 찾기
    node *seek = head->next;
    while (seek->next != tail)
    {
        if (seek->next->data >= k)
            break;
        seek = seek->next;
    }

    // 이어붙이기
    tmp->next = seek->next;
    seek->next = tmp;
}

node *print_list(node *head)
{
    // 순차적으로 출력

    node *tmp = head->next;

    while (tmp != tail)
    {
        printf(" %d ", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");
    return tail;
}

int delete_node(int k)
{
    bool flag = false;
    node *tmp = head->next;

    while (tmp->next != tail)
    {
        // 찾았을 때 전, 후를 이어붙이고 메모리 해제
        if (tmp->next->data == k)
        {
            node *d = tmp->next;
            tmp->next = tmp->next->next;

            free(d);

            flag = true;
        }

        tmp = tmp->next;
    }

    // 잘 됐는지 안됐는지
    if (flag)
        return 1;
    else
        return 0;
}

int main()
{
    node *t;

    init_list();

    ordered_insert(10);
    ordered_insert(5);
    ordered_insert(8);
    ordered_insert(3);
    ordered_insert(1);
    ordered_insert(2);
    ordered_insert(7);

    printf("\n Initial Linked list is ");
    print_list(head->next);
    printf("\n");

    if (delete_node(8) == 1)
    {
        printf(" Delete is done\n");
        print_list(head->next);
    }
    else
        printf(" Can not find data\n");

    return 0;
}