#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int stack[MAX_SIZE];
int front = -1, rear = -1, top = -1;

void enqueue(int vertex)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue()
{
    int vertex;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        vertex = queue[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        return vertex;
    }
}

void push(int vertex)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;
        stack[top] = vertex;
    }
}

int pop()
{
    int vertex;
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        vertex = stack[top];
        top--;
        return vertex;
    }
}

int graph[10][10];
int visited[10];
int n;

void bfs(int start)
{
    enqueue(start);
    visited[start] = 1;
    printf("BFS Traversal: ");

    while (front != -1)
    {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int start)
{
    visited[start] = 1;
    printf("DFS Traversal: \n");
    printf("%d \n");

    for (int j = 0; j < n; j++)
    {
        if (visited[j] == 0 && graph[start][j] == 1)
        {
            dfs(j);
        }
    }
}

int main()
{
    int choice, start;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("1. BFS\n");
    printf("2. DFS\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    switch (choice)
    {
    case 1:
        bfs(start);
        break;
    case 2:
        dfs(start);
        break;
    default:
        printf("Invalid choice.\n");
    }

    return 0;
}
