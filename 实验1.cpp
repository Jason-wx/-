#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct ListNode{
	char *elem;
	int length;
	int listsize;
}*SqList; 
//初始化 
SqList create_list(){
	SqList L;
    L=(SqList)malloc(sizeof(struct ListNode));
    L->length=0;
    return L;
}
//插入
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
//删除顺序表指定位置的元素 
int Delete(SqList L,int i){
	if(L->length == 0){
	   printf("顺序表为空，无法删除");
	   return 0;	
	}
	if(i<1||i>(L->length)){
		printf("删除元素的位置有误");
		return 0; 
		if(i>=1 && i<=L->length){
		for(int k=i;k<L->length;k++){
			L->elem[k-1] = L->elem[k];//元素前移 
		}
		L->length--; 
	}
	}
	
} 
//自动滤去重复或者不法字符 
void filter_list(SqList L){
	int i,j;
	for(i=0;i<L->length;i++){//b不法字符 
		if(L->elem[i]<'A' || L->elem[i]>'Z');
		Delete(L,i);
	}
	for(i=1;i<L->length;i++){
		for(j=0;j<i;j++){//重复字符 
			if(L->elem[i] == L->elem[j]){
				Delete(L,i);
			}
		}
	}
} 
//两顺序表并 
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
//求补集
SqList Supp_set(SqList L){
	SqList L2 = create_list();
	char x='a';//构造一个全集出来 
	int i=1;
	while('A' <= x && x <= 'Z') {
		ListInsert(L2,++i,++x); 
	}
	for(int j=0;j<L->length;j++){//求L的补集 
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
	printf("1.建立L1顺序表"); 
	SqList L1 = create_list();
	printf("请顺序表的长度：");
	scanf("%d",&x);
	printf("请输入各字母：");
	for(int i=1;i<=x;i++){
		scanf("%c ",&e);
		ListInsert(L1,i,e);
	} 
	filter_list(L1);
	printf("2.建立L2顺序表"); 
	SqList L2 = create_list();
	printf("请顺序表的长度：");
	scanf("%d",&x);
	printf("请输入各字母：");
	for(int i=1;i<=x;i++){
		scanf("%c ",&e);
		ListInsert(L2,i,e);
	} 
	filter_list(L2);
	int n;
	do{
		printf("1.L1,L2的并集\n2.L1的补集\n3.L2的补集\n4.退出");
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
				printf("欢迎下次使用"); 
				break;
			} 
			default:printf("输入错误！"); 
		}  
	}while(n!=4);
} 
