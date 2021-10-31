#include <iostream>

using namespace std;
#define CAPACITY 5

int data[CAPACITY];
int front = 0, rear = -1, total_item = 0;

bool is_full();
bool is_data_empty();
void print_array();
void enqueue(int item);
int dequeue();

int main(void)
{
    int item;

    enqueue(11);
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    enqueue(16);
    print_array();
    item = dequeue();
    cout << "Dequeue data: " << dequeue() << " " <<  endl;
    cout << "Dequeue data: " << dequeue() << " " <<  endl;
    cout << "Dequeue data: " << dequeue() << " " <<  endl;
    cout << "Dequeue data: " << dequeue() << " " <<  endl;
    cout << "Dequeue data: " << dequeue() << " " <<  endl;
    print_array();
    enqueue(16);
    print_array();

    return 0;
}

// is array full
bool is_full()
{
    if(total_item == CAPACITY)
        return true;
    return false;
}

// is array empty
bool is_data_empty()
{
    if(total_item == 0)
        return true;
    return false;
}

// enqueue method
void enqueue(int item)
{
    if(is_full())
    {
        cout << "Array is full." << endl;
        return;
    }
    rear = (rear + 1) % CAPACITY;
    data[rear] = item;
    total_item++;
}

// dequeue method
int dequeue()
{
    int item;

    if(is_data_empty())
    {
        cout << "Data is Empty." << endl;
        return -1;
    }
    item = data[front];
    data[front]  = -1;
    front = (front + 1) % CAPACITY;
    total_item--;

    return item;
}

// print array
void print_array()
{
    cout << "Data: ";
    for(int i = 0; i < CAPACITY; i++)
    {
        cout << data[i] << " ";
    }
    cout << "\n";
}
