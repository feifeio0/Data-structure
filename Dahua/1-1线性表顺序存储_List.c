#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
//�洢�ռ��ʼ������ 
#define MAXSIZE 20

//ֵΪ���״̬����OK,ERROR 
typedef int status; 
//elemtype���͸���ʵ���������
typedef int elemtype;
//˳�����Ա�
typedef struct{
	elemtype data[MAXSIZE];//�洢����Ԫ�� 
	int length;//���Ա��� 
}SqList;

status visit(elemtype c){
	printf("%d ",c);
	return OK;	
}

//��ʼ��˳�����Ա�
status InitList(SqList *L){ 
    L->length=0;
    return OK;
}

//�ж�˳�����Ա�L�Ƿ�Ϊ�� 
status ListEmpty(SqList L){ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

//����˳�����Ա�LΪ�ձ�
status ClearList(SqList *L){ 
    L->length=0;
    return OK;
}

//����˳�����Ա�L������Ԫ�ظ���
int ListLength(SqList L){
	return L.length;
}

//��e����L�е�i������Ԫ�ص�ֵ
status GetElem(SqList L,int i,elemtype *e){
    if(L.length==0 || i<1 || i>L.length){ 
    	return ERROR;
    } 
    *e=L.data[i-1];
    return OK;
}

//����e��L�е�λ��,�����ڷ���0 
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

//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e
status ListInsert(SqList *L,int i,elemtype e){
	int k;
	//L�Ѿ����� 
	if (L->length==MAXSIZE){
		return ERROR;
	} 
	//����λ�ò��Ϸ� 
	if (i<1 || i>L->length+1){
		return ERROR;
	}
	//����λ�ò��ڱ�β 
	if (i<=L->length){
		//��������Ԫ�� 
		for(k=L->length-1;k>=i-1;k--){
			L->data[k+1]=L->data[k];
		}
	}
	//������Ԫ�� 
	L->data[i-1]=e;
	L->length++;
	return OK;
}

//ɾ��L�ĵ�i������Ԫ�ز���e������ֵ
status ListDelete(SqList *L,int i,elemtype *e){ 
    int k;
    //���Ա�Ϊ�� 
    if (L->length==0){
		return ERROR;
	} 
	//ɾ��λ�ò��Ϸ� 
    if (i<1 || i>L->length){
        return ERROR;
    }
    *e=L->data[i-1];
    //ɾ��λ�ò��ڱ�β 
    if (i<L->length){
    	//ǰ������Ԫ�� 
        for(k=i;k<L->length;k++){
			L->data[k-1]=L->data[k];
		}
    }
    L->length--;
    return OK;
}

//����L
status ListTraverse(SqList L){
	int i;
    for(i=0;i<L.length;i++){
        visit(L.data[i]);
    }
    printf("\n");
    return OK;
}

//�ϲ�La��Lb����������La��
//��Lb���ҵ�La��û�е�Ԫ�������La�� 
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
    printf("��ʼ��L��L.length=%d\n",L.length);
    //��ʼ��L��L.length=0
    for(j=1;j<=5;j++){ 
        i=ListInsert(&L,1,j);
    } 
    printf("��L�ı�ͷ���β���1��5��L.data=");
    ListTraverse(L);
    //��L�ı�ͷ���β���1��5��L.data=5 4 3 2 1 

    printf("L.length=%d \n",L.length);
    //L.length=5 
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
    //L�Ƿ�գ�i=0(1:�� 0:��) 

    i=ClearList(&L);
    printf("���L��L.length=%d\n",L.length);
    //���L��L.length=0 
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
    //L�Ƿ�գ�i=1(1:�� 0:��) 

    for(j=1;j<=10;j++){ 
        ListInsert(&L,j,j);
    } 
    printf("��L�ı�β���β���1��10��L.data=");
    ListTraverse(L); 
    //��L�ı�β���β���1��10��L.data=1 2 3 4 5 6 7 8 9 10  
    printf("L.length=%d \n",L.length);
	//L.length=10
    ListInsert(&L,1,0);
    printf("��L�ı�ͷ����0��L.data=");
    ListTraverse(L); 
    //��L�ı�ͷ����0��L.data=0 1 2 3 4 5 6 7 8 9 10 
    printf("L.length=%d \n",L.length);
	//L.length=11
    GetElem(L,5,&e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);
    //��5��Ԫ�ص�ֵΪ��4
    for(j=3;j<=4;j++){
        k=LocateElem(L,j);
        if(k)
                printf("��%d��Ԫ�ص�ֵΪ%d\n",k,j);
        else
                printf("û��ֵΪ%d��Ԫ��\n",j);
    }
    

    k=ListLength(L); /* kΪ�� */
    for(j=k+1;j>=k;j--){
    	i=ListDelete(&L,j,&e); /* ɾ����j������ */
        if(i==ERROR)
                printf("ɾ����%d������ʧ��\n",j);
        else
                printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
    }
    printf("�������L��Ԫ�أ�");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* ɾ����5������ */
    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);

    printf("�������L��Ԫ�أ�");
    ListTraverse(L); 

	//����һ����10������Lb
	i=InitList(&Lb);
    for(j=6;j<=15;j++)
        i=ListInsert(&Lb,1,j);

	unionL(&L,Lb);

	printf("��������ϲ���Lb��L��Ԫ�أ�");
    ListTraverse(L); 

    return 0;
}




