import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int n, m;
	static List<Integer> adj[];
	public static void main(String args []) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		adj = new ArrayList[n+1];
		for (int i = 0; i <= n; i++) {
			adj[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			adj[b].add(a);
		}
		int max = 0;
		ArrayList<Integer> ans = new ArrayList<>();
		for (int i = 1; i <= n; i++) {
			int cnt = 0;
			
			Queue<Integer> q = new ArrayDeque<>();
			q.add(i);
			boolean[] visited = new boolean[n+1];
			visited[i] = true;
			while (!q.isEmpty()) {
				int cur = q.poll();
				for (int nxt : adj[cur]) {
					if (visited[nxt]) continue;
					cnt++;
					visited[nxt] = true;
					q.add(nxt);
				}
			}
			
			if (cnt == max) {
				ans.add(i);
			} else if (cnt > max) {
				max = cnt;
				ans.clear();
				ans.add(i);
			}
		}
		for (int a : ans) {
			bw.write(a + " ");
		}
		bw.flush();
		bw.close();
	}
	public static int bfs(int node) {
		int cnt = 0;
		Queue<Integer> q = new ArrayDeque<>();
		q.add(node);
		boolean[] visited = new boolean[n+1];
		visited[node] = true;
		while (!q.isEmpty()) {
			int cur = q.poll();
			for (int nxt : adj[cur]) {
				if (visited[nxt]) continue;
				cnt++;
				visited[nxt] = true;
				q.add(nxt);
			}
		}
		return cnt;
	}
}