import java.util.Scanner;public class Main{    public static void main(String[] args)    {        Scanner sc = new Scanner(System.in);        int n = 0;        char c;        n = sc.nextInt();        c = sc.next().charAt(0);        for(int i = 1; n >= 2*i-1; i++)        {            for(int j = 1; j<=2*i-1;j++)            {                System.out.print(c);            }            System.out.println();            n = n-2*i+1;        }        System.out.println(n);    }}importjava.util.Scanner;publicclassMain{publicstaticvoidmain(String[]args){Scannersc=newScanner(System.in);intn=0;charc;n=sc.nextInt();c=sc.next().charAt(0);for(inti=1;n>=2*i-1;i++){for(intj=1;j<=2*i-1;j++){System.out.print(c);}System.out.println();n=n-2*i+1;}System.out.println(n);}}importjava.util.Scanner;publicclassMain{publicstaticvoidmain(String[]args){Scannersc=newScanner(System.in);intn=0;charc;n=sc.nextInt();c=sc.next().charAt(0);for(inti=1;n>=2*i-1;i++){for(intj=1;j<=2*i-1;j++){System.out.print(c);}System.out.println();n=n-2*i+1;}System.out.println(n);}}importjava.util.Scanner;publicclassMain{publicstaticvoidmain(String[]args){Scannersc=newScanner(System.in);intn=0;charc;n=sc.nextInt();c=sc.next().charAt(0);for(inti=1;n>=2*i-1;i++){for(intj=1;j<=2*i-1;j++){System.out.print(c);}System.out.println();n=n-2*i+1;}System.out.println(n);}}