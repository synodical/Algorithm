import java.io.*;
import java.lang.reflect.Parameter;
import java.util.*;

public class Main {
    static int n,m;
    static int[][] adj;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine());

        int total = 0;
        int cnt = 0;
        while (total <= n-5) {
            total += 5;
            cnt++;
        }
        while (true) {
            if (total == n) {
                break;
            }
            int sub = (n - total);
            if (sub % 3 == 0) {
                cnt += sub / 3;
                break;
            }
            else {
                total -= 5;
                cnt--;
            }
            if (total < 0) {
                cnt = -1;
                break;
            }
        }
        System.out.println(cnt);
    }
}