import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _3040 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String args[]) throws Exception {
		int arr[] = new int[9];
		Set<Integer> set = new HashSet<>();
		int sum = 0;

		// 입력을 받으면서 set에 담고 전체 합을 구함
		for (int i = 0; i < 9; i++) {
			arr[i] = Integer.parseInt(in.readLine());
			set.add(arr[i]);
			sum += arr[i];
		}
		// 전체 번호를 탐색
		for (int i = 0; i < 9; i++) {
			Integer tmp = sum - arr[i] - 100;
			// 만약 100을 뺀값이 set이 있다면 그 값과 함께 가짜 난쟁이라는 것
			// 자기자신은 제외해야함.
			if (set.contains(tmp) && tmp != arr[i]) {
				continue;
			}
			out.write(arr[i] + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}
