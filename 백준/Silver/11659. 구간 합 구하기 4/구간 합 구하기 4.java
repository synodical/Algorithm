import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m;
    static int[] tree;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        tree = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            update(i, Integer.parseInt(st.nextToken()));
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            bw.write(sum(b) - sum(a - 1) + "\n");
        }
        bw.flush();
        bw.close();
    }

    public static void update(int idx, int value) {
        while (idx <= n) {
            tree[idx] += value;
            idx = idx + (idx & -idx);
        }
    }

    public static long sum(int idx) {
        long result = 0;
        while (idx > 0) {
            result += tree[idx];
            idx = idx - (idx & -idx);
        }
        return result;
    }
}