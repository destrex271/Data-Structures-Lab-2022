import java.io.*;

@SuppressWarnings("unchecked")
class CircularQueue<T>{
		T[] arr;
		int cap;
		int front = 0, rear = 0;

		public CircularQueue(int len){
				this.cap = len;
				arr = (T[]) new Object[cap];
		}

		public void enqueue(T t){
				if(!isFull()){
						arr[rear] = t;
						rear = (rear + 1) % cap;
						return;
				}
				System.out.println("Queue Overflow!");
		}

		public T dequeue(){
				if(!isEmpty()){
						T val = arr[front];
						front = (front + 1) % cap;
						return val;
				}
				System.out.println("Queue Underflow!");
				return null;
		}

		public boolean isFull(){
				if(rear == cap)
						return true;
				return false;
		}

		public boolean isEmpty(){
				if(rear == front)
						return true;
				return false;
		}

		public void peek(){
				if(!isEmpty())
						System.out.println(arr[rear-1]);
		}

		public void display(){
				if(!isEmpty()){
						if(front > rear){
								for(int i = front; i < cap; i++){
										System.out.print(arr[i] + " ");
								}
								for(int i = 0; i <= rear; i++){
										System.out.print(arr[i] + " ");
								}
						}else{
								for(int i = front; i < rear; i++){
										System.out.print(arr[i] + " ");
								}
						}
						System.out.println();
				}
		}
}

class Driver{
		public static void main(String args[])throws IOException{
				BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
				int len = Integer.valueOf(bfr.readLine());
				CircularQueue<Integer> cq = new CircularQueue<Integer>(len);
				boolean running = true;
				while(running){
						int ch = Integer.valueOf(bfr.readLine());
						switch(ch){
								case 1:
										int x = Integer.valueOf(bfr.readLine());
										cq.enqueue(x);
										break;
								case 2:
										System.out.println(cq.dequeue());
										break;
								case 3:
										System.out.println(cq.isEmpty());
										break;
								case 4:
										System.out.println(cq.isFull());
										break;
								case 5:
										cq.peek();
										break;
								case 6:
										cq.display();
						}
				}
		}
}
