import java.io.*;
import java.lang.reflect.Parameter;
import java.util.*;

public class Main {
    static int n, m,blue,white;
    static int[][] arr;

    static void cut(int a, int b, int size) {
        int sum = 0;
        for (int i = a; i < a+size; i++) {
            for (int j = b; j < b+size; j++) {
                sum += arr[i][j];
            }
        }
        if (sum == size * size) {
            blue++;
        } else if (sum == 0) {
            white++;
        } else {
            int half = size / 2;
            cut(a, b, half);
            cut(a, b + half, half);
            cut(a + half, b, half);
            cut(a + half, b + half, half);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        cut(0, 0, n);
        bw.write(white + "\n");
        bw.write(blue + "\n");
        bw.flush();
        bw.close();
    }
}