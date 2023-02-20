import java.io.*;
import java.lang.reflect.Parameter;
import java.util.*;

public class Main {
    static int n, m;
    static int[] arrA;
    static int[] arrB;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arrA = new int[n];
        arrB = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arrA[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            arrB[i] = Integer.parseInt(st.nextToken());
        }
        int a = 0, b = 0;
        int index = 0;
        int[] res = new int[n + m];
        while (a < n && b < m) {
            if (arrA[a] < arrB[b]) {
                res[index++] = arrA[a++];
            } else {
                res[index++] = arrB[b++];
            }
        }
        while (a < n) {
            res[index++] = arrA[a++];
        }
        while (b < m) {
            res[index++] = arrB[b++];
        }
        for (int i = 0; i < index; i++) {
            bw.write(res[i] + " ");
        }
        bw.flush();
        bw.close();
    }
}