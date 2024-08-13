import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _11286 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String args[]) throws Exception {
		int N = Integer.parseInt(in.readLine());
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(
				(i1, i2) -> {
					if (Math.abs(i1) == Math.abs(i2)) {
						return i1.compareTo(i2);
					}
					return Integer.valueOf(Math.abs(i1)).compareTo(Math.abs(i2));
				});

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			int x = Integer.parseInt(in.readLine());
			if (x == 0) {
				Integer e = pq.poll();
				sb.append((e == null) ? 0 : e).append("\n");
			} else {
				pq.add(x);
			}
		}
		out.write(sb.toString());
		out.flush();
		out.close();
		in.close();
	}
}