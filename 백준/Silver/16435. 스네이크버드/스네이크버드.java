import java.io.*;
import java.lang.reflect.Parameter;
import java.util.*;

public class Main {
    static int n,l;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        int h = l;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= h) {
                h++;
            } else {
                break;
            }
        }
        System.out.println(h);
    }
}