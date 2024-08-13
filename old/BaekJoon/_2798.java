import java.io.*;
import java.util.*;

class _2798 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int M;
	static int[] arr;
	static ArrayList<Integer> tmp = new ArrayList<>();
	static int answer = -1;

	public static void comb(int idx, int count) {
		if (count == 3) {
			int sum = tmp.get(0) + tmp.get(1) + tmp.get(2);
			if (sum <= M) {
				answer = Math.max(answer, sum);
			}
			return;
		}
		for (int i = idx; i < arr.length; i++) {
			tmp.add(arr[i]);
			comb(i + 1, count + 1);
			tmp.remove(tmp.size() - 1);
		}
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(in.readLine());
		arr = new int[N];

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		comb(0, 0);
		out.write(answer + "");
		out.flush();
		out.close();
		in.close();
	}
}
