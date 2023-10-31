#include <cstdio>

using namespace std;
#define MAXSIZE 100

typedef char ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &sq)
{
    sq.rear = sq.front = 0;
}

void DestroyQueue(SqQueue sq)
{
}

int EnQueue(SqQueue &sq,ElemType x)
{
    if((sq.rear+1)%MAXSIZE == sq.front)
        return 0;
    sq.rear = (sq.rear+1)%MAXSIZE;
    sq.data[sq.rear] = x;
    return 1;
}

int DeQueue(SqQueue &sq,ElemType &x)
{
    if(sq.rear == sq.front)
        return 0;
    sq.front = (sq.front+1)%MAXSIZE;
    x = sq.data[sq.front];
    return 1;
}

int GetHead(SqQueue sq,ElemType &x)
{
    if(sq.rear == sq.front)
        return 0;
    x = sq.data[(sq.front+1)%MAXSIZE];
    return 1;
}

int QueueEmpty(SqQueue sq)
{
    if(sq.rear == sq.front)
        return 1;
    else
        return 0;
}

void basic_action()
{
    SqQueue sq;
    ElemType e;
    printf("初始化队列\n");
    InitQueue(sq);
    printf("队%s\n",QueueEmpty(sq)==1?"空":"非空");
    printf("a进队\n");
    EnQueue(sq,'a');
    printf("b进队\n");
    EnQueue(sq,'b');
    printf("c进队\n");
    EnQueue(sq,'c');
    printf("d进队\n");
    EnQueue(sq,'d');
    printf("队%s\n",QueueEmpty(sq)==1?"空":"非空");
    GetHead(sq,e);
    printf("队头元素为%c\n",e);
    printf("出对次序\n");
    while(!QueueEmpty(sq))
    {
        DeQueue(sq,e);
        printf("%c ",e);
    }
    printf("\n销毁队列\n");
    DestroyQueue(sq);
}

void expand_action()
{
    SqQueue sq;
    ElemType e;
    int n,m,i;
    printf("输入人数n和报数m：");
    scanf("%d%d",&n,&m);
    InitQueue(sq);
    for(i=0;i<n;i++)
        EnQueue(sq,'a'+i);
    i = 0;
    printf("出队次序：");
    while(!QueueEmpty(sq))
    {
        DeQueue(sq,e);
        i++;
        if(i%m!=0)
            EnQueue(sq,e);
        else
            printf("%c ",e);
    }
    printf("\n");
    DestroyQueue(sq);
}

int main()
{
    basic_action();
    printf("\n");
    expand_action();
    return 0;
}
