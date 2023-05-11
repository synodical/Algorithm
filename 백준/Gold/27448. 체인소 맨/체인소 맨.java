import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n, m, ans, f;
    static char[][] arr;
    static String[] x, y;
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        f = Integer.parseInt(st.nextToken());
        arr = new char[n][m];
        x = new String[n - 1];
        y = new String[m -1];

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = s.charAt(j);
            }
        }
        for (int i = 0; i < m -1; i++) {
            StringBuilder tmp = new StringBuilder();
            for (int j = 0; j < n; j++) {
                tmp.append(getCase(arr[j][i], arr[j][i+1]));
            }
            y[i] = tmp.toString() + " ";
        }
        for (int i = 0; i < n - 1; i++) {
            StringBuilder tmp = new StringBuilder();
            for (int j = 0; j < m; j++) {
                tmp.append(getCase(arr[i][j], arr[i + 1][j]));
            }
            x[i] = tmp.toString() + " ";
        }
//        System.out.println(Arrays.toString(x));
//        System.out.println(Arrays.toString(y));
        for (int i = 0; i < n - 1; i++) {
            String[] cur = x[i].split("1");
            for (int j = 0; j < cur.length; j++) {
                String tmp = cur[j];
                int cnt = 0; // 3의 개수
                for (int k = 0; k < tmp.length(); k++) {
                    if (tmp.charAt(k) == '3') {
                        cnt++;
                    }
                }
                if (j == 0 || j == cur.length - 1) {
                    ans += Math.min(f, cnt);
                } else ans += cnt;
            }
        }
//        System.out.println(ans);
        for (int i = 0; i < m - 1; i++) {
            String[] cur = y[i].split("1");
            for (int j = 0; j < cur.length; j++) {
                String tmp = cur[j];
                int cnt = 0; // 3의 개수
                for (int k = 0; k < tmp.length(); k++) {
                    if (tmp.charAt(k) == '3') {
                        cnt++;
                    }
                }
                if (j == 0 || j == cur.length - 1) {
                    ans += Math.min(f, cnt);
                } else ans += cnt;
            }
        }
        System.out.println(ans);
    }
    public static char getCase(char a, char b) {
        if (a == '#' && b == '#') {
            return '1';
        } else if (a == '.' && b == '.') {
            return '2';
        } else return '3';
    }
}