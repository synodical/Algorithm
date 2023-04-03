import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int t;
    static class Pair {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static ArrayList<Pair> conviniences;
    static Queue<Pair> q;
    static boolean[] visited;
    static int n;
    public static void main(String[] args) throws IOException {
        StringTokenizer st;
        t = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < t; tc++) {
            conviniences = new ArrayList<>();
            q = new ArrayDeque<>();

            n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            Pair house = new Pair(x, y);
            q.add(house);
            visited = new boolean[n+1];
            for (int i = 0; i < n+1; i++) {
                st = new StringTokenizer(br.readLine());
                x = Integer.parseInt(st.nextToken());
                y = Integer.parseInt(st.nextToken());
                Pair convi = new Pair(x, y);
                conviniences.add(convi);
            }

            boolean canGo = sol();
            if (canGo) bw.write("happy\n");
            else bw.write("sad\n");
        }
        bw.flush();
        bw.close();
    }
    static boolean sol() {
        while (!q.isEmpty()) {
            Pair cur = q.poll();

            for (int i = 0; i < n+1; i++) {
                Pair tmp = conviniences.get(i);
                int dist = Math.abs(cur.x - tmp.x) + Math.abs(cur.y - tmp.y);
                if (dist <= 1000 && !visited[i]) {
                    visited[i] = true;
                    if (visited[n]) return true;
                    q.add(new Pair(tmp.x, tmp.y));
                }
            }
        }
        return false;
    }
}

/*
1
2
0 0
-1000 0
1000 0
2000 0

1
2
0 0
10000 0
0 1000
0 2000

1
2
0 500
-1000 1000
1000 500
1000 1500

1
2
0 0
1000 5
2000 10
3000 15

1
2
0 0
0 1001
1 1
1000 1001

2
2
0 0
1000 0
1000 1000
2000 1001
2
0 0
1000 0
2000 1000
2000 2000

 */