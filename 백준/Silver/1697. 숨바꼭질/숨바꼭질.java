import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, k;
    static boolean[] visited;
    static class Pair {
        int pos;
        int cnt;

        public Pair(int pos, int cnt) {
            this.pos = pos;
            this.cnt = cnt;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        visited = new boolean[200_002];
        bfs(n);
    }
    static void bfs(int s) {
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(s, 0));
        while (!q.isEmpty()) {
            Pair cur = q.poll();
            visited[cur.pos] = true;
            if (cur.pos == k) {
                System.out.println(cur.cnt);
                return;
            }
            if (cur.pos > 0 && !visited[cur.pos - 1]) {
                q.add(new Pair(cur.pos - 1, cur.cnt + 1));
            }
            if (cur.pos < k && !visited[cur.pos + 1]) {
                q.add(new Pair(cur.pos + 1, cur.cnt + 1));
            }
            if (cur.pos < k && !visited[cur.pos * 2]) {
                q.add(new Pair(cur.pos * 2, cur.cnt + 1));
            }

        }
    }

}