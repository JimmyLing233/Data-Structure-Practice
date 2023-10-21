void basic_action()
{
    SqStack st;
    ElemType e;
    printf("初始化栈st\n");
    InitStack(st);
    printf("栈%s\n",StackEmpty(st)==1?"空":"非空");
    printf("a进栈\n");
    Push(st,'a');
    printf("b进栈\n");
    Push(st,'b');
    printf("c进栈\n");
    Push(st,'c');
    printf("d进栈\n");
    Push(st,'d');
    printf("栈%s\n",StackEmpty(st)==1?"空":"非空");
    GetTop(st,e);
    printf("栈顶元素为%c\n",e);
    printf("出栈次序为：");
    while(!StackEmpty(st))
    {
        Pop(st,e);//出栈，元素e为出栈的元素，出栈后栈顶指针减1，指向新的栈顶元素，原栈顶元素被覆盖
        printf("%c",e);//输出出栈的元素
    }
    printf("\n销毁栈st\n");
    DestroyStack(st);
}

void expand_action()
{
    SqStack st;
    ElemType e;
    printf("初始化栈st\n");
    InitStack(st);
    printf("元素1，2，2，1，2，3依次进栈\n");
    Push(st,'1');
    Push(st,'2');
    Push(st,'2');
    Push(st,'1');
    Push(st,'2');
    Push(st,'3');
    printf("删除所有元素2\n");
    while(!StackEmpty(st))
    {
        Pop(st,e);
        if(e!='2')
            printf("%c",e);
    }
    printf("\n销毁栈st\n");
    DestroyStack(st);
}

int main()
{
    basic_action();
    printf("\n");
    expand_action();
    return 0;
}
