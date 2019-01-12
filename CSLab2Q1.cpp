#include <iostream>
using namespace std;
class node
{
public:
    //data
    int data;
    //pointer for the next node
    node *next;
    //construct that make it null
    node()
    {
        next=NULL;
    }
};
class linkedlist
{
    //HEAD AND CIRCLE ARE LINKED TO EACH OTHER
public:
    node * head;
    node * tail;
    //construct that make it null
    linkedlist()
    {
        head=NULL;
        tail=NULL;
    }
    //a. insert(int data)- Adds a new element to the end of the linked list.
     // Insert
    void insert(int value){
       // If 1st Node is added
       node * temp = new node;
       // Insert value in the node
       temp->data = value;
       // 1st Node only.
       if(head == NULL){
            head = temp;
       }
       // Any other Node only.
       else{
            tail->next = temp;
       }
       tail = temp;
    }
    void insertat(int pos, int value){
        // Reach the place before the pos
        node * current = head;
        int i =1;
        while(i < pos-1){
            i++;
            current = current->next;
        }
        // Create a node
        node * temp = new node;
        temp -> data = value;


        // Moving ptrs like magic ! if not head
        temp->next = current->next;
        current->next = temp;

        // Update the code for 1st position

    }

    // Deletion of last element
    void delet(){
        // store the tail in temp
        node * temp = tail;
        // before tail has to point to null
        node * current = head;
        while(current->next != tail){
            current = current->next;
        }
        current->next = NULL;

        //  to update tail
        tail = current;
        // to delete temp
         delete temp;
    }
    // for displaying data
    void display(){
        node * current = head;
        while(current != NULL){
            cout << current->data << "->";
            current = current->next;
        }
        cout << endl;
    }
    //using delete at
    void deleteat(int pos ){

	node * current = head;
	int n = 1;
	while(n<pos-1){
		n++;
		current = current->next;
		}
	node * temp = new node ;

	temp->next = current->next;
	current->next = current -> next -> next;
	delete temp;
	}
	//using count
	void count(){
	node *current = head;

	cout<<"the no. of linked list is ";
	int n=0;
	while(current != NULL){
		n++;
		current=current->next;
	}
	cout<<n<<endl;
	}

};
    int main(){
    linkedlist m1;
        m1.insert(1);
        m1.insert(2);
        m1.insert(3);
        m1.insert(4);
        m1.display();
        m1.delet();
        m1.count();
        m1.display();
        m1.display();
        m1.insertat(1,3);
        m1.display();
return 0;
}
