#include<stdio.h>
#include<stdlib.h>

struct sNode
{
	int data;
	struct sNode *next;
};

struct queue
{
	struct sNode *stack1;
	struct sNode *stack2;
};

void push(struct sNode** top_ref, int new_data)
{
	struct sNode* new_node = (struct sNode*) malloc(sizeof(struct sNode));
	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

int pop(struct sNode** top_ref)
{
	int res;
	struct sNode *top;


	top = *top_ref;
	res = top->data;
	*top_ref = top->next;
	free(top);
	return res;


}
void enQueue(struct queue *q, int x)
{
	push(&q->stack1, x);
}

int deQueue(struct queue *q)
{
	int x;
	if (q->stack1 == NULL && q->stack2 == NULL)
	{
		printf("kuyruk bos\n");
		return -1;
	}

	if (q->stack2 == NULL)
	{
		while (q->stack1 != NULL)
		{
			x = pop(&q->stack1);
			push(&q->stack2, x);

		}
	}

	x = pop(&q->stack2);
	return x;
}


int main()
{
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->stack1 = NULL;
	q->stack2 = NULL;
	enQueue(q, 1);
	enQueue(q, 2);
	enQueue(q, 3);

	printf("%d ", deQueue(q));
	printf("%d ", deQueue(q));
	printf("%d ", deQueue(q));

	getchar();
}