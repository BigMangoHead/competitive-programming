import java.util.*;
public class Main2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++){
            a[i] = sc.nextInt();
        }
        for(int i=0; i<n; i++){
            if(a[i]<=k) {
                System.out.println("It hadn't snowed this early in "+i+" years!");
                return;
            }
        }
        System.out.println("It had never snowed this early!");
    }
}