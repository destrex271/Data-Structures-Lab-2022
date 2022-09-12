import java.util.*;

class Stack{
		
		char[] arr;
		int top = -1;
		int len;

		public Stack(int len){
				this.len = len;
				arr = new char[this.len];
		}

		public void push(char l){
				if(top == len){
						System.out.println("Stack OverFlow!");
						return;
				}
				arr[++top] = l;
		}

		public boolean isEmpty(){
				if(top == -1){
						return false;
				}
				return true;
		}

		public char pop(){
				if(top == -1){
						System.out.println("Stack Underflow!");
						//top --;
						return '\n';
				}
				return arr[top--];
		}

		public static void main(String args[]){
				Scanner sc = new Scanner(System.in);
				System.out.print("Enter String: ");
				String x = sc.nextLine();
				Stack st = new Stack(x.length());
				for(int i = 0; i < x.length(); i++){
						char t = x.charAt(i);
						if(t != ' '){
								st.push(t);
						}
				}
				while(st.isEmpty()){
						System.out.print(""+st.pop());
				}
				System.out.println();
		}
}
