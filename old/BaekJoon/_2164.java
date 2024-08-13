import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _2164 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void solve() throws IOException {

	}

	public static void main(String args[]) throws Exception {
		int N = Integer.parseInt(in.readLine());
		ArrayDeque<Integer> q = new ArrayDeque<Integer>();

		for (int i = N; i >= 1; i--) {
			q.addLast(i);
		}
		int it = 0;
		while (q.size() != 1) {
			if (it++ % 2 == 0) {
				q.removeLast();
			} else {
				q.addFirst(q.peekLast());
				q.removeLast();
			}
		}
		out.write(q.getFirst());

		out.flush();
		out.close();
		in.close();
	}
}
