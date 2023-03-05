import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _3000 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static class MidHeap {
		PriorityQueue<Integer> pqLowest = new PriorityQueue<>();
		PriorityQueue<Integer> pqHighest = new PriorityQueue<>(Collections.reverseOrder());
		Integer mid;
		Long sum = 0L;
		int size = 0;

		void setMid(int a) {
			mid = a;
			size += 1;
		}

		// 1 3 5
		// 1 2 3 5 6
		// 1 2 3 5 6 8 9
		void pushTwoValue(int a, int b) {
			size += 2;
			int[] tmp = { mid, a, b };
			if (size >= 5) {
				tmp = new int[] { mid, a, b, pqLowest.poll(), pqHighest.poll() };
			}
			Arrays.sort(tmp);

			for (int i = 0; i < tmp.length / 2; i++) {
				pqHighest.add(tmp[i]);
			}
			mid = tmp[tmp.length / 2];
			for (int i = tmp.length / 2 + 1; i < tmp.length; i++) {
				pqLowest.add(tmp[i]);
			}
			sum = (mid + sum) % 20171109;
		}
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			int A = Integer.parseInt(st.nextToken());
			MidHeap mh = new MidHeap();
			mh.setMid(A);
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(in.readLine());
				int X = Integer.parseInt(st.nextToken());
				int Y = Integer.parseInt(st.nextToken());
				mh.pushTwoValue(X, Y);
			}

			out.write("#" + test_case + " " + mh.sum + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}
