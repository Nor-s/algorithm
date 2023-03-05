import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Solution_1861 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int grid[][];
	static int dx[] = { 1, -1, 0, 0 };
	static int dy[] = { 0, 0, 1, -1 };
	static int N = 0;

	public static int dfs(int y, int x) {
		int ret = 1;
		// 사방탐색
		for (int i = 0; i < 4; i++) {
			int nextX = dx[i] + x;
			int nextY = dy[i] + y;
			// 정확히 1 더 큰지 체크
			if (grid[nextY][nextX] - 1 == grid[y][x]) {
				ret += dfs(nextY, nextX);
			}
		}

		return ret;
	}

	public static void dfsAll() throws IOException {
		int answerCount = Integer.MIN_VALUE;
		int answerNumber = Integer.MAX_VALUE;

		// 모든 좌표 순회
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// dfs로 얼마나 갈 수 있는지 계산
				int count = dfs(i, j);
				// 최대 이동횟수를 구함
				if (answerCount < count) {
					answerCount = count;
					answerNumber = grid[i][j];
				} else if (answerCount == count) {
					// 같으면 최저값으로 설정
					answerNumber = Math.min(answerNumber, grid[i][j]);
				}
			}
		}
		String s = answerNumber + " " + answerCount;
		out.write(s);
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			N = Integer.parseInt(in.readLine());
			StringTokenizer st = null;
			grid = new int[N + 2][N + 2];

			for (int i = 1; i <= N; i++) {
				st = new StringTokenizer(in.readLine());
				for (int j = 1; j <= N; j++) {
					grid[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			out.write("#" + test_case + " ");
			dfsAll();
			out.write("\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}