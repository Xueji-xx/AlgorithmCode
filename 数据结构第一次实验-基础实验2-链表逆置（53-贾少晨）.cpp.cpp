/*��д����ʵ�֣�
1����֪�д�д�ַ����ɵ����Ա�LA�洢�ڵ������У���������ʵ�����á� �����������µĽ�㣩
2������Ҫ������������������û����룬���ֱ���ʾ������ǰ�����ú�ĵ������д�д�ַ������С�
2111310110 53-���ٳ�  
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
//������ 
void InitList(LinkList &L){
	L = (LinkList)malloc(sizeof(Node));
	(L) ->next = NULL;
}
//����ڵ� 
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
//�������� 
void reverse(LinkList &L){
	Node *p,*s;
	p = L->next;
	L->next = NULL;
	while(p){
		//pΪ��ǰ���ڴ���Ľڵ� 
		s = p;//��¼��ǰ�ڵ� 
		p = p->next;//�ƶ�����һ��������Ľڵ� 
		//���ýڵ���뵽�Ѿ����õ������� 
		s->next = L->next;//�Ѿ����õ�����ĵ�һ�ڵ� 
		L ->next = s;//���½���һ�ڵ����ó� s 
	}
}
//��ӡ 
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
	cout<<"����������Ҫ����������Ľڵ����:"; 
	int n;
	cin>>n;
	cout<<"����������Ҫ��ӵĽڵ㣺";
	for(int i = 1;i <= n;i ++){
		ElemType e;
		cin>>e;
		Insert(L,i,e);
	}
	cout<<"ԭ����:";
	Linkprint(L);
	reverse(L);
	cout<<"�������ã�"; 
	Linkprint(L);
	return 0;
}
