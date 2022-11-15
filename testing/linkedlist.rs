
struct Node{
    val: isize,
    next: *mut Node
};

struct LinkedList{
    head: Node,
    current: Node
}

pub trait ListBehaviour{
    fn addNode(&mut self, val: isize){
        let n1 = Node{
            val: 10,
        };
        self.current.next = n1;
        self.current = n1;
    }
}

fn main(){
    println!("Test");
}
