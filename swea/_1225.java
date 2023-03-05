import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1225 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void solve() throws IOException {
	}
	// 15
	// 1 2 3 4 5 1 2 3 4
	// 5 1 2 3 4 5 1 2 3
	// 4 5 1 2 3 4 5 1 2 
	// 3 4 5 1 2 3 4 5 1
	// 2 3 4 5 1 2 3 4 5
	// 1 2 3 4 5 1 2 3 4

	public static void main(String args[]) throws Exception {
		for (int test_case = 1; test_case <= 10; test_case++) {
			int N = Integer.parseInt(in.readLine());
			ArrayDeque<Integer> ad = new ArrayDeque<>();
			StringTokenizer st = new StringTokenizer(in.readLine());

			for (int i = 0; i < 8; i++) {
				ad.addLast(Integer.parseInt(st.nextToken()));
			}
			boolean is_continue = true;
			while (is_continue) {
				for (int i = 1; i <= 5; i++) {
					ad.addLast(Math.max(0, ad.getFirst() - i));
					ad.removeFirst();
					if(ad.peekLast() == 0) {
						is_continue = false;
						break;
					}
				}
			}
			StringBuilder sb = new StringBuilder();
			for(int i = 0 ; i < 8; i++) {
				sb.append(ad.getFirst() + " ");
				ad.removeFirst();
			}
			out.write("#" + test_case +  "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}
