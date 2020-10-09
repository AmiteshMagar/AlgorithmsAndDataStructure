#define TRUE 1
#define FALSE 0

#include<bits/stdc++.h>
#include<string>

using namespace std;

//Defining a node class
class Node{
public:
	//any type of data can be accepted as string datatype implemented
	string data;
	Node* next;
	Node(string value){
		data = value;
		next=NULL;
	}
};

//Defining our Data structure Queue
struct Queue{
	Node *head, *tail;
	//These are the starting and the ending of our Queue ds.
	Queue(){
		head = NULL;
		tail = NULL;
	}

	//Function to add data to our queue
	void Enqueue(string input){
		Node *temp = new Node(input);

		if (tail ==NULL) // condition for an empty queue
		{
			head = tail = temp;
			return;
			// setting both equal to the same value as only one element exists
		}

		tail -> next = temp;
		tail = temp;
		//a simple logic to append the next set of data at the tail.
		//Think of this like the old game of snake -- everytime the snake eats
		//its tail gets longer, same holds for the queue.
	}

	//function to read the queue by comparing stord data -- O(n), 
	//where n is the size of the queue.
	int Readqueue(string value){
		Node *temp = head;
		//starting at the head
		
		//empty queue, nothing to find
		if (head == NULL)
			return FALSE;

		while (temp != NULL){
			if(temp -> data == value)
				return TRUE;
				//data found

			temp = temp ->next;
		}
		return FALSE;
		//data not found after going through the queue.
	}

	void Dequeue(){

		//empty queue
        if(head == NULL)
            return;

        Node *temp = head;
        head = head->next;
        
        //condition -- last item is dequeue'd
        if(head == NULL)
            tail = NULL;
    }
};

//driver code
int main(int argc, char* argv[]){

	Queue q;

	
	/*sample code to test simple operations -- attempt 1
    q.Enqueue("Hello");
    q.Enqueue("How are you doing");
    q.Dequeue();
    q.Dequeue();
    q.Enqueue("I am doing fine");
    q.Enqueue("It was nice talking to you");
    q.Dequeue();
    q.Enqueue("Goodbye");
    q.Dequeue();
    cout << (q.head) -> data << endl;
    cout << (q.tail) -> data << endl;*/

    /*Test code for testing Readqueue() feature
    q.Enqueue("1");
    q.Enqueue("2");
    q.Enqueue("3");
    if(q.Readqueue("2"))
    {
    	cout << "Found 2" << endl;
    }

    if(q.Readqueue("5")){
    	cout << "Found 5" << endl;
    }
    else
    	cout << "5 not found" << endl;*/

    return 0;


}

