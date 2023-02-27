import java.io.*;
import java.util.*;

public class Solution {
    static int t,n,m;
    static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            parent = new int[n+1];
            for(int i = 0; i <= n; i++) {
                parent[i] = i;
            }
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                a = getParent(a);
                b = getParent(b);
                if (a < b) parent[b] = a;
                else parent[a] = b;
            }
            int ans = 0;
            for(int i = 1; i <= n; i++) {
                int p = getParent(i);
                if (p == i) ans++;
            }
            System.out.println("#" + tc + " " + ans);
        }
    }
    static int getParent(int n1) {
        if(parent[n1] == n1) return n1;
        else return getParent(parent[n1]);
    }

}