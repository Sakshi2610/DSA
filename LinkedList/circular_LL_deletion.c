// Circular Linked List deletion in 4 ways
// 1. Deletion at begining
// 2. Deletion in between(at index)
// 3. Deletion at the end
// 4. Deletion at a given value 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do{
        printf("Elements %d\n", ptr->data);
        ptr = ptr->next;
    }while (ptr != head);
}

struct Node * deleteAtFirst(struct Node *head){
    struct Node * ptr = head;

    while(ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = head->next;
    free(head);
    head = ptr->next;
    return head;
}

struct Node * deleteAtIndex(struct Node *head, int index){
    struct Node * p = head;
    struct Node * q = head->next;
    
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}

struct Node * deleteAtEnd(struct Node *head){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->next != head){
        p = p->next;
        q = q->next;
    }
    p->next = head;
    free(q);
    return head;
}

struct Node * deleteAtValue(struct Node *head, int value){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->data != value && q->next != head){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node)); //dynamic memory creation in heap using malloc
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));    

    head->data = 7;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = head;
    printf("Before the Deletion in Linked List \n");
    linkedListTraversal(head);
    printf("\n After the Deletion in Linked List \n");
    // head = deleteAtFirst(head);
    // head = deleteAtEnd(head);
    // head = deleteAtIndex(head, 1);
    head = deleteAtValue(head, 3);
    linkedListTraversal(head);
    return 0;
}


