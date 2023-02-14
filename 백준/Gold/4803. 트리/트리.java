import java.io.*;
import java.util.*;

public class Main {
    static int n, m, u, v;
    static List<Integer> tree[];
    static boolean[] isCycle;
    static int[] parent;

    static int getParent(int n1) {
        if (parent[n1] == n1) return n1;
        else return getParent(parent[n1]);
    }

    static boolean union(int n1, int n2) {
        n1 = getParent(n1);
        n2 = getParent(n2);
        if (n1 == n2) return false;
        if (n1 < n2) parent[n1] = n2;
        else parent[n2] = n1;
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = 0;
        while (true) {
            t++;
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            if (n == 0 && m == 0) { // 종료 조건
                break;
            }
            parent = new int[n+1];
            isCycle = new boolean[n + 1];
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
            Set<Integer> cycle = new HashSet<>();
            Set<Integer> cycleRoot = new HashSet<>();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                u = Integer.parseInt(st.nextToken());
                v = Integer.parseInt(st.nextToken());
                if (!union(u, v)) {
                    isCycle[v] = true;
                    isCycle[u] = true;
                    cycle.add(v);
                    cycle.add(u);
                }
            }

            int ans = 0;

            for (int i = 1; i <= n; i++) {
                if (getParent(i) == i) {
                    ans++;
                }
            }
            for (Integer i : cycle) {
                cycleRoot.add(getParent(i));
            }
            ans -= cycleRoot.size();
            bw.write("Case " + t + ": ");
            if (ans == 0) {
                bw.write("No trees.");
            } else if (ans == 1) {
                bw.write("There is one tree.");
            } else if (ans > 1) {
                bw.write("A forest of " + ans + " trees.");

            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
