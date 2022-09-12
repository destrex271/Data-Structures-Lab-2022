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
}

class Driver{
    public static void error(String x, int i, char rep){
        System.out.println("-----------------------------------");
        for(int k = 0; k <= i-1; k++){
            System.out.print(""+x.charAt(k));
        }
        System.err.println("\""+x.charAt(i)+"\"");
        System.err.println("Please Replace by "+ rep);
        System.out.println("-----------------------------------");
    }
    public static char getRep(char rep){
        if(rep == '('){
            return ')';
        }else if(rep == '['){
            return '[';
        }else if(rep == '{'){
            return '}';
        }
        return '\n';
    }
    public static void main(String args[]){
        String exp; 
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Expression: ");
        exp = sc.nextLine();
        Stack stx = new Stack(exp.length());
        boolean failed = false;
        char t;
        for(int i = 0; i < exp.length(); i++){
            char x = exp.charAt(i);
            switch(x){
                case '(':
                case '{':
                case '[':
                    stx.push(x);
                    break;
                case ')':
                    t = stx.pop();
                    if(t != '('){
                        error(exp,i,getRep(t));
                        failed = true;
                    }
                    break;
                case '}':
                    t = stx.pop();
                    if(t != '{'){
                        error(exp,i,getRep(t));
                        failed = true;
                    }
                    break;
                case ']':
                    t = stx.pop();
                    if(t != '['){
                        error(exp,i,getRep(t));
                        failed = true;
                    }
                    break;
            }
        }
        if(!failed){
            System.out.println("Expression valid");
        }
        sc.close();
    }
}