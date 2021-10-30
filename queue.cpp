#include <iostream>

using namespace std;

#define Q_SIZE 5

typedef struct
{
    int data[Q_SIZE + 1];
    int head, tail;
} Queue;

void enqueue(Queue *q, int item);
int dequeue(Queue *q);

int main()
{
    Queue my_q;
    int item;

    my_q.head = 0;
    my_q.tail = 0;

    // enqueue call
    enqueue(&my_q, 9);
    cout << "Tail " << my_q.tail << endl;
    item = dequeue(&my_q);
    cout << "Front " << item <<endl;

    enqueue(&my_q, 9);
    enqueue(&my_q, 10);
    enqueue(&my_q, 11);
    enqueue(&my_q, 12);
    enqueue(&my_q, 13);
    enqueue(&my_q, 14);

    // dequeue
    item = dequeue(&my_q);
    item = dequeue(&my_q);
    item = dequeue(&my_q);
    item = dequeue(&my_q);
    item = dequeue(&my_q);
    item = dequeue(&my_q);

    enqueue(&my_q, 100);
    cout << "Tail " << my_q.tail << endl;
    item = dequeue(&my_q);
    cout << "Front " << item <<endl;

    return 0;
}

// enqueue
void enqueue(Queue *q, int item)
{
    if((q->tail + 1) % (Q_SIZE + 1) == q->head)
    {
        cout << "Queue is Full."<<endl;
        return;
    }
    q->data[q->tail] = item;
    q->tail = (q->tail + 1) % (Q_SIZE + 1);
}

// dequeue
int dequeue(Queue *q)
{
    int item;

    if(q->tail == q->head)
    {
        cout << "Queue is Empty."<<endl;
        return -1;
    }
    item = q->data[q->head];
    q->head = (q->head + 1) % (Q_SIZE + 1);

    return item;
}
