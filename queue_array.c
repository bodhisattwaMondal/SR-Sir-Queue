#include <stdio.h>

#define SIZE 5

void enQueue(int *queue, int *front, int *rear, int element){

    if (*front == -1 && *rear == -1)
    {
        *front = 0;
        *rear = 0;
        queue[*rear] = element;
    }
    else if (*rear + 1 >= SIZE)
        printf("Queue Overflow !!\n");
    else
        queue[++(*rear)] = element; 
}

void deQueue(int *queue, int *front, int* rear){
    if(*front == -1 && *rear == -1)
        printf("Queue Underflow !!\n");
    else if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        int var = queue[*front];
        queue[*front] = '\0';
        (*front)++;
    }
}

int peak(int *queue, int *front){
    if (*front == -1)
        printf("Can't Display: Queue is empty !!\n");
    else
        return queue[*front];
}

void display(int *queue, int *front, int *rear){
    printf("\nEntrie queue: [ ");
    for (int i = *front; i <= *rear; i++)
        printf("%d ", queue[i]);
    printf("]\n");
}

// Driver Code 
int main()
{
    int Queue[SIZE];
    int front = -1;
    int rear = -1;

    for (int i = 0; i < SIZE; i++)
        Queue[i] = '\0';
    
    enQueue(Queue, &front, &rear, 45);
    enQueue(Queue, &front, &rear, 5);
    display(Queue, &front, &rear);

    printf("Front element: %d", peak(Queue, &front));

    deQueue(Queue, &front, &rear);
    display(Queue, &front, &rear);
    return 0;
}