#include <iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node *next; 
    
    Node(int value){
        data = value; 
        next = NULL;
    }
    
};

Node* LinkedList(int arr[], int index, int size){
    if(index == size)
    return NULL;
    
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = LinkedList(arr, index+1, size); 
    return temp; 
}




int main()
{
    Node *Head;
    Head = NULL;
    
    int arr[] = {2,3,4,5,6};
    
    Head = LinkedList(arr,0,5);
    
    Node *temp; 
    temp = Head;
    
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}