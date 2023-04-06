import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int t;
    static long[] fac = new long[1000001];
    static final int MOD = 1234567891;
    public static void main(String[] args) throws IOException {
        init();
        t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            long c1 = fac[n];
            long c2 = (fac[n - k] * fac[k]) % MOD;
            long c3 = cal(c2, MOD - 2);
            bw.write("#" + tc + " " + (c1 * c3 % MOD) + "\n");
        }
        bw.flush();
        bw.close();
    }

    static long cal(long n, long k) {
        if (k == 1) {
            return n;
        }
        long x = cal(n, k / 2) % MOD;
        if (k % 2 == 0) {
            return x * x % MOD;
        } else return ((x * x) % MOD * n) % MOD;
    }
    public static void init() {
        fac[0] = 1;
        for (int i = 1; i <= 1000000; i++) {
            fac[i] = fac[i-1] * i % MOD;
        }
    }
}