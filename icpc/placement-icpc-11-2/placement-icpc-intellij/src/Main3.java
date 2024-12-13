import java.util.*;
public class Main3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ol:
        for(int l = 0; l<n; l++){
            int s = sc.nextInt();
            int h = sc.nextInt();
            Set<int[]> set = new HashSet<>();
            Set<Integer> forbid = new HashSet<>();
            for(int i=0; i<h; i++){
                int[] temp = new int[2];
                temp[0] = sc.nextInt();
                temp[1] = sc.nextInt();
                set.add(temp);
                forbid.add(100*temp[0]+temp[1]);
            }
            for(int r=0; r<=s; r++){
                for(int c=0; c<=s; c++){
                    if(!forbid.contains(r*100+c) && possible(r,c,s,set)){
                        System.out.println(r+" "+c);
                        continue ol;
                    }
                }
            }
            System.out.println("poodle");
        }
    }
    public static boolean possible(int r, int c, int s, Set<int[]> set){
        double max = 0;
        for(int[] point : set){
            max = Math.max(max,dis(r,c,point));
        }
        int dis = r;
        dis = Math.min(dis,c);
        dis = Math.min(dis,s-r);
        dis = Math.min(dis,s-c);
        return max <= dis;
    }
    public static double dis(int r, int c, int[] point){
        return Math.sqrt(Math.pow(r-point[0],2)+Math.pow(c-point[1],2));
    }
}