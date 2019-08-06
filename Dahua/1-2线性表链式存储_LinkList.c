#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h> 

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

//值为结果状态代码OK,ERROR 
typedef int status; 
//elemtype类型根据实际情况而定
typedef int elemtype;
//链表的结点Node
typedef struct Node{
    elemtype data;
    struct Node *next;
}Node;
//定义链表LinkList
typedef struct Node *LinkList;

status visit(elemtype c){
    printf("%d ",c);
    return OK;
}

//初始化链表
status InitList(LinkList *L){
	//L指向头结点 
	//强制类型转换+分配空间 
    *L=(LinkList)malloc(sizeof(Node));
    //存储分配失败 
    if(!(*L)){
    	return ERROR;
    }
    //指针域为空 
    (*L)->next=NULL;
    return OK;
}

//判断链表L是否为空 
status ListEmpty(LinkList L){ 
    if(L->next){
        return FALSE;
    } 
    else{ 
        return TRUE;
    }
}

//重置L为空表
status ClearList(LinkList *L){ 
	LinkList p,q;
	//p指向第一个结点 
	p=(*L)->next;
	//循环到表尾 
	while(p){
		q=p->next;
		free(p);
		p=q;
	}
	//头结点指针域置空 
	(*L)->next=NULL;
	return OK;
}

//返回L中数据元素个数
int ListLength(LinkList L){
    int i=0;
    //p指向第一个结点 
    LinkList p=L->next;
    while(p){
        i++;
        p=p->next;
    }
    return i;
}

//用e返回L中第i个数据元素的值
status GetElem(LinkList L,int i,elemtype *e)
{
	//计数器j 
	int j;
	//声明一个结点p 
	LinkList p;
	//让p指向链表的第一个结点 
	p = L->next;
	j = 1;
	//寻找第i个结点 
	while (p && j<i){
		//让p往下指 
		p = p->next;
		++j;
	}
	//第i个元素不存在 
	if ( !p || j>i ){ 
		return ERROR;
	}
	//获取i个元素的数据 
	*e = p->data;   /*  取第i个元素的数据 */
	return OK;
}

//返回e在L中的位置,不存在返回0 
int LocateElem(LinkList L,elemtype e){
    int i=0;
    LinkList p=L->next;
    while(p){
        i++;
        //找到了 
        if(p->data==e){ 
            return i;
        }
        p=p->next;
    }
    return 0;
}

//在L中第i个位置之前插入数据元素e
status ListInsert(LinkList *L,int i,elemtype e){ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	//寻找第i个结点 
	while (p && j < i){
		p = p->next;
		++j;
	} 
	//第i个元素不存在 
	if (!p || j > i){
		return ERROR;
	} 
	//生成新结点 
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	//将p的后继结点赋值给s的后继
	s->next = p->next;
	//将s赋值给p的后继
	p->next = s;
	return OK;
}

//删除第i个数据元素并用e返回其值
status ListDelete(LinkList *L,int i,elemtype *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	//寻找第i个元素 
	while (p->next && j < i){
        p = p->next;
        ++j;
	}
	//第i个元素不存在 
	if (!(p->next) || j > i){ 
	    return ERROR;
	}
	q = p->next;
	//将q的后继赋值给p的后继
	p->next = q->next;
	//将q结点中的数据给e
	*e = q->data;
	//让系统回收此结点，释放内存 
	free(q);
	return OK;
}

//遍历输出链表
status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p){
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}

//头插法创建n个元素带头结点的单链表L
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	//当前时间值每次都不同 
	//保证不一样的种子 
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	//创建一个带头结点的单链表 
	(*L)->next = NULL;
	for(i=0; i<n; i++){
		//生成新结点 
		p = (LinkList)malloc(sizeof(Node));
		//随机生成1-100的数字
		p->data = rand()%100+1;
		p->next = (*L)->next;    
		//插入到表头 
		(*L)->next = p;
	}
}

//尾插法创建n个元素带头结点的单链表L
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	//r为指向尾部的结点 
	int i;
	//初始化随机数种子
	srand(time(0));
	//L为整个链表 
	*L = (LinkList)malloc(sizeof(Node));
	r=*L;
	for (i=0; i<n; i++){
		//生成新结点 
		p = (Node *)malloc(sizeof(Node));
		//随机生成1-100的数字 
		p->data = rand()%100+1;
		//将表尾终端结点的指针指向新结点
		r->next=p;
		//将当前的新结点定义为表尾终端结点 
		r = p;
	}
	//表示当前链表结束 
	r->next = NULL;
}

int main()
{        
    LinkList L;
    elemtype e;
    status i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("第%d个元素的值为%d\n",k,j);
            else
                    printf("没有值为%d的元素\n",j);
    }
    

    k=ListLength(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* 删除第j个数据 */
            if(i==ERROR)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverse(L); 

    i=ClearList(&L);
    printf("\n清空L后：ListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("整体创建L的元素(头插法)：");
    ListTraverse(L); 
    
    i=ClearList(&L);
    printf("\n删除L后：ListLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("整体创建L的元素(尾插法)：");
    ListTraverse(L); 


    return 0;
}




