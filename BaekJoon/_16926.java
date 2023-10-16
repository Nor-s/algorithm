import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main_16926 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int R = 0;
	static int arr[][];
	static int answer[][];
	static int dx[] = { 1, 0, -1, 0 };
	static int dy[] = { 0, 1, 0, -1 };
	static int N, M;

	public static class Point {
		int y;
		int x;

		Point(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}

	public static void process(ArrayDeque<Point> dq, int r, int len) {
		ArrayDeque<Point> index = dq.clone();
		// start 만큼 pop
		int start = r % (len);
		start = len - start;
		for (int i = 0; i < start; i++) {
			index.addLast(index.pollFirst());
		}
		while (!dq.isEmpty()) {
			Point a = index.pollFirst();
			Point b = dq.pollFirst();
			answer[a.y][a.x] = arr[b.y][b.x];
		}
	}

	public static void solve(int r) {
		int kind = 1;
		int h = arr.length;
		int w = arr[0].length;
		int size = h * w;
		int y = 0, x = 0;
		int len = h + h + w + w - 4;
		int dir = 0;

		ArrayDeque<Point> dq = new ArrayDeque<>();
		// 달팽이 배열처럼 시계방향으로 돌림
		for (int i = 0; i < size; i++) {
			dq.addLast(new Point(y, x));
			// 만약 밖 한줄을 전부 담으면, 담은 배열을 처리
			if (kind == len) {
				process(dq, r, len);
				kind = 0;
				h -= 2;
				w -= 2;
				len = h + h + w + w - 4;
				dq.clear();
			}
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny == -1 || ny == N || nx == -1 || nx == M || answer[ny][nx] != 0) {
				dir = (dir + 1) % 4;
			}
			y += dy[dir];
			x += dx[dir];
			kind++;
		}
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		answer = new int[N][M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		solve(R);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sb.append(answer[i][j]).append(" ");
			}
			sb.append("\n");
		}
		out.write(sb.toString());
		out.flush();
		out.close();
		in.close();
	}
}
