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
				int len;
				Scanner sc = new Scanner(System.in);
				len = sc.nextInt();
				Queue<Integer> q1 = new Queue<Integer>(len*2);
				Queue<Integer> q2 = new Queue<Integer>(len*2);
				int x = sc.nextInt();
				q1.enqueue(x);
				for(int i = 1; i < len; i++){
						x = sc.nextInt();
						if(i%2 == 0){
								q1.enqueue(x);
								while(!q2.isEmpty()){
										q1.enqueue(q2.dequeue());	
								}
						}else{
								q2.enqueue(x);
								while(!q1.isEmpty())
										q2.enqueue(q1.dequeue());
						}
				}
				if(len % 2 == 0){
						q2.show();
				}else{
						q1.show();
				}
		}
}
