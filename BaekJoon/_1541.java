import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class _1541 {
    static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
    static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static String str;

    static int getMinimum(String exp) {
        String exps[] = exp.split("[-]");
        if (exps.length == 1) {
            int sum = 0;
            String nums[] = exp.split("[+]");
            for (String n : nums) {
                sum += Integer.valueOf(n);
            }
            return sum;
        }
        int sum = getMinimum(exps[0]);
        for (int i = 1; i < exps.length; i++) {
            sum -= getMinimum(exps[i]);
        }
        return sum;
    }

    public static void main(String args[]) throws Exception {
        str = in.readLine();
        out.write(getMinimum(str) + "");

        out.flush();
        out.close();
        in.close();
    }
}
