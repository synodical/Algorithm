import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m, k;
    static int[][] tree;
    static int[][] arr;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        tree = new int[n + 1][n + 1];
        arr = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                int in = Integer.parseInt(st.nextToken());
                arr[i][j] = in;
                update(i, j, in);

            }
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int w = Integer.parseInt(st.nextToken());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            if (w == 0) {
                int c = Integer.parseInt(st.nextToken());
                int tmp = c - arr[x1][y1];
                update(x1, y1, tmp);
                arr[x1][y1] = c;
            } else {
                int x2 = Integer.parseInt(st.nextToken());
                int y2 = Integer.parseInt(st.nextToken());
                bw.write(sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1) + "\n");
            }
        }
        bw.flush();
        bw.close();
    }

    public static void update(int row, int idx, long value) {
        int r = row;
        while (r <= n) {
            int c = idx;
            while (c <= n) {
                tree[r][c] += value;
                c = c + (c & -c);
            }
            r = r + (r & -r);
        }
    }

    public static long sum(int row, int idx) {
        long result = 0;
        int r = row;
        while (r > 0) {
            int c = idx;
            while (c > 0) {
                result += tree[r][c];
                c = c - (c & -c);
            }
            r = r - (r & -r);
        }
        return result;
    }
}