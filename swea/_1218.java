import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1218
{
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static final Map<Character, Character> memo = new HashMap<Character, Character>(){{
		put('}', '{');
		put(']', '[');
		put(')', '(');
		put('>', '<');
	}}; // pop해야되는 괄호의 짝을 지정 
	static String str;

	public static boolean solve() throws IOException {
		ArrayDeque<Character> stack = new ArrayDeque<>();

		for(int i = 0; i < str.length(); i++ ) {
			char ch = str.charAt(i);
			Character brac = memo.getOrDefault(ch, null); 
			if(brac == null) {
				// push 해야할 때는 {[(<
				stack.addLast(ch);
			}
			else if(brac == stack.getLast()) {
				// pop 해야할 때는 }[(>
				stack.removeLast();
			}
			else {
				return false;
			}
		}
		return true;
	}

	public static void main(String args[]) throws Exception
	{

		for(int test_case = 1; test_case <= 10; test_case++)
		{
			int N = Integer.parseInt(in.readLine());
			str = in.readLine();

			out.write("#" + test_case + " " + (solve()?1:0) + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}
