//a simple c++ program for taversal of a linked list.

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
   
    Node* next;

};
void printList(Node* n)
{
    while(n != NULL){
        cout<< n->data <<" " ;
        n = n->next;
    }
}
//add a new node at the starting of linkedlist.
//sol :push function take a reference of head node and the new data 
void push(Node **head,int new_data){
    //allocate Node
    Node *new_Node = new Node();
    //put in the data
    new_Node->data = new_data;
    //made the next of new Node as head
    new_Node->next = *head;
    //move the head pointer to the new node
    (*head) = new_Node;

}
//inserting a node after a given node

void insertAfter(Node * prev_node,int new_data){
    //Check if the given prev_node is Null
    if(prev_node == NULL){
        return;
    }
    //allocate a new node
    Node *new_node = new Node(); 
    //insert in the data
    new_node->data = new_data;
    //make next of new_node as next of prev_node
    new_node->next = prev_node->next;
    //move the next of prev_node in next of new_node
    prev_node->next = new_node;

}

void insertend(Node **head_ref ,int new_data){
    //Allocate a node
    Node *new_node = new Node();
    
    Node* last_node = *head_ref;

    //Put in data
    new_node->data = new_data;

    //this new node is going to be the last node, so make next of new node is null
    new_node->next =NULL;

    //if the linkedlist is empty then make the new node as head
    if(*head_ref == NULL){
     *head_ref = new_node;
     return;
    }

     //Else traverse till the last node.
     while(last_node->next != NULL){
         last_node =last_node->next;
     }
        

     //Change the next of last node
     last_node->next=new_node;
     return;

    


}

int main ()
{
    Node* head = NULL;
    Node* second =NULL;
    Node* third =NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data =  1;
    head->next = second;

    second->data =2;
    second->next =third;

    third->data = 3;
    third->next = NULL;

    printList(head);

    push(&head,5);
    cout<< '\n' ;
    printList(head);

    insertAfter(head-> next->next, 6);
    cout<< '\n' ;
    printList(head);

    insertend(&head, 7);
    cout<< '\n' ;
    printList(head);


    return 0;
}