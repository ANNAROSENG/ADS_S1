#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
typedef struct {
    Node* head;
} AdjList;
typedef struct {
    int numVertices;
    AdjList* array;
} Graph;
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->array = (AdjList*)malloc(numVertices * sizeof(AdjList));
for (int i = 0; i < numVertices; i++) {
        graph->array[i].head = NULL;
    }
return graph;
}
void addEdge(Graph* graph, int start, int end) {
    Node* newNode = createNode(end);
    newNode->next = graph->array[start].head;
    graph->array[start].head = newNode;
}
void DFS(Graph* graph, int vertex, int visited[], int* stack, int* stackIndex) {
    visited[vertex] = 1;
Node* current = graph->array[vertex].head;
    while (current != NULL) {
        if (!visited[current->vertex]) {
            DFS(graph, current->vertex, visited, stack, stackIndex);
        }
        current = current->next;
    }
stack[(*stackIndex)++] = vertex;
}
void DFSReverse(Graph* reversedGraph, int vertex, int visited[], int scc[], int sccIndex) {
    visited[vertex] = 1;
    scc[vertex] = sccIndex;
Node* current = reversedGraph->array[vertex].head;
    while (current != NULL) {
        if (!visited[current->vertex]) {
            DFSReverse(reversedGraph, current->vertex, visited, scc, sccIndex);
        }
        current = current->next;
    }
}
void findSCC(Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int stackIndex = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, stack, &stackIndex);
        }
    }
    Graph* reversedGraph = createGraph(graph->numVertices);
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->array[i].head;
        while (current != NULL) {
            addEdge(reversedGraph, current->vertex, i);
            current = current->next;
        }
    }
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    int scc[MAX_VERTICES];
    int sccIndex = 1; // Strongly connected component index
while (stackIndex > 0) {
        int vertex = stack[--stackIndex];
        if (!visited[vertex]) {
            DFSReverse(reversedGraph, vertex, visited, scc, sccIndex);
            sccIndex++;
        }
    }

    printf("Strongly Connected Components:\n");
    for (int i = 1; i < sccIndex; i++) {
        printf("Component %d: ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (scc[j] == i) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    free(reversedGraph->array);
    free(reversedGraph);
}
int main() {
    int numVertices, numEdges;
printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
Graph* graph = createGraph(numVertices);
printf("Enter the number of edges: ");
scanf("%d", &numEdges);
printf("Enter edge information (start vertex, end vertex):\n");
    for (int i = 0; i < numEdges; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        addEdge(graph, start, end);
    }
    findSCC(graph);
    free(graph->array);
    free(graph);
 return 0;
}
Enter the number of vertices: 6
Enter the number of edges: 0
Enter edge information (start vertex, end vertex):
Strongly Connected Components:
Component 1: 5 
Component 2: 4 
Component 3: 3 
Component 4: 2 
Component 5: 1 
Component 6: 0 
