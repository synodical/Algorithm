import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {
    static int n;
    static List<Integer> tree[];
    static Character[] ops;
    static boolean flag = true; //
    static void sol(int cur) {
        int leafNum = tree[cur].size();

        if (leafNum == 0) {
            if (!Character.isDigit(ops[cur])) {
                flag = false; // false라면 조건 불만족이므로 연산 불가
            }
        } else { // leaf 노드가 아닌데 현재 숫자인경우
            if (Character.isDigit(ops[cur])) {
                flag = false;
            }
        }
        for (int i = 0; i < leafNum; i++) {
            sol(tree[cur].get(i));
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int t = 1; t <= 10; t++) {
            n = Integer.parseInt(br.readLine());
            tree = new ArrayList[n + 1];
            ops = new Character[n + 1];

            for (int i = 0; i <= n; i++) {
                tree[i] = new ArrayList<>();
            }
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                char op = st.nextToken().charAt(0);
                ops[a] = op;
                if (!st.hasMoreTokens()) continue;
                int l = Integer.parseInt(st.nextToken());
                tree[a].add(l);
                if (!st.hasMoreTokens()) continue;
                int r = Integer.parseInt(st.nextToken());
                tree[a].add(r);
            }
            sol(1);
            if (!flag) System.out.println("#" + t + " " + 0);
            else System.out.println("#" + t + " " + 1);
            flag = true;
        }
    }
}

/*
3
1 + 2 3
2 +
3 5

3
1 + 2 3
2 4
3 5
 */