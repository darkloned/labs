/**
 * Created by roman on 6/23/17.
 */

import java.lang.reflect.Array;

public class MyStack<T>
{
    private T[] stack;
    private int top= -1;

    public MyStack(Class<T> c, int size)
    {
        @SuppressWarnings("unchecked")
        final T[] stack = (T[]) Array.newInstance(c, size);
        this.stack = stack;
    }

    public void push(T v) { stack[++top] = v; }

    public T pop() { return stack[top--]; }

    public T peek() { return stack[top]; }

    public boolean empty() { return (top == -1); }

    public void clear() { top = -1; }
}
