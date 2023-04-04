import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int[] pi;
	static char[] text, pattern;
	static int ans =0;
	static ArrayList<Integer> list;
	
	public static void main(String[] args) throws Exception {
		text = br.readLine().toCharArray();
		pattern = br.readLine().toCharArray();
		list = new ArrayList<>();
		pi = new int[pattern.length];
		getPi();
		getKMP();
		bw.write(ans + "\n");
		if (ans > 0) {
			for (int a : list) {
				bw.write((a+1) + " ");
			}
		}
		
		bw.flush();
		bw.close();
	}
	public static void getPi() {
		int j = 0;
		for (int i = 1; i < pattern.length; i++) {
			if (j >= pattern.length) break;
			while (j > 0 && pattern[i] != pattern[j]) {
				j = pi[j-1];
			}
			if (pattern[i] == pattern[j]) {
				j++;
				pi[i] = j;
			} else {
				pi[i] = 0;
			}
		}
	}
	public static void getKMP() {
		int j = 0;
		for (int i = 0; i < text.length; i++) {
			if (j >= pattern.length) break;
			while (j > 0 && text[i] != pattern[j]) {
				j = pi[j-1];
			}
			if (text[i] == pattern[j]) {
				if (j == pattern.length-1) {
					ans++;
					list.add(i-j);
					j = pi[j];
				} else {
					j++;
				}
			}
		}
	}
}