#include <malloc.h>
#include <cstdio>

using namespace std;

typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
}SLinkNode;

void InitList(SLinkNode *&L)
{
	L=(SLinkNode *)malloc(sizeof(SLinkNode));
    L->next=NULL;
}

void DestroyList(SLinkNode *&L)
{
    SLinkNode *pre=L,*p=pre->next;
    while(p!=NULL)
    {
        free(pre);
        pre=p;
        p=p->next;
    }
    free(pre);
}

int GetLength(SLinkNode *L)
{
    int i=0;
    SLinkNode *p=L->next;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}

int GetElem(SLinkNode *L,int i,ElemType &e)
{
    int j=0;
    SLinkNode *p=L;
    if(i<=0)
        return 0;
    while(p!=NULL && j<i)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return 0;
    else
    {
        e=p->data;
        return 1;
    }
}

int Locate(SLinkNode *L,ElemType e)
{
    SLinkNode *p=L->next;
    int j=1;
    while(p!=NULL && p->data!=e)
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
        return 0;
    else
        return(j);
}

int InsElem(SLinkNode*&L,ElemType x,int i)
{
    int j=0;
    SLinkNode*p=L,*s;
    if(i<=0)
        return 0;
    while(p!=NULL && j<i-1)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return 0;
    else
    {
        s=(SLinkNode *)malloc(sizeof(SLinkNode));
        s->data=x;
        s->next=p->next;
        p->next=s;
        return 1;
    }
}

int DelElem(SLinkNode *&L,int i)
{
    int j=0;
    SLinkNode *p=L,*q;
    if(i<=0)
        return 0;
    while(p!=NULL && j<i-1)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return 0;
    else
    {
        q=p->next;
        if(q==NULL)
            return 0;
        else
        {
            p->next=q->next;
            free(q);
            return 1;
        }
    }
}

void DispList(SLinkNode *L)
{
    SLinkNode *p=L->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void CreateListF(SLinkNode *&L,ElemType a[],int n)
{
    SLinkNode *s;
    int i;
    L=(SLinkNode *)malloc(sizeof(SLinkNode));
    L->next=NULL;
    for(i=0;i<n;i++)
    {
        s=(SLinkNode *)malloc(sizeof(SLinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}

void CreateListR(SLinkNode *&L,ElemType a[],int n)
{
    SLinkNode *s,*tc;
    int i;
    L=(SLinkNode *)malloc(sizeof(SLinkNode));
    tc=L;
    for(i=0;i<n;i++)
    {
        s=(SLinkNode *)malloc(sizeof(SLinkNode));
        s->data=a[i];
        tc->next=s;
        tc=s;
    }
    tc->next=NULL;
}

void basic_action()
{
    printf("基本操作\n");
    SLinkNode *L;
    ElemType a[20];
    int n,i;
    printf("输入长度：");
    scanf("%d",&n);
    printf("输入元素：");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    CreateListF(L,a,n);
    printf("L:");
    DispList(L);
    printf("L的长度:%d\n",GetLength(L));
    printf("第三位的值:%d\n",Locate(L,3));
    printf("元素5的位置:%d\n",Locate(L,5));
    DelElem(L,4);
    InsElem(L,10,4);
    printf("L:");
    DispList(L);
    DestroyList(L);
    CreateListR(L,a,n);
    printf("\n");
    printf("L:");
    DispList(L);
    printf("L的长度:%d\n",GetLength(L));
    printf("第三位的值:%d\n",Locate(L,3));
    printf("元素5的位置:%d\n",Locate(L,5));
    DelElem(L,4);
    InsElem(L,10,4);
    printf("L:");
    DispList(L);
    DestroyList(L);
}

void expand_action()
{
    printf("拓展设计\n");
    SLinkNode *L;
    ElemType a[20];
    int n,i,min,max;
    printf("输入长度：");
    scanf("%d",&n);
    printf("输入元素：");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    CreateListF(L,a,n);
    printf("L:");
    DispList(L);
    printf("输入min和max：");
    scanf("%d%d",&min,&max);
    printf("删除%d~%d的结点\n",min,max);
    SLinkNode *pre=L,*p=pre->next;
    while(p!=NULL)
    {
        if(p->data>=min && p->data<=max)
        {
            pre->next=p->next;
            free(p);
            p=pre->next;
        }
        else
        {
            pre=p;
            p=p->next;
        }
    }
    printf("L:");
    DispList(L);
    DestroyList(L);
}

int main()
{
    basic_action();
    printf("\n");
    expand_action();
    getchar();
    getchar();
    return 0;
}
