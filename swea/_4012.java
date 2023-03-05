import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _4012 {
	static int[][] ingredients;
	static int answer;

	public static int getScore(int state) {
		int score = 0;
		for (int i = 0; i < ingredients.length; i++) {
			if ((state & (1 << i)) == (1 << i)) {
				for (int j = 0; j < ingredients[0].length; j++) {
					if (i!= j &&(state & (1 << j)) == (1 << j)) {
						score += ingredients[i][j];
					}
				}
			}
		}
		return score;
	}

	public static void cook(int state, int count, int start) {
		if (count == 0) {
			int a = getScore(state);
			int b = getScore(~state);
			answer = Math.min(answer, Math.abs(b - a));
			return;
		}
		if(start >= ingredients.length) {
			return;
		}
		for(int i = start; i < ingredients.length; i++) {
			cook(state | (1 << start), count - 1, i+1);
		}
	}

	public static void main(String args[]) throws Exception {
	    final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(in.readLine());
		// 식재료들을 각각 N/2 개씩 나누어 두 개의 요리를 해야함
		// 맛의 차이가 최소가 되도록 재료를 배분
		for (int test_case = 1; test_case <= T; test_case++) {
			int N = Integer.parseInt(in.readLine());
			answer = Integer.MAX_VALUE;
			ingredients = new int[N][N];
			for (int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(in.readLine(), " ");
				for (int j = 0; j < N; j++) {
					ingredients[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			cook(0, N / 2, 0);
			out.write("#" + test_case + " " + answer + "\n");
		}
		
		out.flush();
        out.close();
        in.close();
	}
}