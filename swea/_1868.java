import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.lang.reflect.Array;
import java.util.*;

class Solutionsss {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static char board[][] = new char[301][301];
	static boolean visited[][];
	static int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
	static int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
	static int N;

	public static boolean isNotNum(int y, int x) {
		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (board[ny][nx] == '*') {
				return false;
			}
		}
		return true;
	}

	public static boolean bfs(int y, int x) {
		if (!isNotNum(y, x)) {
			return false;
		}
		visited[y][x] = true;
		Queue<Integer> q = new ArrayDeque<>();
		q.add(y * N + x);
		while (!q.isEmpty()) {
			Integer p = q.poll();
			int yy = p / N;
			int xx = p % N;
			for (int i = 0; i < 8; i++) {
				int ny = yy + dy[i];
				int nx = xx + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N || board[ny][nx] == '*' || visited[ny][nx]) {
					continue;
				}
				visited[ny][nx] = true;
				if (isNotNum(ny, nx)) {
					q.add(ny * N + nx);
				}
			}
		}
		return true;
	}

	public static int bfsAll() {
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] != '*' && !visited[i][j]) {
					if (bfs(i, j)) {
						count++;
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] != '*' && !visited[i][j]) {
					count++;
				}
			}
		}
		return count;
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			N = Integer.parseInt(in.readLine());
			board = new char[N][N];
			for (int i = 0; i < N; i++) {
				String tmpS = in.readLine();
				for (int j = 0; j < N; j++) {
					board[i][j] = tmpS.charAt(j);
				}
			}
			visited = new boolean[N + 1][N + 1];
			int answer = bfsAll();
			out.write("#" + test_case + " " + answer + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}