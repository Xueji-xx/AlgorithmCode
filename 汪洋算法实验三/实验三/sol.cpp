#include <bits/stdc++.h>
using namespace std;

map<string,int> mp;
vector<pair<string,int>> v;

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
	for(int i = 1;i <= n;i ++)HT[i].weight = v[i].second;
	
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


bool cmp(const pair<string,int> a,pair<string,int>b){
	return a.second>b.second;
}

vector<int> Transform(int n)
{
    vector<int>m;
    if(n == 0)m.push_back(0);
    while(n){
    	m.push_back(n & 1);
    	n >>= 1;
	} 
    return m;
}

int main(){
	//一个苹果和一个香蕉。
    freopen("data.txt","r+",stdin);
    string s;
    cin >> s;
    for(int i = 0;i < s.length();i += 2){
    	string t = s.substr(i,2);
    	mp[t] ++;
	}
	v.push_back({"0",0});
	for(auto i = mp.begin();i != mp.end();i ++){
		v.insert(v.begin()+1,{i->first,i->second});
	}
	
	int p = 0;
	long long sum = 0;
	sort(v.begin()+1,v.end(),cmp);
	
	/*for(auto i : v){
		cout << i.first << ' ' << i.second << endl;
	}*/
	
	HuffmanTree HT;
	HuffmanCode HC;
	int n;	
	n = v.size();
	CreatHuffmanTree(HT,n);
	CreatHuffmanCode(HT,HC,n);
	cout << HC[0] << endl;
	for(int i = 1;i < n;i ++){
		if(v[i].first == "0")continue;
		cout<<v[i].first << ' ' << v[i].second << ' ' <<HC[i]<<endl; 
	}
	
    return 0;
}
