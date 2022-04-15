package stack_queue;

import java.util.Stack;

public class CustomQueue<T> {

    Stack<T> innerStack = new Stack<>();
    Stack<T> outerStack = new Stack<>();

    public void add(T t) {
        innerStack.add(t);
    }

    public T peek() {
        if (outerStack.isEmpty()) {
            while(!innerStack.isEmpty()) {
                outerStack.add(innerStack.pop());
            }
        }
        return outerStack.peek();
    }

    public T poll() {
        if (outerStack.isEmpty()) {
            while(!innerStack.empty()) {
                outerStack.add(innerStack.pop());
            }
        }
        return outerStack.pop();
    }

    public int size() {
        return innerStack.size() + outerStack.size();
    }

    public boolean isEmpty() {
        return innerStack.isEmpty() && outerStack.isEmpty();
    }

    public static void main(String[] args) {

        CustomQueue<Integer> cq = new CustomQueue<>();

        cq.add(1);
        cq.add(3);

        System.out.println(cq.peek());

        cq.poll();
        cq.add(10);

        while(!cq.isEmpty()) {
            System.out.println(cq.poll());
        }
    }
}
