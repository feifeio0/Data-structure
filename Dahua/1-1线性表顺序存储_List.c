#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
//存储空间初始分配量 
#define MAXSIZE 20

//值为结果状态代码OK,ERROR 
typedef int status; 
//elemtype类型根据实际情况而定
typedef int elemtype;
//顺序线性表
typedef struct{
	elemtype data[MAXSIZE];//存储数据元素 
	int length;//线性表长度 
}SqList;

status visit(elemtype c){
	printf("%d ",c);
	return OK;	
}

//初始化顺序线性表
status InitList(SqList *L){ 
    L->length=0;
    return OK;
}

//判断顺序线性表L是否为空 
status ListEmpty(SqList L){ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

//重置顺序线性表L为空表
status ClearList(SqList *L){ 
    L->length=0;
    return OK;
}

//返回顺序线性表L中数据元素个数
int ListLength(SqList L){
	return L.length;
}

//用e返回L中第i个数据元素的值
status GetElem(SqList L,int i,elemtype *e){
    if(L.length==0 || i<1 || i>L.length){ 
    	return ERROR;
    } 
    *e=L.data[i-1];
    return OK;
}

//返回e在L中的位置,不存在返回0 
int LocateElem(SqList L,elemtype e){
    int i;
    if (L.length==0){ 
        return 0;
    } 
    for(i=0;i<L.length;i++){
        if (L.data[i]==e){ 
            break;
        }
    }
    if(i>=L.length){ 
        return 0;
    }
    return i+1;
}

//在L中第i个位置之前插入新的数据元素e
status ListInsert(SqList *L,int i,elemtype e){
	int k;
	//L已经满了 
	if (L->length==MAXSIZE){
		return ERROR;
	} 
	//插入位置不合法 
	if (i<1 || i>L->length+1){
		return ERROR;
	}
	//插入位置不在表尾 
	if (i<=L->length){
		//后移数据元素 
		for(k=L->length-1;k>=i-1;k--){
			L->data[k+1]=L->data[k];
		}
	}
	//插入新元素 
	L->data[i-1]=e;
	L->length++;
	return OK;
}

//删除L的第i个数据元素并用e返回其值
status ListDelete(SqList *L,int i,elemtype *e){ 
    int k;
    //线性表为空 
    if (L->length==0){
		return ERROR;
	} 
	//删除位置不合法 
    if (i<1 || i>L->length){
        return ERROR;
    }
    *e=L->data[i-1];
    //删除位置不在表尾 
    if (i<L->length){
    	//前移数据元素 
        for(k=i;k<L->length;k++){
			L->data[k-1]=L->data[k];
		}
    }
    L->length--;
    return OK;
}

//遍历L
status ListTraverse(SqList L){
	int i;
    for(i=0;i<L.length;i++){
        visit(L.data[i]);
    }
    printf("\n");
    return OK;
}

//合并La和Lb两表结果放在La中
//在Lb中找到La中没有的元素添加在La中 
void unionL(SqList *La,SqList Lb){
	int La_len,Lb_len,i;
	elemtype e;
	La_len=ListLength(*La);
	Lb_len=ListLength(Lb);
	for (i=1;i<=Lb_len;i++){
		GetElem(Lb,i,&e);
		if (!LocateElem(*La,e)){
			ListInsert(La,++La_len,e);
		}
	}
}

int main()
{
    SqList L;
	SqList Lb;
    
    elemtype e;
    status i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：L.length=%d\n",L.length);
    //初始化L后：L.length=0
    for(j=1;j<=5;j++){ 
        i=ListInsert(&L,1,j);
    } 
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);
    //在L的表头依次插入1～5后：L.data=5 4 3 2 1 

    printf("L.length=%d \n",L.length);
    //L.length=5 
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);
    //L是否空：i=0(1:是 0:否) 

    i=ClearList(&L);
    printf("清空L后：L.length=%d\n",L.length);
    //清空L后：L.length=0 
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);
    //L是否空：i=1(1:是 0:否) 

    for(j=1;j<=10;j++){ 
        ListInsert(&L,j,j);
    } 
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L); 
    //在L的表尾依次插入1～10后：L.data=1 2 3 4 5 6 7 8 9 10  
    printf("L.length=%d \n",L.length);
	//L.length=10
    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L); 
    //在L的表头插入0后：L.data=0 1 2 3 4 5 6 7 8 9 10 
    printf("L.length=%d \n",L.length);
	//L.length=11
    GetElem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    //第5个元素的值为：4
    for(j=3;j<=4;j++){
        k=LocateElem(L,j);
        if(k)
                printf("第%d个元素的值为%d\n",k,j);
        else
                printf("没有值为%d的元素\n",j);
    }
    

    k=ListLength(L); /* k为表长 */
    for(j=k+1;j>=k;j--){
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

	//构造一个有10个数的Lb
	i=InitList(&Lb);
    for(j=6;j<=15;j++)
        i=ListInsert(&Lb,1,j);

	unionL(&L,Lb);

	printf("依次输出合并了Lb的L的元素：");
    ListTraverse(L); 

    return 0;
}




