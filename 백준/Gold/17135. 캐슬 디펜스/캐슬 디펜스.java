import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 너무 힘들엇다 ^^ 드디어 잘 수 있다 야호 야스미마쇼~~~~
public class Main {
    static int n, m, d;
    static int[][] arr;
    static boolean[] visited;
    static int our;

    static class Pair implements Comparable<Pair> {

        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Pair o) {
            return this.y - o.y; // x관계없이 왼쪽 적이 가까운게 먼저
        }
    }

    static ArrayList<Pair> q = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        // 최대 경우의 수 15C3이다
        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == 1) {
                    q.add(new Pair(i, j));
                }
            }
        }
        Collections.sort(q);

        ArrayList<List<Integer>> ret = new ArrayList<>();
        for (int i = 0; i < (1 << m); i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if ((i & (1 << j)) > 0) cnt++;
            }
            if (cnt == 3) {
                List<Integer> tmp = new ArrayList<>();
                for (int j = 0; j < m; j++) {
                    if ((i & 1 << j) > 0) {
                        tmp.add(j);
                    }
                }
//                System.out.println(tmp); // tmp의 element는 j 즉 열
                ret.add(tmp);
            }
        }
        our = n;
        int ans = 0;

        for (List<Integer> l : ret) {
            ArrayList<Pair> pq = new ArrayList<>();
            for (Pair pp : q) {
                pq.add(new Pair(pp.x, pp.y));
            }
            int sum = 0;

            while (!pq.isEmpty()) {
                // list에 공격할 가장 가까운 적 저장
                Collections.sort(pq);
                HashSet<Pair> set = new HashSet<>();
                for (Integer a : l) {
                    Pair enemy = getEnemy(pq, a);
                    set.add(enemy);
                }
                int cnt = 0;
                for (int i = pq.size() - 1; i >= 0; i--) {
                    if (set.contains(pq.get(i))) {
                        pq.remove(i);
                        cnt++;
                    }
                }
                sum += cnt;
                for (int i = pq.size() - 1; i >= 0; i--) { // 적: 앞으로 전진
                    pq.get(i).x++;
                    if (pq.get(i).x >= n) {
                        pq.remove(i);
                    }
                }

            }
//            System.out.println(sum);
            ans = Math.max(sum, ans);
        }
        System.out.println(ans);

    }

    static Pair getEnemy(List<Pair> pq, int cur) {
        int minDist = Integer.MAX_VALUE;
        Pair nearEnemy = null;
        // cur과 가장 가까운 적 반환
        for (Pair p : pq) {
            int dist = Math.abs(cur - p.y) + Math.abs(n - p.x);
            if (dist <= d) {
                if (minDist > dist) {
                    nearEnemy = p;
                    minDist = dist;
                }
            }
        }
        return nearEnemy;
    }

}

/*
9 10 4
1 0 0 1 0 1 0 1 1 0
0 0 0 1 0 0 0 1 0 0
0 1 0 0 1 0 0 1 1 1
0 0 1 1 0 1 0 1 1 0
0 1 1 0 0 0 0 1 0 1
0 1 1 1 0 1 0 1 0 0
0 0 0 0 0 0 0 1 0 0
1 1 1 1 1 1 1 1 0 1
0 1 1 0 1 1 0 1 1 0

2 4 2
1 1 1 1
0 1 1 0

5 5 2
1 0 1 1 1
0 1 1 1 1
1 0 1 0 1
1 1 0 1 0
1 0 1 0 1

10 10 1
1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1

7 6 2
0 1 1 0 1 0
1 1 0 1 0 0
1 0 1 0 0 1
0 1 0 0 1 0
1 0 0 1 0 1
0 0 1 0 1 1
0 1 0 1 1 0

 */