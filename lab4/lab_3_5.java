import java.util.*;

@SuppressWarnings("unchecked")
class Stack<T>{
		T[] arr;
		int cap;
		int top = -1;

		public Stack(int cap){
				this.cap = cap;
				arr = (T[]) new Object[cap];
		}

		public boolean isEmpty(){
				if(top == -1){
						return true;
				}
				return false;
		}

		public boolean isFull(){
				if(top == cap){
						return true;
				}
				return false;
		}

		public void push(T val){
				if(this.isFull()){
						System.out.println("Stack Overflow!");
				}
				arr[++top] = val;
		}

		public T pop(){
				if(this.isEmpty()){
						System.out.println("Stack Underflow!");
				}
				return arr[top--];
		}
}


class Driver{
		public static double operate(double a, double b, char c){
				switch(c){
						case '+':
								return (double)a + b;
						case '-':
								return (double)a - b;
						case '*':
								return (double)a * b;
						case '/':
								return (double)a / b;
						case '^':
								return Math.pow(a,b);
				}
				return 0;
		}
		public static void main(String args[]){
				String expression;
				Scanner sc = new Scanner(System.in);
				expression = sc.next();
				Stack<String> stack = new Stack<String>(expression.length());
				for(int i = 0; i < expression.length(); i++){
						char c = expression.charAt(i);
						if(c == '+' || c == '-' || c == '*' || c == '^' || c == '/'){
								String a = operate(Double.valueOf(stack.pop()+""), Double.valueOf(stack.pop()+""), c) + "";
								stack.push(a);
						}else{
								stack.push(c+"");
						}
				}
				System.out.println(stack.pop());
		}
}
