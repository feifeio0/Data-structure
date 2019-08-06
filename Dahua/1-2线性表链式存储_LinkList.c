#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h> 

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

//ֵΪ���״̬����OK,ERROR 
typedef int status; 
//elemtype���͸���ʵ���������
typedef int elemtype;
//����Ľ��Node
typedef struct Node{
    elemtype data;
    struct Node *next;
}Node;
//��������LinkList
typedef struct Node *LinkList;

status visit(elemtype c){
    printf("%d ",c);
    return OK;
}

//��ʼ������
status InitList(LinkList *L){
	//Lָ��ͷ��� 
	//ǿ������ת��+����ռ� 
    *L=(LinkList)malloc(sizeof(Node));
    //�洢����ʧ�� 
    if(!(*L)){
    	return ERROR;
    }
    //ָ����Ϊ�� 
    (*L)->next=NULL;
    return OK;
}

//�ж�����L�Ƿ�Ϊ�� 
status ListEmpty(LinkList L){ 
    if(L->next){
        return FALSE;
    } 
    else{ 
        return TRUE;
    }
}

//����LΪ�ձ�
status ClearList(LinkList *L){ 
	LinkList p,q;
	//pָ���һ����� 
	p=(*L)->next;
	//ѭ������β 
	while(p){
		q=p->next;
		free(p);
		p=q;
	}
	//ͷ���ָ�����ÿ� 
	(*L)->next=NULL;
	return OK;
}

//����L������Ԫ�ظ���
int ListLength(LinkList L){
    int i=0;
    //pָ���һ����� 
    LinkList p=L->next;
    while(p){
        i++;
        p=p->next;
    }
    return i;
}

//��e����L�е�i������Ԫ�ص�ֵ
status GetElem(LinkList L,int i,elemtype *e)
{
	//������j 
	int j;
	//����һ�����p 
	LinkList p;
	//��pָ������ĵ�һ����� 
	p = L->next;
	j = 1;
	//Ѱ�ҵ�i����� 
	while (p && j<i){
		//��p����ָ 
		p = p->next;
		++j;
	}
	//��i��Ԫ�ز����� 
	if ( !p || j>i ){ 
		return ERROR;
	}
	//��ȡi��Ԫ�ص����� 
	*e = p->data;   /*  ȡ��i��Ԫ�ص����� */
	return OK;
}

//����e��L�е�λ��,�����ڷ���0 
int LocateElem(LinkList L,elemtype e){
    int i=0;
    LinkList p=L->next;
    while(p){
        i++;
        //�ҵ��� 
        if(p->data==e){ 
            return i;
        }
        p=p->next;
    }
    return 0;
}

//��L�е�i��λ��֮ǰ��������Ԫ��e
status ListInsert(LinkList *L,int i,elemtype e){ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	//Ѱ�ҵ�i����� 
	while (p && j < i){
		p = p->next;
		++j;
	} 
	//��i��Ԫ�ز����� 
	if (!p || j > i){
		return ERROR;
	} 
	//�����½�� 
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	//��p�ĺ�̽�㸳ֵ��s�ĺ��
	s->next = p->next;
	//��s��ֵ��p�ĺ��
	p->next = s;
	return OK;
}

//ɾ����i������Ԫ�ز���e������ֵ
status ListDelete(LinkList *L,int i,elemtype *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	//Ѱ�ҵ�i��Ԫ�� 
	while (p->next && j < i){
        p = p->next;
        ++j;
	}
	//��i��Ԫ�ز����� 
	if (!(p->next) || j > i){ 
	    return ERROR;
	}
	q = p->next;
	//��q�ĺ�̸�ֵ��p�ĺ��
	p->next = q->next;
	//��q����е����ݸ�e
	*e = q->data;
	//��ϵͳ���մ˽�㣬�ͷ��ڴ� 
	free(q);
	return OK;
}

//�����������
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

//ͷ�巨����n��Ԫ�ش�ͷ���ĵ�����L
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	//��ǰʱ��ֵÿ�ζ���ͬ 
	//��֤��һ�������� 
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	//����һ����ͷ���ĵ����� 
	(*L)->next = NULL;
	for(i=0; i<n; i++){
		//�����½�� 
		p = (LinkList)malloc(sizeof(Node));
		//�������1-100������
		p->data = rand()%100+1;
		p->next = (*L)->next;    
		//���뵽��ͷ 
		(*L)->next = p;
	}
}

//β�巨����n��Ԫ�ش�ͷ���ĵ�����L
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	//rΪָ��β���Ľ�� 
	int i;
	//��ʼ�����������
	srand(time(0));
	//LΪ�������� 
	*L = (LinkList)malloc(sizeof(Node));
	r=*L;
	for (i=0; i<n; i++){
		//�����½�� 
		p = (Node *)malloc(sizeof(Node));
		//�������1-100������ 
		p->data = rand()%100+1;
		//����β�ն˽���ָ��ָ���½��
		r->next=p;
		//����ǰ���½�㶨��Ϊ��β�ն˽�� 
		r = p;
	}
	//��ʾ��ǰ������� 
	r->next = NULL;
}

int main()
{        
    LinkList L;
    elemtype e;
    status i;
    int j,k;
    i=InitList(&L);
    printf("��ʼ��L��ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("��L�ı�ͷ���β���1��5��L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

    i=ClearList(&L);
    printf("���L��ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("��L�ı�β���β���1��10��L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("��L�ı�ͷ����0��L.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("��%d��Ԫ�ص�ֵΪ%d\n",k,j);
            else
                    printf("û��ֵΪ%d��Ԫ��\n",j);
    }
    

    k=ListLength(L); /* kΪ�� */
    for(j=k+1;j>=k;j--)
    {
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

    i=ClearList(&L);
    printf("\n���L��ListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("���崴��L��Ԫ��(ͷ�巨)��");
    ListTraverse(L); 
    
    i=ClearList(&L);
    printf("\nɾ��L��ListLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("���崴��L��Ԫ��(β�巨)��");
    ListTraverse(L); 


    return 0;
}




