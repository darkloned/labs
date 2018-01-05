/**
 * Created by roman on 6/23/17.
 */

import java.io.PrintWriter;
import java.util.Scanner;

public class ShuntingYard
{
    public static void main(String[] args)
    {
        ShuntingYard p = new ShuntingYard();

        p.run();
        p.out.flush();
    }

    private Scanner in = new Scanner(System.in);
    private PrintWriter out = new PrintWriter(System.out);

    private void run()
    {
        String expression = in.nextLine();  // 1 + 2 * x / (x - 8)
        int x = in.nextInt();               // 16

        int ans = Expression.evaluate(expression, x); // 5

        out.println(ans);
    }
}