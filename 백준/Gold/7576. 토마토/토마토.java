import java.io.*;
import java.util.*;

public class Main {
    static int n,m, tc, ans, h;
    static char[] ops;
    static int[] nums;
    static int[][] arr;

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static class Pair {
		int x;
		int y;
		int cnt;
		Pair(int x, int y, int cnt) {
			this.x = x;
			this.y = y;
			this.cnt = cnt;
		}
	}
	static Queue<Pair> q= new ArrayDeque<>();
	public static void main(String[] args) throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine());
		m= Integer.parseInt(st.nextToken());
		n= Integer.parseInt(st.nextToken());
		arr = new int[n][m];
		int zi=0; int zj=0;
		for(int i =0; i< n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j] == 1) {
					zi=i; zj=j;
					q.add(new Pair(i, j, 0));
				}
			}
		}
		boolean already = true;
		for(int i =0; i< n;i++) {
			for(int j=0; j<m; j++) {
				if(arr[i][j] == 0) {
					already = false;
					break;
				}
			}
		}
		if(already) {
			System.out.println(ans);
			return;
		}
		
		
		bfs();
		boolean flag = false;
		for(int i =0; i< n;i++) {
			for(int j=0; j<m; j++) {
				if(arr[i][j] == 0) {
					flag =true;
					break;
				}
			}
		}
		if(flag) ans =-1;
		System.out.println(ans);
		
	}
	static int[] dx= {-1,0,1,0};
	static int[] dy= {0,1,0,-1};
	static void bfs() {
		
		while(!q.isEmpty()) {
			Pair cur = q.poll();
			int curCnt = cur.cnt;
			ans = Math.max(ans, curCnt);
			for (int i =0;i<4;i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx<0 || nx>=n|| ny<0 || ny>= m) continue;
				if (arr[nx][ny] == -1 || arr[nx][ny] == 1) continue;
				
				q.add(new Pair(nx, ny, curCnt+1));
				arr[nx][ny] = 1;
			}
			
		}
	}
	
}