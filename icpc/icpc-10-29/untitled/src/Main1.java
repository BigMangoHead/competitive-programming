import java.util.*;
public class Main1 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        for(int i=0; i<n; i++){
            String s = sc.nextLine();
            StringBuilder p = new StringBuilder();
            p.append(s.charAt(0));
            int j=1;
            boolean b = false;
            while(p.length()<s.length()){
                if(explains(p.toString(),s)){
                    System.out.println(p.length());
                    b = true;
                    break;
                }
                p.append(s.charAt(j));
                j++;
            }
            if(!b) System.out.println(s.length());
        }
    }
    public static boolean explains(String p, String s){
        while(p.length()<=s.length()){
            if(s.indexOf(p)!=0) return false;
            s = s.substring(p.length());
        }
        return p.indexOf(s)==0;
    }
}
