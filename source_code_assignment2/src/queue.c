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
	if (empty(q)) printf("Underflow\n");
	else {
		uint32_t max_priority = q->proc[0]->priority;
		for (int i = 0; i < q->size; i++) {
			if (q->proc[i]->priority > max_priority) {
				max_priority = q->proc[i]->priority;
			}
		}
		for (int i = 0; i < q->size; i++) {
			if (q->proc[i]->priority == max_priority) {
				struct pcb_t * tmp = q->proc[i];
				for (int j = i; j < q->size - 1; j++) {
					q->proc[j] = q->proc[j + 1];
				}
				q->size --;
				return tmp;			
			}
		}
	}
	return NULL;
}

