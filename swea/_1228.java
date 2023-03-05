import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1228 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String args[]) throws Exception {

		for (int test_case = 1; test_case <= 10; test_case++) {
			int N = Integer.parseInt(in.readLine());
			StringTokenizer st = new StringTokenizer(in.readLine());
			LinkedList<Integer> li = new LinkedList<>();

			for (int i = 0; i < N; i++) {
				li.addLast(Integer.parseInt(st.nextToken()));
			}

			int cmdNum = Integer.parseInt(in.readLine());
			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < cmdNum; i++) {
				st.nextToken();
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				for (int j = 0; j < y; j++) {
					li.add(x++, Integer.parseInt(st.nextToken()));
				}
			}
			StringBuilder sb = new StringBuilder();
			sb.append("#" + test_case);
			for (int i = 0; i < li.size(); i++) {
				sb.append(" " + li.get(i));
			}
			out.write(sb.toString() + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}
