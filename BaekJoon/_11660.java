import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main2123423 {
	public static void main(String args[]) throws Exception {
		final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st1 = new StringTokenizer(in.readLine(), " ");
		int n = Integer.parseInt(st1.nextToken());
		int m = Integer.parseInt(st1.nextToken());

		int psum[][] = new int[n + 1][n + 1];
		for (int i = 1; i <= n; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine(), " ");
			for (int j = 1; j <= n; j++) {
				int a = Integer.parseInt(st.nextToken());
				// 전체합 계산
				psum[i][j] += psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1] + a;
			}
		}
		for (int i = 1; i <= m; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine(), " ");
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());
			// 미리 계산된 전체합으로 부분합을 구함
			int answer = psum[x2][y2] - psum[x2][y1 - 1] - psum[x1 - 1][y2] + psum[x1 - 1][y1 - 1];
			System.out.println(answer);
		}
	}
}