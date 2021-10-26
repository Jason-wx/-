#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct ListNode{
	char *elem;
	int length;
	int listsize;
}*SqList; 
//��ʼ�� 
SqList create_list(){
	SqList L;
    L=(SqList)malloc(sizeof(struct ListNode));
    L->length=0;
    return L;
}
//����
int ListInsert(SqList L,int i,char e){
    int k;
    if(L->length==MAXSIZE){
        return 0;
    }
    if(i<1||i>L->length+1){
        return 0;
    }
    if(i<=L->length){
        for(k=L->length-1;k>=i-1;k--){
            L->elem[k+1]=L->elem[k];
        }
    }
    L->elem[i-1]=e;
    L->length++;
    return 1;
} 
//ɾ��˳���ָ��λ�õ�Ԫ�� 
int Delete(SqList L,int i){
	if(L->length == 0){
	   printf("˳���Ϊ�գ��޷�ɾ��");
	   return 0;	
	}
	if(i<1||i>(L->length)){
		printf("ɾ��Ԫ�ص�λ������");
		return 0; 
		if(i>=1 && i<=L->length){
		for(int k=i;k<L->length;k++){
			L->elem[k-1] = L->elem[k];//Ԫ��ǰ�� 
		}
		L->length--; 
	}
	}
	
} 
//�Զ���ȥ�ظ����߲����ַ� 
void filter_list(SqList L){
	int i,j;
	for(i=0;i<L->length;i++){//b�����ַ� 
		if(L->elem[i]<'A' || L->elem[i]>'Z');
		Delete(L,i);
	}
	for(i=1;i<L->length;i++){
		for(j=0;j<i;j++){//�ظ��ַ� 
			if(L->elem[i] == L->elem[j]){
				Delete(L,i);
			}
		}
	}
} 
//��˳��� 
SqList add_twolist(SqList L1,SqList L2){
	SqList L3=create_list();
	int k=0;
	while(k<(L1->length+L2->length)){
		for(int i=0;i<L1->length && i<L2->length;i++){
			ListInsert(L3,++k,L1->elem[i]);
			ListInsert(L3,++k,L1->elem[i]);
		}
		if(k<L1->length){
			for(int j=k;k<L1->length;j++){
				ListInsert(L3,++k,L1->elem[j]);
			}
		}
		if(k<L2->length){
			for(int j=k;k<L2->length;j++){
				ListInsert(L3,++k,L2->elem[j]);
			}
		}
	} 
	return L3;
} 
//�󲹼�
SqList Supp_set(SqList L){
	SqList L2 = create_list();
	char x='a';//����һ��ȫ������ 
	int i=1;
	while('A' <= x && x <= 'Z') {
		ListInsert(L2,++i,++x); 
	}
	for(int j=0;j<L->length;j++){//��L�Ĳ��� 
		for(int k=0;k<26;k++){
			if(L2->elem[k] == L->elem[j]){
				Delete(L2,++k);
			}
		}
	}
	return L2;
} 
int main(){
	int x;
	char e;
	printf("1.����L1˳���"); 
	SqList L1 = create_list();
	printf("��˳���ĳ��ȣ�");
	scanf("%d",&x);
	printf("���������ĸ��");
	for(int i=1;i<=x;i++){
		scanf("%c ",&e);
		ListInsert(L1,i,e);
	} 
	filter_list(L1);
	printf("2.����L2˳���"); 
	SqList L2 = create_list();
	printf("��˳���ĳ��ȣ�");
	scanf("%d",&x);
	printf("���������ĸ��");
	for(int i=1;i<=x;i++){
		scanf("%c ",&e);
		ListInsert(L2,i,e);
	} 
	filter_list(L2);
	int n;
	do{
		printf("1.L1,L2�Ĳ���\n2.L1�Ĳ���\n3.L2�Ĳ���\n4.�˳�");
		scanf("%d",&n);
		switch(n){
			case 1:{
				add_twolist(L1,L2);
				break;
			}
			case 2:{
				SqList L1_supp = Supp_set(L1);
				break;
			}
			case 3:{
				SqList L2_supp = Supp_set(L2);
				break;
			}
			case 4:{
				printf("��ӭ�´�ʹ��"); 
				break;
			} 
			default:printf("�������"); 
		}  
	}while(n!=4);
} 
