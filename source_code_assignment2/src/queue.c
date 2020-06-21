#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	int rear = q->size - 1;
	if (empty(q)) {
		rear = 0;
		q->proc[rear + 1] = proc;
		q->size++;
	}
	if (!empty(q)) {
		if (rear == MAX_QUEUE_SIZE - 1) {
			printf("Overflow\n");
		}
		else {
			q->proc[rear + 1] = proc;
			q->size++;
		}
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	return NULL;
}

