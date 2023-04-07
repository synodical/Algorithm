import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m, k;
    static long[] tree;
    static long[] arr;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        tree = new long[n + 1];
        arr = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = Long.parseLong(br.readLine());
            update(i, arr[i]);
        }
        for (int i = 0; i < m + k; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            long c = Long.parseLong(st.nextToken());
            if (a == 1) {
                long tmp = (c - arr[b]);
                update(b, tmp);
                arr[b] = c;
            } else {
                bw.write(sum(c) - sum(b - 1) + "\n");
            }
        }
        bw.flush();
        bw.close();
    }

    public static void update(int idx, long value) {
        while (idx <= n) {
            tree[idx] += value;
            idx = idx + (idx & -idx);
        }
    }

    public static long sum(long idx) {
        long result = 0;
        while (idx > 0) {
            result += tree[(int) idx];
            idx = idx - (idx & -idx);
        }
        return result;
    }
}