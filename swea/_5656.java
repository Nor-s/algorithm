import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _5656 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int N;
	static int H;
	static int W;
	static Integer board[][];
	static Integer tmpBoard[][];
	static int position[];
	static int dx[] = { 0, 0, 1, -1 };
	static int dy[] = { 1, -1, 0, 0 };
	static int sum = 0;

	public static int isPos(int x) {
		return x == 0 ? 0 : 1;
	}

	public static void update() {
		for (int i = 0; i < W; i++) {
			List<Integer> list = Arrays.asList(tmpBoard[i]);
			Collections.sort(list, (a, b) -> isPos(a) - isPos(b));
			tmpBoard[i] = list.toArray(new Integer[0]);
		}
		// System.out.println("====");
		// for (int j = 0; j < H; j++) {
		// for (int i = 0; i < W; i++) {
		// System.out.print(tmpBoard[i][j] + " ");
		// }
		// System.out.println();
		// }
	}

	public static int boom(int x, int y, int range) {
		int ret = 1;
		tmpBoard[x][y] = 0;
		for (int i = 1; i < range; i++) {
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j] * i;
				int ny = y + dy[j] * i;
				if (nx < 0 || nx >= W || ny < 0 || ny >= H)
					continue;
				if (tmpBoard[nx][ny] == 0)
					continue;
				ret += boom(nx, ny, tmpBoard[nx][ny]);
			}
		}
		return ret;
	}

	public static int down(int x, int y) {
		if (y == H) {
			return 0;
		}
		if (tmpBoard[x][y] == 0) {
			return down(x, y + 1);
		} else {
			return boom(x, y, tmpBoard[x][y]);
		}
	}

	public static int simul() {
		tmpBoard = new Integer[W][H];
		for (int i = 0; i < W; i++) {
			tmpBoard[i] = board[i].clone();
		}
		int ret = 0;
		for (int i = 0; i < N; i++) {
			int tmp = down(position[i], 0);
			ret += tmp;
			update();
		}
		return sum - ret;
	}

	static int answer = (int) 1e9;

	public static void perm(int count) {
		if (count == N) {
			answer = Math.min(answer, simul());
			return;
		}
		for (int i = 0; i < W; i++) {
			position[count] = i;
			perm(count + 1);
		}
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());

			N = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());
			answer = (int) 1e9;
			sum = 0;

			board = new Integer[W][H];
			position = new int[N];

			for (int i = 0; i < H; i++) {
				st = new StringTokenizer(in.readLine());
				for (int j = 0; j < W; j++) {
					board[j][i] = Integer.parseInt(st.nextToken());
					sum += (board[j][i] != 0 ? 1 : 0);
				}
			}
			perm(0);
			out.write("#" + test_case + " " + answer + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}
