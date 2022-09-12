import java.io.*;

class Queue<T>{
		T[] arr;
		int cap;
		int front = 0, rear = 0;

		public boolean isFull(){
				if(rear == cap){
						return true;
				}
				return false;
		}

		public boolean isEmpty(){
				if(rear == front)
						return true;
				return false;
		}

		public void enqueue(T t){
				if(isFull()){
						System.out.println("Stack Overflow!");
						return;
				}
				arr[rear++] = t;
		}

		public T dequeue(){
				if(isEmpty()){
						System.out.println("Stack Underflow!");
						return null;
				}
				return arr[front++];
		}

		public T peek(){
				if(!isEmpty()){
						return arr[rear-1];
				}
				return null;
		}
		
		public void show(){
				if(!isEmpty()){
						for(int i = front; i <= rear; i++){
								System.out.print(arr[i] + " ");
						}
						System.out.println();
				}
		}

}

class Main{
		public static void main(String args[]){
				BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
				Queue
				while(true){
						System.out.println("Enter:\n1: To enqueue elements\n2: To dequeue elements\n3: To Check if queue is Empty\n4: To check if queue is full\n5: To display queue\n6: To check last value stored\nAny: To exit");
						int ch = Integer.parseInt(bfr.readLine());
						switch(ch){
								case 1:

						}
				}
		}
}
