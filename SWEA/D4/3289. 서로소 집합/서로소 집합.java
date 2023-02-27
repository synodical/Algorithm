import java.io.*;
import java.util.*;

public class Solution {
    static int t,n,m;
    static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            parent = new int[n+1];
            for(int i = 0; i <= n; i++) {
                parent[i] = i;
            }
            bw.write("#" + tc + " ");
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int num = Integer.parseInt(st.nextToken());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                if (num == 0) {
                    a = getParent(a);
                    b = getParent(b);
                    if (a < b) parent[b] = a;
                    else parent[a] = b;
                } else {
                    int p1 = getParent(a);
                    int p2 = getParent(b);
                    if (p1 == p2) bw.write("1");
                    else bw.write("0");
                }
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
    static int getParent(int n1) {
        if(parent[n1] == n1) return n1;
        else return getParent(parent[n1]);
    }

}