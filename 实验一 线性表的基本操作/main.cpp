#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;//使用标准模板库的所有定义
#define MaxSize 100//定义线性表的最大长度
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

// 初始化线性表
void InitList(SqList &L)
{
    L.length = 0;
}
// 销毁线性表
void DestroyList(SqList L)
{}
// 求线性表长度
int GetLength(SqList L)
{
    return L.length;
}
// 求线性表中第 i 个元素
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
// 按值查找算法
int Locate(SqList L, ElemType x)
{
    int i = 0;
    while (i < L.length && L.data[i] != x)
        i++;
    if (i >= L.length)  return (0);
    else  return (i+1);
}
// 插入元素
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
// 删除元素
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
// 输出元素值
void DispList(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
}
// 整体创建顺序表
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
    printf(" 测试 1\n");
    printf(" L: "); DispList(L);
    printf( " 长度 :%d\n", GetLength(L));
    i = 3;  GetElem(L, i, e);
    printf("  第 %d 个元素 :%d\n", i, e);
    e = 1;
    printf("  元素 %d 是第 %d 个元素 \n", e, Locate(L, e));
    i = 4;  printf("  删除第 %d 个元素 \n", i);
    DelElem(L, i);
    printf(" L: "); DispList(L);
    printf(" 测试 2\n");
    int a[] = {2, 5, 4, 5, 6, 5, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    printf("  整体创建 L1\n");
    CreateList(L1, a, n);
    printf(" L1: ");  DispList(L1);
    int x = 5;
    printf("  第一个值为 %d 元素的位置是 %d\n", x, Locate(L1, x));
    printf(" 销毁 L 和 L1\n");
    DestroyList(L);
    DestroyList(L1);
}
void expand_action()//拓展
{
}
int main()
{
    basic_action();
    //expand_action();//拓展
    return 0;
}
