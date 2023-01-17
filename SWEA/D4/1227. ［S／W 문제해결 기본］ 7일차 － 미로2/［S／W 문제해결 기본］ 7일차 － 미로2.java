import java.util.Scanner;
import java.io.FileInputStream;
import java.util.*;

class Pair {
	Integer x;
	Integer y;
	public Pair(Integer x, Integer y) {
		this.x = x;
		this.y = y;
	}
	public Integer getX() {
		return x;
	}
	public Integer getY() {
		return y;
	}
}
public class Solution {
	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};
	static int size=100;
	static Queue<Pair> q = new LinkedList<Pair>();
	static char[][] arr = new char[size][size];
	static boolean[][] visit = new boolean[size][size];
	
	public static int bfs() {
		int flag = 0;
		while (!q.isEmpty()) {
			Pair p = q.poll();
			int x = p.getX();
			int y = p.getY();
			visit[x][y] = true;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if (arr[nx][ny] == '1' || visit[nx][ny] || nx < 0 || nx >= size || ny < 0 || ny >= size) {
					continue;
				}
				if (arr[nx][ny] == '3') {
					flag = 1;
				}
				q.add(new Pair(nx, ny));
			}
		}
		return flag;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for (int t = 1; t <= 10; t++) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					visit[i][j] = false;
				}
			}
			
			int T = sc.nextInt();
			sc.nextLine();
			for (int i = 0; i < size; i++) {
				String s = sc.nextLine();
				for (int j = 0; j < size; j++) {
					char c = s.charAt(j);
					arr[i][j] = c;
					if (c == '2') {
						((LinkedList<Pair>) q).add(new Pair(i,j));
					}
				}
			}
			System.out.println("#" + t +" "+ bfs());
		}
	}

}
