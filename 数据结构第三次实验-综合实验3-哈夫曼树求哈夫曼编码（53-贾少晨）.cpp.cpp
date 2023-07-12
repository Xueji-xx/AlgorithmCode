/*
利用Huffman树求Huffman编码，要求终端输入各字符的频率或频度，输出每个字符所对应的编码。
53 贾少晨 2111310110
*/ 

#include<bits/stdc++.h>
using namespace std;

typedef struct {
	int weight;
	int parent,lcd,rcd;
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;

void Select(HuffmanTree HT,int end,int *s1,int *s2){
	int min1,min2;//保证min1 < min2
	//找到一个双亲节点为 0 的点，即未被使用过的新节点
	int i = 1;
	while(HT[i].parent != 0 && i <= end)i++;
	//对min1进行赋值，然后查找下一个节点
	min1 = HT[i].weight;
	*s1 = i;
	i++;
	//查找下一个节点
	while(HT[i].parent != 0 && i <= end)i++;
	//比较两个节点的权值并进行赋值更新
	if(HT[i].weight < min1){
		min2 = min1;
		*s2 = *s1;
		min1 = HT[i].weight;
		*s1 = i;
	} 
	else{
		min2 = HT[i].weight;
		*s2 = i;
	}
	//对剩下的节点进行判断并更新数据
	for(int j = i + 1;j <= end;j ++){
		if(HT[j].parent != 0)continue;//找到双亲节点为 0 的节点
		if(HT[j].weight < min1){
			min2 = min1;
			min1 = HT[j].weight;
			*s2 = *s1;
			*s1 = j;
		} 
		else if(HT[j].weight > min1 && HT[j].weight < min2){
			min2 = HT[j].weight;
			*s2 = j;
		}
	} 
}

void CreatHuffmanTree(HuffmanTree& HT,int n){
	if(n <= 1)return;//无法构成哈夫曼树
	int m = 2 * n - 1;
	//初始化 
	HT = new HTNode[m+1]; //0单元号未用，下标从1开始 
	for(int i = 1;i <= m;i ++){
		HT[i].parent = 0;
		HT[i].lcd = 0;
		HT[i].rcd = 0;
	}
	cout<<"请输入前n个点的权值:" ;
	for(int i = 1;i <= n;i ++)cin>>HT[i].weight;//输入前 n 个点的权值 
	
	//造树
	for(int i = n+1;i <= m;i ++){
		//选出两个权值最小的点进行操作 
		int s1 = 0,s2 = 0;
		Select(HT,i-1,&s1,&s2);
		//保证 s1 < s2 并构建新的节点
		HT[s1].parent = i;HT[s2].parent = i;
		HT[i].lcd = s1;
		HT[i].rcd = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;//权值为两个节点的权值之和 
	} 
} 

void CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n){
	int start,c,f;
	HC = new char*[n+1];      //下表从1开始，分配存储n个字符编码的编码表空间
	char *cd = new char[n];//分配临时内存空间给动态数组空间 
	cd[n-1] = '\0';
	for(int i = 1;i <= n;i ++){//逐个字符求哈夫曼编码
		start = n-1;//指向编码结束的位置
		c = i;f = HT[c].parent;//指向当前节点 c 的双亲节点 
		while(f != 0){
			start--;//开始回溯 
			if(HT[f].lcd == c)cd[start] = '0';//如果 c 是 f 的左孩子，那么就生成 0
			else cd[start] = '1';//如果 c 是 f 的右孩子，那么就生成 1
			c = f;f = HT[f].parent;//继续向上回溯 
		}
		HC[i] = new char[n-start];//为当前第 i 个字符进行编码
		strcpy(HC[i],&cd[start]); 
	}
	delete cd;
}

/*
测试数据
6
45 13 12 16 9 5
预期结果 
A:0
B:101
C:100
D:111
E:1101
F:1100
*/ 

int main(){
	HuffmanTree HT;
	HuffmanCode HC;
	int n;
	cout<<"请输入你将要输入的字符频度个数：";
	cin>>n;
	CreatHuffmanTree(HT,n);
	CreatHuffmanCode(HT,HC,n);
	cout<<"求得的哈夫曼编码为(默认按照从A - Z进行排列):"<<endl;
	for(int i = 1;i <= n;i ++)cout<<char('A'-1+i)<<": "<<HC[i]<<endl; 
	return 0;
}
