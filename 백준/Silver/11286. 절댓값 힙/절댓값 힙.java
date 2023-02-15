import java.io.*;
import java.util.PriorityQueue;

public class Main {
    static class Pair implements Comparable<Pair> {
        int abs;
        int v;

        public Pair(int abs, int v) {
            this.abs = abs;
            this.v = v;
        }

        @Override
        public int compareTo(Pair o) {
            int cnt = this.abs - o.abs;
            if (cnt == 0) {
                cnt = this.v - o.v;
            }
            return cnt;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(br.readLine());
            if (x == 0) {
                if (pq.size() == 0) {
                    bw.write("0\n");
                }
                else bw.write(pq.poll().v+"\n");
            }
            else {
                pq.offer(new Pair(Math.abs(x), x));
            }

        }
        bw.flush();
        bw.close();
    }
}