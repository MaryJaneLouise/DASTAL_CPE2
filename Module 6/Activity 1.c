#include <stdio.h>
#include <stdlib.h>

#define numVertices 5

struct storeGraph {
    struct Node* head[numVertices];
};

struct Node {
    int destination;
    struct Node* next;
};

struct edgeGraph {
    int source, destination;
};

struct storeGraph* createGraph(struct edgeGraph edges[], int n) {
    struct storeGraph* graph = (struct storeGraph*)malloc(sizeof(struct storeGraph));

    for (int i = 0; i < numVertices; i++) {
        graph->head[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int source = edges[i].source;
        int destination = edges[i].destination;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->destination = destination;
        newNode->next = graph->head[source];
        graph->head[source] = newNode;
    }
    return graph;
}

void printGraph(struct storeGraph* graph) {
    for (int i = 0; i < numVertices; i++) {
        struct Node* pointerNode = graph->head[i];
        while (pointerNode != NULL) {
            printf("[Point %d —> Point %d]\t", i, pointerNode->destination);
            pointerNode = pointerNode->next;
        }
        printf("\n");
    }
}

int main() {
    struct edgeGraph edges[] = {
                    {0, 1},
                    {1, 3},
                    {2, 1},
                    {3, 4},
                    {4, 2}
    };
    int n = sizeof(edges)/sizeof(edges[0]);
    struct storeGraph *graph = createGraph(edges, n);
    printf("Note: A = 0, B = 1...\n\nDirected Graph using adjacency list:\n");
    printGraph(graph);

    return 0;
}
