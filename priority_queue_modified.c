#include <stdio.h>
#define SIZE 5

typedef struct priorityQueueElement
{
    char data;
    int prio;
} pqelem;

typedef struct priorityQueue
{
    pqelem pqe;
} PQ;

void priorityEnqueue(PQ *queue, pqelem elem, int *rear, int *front);
void deQueue(PQ *queue, int *rear, int *front);
void display(PQ *Queue, int *rear, int *front);

// Driver Code
int main()
{
    PQ Queue[SIZE];
    int front = -1;
    int rear = -1;

    for (int i = 0; i < SIZE; i++)
    {
        Queue[i].pqe.data = '\0';
        Queue[i].pqe.prio = '\0';
    }

    // Test Cases :
    // Empty Queue
    display(Queue, &rear, &front);

    // Priority Enqueue
    pqelem element;
    element.data = 'A';
    element.prio = 3;
    priorityEnqueue(Queue, element, &rear, &front);

    element.data = 'B';
    element.prio = 5;
    priorityEnqueue(Queue, element, &rear, &front);

    element.data = 'J';
    element.prio = 8;
    priorityEnqueue(Queue, element, &rear, &front);
    display(Queue, &rear, &front);

    element.data = 'C';
    element.prio = 1;
    priorityEnqueue(Queue, element, &rear, &front);
    display(Queue, &rear, &front);

    // Dequeue
    deQueue(Queue, &rear, &front);
    display(Queue, &rear, &front);
    return 0;
}

// special type of enqueue func.
// which will put the elements w.r.t to their priority
// following the FIFO algorithm
void priorityEnqueue(PQ *queue, pqelem elem, int *rear, int *front)
{
    // Queue Overflow Check
    if ((*rear) + 1 >= SIZE)
        printf("Queue Overflow !!");
    else
    { // Element will be inserted in the queue

        // First time entry
        if (*rear == -1)
        {
            queue[0].pqe = elem;
            *rear = 0;
            *front = 0;
        }
        else
        {
            int i = *rear;
            while (i >= *front && elem.prio <= queue[i].pqe.prio)
            {
                queue[i + 1].pqe = queue[i].pqe;
                i--;
            }
            queue[i + 1].pqe = elem;
            ++(*rear);
        }
    }
}

void deQueue(PQ *queue, int *rear, int *front)
{
    if (*front == -1 && *rear == -1)
        printf("Queue Underflow !!\n");
    else if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        queue[*front].pqe.data = '\0';
        queue[*front].pqe.prio = '\0';
        (*front)++;
    }
}

void display(PQ *queue, int *rear, int *front)
{
    if (*front == -1)
        printf("\nCan't Display : Empty Queue !!\n");
    else
    {
        printf("\nEntrie queue: [ ");
        for (int i = *front; i <= *rear; i++)
            printf("%c{%d} ", queue[i].pqe.data, queue[i].pqe.prio);
        printf("]\n");
    }
}
