import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1987 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static char board[][];
	static int[] horse = new int[] { 0, 0 };
	static int[] dx = { 1, -1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };
	static boolean visited[] = new boolean[127];

	static int answer = 0;

	public static void search(int y, int x, int depth) {
		answer = Math.max(answer, depth);
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx == -1 || nx == board[0].length || ny == -1 || ny == board.length || visited[board[ny][nx]]) {
				continue;
			}
			visited[board[ny][nx]] = true;
			search(ny, nx, depth + 1);
			visited[board[ny][nx]] = false;
		}
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		int R = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		board = new char[R][C];

		for (int i = 0; i < R; i++) {
			String s = in.readLine();
			for (int j = 0; j < C; j++) {
				board[i][j] = s.charAt(j);
			}
		}

		visited[board[0][0]] = true;
		search(0, 0, 1);
		out.write(answer + "");

		out.flush();
		out.close();
		in.close();
	}
}
