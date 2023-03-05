import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Sol_2023_02_07_14_36
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T= Integer.parseInt(br.readLine());

		for(int test_case = 1; test_case <= T; test_case++)
		{
			int n = Integer.parseInt(br.readLine());
			String[] board = new String[n];

			for(int i = 0; i < n; i++) {
				board[i] = br.readLine();
			}
			int answer = 0;
			int temp = n/2;

			for(int i = 0; i < n; i++) {
				int j = 0;
				for(; j < temp; j++) {
				}
				for(; j <n - temp; j++) {
					answer += (int)(board[i].charAt(j) - '0');
				}
				temp += ((double)i >= n/2)? 1:-1;
			}
			System.out.println("#" + test_case + " " + answer);
		}
	}
}