import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Solution_2930 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	static class MaxHeap {
		int arr[];
		int tail = 1;

		public MaxHeap(int n) {
			arr = new int[n + 1];
			arr[0] = Integer.MAX_VALUE;
		}

		public void swap(int a, int b) {
			int temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
		}

		public void add(int val) {
			arr[tail++] = val;
			int child = tail - 1;
			int parent = child / 2;
			while (arr[parent] < arr[child]) {
				swap(child, parent);
				child = parent;
				parent = child / 2;
			}
		}

		public int pop() {
			if (tail == 1) {
				return -1;
			}
			int ret = arr[1];
			arr[1] = arr[tail - 1];
			arr[tail - 1] = Integer.MIN_VALUE;

			int parent = 1;
			int right = parent * 2 + 1;
			int left = parent * 2;

			while (left < tail - 1) {
				int child = (arr[left] < arr[right]) ? right : left;

				if (arr[child] > arr[parent]) {
					swap(parent, child);
				}
				parent = child;
				left = parent * 2;
				right = parent * 2 + 1;
			}

			tail--;
			return ret;
		}

		public void clear() {
			tail = 1;
		}
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());
		MaxHeap mh = new MaxHeap(100007);

		for (int test_case = 1; test_case <= T; test_case++) {
			int N = Integer.parseInt(in.readLine());
			out.write("#" + test_case + " ");
			StringBuilder sb = new StringBuilder();
			StringTokenizer st = null;
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(in.readLine());
				char cmd = st.nextToken().charAt(0);
				if (cmd == '1') {
					mh.add(Integer.parseInt(st.nextToken()));
				} else {
					sb.append(mh.pop()).append(" ");
				}
			}
			out.append(sb.toString()).append("\n");
			mh.clear();
		}

		out.flush();
		out.close();
		in.close();
	}
}