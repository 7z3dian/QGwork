#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    struct node* front;
    int num;
    struct node* next;
}list,*List;
int main() {//˫������ĳ�ʼ��
    List  head=NULL;
    head = (List)malloc(sizeof(list));
    head->front = NULL;
    head->next = NULL;
    return 0;
}
