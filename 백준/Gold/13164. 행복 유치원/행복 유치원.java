import java.io.*;
import java.util.*;

public class Main {
    static int n, k;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        arr = new int[n + 1];
        List<Integer> sub = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < n-1; i++) {
            sub.add(arr[i + 1] - arr[i]);
            ans += sub.get(i);
        }
        Collections.sort(sub, Collections.reverseOrder());
        for (int i = 0; i < k-1; i++) {
            ans -= sub.get(i);
        }
        System.out.println(ans);
    }
}