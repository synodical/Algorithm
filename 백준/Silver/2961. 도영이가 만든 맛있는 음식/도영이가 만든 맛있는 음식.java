import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Pair {
    int s;
    int b;

    public Pair(int s, int b) {
        this.s = s;
        this.b = b;
    }
}
public class Main {
    static int n;
    static boolean[] isSelected;
    static int[] nums;
    static Pair[] cook;
    static int ans = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        isSelected = new boolean[n];
        nums = new int[n];
        cook = new Pair[n];
        for (int i = 0; i < n; i++) {
            nums[i] = i;
        }
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int ss = Integer.parseInt(st.nextToken());
            int bb = Integer.parseInt(st.nextToken());
            cook[i] = new Pair(ss, bb);
        }
        generateSubSet(0);
        System.out.println(ans);
    }
    private static void generateSubSet(int cnt){ // cnt: 직접까지 고려된 원소 수

        if(cnt == n){ // 기저 조건
            // 하나의 부분 집합이 완성됐을 때 할 일
            int sour = 1;
            int bitter = 0;
            for (int i = 0; i < n; i++) {
//                System.out.print((isSelected[i] ? nums[i]: "X") + "\t");
                if (isSelected[i]) {
//                    System.out.print(nums[i]);
                    sour *= cook[nums[i]].s;
                    bitter += cook[nums[i]].b;
                    ans = Math.min(ans, Math.abs(sour - bitter));
                }

            }
//            System.out.println();
            return;
        }
        // 현재 원소를 부분집합의 구성에 포함
        isSelected[cnt] = true;
        generateSubSet(cnt + 1);
        // 현재 원소를 부분집합의 구성에 비포함
        isSelected[cnt] = false;
        generateSubSet(cnt + 1);
    }
}