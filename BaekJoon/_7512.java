import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _7512aa {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static final int MAX = 2000000;
	public static boolean isNotPrime[] = new boolean[MAX + 1];
	static List<Long> sum = new ArrayList<>();
	static int answer = 0;
	static int[] N;
	static Map<Integer, Integer> m = new HashMap<>();

	public static void init() {
		isNotPrime[0] = isNotPrime[1] = true;
		int size = (int) Math.sqrt(MAX);
		for (int i = 2; i <= size; i++) {
			if (!isNotPrime[i]) {
				for (int j = i * i; j <= MAX; j += i) {
					isNotPrime[j] = true;
				}
			}
		}

		sum.add(0L);
		for (int i = 2; i <= MAX; i++) {
			if (!isNotPrime[i]) {
				sum.add(sum.get(sum.size() - 1) + (long)i);
			}
		}
	}

	public static int solve() throws IOException {
		int size = sum.size();
		for (int i = 0; i < size; i++) {
			for(int j = 0; j < N.length; j++) {
				if(i + N[j] >= size) {
					break;
				}
				int tmpSum = (int) (sum.get(i + N[j]) - sum.get(i));
				if(tmpSum > MAX) {
					break;
				}
				if(isNotPrime[tmpSum]) {
					continue;
				}
				m.put(tmpSum, m.getOrDefault(tmpSum, 0) + 1);
				if (m.get(tmpSum) == N.length) {
					m.clear();
					return tmpSum;
				}
			}
		}
		m.clear();
		throw new IOException();
	}

	public static void main(String args[]) throws Exception {
		init();
		int T = Integer.parseInt(in.readLine());
		StringBuilder sb = new StringBuilder();

		for (int i = 1; i <= T; i++) {
			int n = Integer.parseInt(in.readLine());
			N = new int[n];
			StringTokenizer st = new StringTokenizer(in.readLine());
			for (int j = 0; j < n; j++) {
				N[j] = Integer.parseInt(st.nextToken());
			}
			answer = solve();
			sb.append("Scenario ").append(i).append(":\n");
			sb.append(answer).append("\n");
		}
		out.write(sb.toString());
		out.flush();
		out.close();
		in.close();
	}
}
