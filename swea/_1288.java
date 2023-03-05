import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Solution1288
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int fullyCheck = (1 << 10) -1;
			int check = 0;
            int count = 0;
			int N = Integer.parseInt(in.readLine());

			for(count = 1; check != fullyCheck ; count++) {
				char[] chars = String.valueOf(count*N).toCharArray();
				for(char c : chars) {
					int num = c - '0';
					check =  check | (1<<num);
				}
			}
			System.out.println("#" + test_case + " " + (count-1)*N);
		}
	}
}