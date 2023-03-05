import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _10507 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int arr[];

	// 연속 공부 기간
	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			int P = Integer.parseInt(st.nextToken());

			arr = new int[N];
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(in.readLine());
				arr[i] = Integer.parseInt(st.nextToken());
			}
			out.write("#" + test_case + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}
