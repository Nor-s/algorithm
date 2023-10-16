import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _2839 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String args[]) throws Exception {
		int N = Integer.parseInt(in.readLine());
		// 완전 탐색
		for (int three = 0; three <= N / 3; three++) {
			for (int five = 0; five <= N / 5; five++) {
				if (three * 3 + five * 5 == N) {
					System.out.println(three + five);
					return;
				}
			}
		}
		System.out.println(-1);
		out.flush();
		out.close();
		in.close();
	}
}
