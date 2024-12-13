import java.util.*;
public class Main1{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int seated = 0;
        int count = 0;
        for(int i=0; i<m; i++){
            int numToSeat = sc.nextInt();
            if(n-seated>=numToSeat){
                seated+=numToSeat;
                count++;
            }
        }
        System.out.println(m-count);
    }
}