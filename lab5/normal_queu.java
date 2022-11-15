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

    public void peek(){
        if(!isEmpty()){
            System.out.println("Current value is: " + arr[rear-1]); 
        }else{
            System.out.println("Queue is Empty");
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
}

class Driver{
    public static void main(String args[]){
        System.out.println("Enter the length of your queue");
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        Queue<Integer> queue = new Queue<Integer>(len);
        while(true){
            System.out.println("Enter: 1. Enqueue\n 2. Dequeue\n 3. Check if queue is Empty\n 4. Check if queue is Full\n 5. Display\n 6. Peek\n Any key to exit");
            int ch = sc.nextInt();
            switch(ch){
                case 1:
                        System.out.println("Enter the value you want to enqueue");
                        int x = sc.nextInt();
                        queue.enqueue(x);
                        break;
                case 2:
                        System.out.println("Dequeued: " + queue.dequeue());
                        break;
                case 3:
                        System.out.println("Queue is : " + (queue.isEmpty()?"Empty":"Not Empty"));
                        break;
                case 4:
                        System.out.println("Queue is : " + (queue.isFull()?"Full":"Not Full"));
                        break;
                case 5:
                        queue.show();
                        break;
                case 6:
                        queue.peek();
                        break;
                default:
                        System.exit(0);
            }
        }
    }
}
