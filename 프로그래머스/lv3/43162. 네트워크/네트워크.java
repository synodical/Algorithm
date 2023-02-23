import java.util.*;
import java.lang.*;
import java.io.*;

class Solution {
    int[] parent;
    public int solution(int n, int[][] computers) {
        int answer = 0;
        parent = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for(int i = 0; i < computers.length; i++) {
            for(int j =0; j< computers[i].length; j++) {
                if (computers[i][j] == 1) {
                    int p1 = getParent(i);
                    int p2 = getParent(j);
                    parent[p1] = p2;
                }
            }
        }
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < n; i++) {
            int p1 = getParent(i);
            if(set.contains(p1)) continue;
            set.add(p1);
        }
        answer = set.size();
        return answer;
    }
    int getParent(int n1) {
        if(parent[n1] == n1) return n1;
        else return getParent(parent[n1]);
    }
}