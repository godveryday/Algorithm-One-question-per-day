/* array�� ������ �߰��� ũ�� �ٲ���� �� ����, ����.. linked list version */
// linked list�� ���鶧�� top�� ���� ���� �ʴ°ǰ�?!!!!!

#include<stdio.h>
#include<stdlib.h>

 typedef struct Newnode
{
    int data;        
    struct Newnode *next;

}newnode_t;


typedef struct head
{
    newnode_t *top_ptr;
    int top;
    int count;
}head_t;

int main()
{
    //? �Լ��� ���ϰ��� ������ ����ұ�?  --> �Ƹ��� �ּҸ� �Ѱ��ٰ��̹Ƿ� newnode_t?
    int size;
    printf("Input size :");
    scanf("%d", &size);

    newnode_t *ptr = Create_newnode(size); 
    Push(ptr);
    return 0;
}

Create_newnode(int size)  //�׷� newnode, head ����ȿ��� �Ѵ��ϸ� �ǰڴ�! --> �����ϴ°� ������?!
{
    head_t *pheadptr = (head_t *)malloc(sizeof(head_t));
    pheadptr->top = -1;
    pheadptr -> count = 0;
    //�ٵ� �̷��� �ϸ� head�����Ͱ� ��� ������. �̰Ը³�?
    
    newnode_t *pNewnode = (newnode_t *)malloc(sizeof(newnode_t));   //typedef�ߴµ� �� newnode_t ��������?  --> main�ȿ��� �����߱� ����.
    pNewnode->next = pheadptr->top_ptr;
    //�̷��� �Ϸ��ϱ� �����Ͱ� �ʹ� ���� �ʿ��ѵ�?
    
    
}
    
Push(newnode_t *ptr, int item)
{
    ptr->data = item;
    ptr->next = 
}