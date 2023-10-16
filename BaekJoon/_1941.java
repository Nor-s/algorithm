import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1941 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static char board[][] = new char[5][5];
	static boolean visited[][] = new boolean[5][5];
	static boolean visited2[][] = new boolean[5][5];
	static int answer = 0;
	static int dx[] = { -1, 0, 1, 0 };
	static int dy[] = { 0, -1, 0, 1 };
	static List<Integer> cached = new ArrayList<Integer>();

	public static class Point {
		public int y;
		public int x;
		Point(int y, int x) {
			this.y = y; this.x = x;
		}
	}
	
	public static Point getPoint(int num) {
		return new Point(num/5, num%5);
	}
	public static char getBoard(int num) {
		Point p = getPoint(num);
		return board[p.y][p.x];
	}
	public static int check() throws IOException {
		Queue<Integer> q = new LinkedList<>();
		boolean[] visited = new boolean[25];
		q.add(cached.get(0));
		visited[cached.get(0)] = true;
		int count = 0;

		while(!q.isEmpty()) {
			int num = q.peek(); q.remove();
			Point P = getPoint(num);
			count++;
			for(int i = 0 ; i < cached.size(); i++) {
				int nextNum = cached.get(i);
				Point nextP = getPoint(nextNum);
				int sub = Math.abs(nextP.x - P.x) + Math.abs(nextP.y - P.y);
				if(!visited[nextNum] && sub == 1) {
					visited[nextNum] = true;
					q.add(nextNum);
				}
			}
		}
		return count;
	}
	public static void dp(int start, int count, int countY) throws IOException {
		if(countY == 4) {
			return;
		}
		if(count == 7) {
			answer += (check() == 7)?1:0;
			return;
		}
		for(int i = start; i < 25; i++) {
			cached.add(i);
			dp(i + 1, count + 1, countY + ((getBoard(i) == 'Y')?1:0));
			cached.remove(cached.size() - 1);
		}
	}

	// 'S'(이다‘솜’파의 학생을 나타냄) 또는 'Y'(임도‘연’파의 학생을 나타냄
	// 이다솜파가 적어도 4명
	public static void main(String args[]) throws Exception {
		for (int i = 0; i < 5; i++) {
			String s = in.readLine();
			for (int j = 0; j < 5; j++) {
				board[i][j] = s.charAt(j);
			}
		}
		dp(0, 0, 0);
		System.out.println(answer);
		out.flush();
		out.close();
		in.close();
	}
}
