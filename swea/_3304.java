import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Solution_3304 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	static int[][] cached = new int[1001][1001];
	static String a, b;

	public static int dp(int aidx, int bidx) {
		if (aidx == a.length() || bidx == b.length()) {
			return 0;
		}
		if (cached[aidx][bidx] == -1) {
			cached[aidx][bidx] = 0;
			if (a.charAt(aidx) == b.charAt(bidx)) {
				cached[aidx][bidx] = dp(aidx + 1, bidx + 1) + 1;
			} else {
				cached[aidx][bidx] = Math.max(cached[aidx][bidx], dp(aidx, bidx + 1));
				cached[aidx][bidx] = Math.max(cached[aidx][bidx], dp(aidx + 1, bidx));
			}
		}
		return cached[aidx][bidx];
	}

	static int solve() {
		int answer = 0;
		for (int i = 0; i < a.length(); i++) {
			answer = Math.max(answer, dp(i, 0));
		}
		return answer;
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			a = st.nextToken();
			b = st.nextToken();
			for (int i = 0; i < a.length(); i++) {
				for (int j = 0; j < b.length(); j++) {
					cached[i][j] = -1;
				}
			}

			out.write("#" + test_case + " " + solve() + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}
