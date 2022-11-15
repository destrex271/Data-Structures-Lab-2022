

@SuppressWarnings("unchecked")
public class Stack<T>{
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
