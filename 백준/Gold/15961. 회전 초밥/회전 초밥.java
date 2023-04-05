import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, d, k, c;
    static int[] arr, kind;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        arr = new int[n];
        kind = new int[d+1];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        int s = 0; int e = k-1;
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < k; i++) {
            set.add(arr[i]);
            kind[arr[i]]++;
        }
        int ans = 0;
        while (s < arr.length -1) {
            if (set.contains(c)) {
                ans = Math.max(ans, set.size());
            } else {
                ans = Math.max(ans, set.size()+1);
            }
            e++;
            e = e % arr.length;
            s = s % arr.length;
            kind[arr[s]]--;
            if (kind[arr[s]] == 0) {
                set.remove(arr[s]);
            }
            set.add(arr[e]);
            kind[arr[e]]++;
            s++;

        }
        System.out.println(ans);
    }
}

/*
// 회전 초밥인데 회전을 안하면 어카냐..
8 30 4 30
9
25
7
9
7
30
2
7
-->5

8 30 4 30
7
9
7
30
2
9
7
25
-->5

8 50 4 7
2
6
9
7
7
9
7
30
--> 4

 */