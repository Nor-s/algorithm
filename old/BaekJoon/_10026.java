import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _10026 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static char board[][];
	static int visited[][];
	static int dx[] = { 0, 0, 1, -1 };
	static int dy[] = { 1, -1, 0, 0 };
	static HashMap<Character, Character> rgbMap = new HashMap<Character, Character>() {
		{
			put('B', 'B');
			put('R', 'G');
			put('G', 'R');
		}
	};

	public static void dfs(int y, int x, char mark, boolean isRedGreen) {
		visited[y][x] = mark;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx == -1 || nx == board[0].length || ny == -1 || ny == board.length || visited[ny][nx] != 0) {
				continue;
			}
			if (board[ny][nx] == mark || (isRedGreen && rgbMap.get(board[ny][nx]) == mark)) {
				dfs(ny, nx, mark, isRedGreen);
			}
		}
	}

	public static int dfsAll(boolean isRedGreen) {
		int answer = 0;
		visited = new int[board.length][board[0].length];
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				if (visited[i][j] == 0) {
					dfs(i, j, board[i][j], isRedGreen);
					answer++;
				}
			}
		}
		return answer;
	}

	public static void main(String args[]) throws Exception {
		int N = Integer.parseInt(in.readLine());

		board = new char[N][N];
		for (int i = 0; i < N; i++) {
			String s = in.readLine();
			for (int j = 0; j < N; j++) {
				board[i][j] = s.charAt(j);
			}
		}
		System.out.print(dfsAll(false));
		System.out.print(" ");
		System.out.print(dfsAll(true));
		out.flush();
		out.close();
		in.close();
	}
}
