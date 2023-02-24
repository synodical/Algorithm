import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Parameter;
import java.util.*;

public class Main {
    static int l, c, v;
    static List<Character> vowels = new ArrayList<>();
    static List<Character> consonant = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        l = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < c; i++) {
            char cr = st.nextToken().charAt(0);
            if (cr == 'a' || cr == 'e' || cr == 'i' || cr == 'o' || cr == 'u') {
                vowels.add(cr);
            } else consonant.add(cr);
        }
        Collections.sort(vowels);
        Collections.sort(consonant);
        ArrayList<List<Character>> ret = new ArrayList<>();
        for (int i = 0; i < 1 << vowels.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < vowels.size(); j++) {
                if ((i & 1 << j) > 0) cnt++;
            }
            if (cnt >= 1) {
                List<Character> tmp = new ArrayList<>();
                for (int j = 0; j < vowels.size(); j++) {
                    if ((i & 1 << j) > 0) {
                        tmp.add(vowels.get(j));
                    }
                }
                ret.add(tmp);
            }
        }
        List<String> ans = new ArrayList<>();
        for (List<Character> list : ret) {
            int k = l - list.size();
            if (k <= 0) {
                continue;
            } 
//            System.out.print(list);

            // consonant에서 k개 고르기
            ArrayList<List<Character>> selectedCon = new ArrayList<>();
            for (int i = 0; i < 1 << consonant.size(); i++) {
                int cnt = 0;
                for (int j = 0; j < consonant.size(); j++) {
                    if ((i & 1 << j) > 0) cnt++;
                }
                if (cnt == k && cnt >= 2) {
                    List<Character> tmp = new ArrayList<>();
                    for (int j = 0; j < consonant.size(); j++) {
                        if ((i & 1 << j) > 0) {
                            tmp.add(consonant.get(j));
                        }
                    }
                    StringBuilder s = new StringBuilder();
                    int a = 0;
                    int b = 0;
                    while (a < list.size() && b < tmp.size()) {
                        if (list.get(a) < tmp.get(b)) {
                            s.append(list.get(a++));
                        } else {
                            s.append(tmp.get(b++));
                        }
                    }
                    while (a < list.size()) {
                        s.append(list.get(a++));
                    }
                    while (b < tmp.size()) {
                        s.append(tmp.get(b++));
                    }
                    ans.add(String.valueOf(s));
                    s = new StringBuilder(s.substring(0, l - k));
                }
            }
        }
        Collections.sort(ans);
        for (int i = 0; i < ans.size(); i++) {
            System.out.println(ans.get(i));
        }
    }

}

/*
4 6
a t c i s w

4 6
a t c i e o
r
 */