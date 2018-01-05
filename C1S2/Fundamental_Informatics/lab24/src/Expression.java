/**
 * Created by roman on 6/23/17.
 */

public class Expression
{
    private MyStack<Integer> values;
    private MyStack<Character> ops;

    private Expression()
    {
        this.values = new MyStack<>(Integer.class, 1024);
        this.ops    = new MyStack<>(Character.class, 1024);
    }

    public static int evaluate(String expression, int x)
    {
        expression = Expression.removeUnaryMinuses(expression.toCharArray());

        char[] tokens = expression.toCharArray();

        Expression e = new Expression();

        for (int i = 0; i < tokens.length; i++)
        {
            if (tokens[i] == ' ')
                continue;

            if (tokens[i] == 'x')
                e.values.push(x);

            else if (tokens[i] >= '0' && tokens[i] <= '9')
            {
                StringBuilder sb = new StringBuilder();

                while (i < tokens.length && tokens[i] >= '0' && tokens[i] <= '9')
                    sb.append(tokens[i++]);

                e.values.push(Integer.parseInt(sb.toString()));

                if (i >= tokens.length) break;
            }

            if (tokens[i] == Operator.LEFT_PAR)
                e.ops.push(tokens[i]);

            else if (tokens[i] == Operator.RIGHT_PAR)
            {
                while (e.ops.peek() != Operator.LEFT_PAR)
                    e.values.push(evalOp(e.ops.pop(), e.values.pop(), e.values.pop()));
                e.ops.pop();
            }

            else if (Operator.priorityMap.containsKey(tokens[i]))
            {
                while (!e.ops.empty() && hasPriority(tokens[i], e.ops.peek()))
                    e.values.push(evalOp(e.ops.pop(), e.values.pop(), e.values.pop()));

                e.ops.push(tokens[i]);
            }
        }

        // eval remaining operators
        while (!e.ops.empty())
            e.values.push(evalOp(e.ops.pop(), e.values.pop(), e.values.pop()));


        return e.values.pop(); // last value is result
    }

    // true, if op2.priority >= op1.priority
    private static boolean hasPriority(char op1, char op2)
    {
        return (Operator.priorityMap.containsKey(op2) &&
                Operator.priorityMap.get(op2).priority >= Operator.priorityMap.get(op1).priority);
    }

    private static int evalOp(char op, int b, int a)
    {
        switch (op)
        {
            case Operator.ADD:
                return a + b;

            case Operator.SUB:
                return a - b;

            case Operator.MUL:
                return a * b;

            case Operator.DIV:
                if (b == 0)
                    throw new UnsupportedOperationException("Can't divide by zero");

                return a / b;
        }

        return 0;
    }

    private static String removeUnaryMinuses(char[] expression)
    {
        StringBuilder rightExpression = new StringBuilder();

        for (int i = 0; i < expression.length; i++)
        {
            char c = expression[i];

            if (c == Operator.SUB && (i == 0 || expression[i - 1] == Operator.LEFT_PAR))
            {
                rightExpression.append("0");
            }

            rightExpression.append(c);
        }

        return rightExpression.toString();
    }
}
