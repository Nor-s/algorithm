import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solutionsdsdsdsddddd
{
	public static String s;
	public static long cached[][];
    
	/**
	 
2
BC
ADCBBACDCBCBACBDCABDCBA
	 * @return
	 */
	public static long dp() {
		cached[0][1] = 1;
		for(int day = 1; day <= cached.length - 1; day++) {
			int solo = 1<<((int)s.charAt(day - 1)- (int)'A');

			for(int current_state = 1; current_state < 16; current_state++) {		
				if((current_state & solo) != solo) {
					continue;
				}
				for(int before_state = 1; before_state < 16; before_state++) {	
					if((before_state & current_state) != 0)  {
						cached[day][current_state] = (cached[day][current_state] + cached[day - 1][before_state])%1000000007;
					}
				}
			}
		}

		long ret = 0;
		for(int current_state = 1; current_state < 16; current_state++) {		
			ret = (ret + cached[cached.length-1][current_state])%1000000007;
		}
		return ret;
	}

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T= Integer.parseInt(br.readLine());

		for(int test_case = 1; test_case <= T; test_case++) {
			s = br.readLine();		
            cached = new long[s.length()+1][16];
			
			long answer = dp();
			System.out.println("#" + test_case + " " + answer);
		}
	}
}