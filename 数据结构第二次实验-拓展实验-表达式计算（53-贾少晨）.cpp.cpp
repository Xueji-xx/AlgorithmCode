/*表达式计算 编写程序实现：通过键盘输入一个简单四则运算表达式（只包含+、-、*、/，运算符），输出计算结果。
2111310110 贾少晨 53*/ 



#include<iostream>
#include<stdlib.h>
using namespace std;
#define SDataType char
#define STACK_INIT_SIZE 100
#define STACKUP 10


typedef struct{
	SDataType *base; //栈底指针
	SDataType *top;  //栈顶指针
	int StackSize;   //当前已经分配的存储空间，以元素为单位 
}stack;

bool Initstack(stack &s){
	s.base = (SDataType *)malloc(STACK_INIT_SIZE * sizeof(SDataType));//创建新节点 
	if(!s.base)return false;//创建失败 
	s.top = s.base;//空栈 
	s.StackSize = STACK_INIT_SIZE;
	return true;
}

bool push(stack &s,SDataType x){
	SDataType *p;
	if(s.top - s.base == s.StackSize){//栈满，防止上溢 
		p = (SDataType *)malloc((STACK_INIT_SIZE + STACKUP)*sizeof(SDataType));
		if(!p)return false;//没有空间 
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
	if(s.top != s.base){//没有溢出，弹出栈顶元素 
		s.top--;
		x = *(s.top);
	}
	else return '#';//下溢
	return x; 
}


int main(){
	stack s;
	Initstack(s);//创建
	cout<<"请输入你需要计算的表达式：";
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
