import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Parameter;
import java.util.*;

public class Main {
    static int n;
    static int[][] arr;
    static int ans = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) cnt++;
            }
            if (cnt == (n / 2)) {
                boolean[] isSelected = new boolean[n];
                for (int j = 0; j < n; j++) {
                    if ((i & (1 << j)) != 0) {
                        isSelected[j] = true;
                    }
                }
//                System.out.println(Arrays.toString(isSelected));
                sol(isSelected);
            }
        }
        System.out.println(ans);
    }

    static void sol(boolean[] isSelected) {
        int start = 0;
        int link = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n; j++) {
                if (isSelected[i] && isSelected[j]) {
                    start += arr[i][j] + arr[j][i];
                } else if (!isSelected[i] && !isSelected[j]) {
                    link += arr[i][j] + arr[j][i];
                }
            }
        }
        ans = Math.min(ans, Math.abs(start - link));
    }
}