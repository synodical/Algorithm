import java.io.*;
import java.lang.reflect.Parameter;
import java.util.*;

public class Main {

    static int n,m,k, x;
    static int[][] adj;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        adj = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int a = Integer.parseInt(st.nextToken());
                if (a == 1) {
                    adj[i][j] = 1;
                } else {
                    adj[i][j] = (1<<8);
                }
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] < (1<<8)) {
                    bw.write("1 ");
                } else bw.write("0 ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

}