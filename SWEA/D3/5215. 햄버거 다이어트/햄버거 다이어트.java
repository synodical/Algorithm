import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {
    static boolean[] isSelected;
    static boolean[][] ans;
    static int n, l;
    static int total;
    static class Pair {
        int taste;
        int cal;

        public Pair(int taste, int cal) {
            this.taste = taste;
            this.cal = cal;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= t; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            l = Integer.parseInt(st.nextToken());
            isSelected = new boolean[n];
            ans = new boolean[(int) Math.pow(2, n)][n];
            List<Pair> hamburger = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                int taste = Integer.parseInt(st.nextToken());
                int cal = Integer.parseInt(st.nextToken());
                hamburger.add(new Pair(taste, cal));
            }
            subset(0);
            int score = 0;
            for (int i = 0; i < ans.length; i++) {
                boolean[] cur = ans[i];
                int curTaste = 0;
                int curCal = 0;

                for (int j = 0; j < cur.length; j++) {
                    if (cur[j]) { // selected
                        Pair curHam = hamburger.get(j);
                        if (curCal + curHam.cal < l) {
                            curCal += curHam.cal;
                            curTaste += curHam.taste;

                        }
                    }
                }
                score = Math.max(score, curTaste);
            }
            System.out.println("#" + tc + " " + score);
            total = 0;
        }
    }

    static void subset(int cnt) {
        if (cnt == n) {
            for (int i = 0; i < n; i++) {
                ans[total][i] = isSelected[i];
            }
            total++;
            return;
        }
        isSelected[cnt] = true;
        subset(cnt + 1);
        isSelected[cnt] = false;
        subset(cnt + 1);
    }
}

/*
1
5 1000
100 200
300 500
250 300
500 1000
400 400
#1 750

2
5 1000
100 200
300 500
250 300
500 1000
400 400
1 100
100 100



 */