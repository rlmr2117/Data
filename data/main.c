#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack1[MAX_SIZE];
int stack2[MAX_SIZE];
int top1 = -1;
int top2 = -1;

void enqueue(int data) {
    if (top1 == MAX_SIZE - 1) {
        printf("Queue is full.\n");
        return;
    }
    stack1[++top1] = data;
}

int dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    if (top2 == -1) {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }
    int data = stack2[top2--];
    return data;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    enqueue(4);
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    printf("%d ", dequeue());
    return 0;
}