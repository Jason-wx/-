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
	   printf("顺序表为空，无法删除");
	   return 0;	
	}
	if(i<0||i>(L->length-1)){
		printf("删除元素的位置有误");
		return 0; 
	}
	if(i>=0 && i<=L->length-1){
		for(int k=i;k<L->length;k++){
			L->elem[k] = L->elem[k+1];//元素前移 
		}
		L->length--; 
	}
	return 1;
}
void Standard(SqList L){
	for(int i=0;i<L->length;i++){
		//非法字符 
		if(L->elem[i]<'a' || L->elem[i]>'z'){
			Delete(L,i);
			i--;
		}
	}
    for(int i=0;i<L->length;i++){
    	for(int j=i+1;j<L->length;j++){
    		if(L->elem[i]==L->elem[j]){
    			Delete(L,j);
    			j--;//删除的时候这个位置之后全部往前移一个位置，我们要对下标减一重新便利 
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
		printf("越界"); 
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
	for(int j=0;j<L->length;j++){//求L的补集 
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
	printf("1.构造L1：");
	SqList L1 = InitList();
	create_list(L1);
	Standard(L1);
	Output(L1);
	printf("\n2.构造L2：");
	SqList L2 = InitList();
	create_list(L2);
	Standard(L2);
	Output(L2); 
	int x;
	do{
		printf("\n1.求L1，L2并集。\n2.求L1补集。\n3.求L2补集\n4.退出\n");
		scanf("%d",&x);
		switch(x){
			case 1:{
				printf("L1,L2并集为：");
				Output(add_list(L1,L2));
				break;
			}
			case 2:{
				printf("L1补集：");
				Output(Supp_list(L1)); 
				break;
			}
			case 3:{
				printf("L2补集：");
				Output(Supp_list(L2)); 
				break;
			}
			case 4:{
				printf("欢迎下次使用"); 
				break;
				}
			default:printf("输入错误"); 
		}
	}while(x!=4);
}
