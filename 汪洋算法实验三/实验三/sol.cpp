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
	int min1,min2;//��֤min1 < min2
	//�ҵ�һ��˫�׽ڵ�Ϊ 0 �ĵ㣬��δ��ʹ�ù����½ڵ�
	int i = 1;
	while(HT[i].parent != 0 && i <= end)i++;
	//��min1���и�ֵ��Ȼ�������һ���ڵ�
	min1 = HT[i].weight;
	*s1 = i;
	i++;
	//������һ���ڵ�
	while(HT[i].parent != 0 && i <= end)i++;
	//�Ƚ������ڵ��Ȩֵ�����и�ֵ����
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
	//��ʣ�µĽڵ�����жϲ���������
	for(int j = i + 1;j <= end;j ++){
		if(HT[j].parent != 0)continue;//�ҵ�˫�׽ڵ�Ϊ 0 �Ľڵ�
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
	if(n <= 1)return;//�޷����ɹ�������
	int m = 2 * n - 1;
	//��ʼ�� 
	HT = new HTNode[m+1]; //0��Ԫ��δ�ã��±��1��ʼ 
	for(int i = 1;i <= m;i ++){
		HT[i].parent = 0;
		HT[i].lcd = 0;
		HT[i].rcd = 0;
	}
	for(int i = 1;i <= n;i ++)HT[i].weight = v[i].second;
	
	//����
	for(int i = n+1;i <= m;i ++){
		//ѡ������Ȩֵ��С�ĵ���в��� 
		int s1 = 0,s2 = 0;
		Select(HT,i-1,&s1,&s2);
		//��֤ s1 < s2 �������µĽڵ�
		HT[s1].parent = i;HT[s2].parent = i;
		HT[i].lcd = s1;
		HT[i].rcd = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;//ȨֵΪ�����ڵ��Ȩֵ֮�� 
	} 
} 

void CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n){
	int start,c,f;
	HC = new char*[n+1];      //�±��1��ʼ������洢n���ַ�����ı����ռ�
	char *cd = new char[n];//������ʱ�ڴ�ռ����̬����ռ� 
	cd[n-1] = '\0';
	for(int i = 1;i <= n;i ++){//����ַ������������
		start = n-1;//ָ����������λ��
		c = i;f = HT[c].parent;//ָ��ǰ�ڵ� c ��˫�׽ڵ� 
		while(f != 0){
			start--;//��ʼ���� 
			if(HT[f].lcd == c)cd[start] = '0';//��� c �� f �����ӣ���ô������ 0
			else cd[start] = '1';//��� c �� f ���Һ��ӣ���ô������ 1
			c = f;f = HT[f].parent;//�������ϻ��� 
		}
		HC[i] = new char[n-start];//Ϊ��ǰ�� i ���ַ����б���
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
	//һ��ƻ����һ���㽶��
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
