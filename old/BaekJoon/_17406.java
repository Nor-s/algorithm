import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _17406 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int board[][];
	static int dx[][] = { { 1, 0, -1, 0 }, { 0, 1, 0, -1 } };
	static int dy[][] = { { 0, 1, 0, -1 }, { 1, 0, -1, 0 } };
	static int[][] op;
	static boolean visited[];
	static int answer = Integer.MAX_VALUE;

	public static class Point {
		int y, x;

		Point(int y, int x) {
			this.y = y;
			this.x = x;
		}

		boolean equals(Point p) {
			return p.x == x && p.y == y;
		}
	}

	static void next(Point p, int dir, int kind) {
		p.y += dy[kind][dir];
		p.x += dx[kind][dir];
	}

	public static void rotate(int r, int c, int k, int kind) {
		if (k == 0) {
			return;
		}

		int dir = 0;
		Point sP = new Point(r - k, c - k);
		Point eP = new Point(r + k, c + k);
		Point cP = new Point(sP.y, sP.x);
		int start = board[sP.y][sP.x];
		int before = start;

		for (;;) {
			int tmp = board[cP.y][cP.x];
			board[cP.y][cP.x] = before;
			before = tmp;

			Point nP = new Point(cP.y, cP.x);
			next(nP, dir, kind);
			if (sP.equals(nP) || eP.y < nP.y || eP.x < nP.x || nP.y < sP.y || nP.x < sP.x) {
				dir = (dir + 1) % 4;
				if (dir == 0) {
					board[sP.y][sP.x] = before;
					break;
				}
			}
			next(cP, dir, kind);
		}
		rotate(r, c, k - 1, kind);
	}

	public static void perm(int idx, int count) {
		if (count == op.length) {
			for (int i = 1; i < board.length - 1; i++) {
				int cost = 0;
				for (int j = 1; j < board[0].length - 1; j++) {
					cost += board[i][j];
				}
				answer = Math.min(answer, cost);
			}
			return;
		}
		for (int i = 0; i < op.length; i++) {
			if (!visited[i]) {
				visited[i] = true;
				rotate(op[i][0], op[i][1], op[i][2], 0);

				perm(i + 1, count + 1);

				rotate(op[i][0], op[i][1], op[i][2], 1);
				visited[i] = false;
			}
		}
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		visited = new boolean[K];
		op = new int[K][3];

		board = new int[N + 2][M + 2];

		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 1; j <= M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(in.readLine());
			op[i][0] = Integer.parseInt(st.nextToken());
			op[i][1] = Integer.parseInt(st.nextToken());
			op[i][2] = Integer.parseInt(st.nextToken());
		}
		perm(0, 0);
		sb.append(answer);

		out.write(sb.toString());
		out.flush();
		out.close();
		in.close();
	}
}