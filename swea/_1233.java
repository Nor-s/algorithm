import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Solution {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static Object node[] = new Object[201];
	static int N;
	static boolean answer = true;

	static Object order(int idx) {
		if (idx > N) {
			return null;
		}
		Object a = order(idx * 2);
		Object b = order(idx * 2 + 1);
		if (node[idx] instanceof Character) {
			if (a instanceof Integer && b instanceof Integer) {
				return new Integer((Integer) a + (Integer) b);
			}
			answer = false;
		}
		if (!(node[idx] instanceof Integer && a == null && b == null)) {
			answer = false;
		}
		return node[idx];
	}

	public static void main(String args[]) throws Exception {
		for (int test_case = 1; test_case <= 10; test_case++) {
			N = Integer.parseInt(in.readLine());
			StringTokenizer st = null;

			for (int i = 0; i < N; i++) {
				answer = false;
				st = new StringTokenizer(in.readLine());
				int idx = Integer.parseInt(st.nextToken());
				String num = st.nextToken();
				if ('0' <= num.charAt(0) && num.charAt(0) <= '9') {
					node[idx] = Integer.parseInt(num);
				} else {
					node[idx] = new Character(num.charAt(0));
				}
			}
			order(1);
			out.write("#" + test_case + " ");
			if (answer) {
				out.write('1');
			} else {
				out.write('0');
			}
			out.write('\n');
		}

		out.flush();
		out.close();
		in.close();
	}
}