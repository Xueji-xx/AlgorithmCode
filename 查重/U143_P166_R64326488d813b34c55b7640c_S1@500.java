import java.util.Scanner;public class Main {    static final int N = 1010;    static int n, res = 0, cnt = 0;    static char c;    static int[] a = new int[N];    public static void dfs(int u) {        if (u == cnt)            return;        int count = 2 * (u + 1) - 1;        int blank = cnt - u - 1;        n -= count;        while (blank-- > 0)            System.out.print(" ");        while (count-- > 0)            System.out.print(c);        System.out.println();        dfs(u + 1);    }    public static void solve() {        for (int i = 1; res + i <= n; i += 2) {            res += i;            a[cnt++] = res;        }        dfs(0);        System.out.println(n);    }    public static void main(String[] args) {        Scanner scanner = new Scanner(System.in);        n = scanner.nextInt();        c = scanner.next().charAt(0);        scanner.close();        solve();    }}importjava.util.Scanner;publicclassMain{staticfinalintN=1010;staticintn,res=0,cnt=0;staticcharc;staticint[]a=newint[N];publicstaticvoiddfs(intu){if(u==cnt)return;intcount=2*(u+1)-1;intblank=cnt-u-1;n-=count;while(blank-->0)System.out.print("");while(count-->0)System.out.print(c);System.out.println();dfs(u+1);}publicstaticvoidsolve(){for(inti=1;res+i<=n;i+=2){res+=i;a[cnt++]=res;}dfs(0);System.out.println(n);}publicstaticvoidmain(String[]args){Scannerscanner=newScanner(System.in);n=scanner.nextInt();c=scanner.next().charAt(0);scanner.close();solve();}}importjava.util.Scanner;publicclassMain{staticfinalintN=1010;staticintn,res=0,cnt=0;staticcharc;staticint[]a=newint[N];publicstaticvoiddfs(intu){if(u==cnt)return;intcount=2*(u+1)-1;intblank=cnt-u-1;n-=count;while(blank-->0)System.out.print("");while(count-->0)System.out.print(c);System.out.println();dfs(u+1);}publicstaticvoidsolve(){for(inti=1;res+i<=n;i+=2){res+=i;a[cnt++]=res;}dfs(0);System.out.println(n);}publicstaticvoidmain(String[]args){Scannerscanner=newScanner(System.in);n=scanner.nextInt();c=scanner.next().charAt(0);scanner.close();solve();}}importjava.util.Scanner;publicclassMain{staticfinalintN=1010;staticintn,res=0,cnt=0;staticcharc;staticint[]a=newint[N];publicstaticvoiddfs(intu){if(u==cnt)return;intcount=2*(u+1)-1;intblank=cnt-u-1;n-=count;while(blank-->0)System.out.print("");while(count-->0)System.out.print(c);System.out.println();dfs(u+1);}publicstaticvoidsolve(){for(inti=1;res+i<=n;i+=2){res+=i;a[cnt++]=res;}dfs(0);System.out.println(n);}publicstaticvoidmain(String[]args){Scannerscanner=newScanner(System.in);n=scanner.nextInt();c=scanner.next().charAt(0);scanner.close();solve();}}