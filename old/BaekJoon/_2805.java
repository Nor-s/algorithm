import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _2805 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int[] trees;
	static int M;

	public static boolean isOver(int h) {
		int sum = 0;
		for (int i = 0; i < trees.length; i++) {
			int hh = trees[i] - h;
			hh = (hh < 0) ? 0 : hh;
			sum += hh;
			if (sum >= M) {
				return true;
			}
		}
		return false;
	}

	public static int searchHeight() {
		int lo = 0;
		int hi = 1_000_000_001;
		while (lo + 1 != hi) {
			int mid = (lo + hi) / 2;
			if (isOver(mid)) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		return lo;
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken()); // 나무의 수
		M = Integer.parseInt(st.nextToken()); // 나무의 길이
		trees = new int[N];

		st = new StringTokenizer(in.readLine());
		for (int i = 0; i < N; i++) {
			trees[i] = Integer.parseInt(st.nextToken());
		}
		out.write(String.valueOf(searchHeight()));

		out.flush();
		out.close();
		in.close();
	}
}
