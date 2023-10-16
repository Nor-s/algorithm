import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class _15686 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int board[][];
	static List<int[]> chickenPoints = new ArrayList<>();
	static List<int[]> homePoints = new ArrayList<>();
	static List<int[]> selectedChicken = new ArrayList<>();
	static int M = 0;
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { 1, 0, -1, 0 };
	static int answer = 9999999;

	public static int getDist(int y, int x, int yy, int xx) {
		return Math.abs(yy - y) + Math.abs(xx - x);
	}

	public static int getCityDist() {
		int ret = 0;
		for (int[] point : homePoints) {
			int mindist = Integer.MAX_VALUE;
			for (int[] point2 : selectedChicken) {
				mindist = Math.min(mindist, getDist(point[0], point[1], point2[0], point2[1]));
			}
			ret += mindist;
		}
		return ret;
	}

	public static void combination(int idx, int count) {
		if (count == M) {
			answer = Math.min(answer, getCityDist());
			return;
		}
		for (int i = idx; i < chickenPoints.size(); i++) {
			selectedChicken.add(chickenPoints.get(i));
			combination(i + 1, count + 1);
			selectedChicken.remove(selectedChicken.size() - 1);
		}
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		board = new int[N][N];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if (board[i][j] == 1) {
					homePoints.add(new int[] { i, j });
				}
				if (board[i][j] == 2) {
					chickenPoints.add(new int[] { i, j });
				}
			}
		}
		combination(0, 0);
		out.write(answer + "\n");
		out.flush();
		out.close();
		in.close();
	}
}
