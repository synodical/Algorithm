import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int s, p, a,c,g,t;
    static String str;

    static int curA = 0, curC = 0, curG = 0, curT = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());
        str = br.readLine();
        st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        g = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());
        int end = p;
        int start = 0;
        int ans = 0;

        for (int i = 0; i < p; i++) {
            add(str.charAt(i));

        }
        if (curA >= a && curC >= c && curG >= g && curT >= t) {
            ans++;
        }
        end--;
        while (end < str.length()-1) {
            char r = str.charAt(start);
            delete(r);
            start++;
            end++;

            char cc = str.charAt(end);
            add(cc);

            if (curA >= a && curC >= c && curG >= g && curT >= t) {
                ans++;
            }

        }
        System.out.println(ans);
    }

    static void add(char c) {
        if (c == 'A') {
            curA++;
        } else if (c == 'C') {
            curC++;
        } else if (c == 'G') {
            curG++;
        } else if (c == 'T') {
            curT++;
        }
    }
    static void delete(char c) {
        if (c == 'A') {
            curA--;
        } else if (c == 'C') {
            curC--;
        } else if (c == 'G') {
            curG--;
        } else if (c == 'T') {
            curT--;
        }
    }


}

/*
1 1
A
1 0 0 0

1 1
G
1 0 0 0

4 3
GATA
1 0 0 1
// 2


*/