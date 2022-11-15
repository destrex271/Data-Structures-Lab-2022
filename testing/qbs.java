import java.util.*;

class Queue{
		int[] arr;
		int cap;
		int front = 0;
		int rear = 0;

		public Queue(int len){
				this.cap = len;
				arr = new int[cap];
		}

		void enqueue(int x){
				if(rear == cap-1){
						System.out.println("Queue Overflow!");
						return;
				}
				arr[rear++] = x;
		}

		int dequeue(){
				if(front == rear){
						System.out.println("Queue Overflow");
				}
				return arr[front++];
		}
}

class Driver{
		public static void main(String args[]){
				Queue q1 = new Queue(4);
				Queue q2 = new Queue(4);

				Scanner sc = new Scanner(System.in);
				for(int i = 0; i < q1.cap; i++){
						int x = sc.nextInt();
						q1.enqueue(x);
				}
		}
}
