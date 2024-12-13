import java.util.*;
public class Main2{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        List<String> list = new ArrayList<>();
        int index1 = line.indexOf(" xor ");
        int index2 = line.indexOf(" = ");
        list.add(line.substring(0,index1));
        list.add(line.substring(index1+5,index2));
        list.add(line.substring(index2+3));
        list.sort((a, b) -> count(a) - count(b));
        int sum = 0;
        for(String s : list) sum+=count(s);
        sum -= count(list.get(2));
        List<char[]> l = new ArrayList<>();
        for(String s : list){
            l.add(s.toCharArray());
        }
        System.out.println(method(l,sum));
    }
    public static int count(String s){
        int count = 0;
        for(char c : s.toCharArray()){
            if(c=='?') count++;
        }
        return count;
    }
    public static void print(List<char[]> list){
        String a = new String(list.get(0));
        String b = new String(list.get(1));
        String c = new String(list.get(2));
        System.out.println(a +" ^ " + b + " = " + c);
    }
    public static boolean possible(int n, char[] b){
        char[] a = Integer.toString(n).toCharArray();
        if(a.length!=b.length) return false;
        for(int i=0; i<a.length; i++){
            if(b[i]!='?' && a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
    public static int method(List<char[]> list,int sum){
        if(sum==0){
            return possible(compute(list),list.get(2)) ? 1 : 0;
        }
        int tot = 0;
        ol:
        for(int i=0; i<2; i++){
            for(int k=0; k<list.get(i).length; k++){
                if(list.get(i)[k]=='?'){
                    for(int j=48; j<=57; j++){
                        if(list.get(i).length>1 && k==0 && j==48){continue;}
                        list.get(i)[k] = (char)j;
                        tot += method(list,sum-1);
                    }
                    list.get(i)[k] = '?';
                    break ol;
                }
            }
        }

        return tot;
    }
    public static List<char[]> clone(List<char[]> list){
        List<char[]> clone = new ArrayList<>(3);
        for(char[] thing : list){
            clone.add(helper(thing));
        }
        return clone;
    }
    public static char[] helper(char[] list){
        char[] res = new char[list.length];
        for(int i=0; i<list.length; i++){
            res[i] = list[i];
        }
        return res;
    }
    public static int compute(List<char[]> list){
        int a = Integer.parseInt(new String(list.get(0)));
        int b = Integer.parseInt(new String(list.get(1)));
        return a^b;
    }
}
