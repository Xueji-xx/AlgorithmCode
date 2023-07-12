#include <iostream>
using namespace std;

void dfs(int a, int b, int x, int y, int n){
    if(n == 1) return;
    n = n / 2;
    if(x <= a + n - 1 && y <= b + n - 1){ //���������Ѹ��ǵ�λ�������Ͻǣ�ʹ��1�ŵ�̺
        printf("%d %d 3\n", a + n, b + n);
        dfs(a, b, x, y, n); //����λ�ò���
        dfs(a, b + n, a + n - 1, b + n, n);
        dfs(a + n, b, a + n, b + n - 1, n);
        dfs(a + n, b + n, a + n, b + n, n);
    }
    else if(x <= a + n - 1 && y >= b + n){ //���������Ѹ��ǵ�λ�������Ͻǣ�ʹ��2�ŵ�̺
        printf("%d %d 1\n", a + n, b + n - 1);
        //���Σ��ֳ�4����С�Ĳ��ֵݹ鴦��
        dfs(a, b, a + n - 1, b + n - 1, n);
        dfs(a, b + n, x, y, n); //����λ�ò���
        dfs(a + n, b, a + n, b + n - 1, n);
        dfs(a + n, b + n, a + n, b + n, n);
    }
    else if(x >= a + n && y <= b + n - 1){ //���������Ѹ��ǵ�λ�������½ǣ�ʹ��3�ŵ�̺ 
        printf("%d %d 2\n", a + n - 1, b + n);
        dfs(a, b, a + n - 1, b + n - 1, n);
        dfs(a, b + n, a + n - 1, b + n, n);
        dfs(a + n, b, x, y, n); //����λ�ò���
        dfs(a + n, b + n, a + n, b + n, n);
    }
    else{ //���������Ѹ��ǵ�λ�������½ǣ�ʹ��4�ŵ�̺
        printf("%d %d 4\n", a + n - 1, b + n - 1);
        dfs(a, b, a + n - 1, b + n - 1, n);
        dfs(a, b + n, a + n - 1, b + n, n);
        dfs(a + n, b, a + n, b + n - 1, n);
        dfs(a + n, b + n, x, y, n); //����λ�ò���
    }
}
int main(){
    int x, y, k;
    scanf("%d%d%d", &k, &x, &y);
    int n = 1 << k; //�Թ���С
    dfs(1, 1, x, y, n);
    return 0;
}
