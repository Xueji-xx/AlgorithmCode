/*
括号匹配检查，要求键盘输入包含（），{},[]的符号串，实现检查括号是否匹配。要求输入的字符串中要过滤掉不是括号的字符。
2111310110 53-贾少晨 
*/
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
	Initstack(s);//创建栈 
	cout<<"请输入您将要输入的字符串：";
	string str;//输入字符串 
	cin>>str;
	bool flag = true;
	bool flag1 = true;
	bool flag_k = false;
	for(auto x : str){
		if(x != '(' && x != ')' && x != '[' && x != ']' && x != '{' && x != '}')continue;//剔除不是括号的字符 
		push(s,x);
		if(x == ')'){
			pop(s);//弹出右括号 
			if(pop(s) == '(')continue;//左括号匹配 
			else{
				flag = false;
				flag1 = false;
				break;
			}
		}
		else if(x == ']'){
			pop(s);//同上 
			if(pop(s) == '[')continue;//同上 
			else{
				flag = false;
				flag1 = false;
				break;
			}
		}
		else if(x == '}'){
			pop(s);//同上 
			if(pop(s) == '{')continue;//同上 
			else{
				flag = false;
				flag1 = false;
				break;
			}
		}
		flag_k = true;
	}
	if(flag && flag1 && flag_k)cout<<"YES";
	else cout<<"NO";
	return 0;
} 
