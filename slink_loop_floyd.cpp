// C program to detect loop in a linked list 
#include<stdio.h> 
#include<stdlib.h> 
#include <iostream>
#include  <memory> 
  
/* Link list node */
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  
struct NodeP 
{ 
    int data; 
    std::shared_ptr<NodeP> next;
}; 
  
void pushP(std::shared_ptr<NodeP> & head_ref, int new_data) 
{ 
    /* allocate node */
    std::shared_ptr<NodeP> new_nodeP =  std::make_shared<NodeP>();
           
    /* put in the data  */
    new_nodeP->data  = new_data; 
  
  
    /* link the old list off the new node */
    new_nodeP->next = head_ref; 
  
    /* move the head to point to the new node */
    head_ref    = new_nodeP; 

} 
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node =  new Node();
           
  
    /* put in the data  */
    new_node->data  = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
} 
  
int detectloopP(std::shared_ptr<NodeP> list)
{ 
    std::shared_ptr<NodeP>  slow_p = list, fast_p = list; 
   
         printf("At data points slow %d fast %d\n",slow_p->data,fast_p->data); 
    while (slow_p && fast_p && fast_p->next ) 
    { 
        slow_p = slow_p->next; 
        fast_p  = fast_p->next->next; 
         printf("At data points slow %d fast %d\n",slow_p->data,fast_p->data); 
        if (slow_p == fast_p) 
        { 
           printf("Found Loop\n"); 
           return 1; 
        } 
    } 
    return 0; 
} 
  
int detectloop(struct Node *list) 
{ 
    struct Node  *slow_p = list, *fast_p = list; 
   
    while (slow_p && fast_p && fast_p->next ) 
    { 
         printf("At data points slow %d fast %d\n",slow_p->data,fast_p->data); 
        slow_p = slow_p->next; 
        fast_p  = fast_p->next->next; 
        if (slow_p == fast_p) 
        { 
           printf("Found Loop\n"); 
           return 1; 
        } 
    } 
    return 0; 
} 
  
/* Drier program to test above function*/
int testLoop() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
    std::shared_ptr<NodeP> headP = nullptr;
  
    pushP(headP, 60); 
    pushP(headP, 50); 
    pushP(headP, 40); 
    pushP(headP, 30); 
    pushP(headP, 20); 
    pushP(headP, 10); 
    /*
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 10); 
 */ 
    /* Create a loop for testing */
  //  head->next->next->next->next = head; 
    headP->next->next->next->next = headP; 
   // detectloop(head); 
    detectloopP(headP); 
  
    return 0; 
} 

int main()
{
	return(testLoop());
}
