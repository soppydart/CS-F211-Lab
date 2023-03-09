#include <stdio.h>
#include <stdlib.h>
#define int long long

struct q_t
{
    int data[1000];
    int rear;
    int front;
    int size;
};
typedef struct q_t Queue;

void init(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}
void enqueue(Queue *q, int value)
{

    q->rear = (q->rear + 1) % 1000;
    q->data[q->rear] = value;
    q->size++;
}
int dequeue(Queue *q)
{
    int value = q->data[q->front];
    q->front = (q->front + 1) % 1000;
    q->size--;
    return value;
}

int josephus(Queue *q, int n, int k)
{
    for (int i = 1; i <= n; i++)
    {

        enqueue(q, i);
    }
    while (q->size > 1)
    {
        // first thing we'd need to do here would be:: for loop k - 1 times in which you dequeue and enqueue, finally dequeue once the for loop exits, and return the remaining element at the end
        for (int i = 0; i < k - 1; i++)
        {
            int value = dequeue(q);
            enqueue(q, value);
        }
        dequeue(q);
    }
    return dequeue(q);
}
int main()
{

    int n, k;
    scanf("%lld %lld", &n, &k);
    Queue q;
    init(&q);
    printf("%lld\n", josephus(&q, n, k));
}