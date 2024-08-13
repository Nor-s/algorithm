import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Sol_2023_02_06_14_091
{
	// 질문과 답변 등 문자열 선언
	static String first = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";
	static String student = "\"재귀함수가 뭔가요?\"";
	static String answer1 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
	static String answer2 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
	static String answer3 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
	static String answer4 = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
	static String end = "라고 답변하였지.";

	// n번 재귀 수행, 문자열을 tab만큼 띄어서 출력하는 함수
	public static void chatBot(int n, String tab) {
		// 학생의 질문 출력
		System.out.println(tab + student);
		if(n == 0) {
			// 기저조건: 재귀함수에 대한 답을 출력
			System.out.println(tab + answer4);
		}
		else {
			// 잘들어보게~를 출력
			System.out.println(tab + answer1);
			System.out.println(tab + answer2);
			System.out.println(tab + answer3);
			// n-1번 재귀 수행, tab을 증가
			chatBot(n -1, tab + "____");
		}
		// 끝말 출력
		System.out.println(tab + end);
	}

	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		System.out.println(first);
		chatBot(n, "");
	}
}