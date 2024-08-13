import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

class Main_2493 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String args[]) throws Exception {
		int N = Integer.parseInt(in.readLine());
		int arr[] = new int[N];
		int answer[] = new int[N];
		ArrayDeque<Integer> stack = new ArrayDeque<Integer>();

		StringTokenizer st = new StringTokenizer(in.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		// 뒤에서부터 시작
		for (int i = N - 1; i >= 0; i--) {
			// 스택의 top 보다 현재 탑이 크면 현재 탑에서 스택의 top의 레이저를 수신한것
			while (!stack.isEmpty() && arr[stack.peekLast()] < arr[i]) {
				answer[stack.peekLast()] = i + 1;
				stack.removeLast();
			}
			stack.addLast(i);
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			sb.append(answer[i]).append(" ");
		}
		out.write(sb.toString());

		out.flush();
		out.close();
		in.close();
	}
}
