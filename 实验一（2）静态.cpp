#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct ListNode{
	char elem[MAXSIZE];
	int length;
}*SqList; 
SqList InitList(){
	SqList L;
	L=(SqList)malloc(MAXSIZE*sizeof(SqList));
	L->length=0; 
	return L;
}
void create_list(SqList L){
	char x ;
	scanf("%c",&x);
	int i=0;	
	while(x != '\n'){
		L->elem[i++]=x;
		L->length++;
		scanf("%c",&x);
	}
}
int Delete(SqList L,int i){
	if(L->length == 0){
	   printf("˳���Ϊ�գ��޷�ɾ��");
	   return 0;	
	}
	if(i<0||i>(L->length-1)){
		printf("ɾ��Ԫ�ص�λ������");
		return 0; 
	}
	if(i>=0 && i<=L->length-1){
		for(int k=i;k<L->length;k++){
			L->elem[k] = L->elem[k+1];//Ԫ��ǰ�� 
		}
		L->length--; 
	}
	return 1;
}
void Standard(SqList L){
	for(int i=0;i<L->length;i++){
		//�Ƿ��ַ� 
		if(L->elem[i]<'a' || L->elem[i]>'z'){
			Delete(L,i);
			i--;
		}
	}
    for(int i=0;i<L->length;i++){
    	for(int j=i+1;j<L->length;j++){
    		if(L->elem[i]==L->elem[j]){
    			Delete(L,j);
    			j--;//ɾ����ʱ�����λ��֮��ȫ����ǰ��һ��λ�ã�����Ҫ���±��һ���±��� 
			}
		}
	}
}
void Output(SqList L){
	for(int i=0;i<L->length;i++){
		printf("%c",L->elem[i]);
	}
	printf("\n");
}
SqList add_list(SqList L1,SqList L2){
	SqList L3 = InitList();
	if(L1->length+L2->length > MAXSIZE){
		printf("Խ��"); 
	}
	int i=0,j=0;
	while((L1->elem[i]!='\0')&&(L2->elem[i]!='\0')){
		L3->elem[j++]=L1->elem[i];
		L3->elem[j++]=L2->elem[i];
		i++;
		L3->length+=2;
	}
	if(L1->elem[i]='\0'){
		for(int j=i;j<L2->length;j++){
			L3->elem[j++]=L2->elem[j];
			L3->length++;
		}
	}
	if(L2->elem[i]=='\0'){
		for(int j=i;j<L1->length;j++){
			L3->elem[j++]=L1->elem[j];
			L3->length++;
	    }
	}
	for(int i=0;i<L3->length;i++){	
		for(int j=i+1;j<L3->length;j++){
			if(L3->elem[j]==L3->elem[i]){
				Delete(L3,j);
				j--;
			}
		}
	}
	return L3;
} 
SqList Supp_list(SqList L){
	char x='a';
	SqList L3 = InitList();
	for(int i=0;i<26;i++){
		L3->elem[i]=x;
		x++; 
		L3->length++;
	}
	for(int j=0;j<L->length;j++){//��L�Ĳ��� 
		for(int k=0;k<26;k++){
			if(L3->elem[k] == L->elem[j]){
				Delete(L3,k);
				k--;
			}
		}
	}
	return L3;
}
int main(){
	printf("1.����L1��");
	SqList L1 = InitList();
	create_list(L1);
	Standard(L1);
	Output(L1);
	printf("\n2.����L2��");
	SqList L2 = InitList();
	create_list(L2);
	Standard(L2);
	Output(L2); 
	int x;
	do{
		printf("\n1.��L1��L2������\n2.��L1������\n3.��L2����\n4.�˳�\n");
		scanf("%d",&x);
		switch(x){
			case 1:{
				printf("L1,L2����Ϊ��");
				Output(add_list(L1,L2));
				break;
			}
			case 2:{
				printf("L1������");
				Output(Supp_list(L1)); 
				break;
			}
			case 3:{
				printf("L2������");
				Output(Supp_list(L2)); 
				break;
			}
			case 4:{
				printf("��ӭ�´�ʹ��"); 
				break;
				}
			default:printf("�������"); 
		}
	}while(x!=4);
}
