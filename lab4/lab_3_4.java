import java.util.*;

class Stack{
    char[] arr;
    int top = -1;
    int len;

    public Stack(int len){
        this.len = len;
        arr = new char[this.len];
    }

    public boolean isFull(){
				if(top == this.len){
						return true;
				}
        return false;
    }

    public boolean isEmpty(){
        // boolean val = false;
				if(top == -1){
						return true;
				}
        return false;
    }

    public void push(char c){
        if(!this.isFull())
            arr[++top] = c;
        return;
    }
    
    public char pop(){
        if(!this.isEmpty())
            return arr[top--];
        return '\n';
    }

		public char cur(){
				if(top == -1){
						return '\n';
				}
				return arr[top];
		}

		public void show(){
				if(!isEmpty()){
						for(int i = top; i < len; i++){
								System.out.print(arr[i] + " ");
						}
				}
				System.out.println();
		}

}

class InfixToPostFix {
		public static int precendence(char c){
				if(c == '+' || c == '-'){
						return 2;
				}else if(c == '*' || c == '/'){
						return 1;
				}
				return 0;
		}
		public static void main(String args[]){
				Scanner sc = new Scanner(System.in);
				String expression = sc.nextLine();
				String postfix = "";
				Stack stack = new Stack(expression.length());
				for(int i = 0; i < expression.length(); i++){
						char t = expression.charAt(i);
						// System.out.println(t);
						if(Character.isLetter(t)){
								postfix += t + "";
						}else{
								switch(t){
										case '(':
												stack.push(t);
												break;
										case ')':
												while(true){
														char c = stack.pop();
														if(c == '('){
																break;
														}else{
																postfix += c;
														}
												}
												break;
										default:
												stack.push(t);
												while(!stack.isEmpty()){
														if(precendence(stack.cur()) <= precendence(stack.cur())){
																break;
														}else{
																postfix += stack.pop();
																stack.push(t);	
														}
												}
								}
						}
						// stack.show();
						// System.out.println("Postfix: " + postfix);
				}
				while(!stack.isEmpty()){
						postfix += stack.pop();
				}
				System.out.println("Postfix: " + postfix);
				sc.close();
		}
}
