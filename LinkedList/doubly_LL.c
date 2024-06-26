// Doubly Linked List creation and Traversal in one code

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
    
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
    head->prev = NULL;

    second->data = 8;
    second->next = third;
    second->prev = head;

    third->data = 2;
    third->next = fourth;
    third->prev = second;

    fourth->data = 5;
    fourth->next = NULL;
    fourth->prev = third;

    linkedListTraversal(head);
    return 0;
}


