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
						rear = (rear + 1) % cap;
				}else{
						System.out.println("Queue overflow!");
				}
		}

		public T dequeue(){
				if(!isEmpty()){
						T val = arr[front];
						front = (front+1) % cap;
						return val;
				}else{
						System.out.println("Queue underflow");
						return null;
				}
		}

		public void show(){
				System.out.println("------------\nfront="+front+"\nrear="+rear);
				int i = front;
				do{
					System.out.println(arr[i]);
					i = (i+1) % cap;
				}while(i != rear);
		}
}

class Driver{
    public static void main(String args[]){
        System.out.println("Enter the length of your queue");
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        Queue<Integer> queue = new Queue<Integer>(len);
        while(true){
            System.out.println("Enter: 1. Enqueue\n 2. Dequeue\n 3. Check if queue is Empty\n 4. Check if queue is Full\n 5. Display\n Any key to exit");
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
                default:
                        System.exit(0);
            }
        }
    }
}