import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class _2023 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static String s = new String("100000000");

	public static boolean isPrime(int n) {
		if(n < 2) {
			return false;
		}
	
		final int size = (int) Math.sqrt(n);
		for (int i = 2; i <= size; i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}


	public static void main(String args[]) throws Exception {
		int N = Integer.parseInt(in.readLine());
		int start = Integer.parseInt(s.substring(0, N));
		int end = Integer.parseInt(s.substring(0, N + 1));
		StringBuilder sb = new StringBuilder();

		int numlist[] = new int[N];
		// 1일 때 예외, 홀수만 검색
		int skip = (start == 1)? 1: 2;

		for (int i = start + 1; i < end; i += skip) {
			int n = i;
			int idx = N - 1;
			// 생길 수 있는 숫자를 전부 거꾸로 리스트에 담음
			while (n > 0) {
				numlist[idx--] = n;
				n /= 10;
			}
			int j;
			// 리스트에 담은 숫자의 소수판별
			for (j = 0; j < N; j++) {
				if ((numlist[j] != 2 && numlist[j] % 2 == 0) || !isPrime(numlist[j])) {
					break;
				}
			}
			// 만약 전부 소수이면 출력
			if (j == N) {
				sb.append(i).append("\n");
			}
		}
		out.write(sb.toString());
		out.flush();
		out.close();
		in.close();
	}
}
