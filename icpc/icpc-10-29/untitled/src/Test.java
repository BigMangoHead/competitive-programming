import java.util.*;
public class Test {
    public static void main(String[] args){
        System.out.println(explains("I Repeat Myself ","I Repeat Myself I Repeat Myself I Repeat"));
    }
    public static boolean explains(String p, String s){
        while(p.length()<=s.length()){
            System.out.println("here1");
            if(s.indexOf(p)!=0) return false;
            s = s.substring(p.length());
        }
        System.out.println("here2");
        return p.indexOf(s)==0;
    }
}
