import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n;
    static int[] parent;
    static class Node {
        int num;
        int x;
        int y;
        int z;

        public Node(int num, int x, int y, int z) {
            this.num = num;
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }
    static class Planet implements Comparable<Planet> {
        int dist;
        int a;
        int b;

        public Planet(int dist, int a, int b) {
            this.dist = dist;
            this.a = a;
            this.b = b;
        }

        @Override
        public int compareTo(Planet o) {
            return this.dist - o.dist;
        }
    }

    static ArrayList<Node> list = new ArrayList<>();
    static ArrayList<Planet> planets = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        parent = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            list.add(new Node(i, x, y, z));
        }

        list.sort(Comparator.comparingInt(p -> p.x));
        for (int i = 0; i < n - 1; i++) {
            int dist = Math.abs(list.get(i).x - list.get(i + 1).x);
            planets.add(new Planet(dist, list.get(i).num, list.get(i + 1).num));
        }
        list.sort(Comparator.comparingInt(p -> p.y));
        for (int i = 0; i < n - 1; i++) {
            int dist = Math.abs(list.get(i).y - list.get(i + 1).y);
            planets.add(new Planet(dist, list.get(i).num, list.get(i + 1).num));
        }
        list.sort(Comparator.comparingInt(p -> p.z));
        for (int i = 0; i < n - 1; i++) {
            int dist = Math.abs(list.get(i).z - list.get(i + 1).z);
            planets.add(new Planet(dist, list.get(i).num, list.get(i + 1).num));
        }

        Collections.sort(planets);

        int ans = 0;
        for (Planet p : planets) {
            int p1 = getParent(p.a);
            int p2 = getParent(p.b);
            if (p1 == p2) continue;
            else if (p1 < p2) {
                parent[p2] = p1;
            } else {
                parent[p1] = p2;
            }
            ans += p.dist;
        }
        bw.write(ans+" ");
        bw.flush();
        bw.close();
    }

    public static int getParent(int n1) {
        if (parent[n1] == n1) return n1;
        else return getParent(parent[n1]);
    }
}