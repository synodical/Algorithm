import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[] arr = new int[101];
    static int n;
    static void sol(int gender, int s) {
        if (gender == 1) {
            for (int i = 1; i <= n; i++) {
                if (i % s == 0) {
                    arr[i] ^= 1;
                }
            }
        } else {
            arr[s] ^= 1;

            for (int j = 1; j <= n; j++) {
                if (s - j >= 1 && s+j <= n && arr[s - j] == arr[s + j]) {
                    arr[s - j] ^= 1;
                    arr[s + j] ^= 1;
                } else {
                    return;
                }
            }

        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            int a = Integer.parseInt(st.nextToken());
            arr[i] = a;
        }
        int m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int gender = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            sol(gender, s);
        }
        
        for (int j = 1; j <= n; j++) {
            System.out.print(arr[j] + " ");
            if (j % 20 == 0) {
                System.out.println();
            }
        }
    }
}