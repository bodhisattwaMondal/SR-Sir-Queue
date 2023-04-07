#include <stdio.h>
#define SIZE 5

typedef struct priorityQueueElement
{
    char data;
    int priority;
} pqelement;

typedef struct priorityQueue
{
    pqelement pqe;
} PQ;

// special type of enqueue func.
// which will put the elements w.r.t to their priority
// following the FIFO algorithm
void prioEnQueue(PQ *queue, int *front, int *rear, char element, int prio)
{
    if (*rear >= SIZE - 1)
        printf("\nQueue Overflow !!\n");
    else
    {
        // First time entry
        if (*rear == -1)
        {
            *front = 0;
            *rear = 0;
            queue[*rear].pqe.data = element;
            queue[*rear].pqe.priority = prio;
        }
        else
        {
            int i = *rear;
            while (i >= *front && prio <= queue[i].pqe.priority)
            {
                queue[i + 1] = queue[i];
                i--;
            }
            queue[i + 1].pqe.data = element;
            queue[i + 1].pqe.priority = prio;
            ++(*rear);
        }
    }
}

int deQueue(PQ *queue, int *front, int *rear)
{
    int element;
    if (*front == -1)
        printf("\nQueue Underflow !!\n");
    else
    {
        element = queue[*front].pqe.data;
        // if only one element is present
        if (*front == *rear)
        {
            queue[*front].pqe.data = '\0';
            queue[*front].pqe.priority = '\0';
            *rear = -1;
            *front = -1;
        }
        else
        {
            queue[*front].pqe.data = '\0';
            queue[*front].pqe.priority = '\0';
            (*front)++;
        }
    }
    return element;
}

void display(PQ *queue, int *front, int *rear)
{
    if (*front == -1)
        printf("\nCan't Display : Empty Queue !!\n");
    else
    {
        printf("\nEntrie queue: [ ");
        for (int i = *front; i <= *rear; i++)
            printf("%c{%d} ", queue[i].pqe.data, queue[i].pqe.priority);
        printf("]\n");
    }
}

// Driver Code
int main()
{
    // Creating myQueue
    PQ Queue[SIZE];
    int front = -1;
    int rear = -1;

    for (int i = 0; i < SIZE; i++)
    {
        Queue[i].pqe.data = '\0';
        Queue[i].pqe.priority = '\0';
    }

    // Test Cases: 

    // 1. Empty Queue 
    display(Queue, &front, &rear);

    // 2. Priority Based Enqueue
    prioEnQueue(Queue, &front, &rear, 'H', 3);
    prioEnQueue(Queue, &front, &rear, 'Z', 6);
    prioEnQueue(Queue, &front, &rear, 'A', 1);
    prioEnQueue(Queue, &front, &rear, 'C', 2);
    display(Queue, &front, &rear);

    // 3. Dequeue
    deQueue(Queue, &front, &rear);
    display(Queue, &front, &rear);

    return 0;
}