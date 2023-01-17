//
//  boj.c
//  boj
//
//  Created by LeeYeEun on 2021/07/07.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10000

int stack[MAX];
int top_index = -1;

void push(int x) {
    stack[++top_index] = x;
}

bool empty(void) {
    if(top_index == -1) return true;
    return false;
}

int pop(void) {
    if (empty()) {
        return -1;
    }
    return stack[top_index--];
}

int top(void) {
    if (top_index == -1) return -1;
    return stack[top_index];
}

int size(void) {
    return top_index + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char input[6];
        scanf("%s", input);
        if (!strcmp(input, "push")) {
            int x;
            scanf("%d\n", &x);
            push(x);
        }
        else if (!strcmp(input, "pop")) {
            printf("%d\n", pop());
        }
        else if (!strcmp(input, "size")) {
            printf("%d\n", size());
        }
        else if (!strcmp(input, "empty")) {
            printf("%d\n", empty());
        }
        else if (!strcmp(input, "top")) {
            printf("%d\n", top());
        }
    }
    return 0;
}

