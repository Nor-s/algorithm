import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1953 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	static class Dir {
		int dy[];
		int dx[];

		Dir(int[] y, int[] x) {
			dy = y;
			dx = x;
		}
	}

	static Dir dirs[] = {
			new Dir(new int[] { 1, -1, 0, 0 }, new int[] { 0, 0, 1, -1 }),
			new Dir(new int[] { 1, -1 }, new int[] { 0, 0 }),
			new Dir(new int[] { 0, 0 }, new int[] { 1, -1 }),
			new Dir(new int[] { -1, 0 }, new int[] { 0, 1 }),
			new Dir(new int[] { 1, 0 }, new int[] { 0, 1 }),
			new Dir(new int[] { 1, 0 }, new int[] { 0, -1 }),
			new Dir(new int[] { -1, 0 }, new int[] { 0, -1 })
	};
	static int board[][];
	static int R;
	static int C;
	static int L;

	static int bfs() {
		ArrayDeque<int[]> q = new ArrayDeque<>();
		boolean visited[][] = new boolean[board.length][board[0].length];
		int answer = 1;

		q.add(new int[] { R, C, 1 });
		visited[R][C] = true;
		while (!q.isEmpty()) {
			int[] point = q.pollFirst();
			int y = point[0];
			int x = point[1];
			int l = point[2];
			int dirIdx = board[y][x] - 1;
			Dir dir = dirs[dirIdx];
			int size = dir.dx.length;

			for (int i = 0; i < size; i++) {
				int ny = dir.dy[i] + y;
				int nx = dir.dx[i] + x;
				if (ny == -1 || ny == board.length || nx == -1 || nx == board[0].length || visited[ny][nx]
						|| board[ny][nx] == 0) {
					continue;
				}
				Dir nDir = dirs[board[ny][nx] - 1];
				for (int j = 0; j < nDir.dx.length; j++) {
					int nny = nDir.dy[j] + ny;
					int nnx = nDir.dx[j] + nx;
					if (nny == y && nnx == x && l != L) {
						visited[ny][nx] = true;
						answer++;
						q.add(new int[] { ny, nx, l + 1 });
						break;
					}
				}

			}
		}

		return answer;
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			R = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());
			L = Integer.parseInt(st.nextToken());

			board = new int[N][M];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(in.readLine());
				for (int j = 0; j < M; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			out.write("#" + test_case + " " + bfs() + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}
