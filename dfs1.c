#include <stdio.h>
#include <stdlib.h>
int adj[10][10], stack[10], visited[10], size = 10, i, p, a, j, v, s, top = -1;
void push(int z)
{
if (top == size - 1)
{
printf("\n\nStack is full!");
}
else
{
top++;
stack[top] = z;
}
}
int pop()
{
if (top == -1)
{
return 0;
}
else
{
a = stack[top];
top--;
return a;
}
}
void dfs(int x, int y)
{
push(s);
visited[s] = 1;
p = pop();
if (p != 0)
{
printf("%d ", p);
while (p != 0)
{
for (i = 1; i <= v; i++)
{
if (adj[p][i] == 1 && visited[i] == 0)
{
push(i);
visited[i] = 1;
}
}
p = pop();
if (p != 0)
{
printf("%d ", p);
}
}
}
}
int main()
{
printf("Enter no. of vertices : ");
scanf("%d", &v);
printf("Enter Adjacency Matrix : ");
for (i = 1; i <= v; i++)
{
visited[i] = 0;
for (j = 1; j <= v; j++)
{
scanf("%d", &adj[i][j]);
}
}
printf("Enter the starting vertex : ");
scanf("%d", &s);
printf("DFS TRAVERSAL : ");
dfs(s, v);
return 0;
}
