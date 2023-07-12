/*编写程序实现：
1、巳知有大写字符构成的线性表LA存储在单链表中，将单链表实现逆置。 （即不增加新的结点）
2、程序要求单链表的数据内容由用户输入，并分别显示出逆置前和逆置后的单链表中大写字符的序列。
2111310110 53-贾少晨  
*/


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef char ElemType;

struct Node{
	ElemType data;
	struct Node *next;
};

typedef struct Node *LinkList;
//链表创建 
void InitList(LinkList &L){
	L = (LinkList)malloc(sizeof(Node));
	(L) ->next = NULL;
}
//插入节点 
int Insert(LinkList &L,int i,ElemType e){
	LinkList p,s;
	p = L;
	int cnt = 1;
	while(p && cnt < i){
		cnt++;
		p = p->next;
	}
	if(!p)return -1;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}
//链表逆置 
void reverse(LinkList &L){
	Node *p,*s;
	p = L->next;
	L->next = NULL;
	while(p){
		//p为当前正在处理的节点 
		s = p;//记录当前节点 
		p = p->next;//移动到下一个待处理的节点 
		//将该节点插入到已经逆置的链表当中 
		s->next = L->next;//已经逆置的链表的第一节点 
		L ->next = s;//重新将第一节点设置成 s 
	}
}
//打印 
void Linkprint(LinkList L){
	LinkList p = L->next;
	while(p){
		cout<<p->data<<' ';
		p = p->next;
	}
	cout<<endl;
}



int main(){
	LinkList L;
	InitList(L);
	cout<<"请输入您将要创建的链表的节点个数:"; 
	int n;
	cin>>n;
	cout<<"请输入您想要添加的节点：";
	for(int i = 1;i <= n;i ++){
		ElemType e;
		cin>>e;
		Insert(L,i,e);
	}
	cout<<"原链表:";
	Linkprint(L);
	reverse(L);
	cout<<"链表逆置："; 
	Linkprint(L);
	return 0;
}
