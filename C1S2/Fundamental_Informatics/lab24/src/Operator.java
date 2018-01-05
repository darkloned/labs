/**
 * Created by roman on 6/23/17.
 */

import java.util.HashMap;
import java.util.Map;

public class Operator
{
    public static final char ADD = '+', SUB = '-', MUL = '*', DIV = '/', LEFT_PAR = '(', RIGHT_PAR = ')';

    public enum OperatorPriority
    {
        ADD(1), SUBTRACT(2), MULTIPLY(3), DIVIDE(4);

        final int priority;

        OperatorPriority(int p) { priority = p; }
    }

    public static Map<Character, OperatorPriority> priorityMap = new HashMap<Character, OperatorPriority>()
    {{
        put(ADD, OperatorPriority.ADD);
        put(SUB, OperatorPriority.SUBTRACT);
        put(MUL, OperatorPriority.MULTIPLY);
        put(DIV, OperatorPriority.DIVIDE);
    }};
}
