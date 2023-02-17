import java.io.*;
import java.lang.reflect.Parameter;
import java.util.*;

public class Main {
    static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static int n,m;
    static int[][] arr;
    static int[] res;
    static List<Pair> chicken = new ArrayList<>();
    static List<Pair> house = new ArrayList<>();
    static int ans = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][n];
        res = new int[m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 1) {
                    house.add(new Pair(i, j));
                }
                else if (arr[i][j] == 2) {
                    chicken.add(new Pair(i, j));
                }
            }
        }
        ans = Integer.MAX_VALUE;
        combi(0, 0);

        System.out.println(ans);

    }
    static void combi(int cnt, int start) {
        if (cnt == m) {
            int sum = 0;
//            System.out.println(Arrays.toString(res));
            List<Pair> c = new ArrayList<>();
            for (int i = 0; i < res.length; i++) {
                c.add(chicken.get(res[i])); // 선택된 치킨집들
            }
//            System.out.println(chicken.toArray());
            int curDist = 0;
            for (int i = 0; i < house.size(); i++) {
                int minDist = Integer.MAX_VALUE;
                for (int j = 0; j < c.size(); j++) {
                    curDist = Math.abs(c.get(j).x - house.get(i).x)
                            + Math.abs(c.get(j).y - house.get(i).y);
                    minDist = Math.min(minDist, curDist);
                }
                sum += minDist;
            }
//            System.out.println();
            ans = Math.min(ans, sum);

            return;
        }
        for (int i = start; i < chicken.size(); i++) {
            res[cnt] = i;
            combi(cnt + 1, i + 1);
        }
    }
}