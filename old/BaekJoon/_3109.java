import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int board[][];
	static int dy[] = { -1, 0, 1 };
	static int dx[] = { 1, 1, 1 };

	public static boolean isOuterOrBuilding(int ny, int nx) {
		return (ny == -1 || ny == board.length || nx == -1 || nx == board[0].length || board[ny][nx] == -1);
	}

	public static boolean dfs(int y, int x, int kind) {
		board[y][x] = kind;
		if (x == board[0].length - 1) {
			return true;
		}
		for (int i = 0; i < 3; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (isOuterOrBuilding(ny, nx) || board[ny][nx] != 0) {
				continue;
			}
			if (dfs(ny, nx, kind)) {
				return true;
			}
		}
		return false;
	}

	public static int solve() {
		int answer = 0;
		for (int i = 0; i < board.length; i++) {
			if (board[i][0] == 0 && dfs(i, 0, i + 1)) {
				answer++;
			}
		}

		return answer;
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		int R = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());

		board = new int[R][C];

		for (int i = 0; i < R; i++) {
			String s = in.readLine();
			for (int j = 0; j < C; j++) {
				if (s.charAt(j) == 'x') {
					board[i][j] = -1;
				}
			}
		}
		out.write(solve() + "");
		out.write("\n");
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				out.write(board[i][j] + " ");
			}
			out.write("\n");
		}
		out.flush();
		out.close();
		in.close();
	}
}