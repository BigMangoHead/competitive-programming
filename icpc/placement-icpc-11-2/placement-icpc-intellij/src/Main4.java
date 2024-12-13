import java.util.*;
public class Main4 {
    static Map<Integer,Set<Integer>> map;
    static int[][] fuels;
    static int[] weights;
    static Map<Integer,Integer> dp;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int vertices = sc.nextInt();
        int edges = sc.nextInt();
        weights = new int[vertices];
        for(int i=0; i<vertices; i++){
            weights[i] = sc.nextInt();
        }
        map = new HashMap<>();
        fuels = new int[vertices][vertices];
        for(int i=0; i<edges; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            if(a>=vertices || b>=vertices) continue;
            int fuel = sc.nextInt();
            fuels[a][b] = fuel;
            fuels[b][a] = fuel;
            if(map.containsKey(a)){
                map.get(a).add(b);
            }
            else{
                Set<Integer> temp = new HashSet<>();
                temp.add(b);
                map.put(a,temp);
            }
            if(map.containsKey(b)){
                map.get(b).add(a);
            }
            else{
                Set<Integer> temp = new HashSet<>();
                temp.add(a);
                map.put(b,temp);
            }
        }
        int min = Integer.MAX_VALUE;
        for(int i=0; i<vertices; i++){
            for(int node : map.get(i)){
                min = Math.min(min,weights[node]+go(node));
            }
        }
        System.out.println(min);
    }
    public static int go(int node){
        int min = Integer.MAX_VALUE;
        for(int n : map.get(node)){
            min = Math.min(min,fuels[node][n]+travel(node,100000*node+n,n));
        }
        return min;
    }
    public static int travel(int originV, int originE, int current){
        dp = new HashMap<>();
        return attempt(originV,originE,current,weights[current]);
    }
    public static int attempt(int originV, int originE, int a, int remaining){
        int min = weights[a];
        if(dp.containsKey(a)){
            return dp.get(a);
        }
        for(int n : map.get(a)){
            if(n==originV) continue;
            if(n*100000+a==originE) continue;
            if(remaining<=fuels[n][a]) continue;
            int sav = fuels[n][a]+attempt(originV, originE ,n,remaining-fuels[n][a]);
            if(sav<min){
                min = sav;
            }

        }
        dp.put(a,min);
        return min;
    }
}