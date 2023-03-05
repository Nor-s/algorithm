import java.util.*;

class Sol_2023_02_06_11_27
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)
		{			
			String answer = "OFF";
			int n = sc.nextInt(); 
			int a = sc.nextInt();
			int fullybit = (1<<n) -1;

			if(fullybit == (a & fullybit)) {
				answer = "ON";
			}
			System.out.println("#" + test_case + " " + answer);
		}
	}
}