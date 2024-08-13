import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class _1062 {
	static ArrayList<Character> list = new ArrayList<>(Arrays.asList('a', 'n', 't', 'i', 'c'));
	static Set<String> check = new HashSet<>();
	static String[] checkChar;
	static String[] s;
	static String[] temps;
	static int max = Integer.MIN_VALUE;
	static boolean[] visit;
	static int count = 0;

	public static void dfs(int n, int dep, int start) {
		if (dep == n) {
			for (int i = 0; i < temps.length; i++) {
				for (int j = 0; j < visit.length; j++) {
					temps[i].replaceAll(checkChar[j], "");
				}
				if (temps[i].equals("")) {
					count++;
				}
			}
			max = Math.max(max, count);
			temps = s.clone();
			count = 0;
			return;

		}
		for (int i = start; i < n; i++) {
			if (!visit[i]) {
				visit[i] = true;
				dfs(n, dep + 1, i + 1);
				visit[i] = false;
				dfs(n, dep, i + 1);
				//
			}
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		if (k < 5) {
			System.out.println(0);
			return;
		}
		s = new String[n];
		String temp = "";

		for (int i = 0; i < n; i++) {
			temp = br.readLine();

			for (int j = 4; j < temp.length() - 4; j++) {
				if (list.contains(temp.charAt(j)))
					continue;
				else {
					if (s[i] == null)
						s[i] = String.valueOf(temp.charAt(j));
					else
						s[i] += String.valueOf(temp.charAt(j));
				}
			}
			if (s[i].length() <= k - 5)
				check.add(s[i]);

		}
		visit = new boolean[check.size()];
		checkChar = check.toArray(new String[0]);

		temps = s.clone();

		dfs(k - 5, 0, 0);

		System.out.println(max);
	}
}
