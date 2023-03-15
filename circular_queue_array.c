#include <stdio.h>
#define SIZE 5

void enQueue(int *queue, int *front, int *rear, int item)
{

    // Checking for Queue Overflow !!
    if ((*front == 0 && *rear == SIZE - 1) || (*front == *rear + 1))
        printf("\nQueue Overflow !!\n");

    else
    {
        if (*front == -1)
            *front = 0;
        *rear = ((*rear) + 1) % SIZE; // circular increment of rear
        queue[*rear] = item;
        printf("\nInserted -> %d", item);
    }
}

int deQueue(int *queue, int *front, int *rear)
{
    int element;
    // Checking for Queue Underflow !!
    if (*front == -1)
        printf("\nQueue Underflow !!\n");
    else
    {
        element = queue[*front];
        if (*front == *rear)
        {
            *front = -1;
            *rear = -1;
        }
        else
        {
            queue[*front] = '\0';
            *front = ((*front) + 1) % SIZE; // Circular increment of front
        }
        printf("\nDeleted -> %d\n", element);
        return element;
    }
}

void display(int *queue, int *front, int *rear)
{
    int i;
    // Checking for Queue Underflow !!
    if (*front == -1)
        printf("\nCan't display: Queue Underflow !!\n");
    else
    {
        printf("\nFront -> %d(index)", *front);
        printf("\nEntire Queue: [ ");
        for (i = *front; i != *rear; i = (i + 1) % SIZE)
            printf("%d ", queue[i]);
        printf("%d ]\n", queue[i]);
        printf("Rear -> %d(index)\n", *rear);
    }
}

// Driver Code
int main()
{
    // Creating my Queue
    int circularQueue[SIZE];
    int front = -1;
    int rear = -1;
    for (int i = 0; i < SIZE; i++)
        circularQueue[i] = '\0';

    // Fails because front = -1
    deQueue(circularQueue, &front, &rear);

    enQueue(circularQueue, &front, &rear, 1);
    enQueue(circularQueue, &front, &rear, 2);
    enQueue(circularQueue, &front, &rear, 3);
    enQueue(circularQueue, &front, &rear, 4);
    enQueue(circularQueue, &front, &rear, 5);

    // Fails to enqueue because front == 0 && rear == SIZE - 1
    enQueue(circularQueue, &front, &rear, 6);

    display(circularQueue, &front, &rear);
    deQueue(circularQueue, &front, &rear);

    display(circularQueue, &front, &rear);

    enQueue(circularQueue, &front, &rear, 7);
    display(circularQueue, &front, &rear);

    // Fails to enqueue because front == rear + 1
    enQueue(circularQueue, &front, &rear, 8);
    return 0;
}