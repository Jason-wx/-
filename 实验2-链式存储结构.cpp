#include <stdio.h>
#include <stdlib.h>
typedef struct List{
	int elem;
	struct List *next;
}*SqList;
SqList head_establish_list(int sum){
	SqList head,p;
	int a;
	head = (SqList)malloc(sizeof(SqList));
	head->next = NULL;
	printf("���������:"); 
	for(int i=0;i<sum;i++){
		p=(SqList)malloc(sizeof(SqList));
		scanf("%d",&a);
		p->elem=a;
		p->next=head->next; 
		head->next=p;
	}
	return head;
}
void Delete_elem(SqList L,int min,int max){
	SqList p,q;
	p=L;
	q=L->next;
	while(q->next != NULL){
		if(q->elem>min && q->elem<max){
			p->next=q->next;
			free(q);
			q=p->next;
		}
		else{
			p=p->next;
	    	q=q->next;
		}
     		
	}
}
void Classify_list(SqList L,SqList L1,SqList L2){
	SqList l=L->next;
	int a;
	while(l!=NULL){
		if(l->elem % 2 == 0){
			L1->next=l; 
			L1=L1->next;
			a=1;
		}
		else if(l->elem%2 == 1){
			L2->next=l;
			L2=L2->next;
			a=0;
		}
		l=l->next;
	}
	if(a==0){
	    L1->next=NULL;
	}
    else{
   	    L2->next=NULL;
    }
}
void Output(SqList L){
	SqList p;
	p=L->next;
	while(p!=NULL){
		printf("%d ",p->elem);
		p=p->next;
	}
	printf("\n");
}
int main(){
	int n,min,max;
	printf("���������ȣ�");
	scanf("%d",&n);
	SqList head = head_establish_list(n);
	printf("L����"); 
	Output(head);
	printf("Ҫɾ����������������䣨��������");
	scanf("%d %d",&min,&max);
	while(min>max){
		    printf("�������,���������룺");
		   	scanf("%d %d",&min,&max);
	} 
	Delete_elem(head,min,max);
	printf("�޸ĺõ�L����");
	Output(head);
	SqList L1;
	L1=(SqList)malloc(sizeof(SqList));
	L1->next=NULL;
	SqList L2;
	L2=(SqList)malloc(sizeof(SqList));
	L2->next=NULL;
	Classify_list(head,L1,L2);
	printf("ż��L1����");
	Output(L1);
	printf("����L2����:");
	Output(L2);
}
