import java.util.*;public class Main {    public static void main(String[] args) {        Scanner sc = new Scanner(System.in);        String input = sc.nextLine();        System.out.println(read(input));    }    private static int index; // 记录当前读到的字符下标    private static String read(String s) {        String res = "";        while (index < s.length()) {            char c = s.charAt(index);            if (c == '[') {                index++; // 跳过 '['                int n = readNumber(s); // 读入数字                 String s1 = read(s); // 递归读入                 while (n-- > 0) {                    res += s1; // 重复                 }            } else if (c == ']') {                index++; // 跳过 ']'                return res; // 返回当前的             } else {                index++; // 跳过一个字符                res += c; // 将当前字符加入            }        }        return res;    }    private static int readNumber(String s) {        int res = 0;        while (index < s.length() && Character.isDigit(s.charAt(index))) {            res = res * 10 + (s.charAt(index) - '0');            index++;        }        return res;    }}importjava.util.*;publicclassMain{publicstaticvoidmain(String[]args){Scannersc=newScanner(System.in);Stringinput=sc.nextLine();System.out.println(read(input));}privatestaticintindex;//记录当前读到的字符下标privatestaticStringread(Strings){Stringres="";while(index<s.length()){charc=s.charAt(index);if(c=='['){index++;//跳过'['intn=readNumber(s);//读入数字Strings1=read(s);//递归读入while(n-->0){res+=s1;//重复}}elseif(c==']'){index++;//跳过']'returnres;//返回当前的}else{index++;//跳过一个字符res+=c;//将当前字符加入}}returnres;}privatestaticintreadNumber(Strings){intres=0;while(index<s.length()&&Character.isDigit(s.charAt(index))){res=res*10+(s.charAt(index)-'0');index++;}returnres;}}importjava.util.*;publicclassMain{publicstaticvoidmain(String[]args){Scannersc=newScanner(System.in);Stringinput=sc.nextLine();System.out.println(read(input));}privatestaticintindex;//记录当前读到的字符下标privatestaticStringread(Strings){Stringres="";while(index<s.length()){charc=s.charAt(index);if(c=='['){index++;//跳过'['intn=readNumber(s);//读入数字Strings1=read(s);//递归读入while(n-->0){res+=s1;//重复}}elseif(c==']'){index++;//跳过']'returnres;//返回当前的}else{index++;//跳过一个字符res+=c;//将当前字符加入}}returnres;}privatestaticintreadNumber(Strings){intres=0;while(index<s.length()&&Character.isDigit(s.charAt(index))){res=res*10+(s.charAt(index)-'0');index++;}returnres;}}importjava.util.*;publicclassMain{publicstaticvoidmain(String[]args){Scannersc=newScanner(System.in);Stringinput=sc.nextLine();System.out.println(read(input));}privatestaticintindex;//记录当前读到的字符下标privatestaticStringread(Strings){Stringres="";while(index<s.length()){charc=s.charAt(index);if(c=='['){index++;//跳过'['intn=readNumber(s);//读入数字Strings1=read(s);//递归读入while(n-->0){res+=s1;//重复}}elseif(c==']'){index++;//跳过']'returnres;//返回当前的}else{index++;//跳过一个字符res+=c;//将当前字符加入}}returnres;}privatestaticintreadNumber(Strings){intres=0;while(index<s.length()&&Character.isDigit(s.charAt(index))){res=res*10+(s.charAt(index)-'0');index++;}returnres;}}