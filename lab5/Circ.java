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
						System.out.println("------------\nfront="+front+"\nrear="+rear);
						if(front > rear){
								for(int i = front; i < cap; i++){
										System.out.println(arr[i] + " ");
								}
								for(int i = 0; i <= rear; i++){
										System.out.println(arr[i] + " ");
								}
						}
						for(int r = front; r < rear; r++){
								System.out.print(arr[r] + " ");
						}
						System.out.println();
				}
		}
}


class Driver2{
		public static void main(String args[]){
				int len;
				Scanner sc = new Scanner(System.in);
				len = sc.nextInt();
				Queue<Integer> q1 = new Queue<Integer>(len+1);
				for(int i = 0; i < len; i++){
						int x = sc.nextInt();
						if(q1.isEmpty()){
								q1.enqueue(x);
						}else{
								q1.enqueue(x);
								q1.enqueue(q1.dequeue());
						}
						q1.show();
				}
		}
}

