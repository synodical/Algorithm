import java.lang.*;
import java.util.*;
import java.io.*;

class Solution {
    int[] parent;
    class Node implements Comparable<Node> {
        int u;
        int v;
        int cost;
        public Node(int u, int v, int cost) {
            this.u = u;
            this.v = v;
            this.cost = cost;
        }
        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }
    public int solution(int num, int[][] costs) {
        int answer = 0;
        parent = new int[num];
        for(int i =0;i<num; i++) {
            parent[i] = i;
        }
        Queue<Node> island = new PriorityQueue<>();
        for(int i = 0; i<costs.length; i++) {
            island.offer(new Node(costs[i][0], costs[i][1], costs[i][2]));
        }
        // for(int i = 0; i<island.size(); i++) {
        //     System.out.println(island.get(i).cost);
        // }
        while(!island.isEmpty()) {
            Node n = island.poll();
            int p1 = getParent(n.v);
            int p2 = getParent(n.u);
            if (p1 != p2) {
                System.out.println((n.v) + " "+(n.u) + " " +n.cost);
                parent[p1] = p2;
                answer += n.cost;
            }
        }
        return answer;
    }
    int getParent(int n1) {
        if (parent[n1] == n1) return n1;
        else return getParent(parent[n1]);
    }
    void union(int n1, int n2) {
        int p1 = getParent(n1);
        int p2 = getParent(n2);
        if (p1 < p2) parent[n2] = n1;
        else parent[n1] = n2;
    }
    
}