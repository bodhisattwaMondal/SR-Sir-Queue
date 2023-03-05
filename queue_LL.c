#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int element;
    struct Queue *next;
}Queue;

void enQueue(Queue **front, Queue **rear, int element){
    // Creating new node 
    Queue *newNode = (Queue *)malloc(sizeof(Queue));
    newNode->element = element;
    newNode->next = NULL;
    // if queue is initially empty 
    if (*front == NULL && *rear == NULL)
    {
        *front = newNode;
        *rear = newNode;
    }
    // appending in the queue
    else{
        (*rear)->next = newNode;
        *rear = newNode;
    }
    
}

void deQueue(Queue **front, Queue **rear){
    if (*front == NULL && *rear == NULL)
        printf("Can't dlt - Empty Queue !!");
    else
    {
        Queue *temp = *front;
        *front = (*front)->next;
        // if only one element in the queue
        if (*front == NULL)
            *rear = *front;
        free(temp);
    }
}

int peak(Queue *front){
    if (front == NULL)
        printf("Can't display - Empty Queue!!");
    else
        return front->element;
    
}

void display(Queue *front, Queue *rear){
    if (front == NULL && rear == NULL)
        printf("Can't display - Empty Queue!!");
    else{
        Queue *temp = front;
        printf("\nEntire Queue: \n");
        while (temp != NULL)
        {
            printf("%d->", temp->element);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Driver Code 
int main()
{
    Queue *front = NULL;
    Queue *rear = NULL;

    enQueue(&front, &rear, 45);
    enQueue(&front, &rear, 9);
    enQueue(&front, &rear, 6);
    printf("Element at front: %d ", peak(front));
    display(front, rear);

    deQueue(&front, &rear);
    display(front, rear);

    return 0;
}