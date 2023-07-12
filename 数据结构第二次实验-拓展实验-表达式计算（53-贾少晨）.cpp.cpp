/*���ʽ���� ��д����ʵ�֣�ͨ����������һ��������������ʽ��ֻ����+��-��*��/����������������������
2111310110 ���ٳ� 53*/ 



#include<iostream>
#include<stdlib.h>
using namespace std;
#define SDataType char
#define STACK_INIT_SIZE 100
#define STACKUP 10


typedef struct{
	SDataType *base; //ջ��ָ��
	SDataType *top;  //ջ��ָ��
	int StackSize;   //��ǰ�Ѿ�����Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
}stack;

bool Initstack(stack &s){
	s.base = (SDataType *)malloc(STACK_INIT_SIZE * sizeof(SDataType));//�����½ڵ� 
	if(!s.base)return false;//����ʧ�� 
	s.top = s.base;//��ջ 
	s.StackSize = STACK_INIT_SIZE;
	return true;
}

bool push(stack &s,SDataType x){
	SDataType *p;
	if(s.top - s.base == s.StackSize){//ջ������ֹ���� 
		p = (SDataType *)malloc((STACK_INIT_SIZE + STACKUP)*sizeof(SDataType));
		if(!p)return false;//û�пռ� 
		s.base = p;
		s.top = s.base + s.StackSize;
		s.StackSize += STACKUP;
	}
	*(s.top) = x;
	s.top++;
	return true;
}

char pop(stack &s){
	SDataType x;
	if(s.top != s.base){//û�����������ջ��Ԫ�� 
		s.top--;
		x = *(s.top);
	}
	else return '#';//����
	return x; 
}


int main(){
	stack s;
	Initstack(s);//����
	cout<<"����������Ҫ����ı��ʽ��";
	string str;
	cin>>str;
	for(int i = 1;i <= str.length()-1;i ++){
		char x = str[i];
		push(s,x);
		if(x == ')'){
			pop(s);
			
		}
	} 
	return 0;
}
