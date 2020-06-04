#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *a;
};
void create(struct queue *q,int size)
{
    q->size=size;               //no need of this in case size is obtained from user
    q->front=q->rear=-1;
    q->a=(int *)malloc(q->size * sizeof(int));

}
void enqueue(struct queue *q,int x)
{
    if(q->rear==q->size-1)
    {
        printf("Sorry queue is full\n
               ");
    }
    else
    {
        q->rear++;
        q->a[q->rear]=x;
    }
}
int dequeue(struct queue *q)
{
    int x=-1;
    if(q->front == q->rear)
        printf("SOrry queue is empty\n");
    else
    {
        q->front++;
        x=q->a[q->front];
        free(q->a[q->front]);
    }
    return x;
}
void display(struct queue q)
{
    int i;
    for(i=q.front+1;i<=q.rear;i++)
        printf("%d ",q.a[i]);
    printf("\n");
}
int main()
{
   struct queue q;
   create(&q,6);     //create(&q,q.size)//sf the q size

   enqueue(&q,10);
   enqueue(&q,20);
   enqueue(&q,30);
   enqueue(&q,40);
   enqueue(&q,50);
   enqueue(&q,60);

   display(q);
   printf("%d ",dequeue(&q));
   //display(q);

}
