import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int t;
    static int[] dp, arr;
    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        dp = new int[n];
        arr = new int[n];
        int ans = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int end = 0;
        for (int i = 0; i < n; i++) {
            // 검색 실패: 삽입할 위치 - 1
            int pos = Arrays.binarySearch(dp, 0, end, arr[i]);
            if (pos >= 0) {
                continue;
            }
            pos = Math.abs(pos) - 1; // 실제 dp 배열에 삽입할 위치
            dp[pos] = arr[i];
            if (pos == end) { // dp 배열의 맨 뒤에 삽입했다는 의미
                end++;
            }
        }
        bw.write(end + " ");
        bw.flush();
        bw.close();
    }
}