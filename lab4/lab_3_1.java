import java.util.*;

class StackUnderFlowExcpetion extends Exception{
		public StackUnderFlowExcpetion(){
				super("Stack Underflow!");
		}
}

class StackOverflowException extends Exception{
		public StackOverflowException(){
				super("Stack Overflow!");
		}
}

class Stack{

		int[] arr;
		int top = -1;

		public Stack(){
				arr = new int[100];
		}

		public void push(int a){
				try{
						if(this.isFull()){
								throw new StackOverflowException();
						}
				}catch(Exception e){
						return;
				}
				arr[++top] = a;
		}

		public int pop(){
				try{
						if(this.isEmpty()){
								throw new StackUnderFlowExcpetion();
						}
				}catch(Exception e){
						return -1;
				}
				return arr[top--];
		}

		public boolean isEmpty(){
				if(top == -1){
						return true;
				}
				return false;
		}

		public boolean isFull(){
				if(top == arr.length){
						return true;
				}
				return false;
		}

		public void display(){
				if(top == arr.length){
						System.out.println("Stack Overflow!");
						return;
				}else if(this.isEmpty()){
						System.out.println("Stack Underflow!");
						return;
				}
				for(int i = 0; i <= top; i++){
						System.out.println(arr[i]);
				}
		}

		public static void main(String args[]){
				Scanner sc = new Scanner(System.in);
				Stack stack = new Stack();
				while(true){
						System.out.println("Enter:\n1: Push\n2: Pop\n3: Display\nAny: Quit");
						int ch;
						ch = sc.nextInt();
						switch(ch){
								case 1:
										int x;
										System.out.println("Enter value to push");
										x = sc.nextInt();
										stack.push(x);
										break;
								case 2:
										int val = stack.pop();
										break;
								case 3:
										stack.display();
										break;
								default:
										System.out.println("Thanks for using!");
										System.exit(0);
						}
				}
		}
}
