#include<iostream>
using namespace std;
#define NEXT(index,QSIZE) ((index+1)%QSIZE)

typedef struct Queue {
	int* buf;
	int qsize;
	int front;
	int rear;
	int count;
}Queue;

void InitQueue(Queue* queue, int qsize)
{
	queue->buf = new int[qsize];
	queue->qsize = qsize;
	queue->front = queue->rear = 0;
	queue->count = 0;
}

int IsFull(Queue* queue)
{
	return queue->count == queue->qsize;
}

int IsEmpty(Queue* queue)
{
	return queue->count == 0;
}

void Enqueue(Queue* queue, int data)
{
	if (IsFull(queue)) {
		cout << "ť�� �� á��\n";
		return;
	}
	queue->buf[queue->rear] = data;
	queue->rear = NEXT(queue->rear, queue->qsize);
	queue->count++;
}

int Dequeue(Queue* queue)
{
	int re = 0;
	if (IsEmpty(queue))
	{
		cout << "ť�� �����\n";
		return re;
	}
	re = queue->buf[queue->front];
	queue->front = NEXT(queue->front, queue->qsize);
	queue->count--;
	return re;
}

int main(void)
{
	int i;
	Queue queue;

	InitQueue(&queue, 10);
	for (i = 1; i <= 5; i++) {
		cout << i << "�Է�\n";
		Enqueue(&queue, i);
	}
	cout << endl;

	while (!IsEmpty(&queue)) {
		cout << Dequeue(&queue) << "���\n";
	}
	cout << endl;
	return 0;
}