import java.io.BufferedReader;
import java.io.InputStreamReader;

class Sol_2023_02_06_14_39
{
	static public String s; // 원래 메모리 값
	static char bits[] = {'0', '1'}; // 0 1 비트

	// 메모리에서 idx 번째 비트를 조사하는 함수, bit_idx는 마지막으로 덮어쓴 메모리 비트
	public static int solve(int idx, int bit_idx) {
		// 기저조건: 문자열 끝에 도달하면 복구 완료
		if(idx == s.length()) return 0; 
		// 마지막으로 덮어쓴 비트와 원래 메모리 값이 같으면 다음 비트 검사
		if(s.charAt(idx) == bits[bit_idx]) return solve(idx + 1, bit_idx); 	
		// 다르면, 해당 비트로 다시 덮어쓰고 다음 비트 검사
		return solve(idx + 1, (bit_idx + 1)%2) + 1;
	}

	public static void main(String args[]) throws Exception
	{
		// 인풋
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for(int test_case = 1; test_case <= T; test_case++)
		{
			s = br.readLine();
			System.out.println("#" + test_case + " " + solve(0, 0));
		}
	}
}