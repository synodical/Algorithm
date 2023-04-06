import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, d, k, c;
    static int[] arr;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        int s = 0; int e = k-1;
        int[] kind = new int[d + 1];
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < k; i++) {
            set.add(arr[i]);
            kind[arr[i]]++;
        }
        int ans = 0;
        while (s < arr.length-1) {

            e++;
            s %= arr.length;
            e %= arr.length;
            kind[arr[s]]--;
            if (kind[arr[s]] == 0) {
                set.remove(arr[s]);
            }
            kind[arr[e]]++;
            set.add(arr[e]);
            if (set.contains(c)) {
                ans = Math.max(ans, set.size());
            } else {
                ans = Math.max(ans, set.size() + 1);
            }
            s++;
        }
        System.out.println(ans);
    }
}

/*
8 30 4 30
2
3
4
4
2
3
4
4

 */