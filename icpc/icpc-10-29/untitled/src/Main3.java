import java.util.*;
public class Main3 {
    static char[][] b;
    static char[][] temp;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int j=0; j<n; j++){
            int rows = sc.nextInt();
            int cols = sc.nextInt();
            int days = sc.nextInt();
            sc.nextLine();
            b = new char[rows][cols];
            for(int i=0; i<rows; i++){
                String line = sc.nextLine();
                for(int l=0; l<cols; l++){
                    b[i][l] = line.charAt(l);
                }
            }
            for(int t=0; t<days; t++) {
                temp = new char[rows][cols];
                copy(b,temp);
                for (int i = 0; i < rows; i++) {
                    for (int k = 0; k < cols - 1; k++) {
                        fight(i, k, i, k + 1);
                    }
                }
                for (int i = 0; i < cols; i++) {
                    for (int k = 0; k < rows - 1; k++) {
                        fight(k, i, k + 1, i);
                    }
                }
                copy(temp,b);
            }
            for(char[] line : b){
                for(char c: line){
                    System.out.print(c);
                }
                System.out.println();
            }
            System.out.println();
        }
    }
    public static void copy(char[][] a, char[][] b){
        for(int r=0; r<a.length; r++){
            System.arraycopy(a[r], 0, b[r], 0, a[0].length);
        }
    }
    public static void fight(int r1, int c1, int r2, int c2){
        if(b[r1][c1]=='R'){
            if(b[r2][c2]=='S'){
                temp[r2][c2] = 'R';
                return;
            }
            if(b[r2][c2]=='P'){
                temp[r1][c1]='P';
                return;
            }
            return;
        }
        if(b[r1][c1]=='S'){
            if(b[r2][c2]=='P'){
                temp[r2][c2] = 'S';
                return;
            }
            if(b[r2][c2]=='R'){
                temp[r1][c1] = 'R';
                return;
            }
            return;
        }
        if(b[r1][c1]=='P'){
            if(b[r2][c2]=='S'){
                temp[r1][c1] = 'S';
                return;
            }
            if(b[r2][c2]=='R'){
                temp[r2][c2] = 'P';
            }
        }
    }
}