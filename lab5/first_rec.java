import java.util.*;


@SuppressWarnings("unchecked")
class Queue<T>{
    T[] arr;
    int cap;
    int front = 0, rear = 0;

    public Queue(int len){
        this.cap = len;
        arr = (T[]) new Object[cap];
    }

    public boolean isFull(){
        if(rear == cap){
                return true;
        }
        return false;
    }

    public boolean isEmpty(){
        if(front == rear){
                return true;
        }
        return false;
    }

    public void enqueue(T t){
        if(!isFull()){
                arr[rear] = t;
                rear = (rear + 1) ;
        }else{
                System.out.println("Queue overflow!");
        }
    }

    public T dequeue(){
        if(!isEmpty()){
                T val = arr[front];
                front = (front+1);
                return val;
        }else{
                System.out.println("Queue underflow");
                return null;
        }
    }

    public void show(){
        if(!isEmpty()){
            for(int r = front; r < rear; r++){
                    System.out.print(arr[r] + " ");
            }
            System.out.println();
			}
	}

    public T peek(){
        if(!isEmpty()){
            return arr[front];
        }
        return null;
    }
}


class Driver{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Queue<Character> q = new Queue<Character>(s.length());
        for(int i = 0; i < s.length(); i++){
            q.enqueue(s.charAt(i));
        }
        while(true){
            if(q.isEmpty()){break;}
            char a = q.dequeue();
            int count = 0;
            // q.show();
            while(q.peek() == a){
                q.dequeue();
                // q.show();
                count++;
            }
            if(count == 0){
                System.out.println(a + " is the first not repeating character.");
                break;
            }
            System.out.println("----------------------------");
        }
    }
}