import java.io.*;
import java.util.*;

public class Solution {
    static int t,n,m;
    static int[] arr;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        t = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < t; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            arr = new int[n];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());

            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (arr[i] + arr[j] > m) continue;
                    ans = Math.max(ans, arr[i] + arr[j]);
                }
            }
            if (ans == 0) ans = -1;
            System.out.println("#" + (tc +1)+ " " + ans);
        }


    }
}

/*
6 6
1 2
2 3
4 5
5 6
4 6
3 4
0 0
-- 0

6 6
1 2
1 3
2 3
4 5
4 6
3 5
0 0
-- 0

3 3
1 2
3 1
3 2
0 0


7 7
1 2
2 3
3 1
4 5
5 6
6 4
1 6
0 0

// 1
 */