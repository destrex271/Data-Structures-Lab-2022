import java.io.*;

@SuppressWarnings("unchecked")
class Queue<T>{
		T[] arr;
		int cap;
		int front = 0, rear = 0;

		public Queue(int cap){
				this.cap = cap;
				arr = (T[])new Object[this.cap];
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

		public void enqueue(T t){
				if(!isFull()){
						arr[rear++] = t;
						return;
				}
				System.out.println("Queue Overflow!");
		}

		public T dequeue(){
				if(!isEmpty()){
						return arr[front++];
				}
				System.out.println("Queue Underflow!");
				return null;
		}

		public void display(){
				if(!isEmpty()){
						for(int i = front; i<rear; i++){
								System.out.print(arr[i] + " ");
						}
				}
				System.out.println();
		}
}

class Driver{
		public static void main(String args[])throws IOException{
				BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
				int len = Integer.valueOf(bfr.readLine());
				Queue<Integer> q1 = new Queue<Integer>(len);
				Queue<Integer> q2 = new Queue<Integer>(len);

				int i = 0;
				while(i <= (len/2) - 1){
						System.out.println("Enter val");
						int x = Integer.valueOf(bfr.readLine());
						q1.enqueue(x);
						i++;
				}
				while(i < len){
						System.out.println("Enter val");
						int x = Integer.valueOf(bfr.readLine());
						q2.enqueue(x);
						i++;
				}

				q1.display();
				q2.display();

				for(i = 0; i < len; i++){
						if(i%2 == 0){
								System.out.print(q1.dequeue() + " ");
						}else{
								System.out.print(q2.dequeue() + " ");
						}
				}
		}
}
