#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    struct node* front;
    int num;
    struct node* next;
}list,*List;
int main() {//双向链表的初始化
    List  head=NULL;
    head = (List)malloc(sizeof(list));
    head->front = NULL;
    head->next = NULL;
    return 0;
}
