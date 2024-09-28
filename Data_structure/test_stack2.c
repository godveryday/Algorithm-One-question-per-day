/* array의 단점인 중간에 크기 바뀌었을 때 삽입, 힘듬.. linked list version */
// linked list로 만들때는 top이 값이 들어가지 않는건가?!!!!!

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
    //? 함수의 리턴값을 무엇을 줘야할까?  --> 아마도 주소를 넘겨줄것이므로 newnode_t?
    int size;
    printf("Input size :");
    scanf("%d", &size);

    newnode_t *ptr = Create_newnode(size); 
    Push(ptr);
    return 0;
}

Create_newnode(int size)  //그럼 newnode, head 여기안에서 둘다하면 되겠다! --> 따로하는게 나을듯?!
{
    head_t *pheadptr = (head_t *)malloc(sizeof(head_t));
    pheadptr->top = -1;
    pheadptr -> count = 0;
    //근데 이렇게 하면 head포인터가 계속 생성됨. 이게맞나?
    
    newnode_t *pNewnode = (newnode_t *)malloc(sizeof(newnode_t));   //typedef했는데 왜 newnode_t 사용못하지?  --> main안에서 선언했기 때문.
    pNewnode->next = pheadptr->top_ptr;
    //이렇게 하려니깐 포인터가 너무 많이 필요한데?
    
    
}
    
Push(newnode_t *ptr, int item)
{
    ptr->data = item;
    ptr->next = 
}