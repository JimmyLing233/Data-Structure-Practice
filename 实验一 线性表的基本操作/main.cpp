#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;//ʹ�ñ�׼ģ�������ж���
#define MaxSize 100//�������Ա����󳤶�
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

// ��ʼ�����Ա�
void InitList(SqList &L)
{
    L.length = 0;
}
// �������Ա�
void DestroyList(SqList L)
{}
// �����Ա���
int GetLength(SqList L)
{
    return L.length;
}
// �����Ա��е� i ��Ԫ��
int GetElem(SqList L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return 0;
    else
    {
        e = L.data[i-1];
        return 1;
    }
}
// ��ֵ�����㷨
int Locate(SqList L, ElemType x)
{
    int i = 0;
    while (i < L.length && L.data[i] != x)
        i++;
    if (i >= L.length)  return (0);
    else  return (i+1);
}
// ����Ԫ��
int InsElem(SqList &L, ElemType x, int i)
{
    int j;
    if (i < 1 || i > L.length + 1)
        return 0;
    for (j = L.length; j > i-1; j--)
        L.data[j] = L.data[j-1];
    L.data[i-1] = x;
    L.length++;
    return 1;
}
// ɾ��Ԫ��
int DelElem(SqList &L, int i)
{
    int j;
    if (i < 1 || i > L.length)
        return 0;
    for (j = i; j < L.length; j++)
        L.data[j-1] = L.data[j];
    L.length--;
    return 1;
}
// ���Ԫ��ֵ
void DispList(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
}
// ���崴��˳���
void CreateList(SqList &L, ElemType a[], int n)
{
    int i, k = 0;
    for (i = 0; i < n; i++)
    {
        L.data[k] = a[i];
        k++;
    }
    L.length = k;
}
void basic_action()
{
    int i;
    ElemType e;
    SqList L, L1;
    InitList(L);
    InsElem(L, 1, 1);
    InsElem(L, 3, 2);
    InsElem(L, 1, 3);
    InsElem(L, 5, 4);
    InsElem(L, 4, 5);
    InsElem(L, 2, 6);
    printf(" ���� 1\n");
    printf(" L: "); DispList(L);
    printf( " ���� :%d\n", GetLength(L));
    i = 3;  GetElem(L, i, e);
    printf("  �� %d ��Ԫ�� :%d\n", i, e);
    e = 1;
    printf("  Ԫ�� %d �ǵ� %d ��Ԫ�� \n", e, Locate(L, e));
    i = 4;  printf("  ɾ���� %d ��Ԫ�� \n", i);
    DelElem(L, i);
    printf(" L: "); DispList(L);
    printf(" ���� 2\n");
    int a[] = {2, 5, 4, 5, 6, 5, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    printf("  ���崴�� L1\n");
    CreateList(L1, a, n);
    printf(" L1: ");  DispList(L1);
    int x = 5;
    printf("  ��һ��ֵΪ %d Ԫ�ص�λ���� %d\n", x, Locate(L1, x));
    printf(" ���� L �� L1\n");
    DestroyList(L);
    DestroyList(L1);
}
void expand_action()//��չ
{
}
int main()
{
    basic_action();
    //expand_action();//��չ
    return 0;
}
