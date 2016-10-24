//Queue
//FIFO

#include <iostream>

using namespace std;

class QueuE
{
private:
    int *queueArray;
    int queueSize;
    int front;
    int rear;
    int num_items;
public:
    QueuE(int s)
    {
        queueArray = new int[s];
        queueSize = s;
        front = -1;
        rear = -1;
        num_items = 0;
    }
    bool isEmpty()
    {
        if (num_items)
            return false;
        else
            return true;
    }
    bool isFull()
    {
        if (num_items < queueSize)
            return false;
        else
            return true;
    }
    void enqueue(int data)
    {
        if (isFull())
            cout << "queue is full" << endl;
        else
        {
            rear = (rear+1) % queueSize;
            queueArray[rear] = data;
            num_items++;
        }
    }
    int dequeue()
    {
        if (isEmpty())
            cout << "queue is empty" << endl;
        else
        {
            int tempFront = front;
            front = (front + 1) % queueSize;
            num_items--;
            return queueArray[tempFront];
        }
    }
    void print_queue()
    {
        cout << "front --> ";
        for (int i = 0; i < num_items; i++)
            cout << queueArray[i] << " ";
        cout << endl;
    }
};

int main()
{
    QueuE q(10);
    q.enqueue(5);
    q.enqueue(10);
    q.print_queue();
    q.dequeue();
    q.print_queue();
    q.enqueue(6);
    q.enqueue(100);
    q.enqueue(75);
    q.print_queue();

    return 0;
}
