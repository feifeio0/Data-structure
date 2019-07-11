/*要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。*/ 
/*L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；
函数Merge要将L1和L2合并为一个非递减的整数序列。
应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。
*/ 
/*
输入样例：
3
1 3 5
5
2 4 6 8 10
输出样例：
1 2 3 4 5 6 8 10 
NULL
NULL
*/ 
#include <stdio.h>
#include <stdlib.h>
 
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;
 
List Read(); /*细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL   （同上）*/
 
List Merge( List L1, List L2 );
 
int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
 
/* 你的代码将被嵌在这里 */
List Read()
{
    int n;
    scanf("%d",&n);
    List L=(List)malloc(sizeof(PtrToNode));   ///申请一个头结点
    L->Next = NULL;        ///头指针为空
    if(n)    ///当n不是0时
    {
        List r=L;     ///r是一个中间变量的节点
        for(int i=0;i<n;i++) 
        {
            List p=(List)malloc(sizeof(struct Node));
            scanf("%d",&(p->Data));    ///尾插法
            r->Next = p;
            r = p;
        }
        r->Next = NULL;         
    }
    return L;
}
 
void Print( List L )
{
   List p=L->Next;
   if(p)
   {
       List r;
       r = L;
       while(r->Next)
       {
           r = r->Next;
           printf("%d ",r->Data);
       }
   }
   else
   {
       printf("NULL");
   }
   printf("\n");
}
 
List Merge( List L1, List L2 )   ///合并函数  重点要写的函数！
{
    List pa,pb,pc,L;
    L = (List)malloc(sizeof(struct Node));
    pa=L1->Next;
    pb=L2->Next;
    pc = L;
    while(pa && pb)
    {
        if(pa->Data <= pb->Data)
        {
            pc->Next = pa;
            pc = pa;
            pa = pa->Next;
        }
        else
        {
            pc->Next = pb;
            pc = pb;
            pb = pb->Next;
        }
    }
    pc->Next = pa ? pa : pb;
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}

