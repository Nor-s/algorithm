import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1759 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	// 최소 한 개의 모음, 최소 두 개의 자음
	// 암호는 증가하는 순서
	// 문자의 종류 = C 가지
	// C개의 문자에 가능성 있는 암호
	// L 개.. 선택
	// 15 ~ 3
	static char ch[];
	static boolean isVowel[] = new boolean[27];
	static int L, C;
	static {
		isVowel['a' - 'a'] = true;
		isVowel['e' - 'a'] = true;
		isVowel['i' - 'a'] = true;
		isVowel['o' - 'a'] = true;
		isVowel['u' - 'a'] = true;
	}
	static boolean word[] = new boolean[27];

	public static void combination(int idx, int vowelCount, int consonantCount) throws IOException {
		if (vowelCount + consonantCount > L) {
			return;
		}
		if (vowelCount > 0 && consonantCount > 1 && vowelCount + consonantCount == L) {
			for (int i = 0; i < 27; i++) {
				if (word[i]) {
					char c = (char) (i + 'a');
					out.write(c);
				}
			}
			out.write("\n");
			return;
		}

		for (int i = idx; i < ch.length; i++) {
			word[ch[i] - 'a'] = true;
			combination(i + 1, vowelCount + (isVowel[ch[i] - 'a'] ? 1 : 0),
					consonantCount + (isVowel[ch[i] - 'a'] ? 0 : 1));
			word[ch[i] - 'a'] = false;

		}
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(in.readLine());
		ch = new char[C];
		for (int i = 0; i < C; i++) {
			ch[i] = st.nextToken().charAt(0);
		}
		Arrays.sort(ch);
		combination(0, 0, 0);

		out.flush();
		out.close();
		in.close();
	}
}
