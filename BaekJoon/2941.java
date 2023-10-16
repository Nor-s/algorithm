import java.util.*;

class Sol_2023_01_20_08_38
{	static String s ;
	static String abc[] = {
		"c=",
		"c-",
		"dz=",
		"d-",
		"lj",
		"nj",
		"s=",
		"z="
	};

	public static int check(int idx) {
		for(int i = 0; i < abc.length; i++) {
			int count = 0;
			for(int j = 0; j < abc[i].length(); j++) {
				if((idx + j < s.length()) && (s.charAt(idx+j) == abc[i].charAt(j))) {
					count++;
				}
			}
			if(count == abc[i].length()) {
				return i;
			}
		}
		return -1;
	}

	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		s = sc.nextLine();
		int answer = 0;
		for(int i = 0; i < s.length();) {
			int abc_idx = check(i);
			if(abc_idx != -1) {
				i += abc[abc_idx].length();
			}
			else {
				i++;
			}
			answer++;
		}
		System.out.println(answer);
	}
}