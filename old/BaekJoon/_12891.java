import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _12891 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static String DNA;
	static int[] minNum = {0, 0, 0, 0, -10000000};
	static Map<Character, Integer> mp = new HashMap<Character, Integer>(){{
		put('A', 0);
		put('C', 1); 
		put('G', 2); 
		put('T', 3);}};

	public static boolean check() {
		for(int i = 0; i < 4; i++) {
			if(minNum[i] > 0) {
				return false;
			}
		}
		return true;
	}

	public static int solve(int P) throws IOException {
		int count = 0;

		for(int i = 0; i < P; i++) {
			int idx = mp.getOrDefault(DNA.charAt(i), 4);
			minNum[idx]--;
		}
		if(check()){
			count++;
		}
		for(int i = P; i < DNA.length(); i++) {
			int subIdx = mp.getOrDefault(DNA.charAt(i - P), 4);
			int addIdx = mp.getOrDefault(DNA.charAt(i), 4);

			minNum[subIdx]++;
			minNum[addIdx]--;
			if(check()) {
				count++;
			}
		}
		return count;
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());

		// P <= S <= 1,000,000
		int S = Integer.parseInt(st.nextToken());
		int P = Integer.parseInt(st.nextToken());
		DNA = in.readLine();


		// 부분문자열에 포함되어야 할 {‘A’, ‘C’, ‘G’, ‘T’} 의 최소 개수
		st = new StringTokenizer(in.readLine());
		for (int i = 0; i < 4; i++) {
			minNum[i] = Integer.parseInt(st.nextToken());
		}

		out.write(String.valueOf(solve(P)));

		out.flush();
		out.close();
		in.close();
	}
}
