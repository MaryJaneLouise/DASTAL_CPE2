#include<stdio.h>
#include<stdlib.h>

struct Edge;

struct Vertex {
    int info;
    struct Vertex *nextVertex;
    struct Edge *firstEdge;
}*start = NULL;

struct Edge {
    struct Vertex *destVertex;
    struct Edge *nextEdge;
    struct Weight *weight;
};

void insertVertex(int vertex) {
    struct Vertex *tmp,*ptr;
    tmp = malloc(sizeof(struct Vertex));
    tmp->info = vertex;
    tmp->nextVertex = NULL;
    tmp->firstEdge = NULL;

    if(start == NULL)
    {
        start = tmp;
        return;
    }
    ptr = start;
    while(ptr->nextVertex!=NULL)
        ptr = ptr->nextVertex;
    ptr->nextVertex = tmp;
}

void deleteVertex(int vertex) {
    struct Vertex *tmpV,*q;
    struct Edge *p,*tmpE;
    if(start == NULL) {
        printf("\nThe list is still empty. Add new vertices to delete some.\n");
        return;
    }

    if(start->info == vertex) {
        tmpV = start;
        start = start->nextVertex;
    }
    else {
        q = start;
        while(q->nextVertex != NULL) {
            if(q->nextVertex->info == vertex)
                break;
            q = q->nextVertex;
        }

        if(q->nextVertex==NULL) {
            printf("Vertex was not found on the memory list.\n");
            return;
        }
        else {
            tmpV = q->nextVertex;
            q->nextVertex = tmpV->nextVertex;
        }
    }

    p = tmpV->firstEdge;
    while(p!=NULL) {
        tmpE = p;
        p = p->nextEdge;
        free(tmpE);
    }
    free(tmpV);
}

void deleteIncomingEdges(int vertex) {
    struct Vertex *ptr;
    struct Edge *q,*tmp;

    ptr = start;
    while(ptr!=NULL) {
        if(ptr->firstEdge == NULL) {
            ptr = ptr->nextVertex;
            continue;
        }

        if(ptr->firstEdge->destVertex->info == vertex) {
            tmp = ptr->firstEdge;
            ptr->firstEdge = ptr->firstEdge->nextEdge;
            free(tmp);
            continue;
        }

        q = ptr->firstEdge;

        while(q->nextEdge!= NULL) {
            if(q->nextEdge->destVertex->info == vertex)
            {
                tmp = q->nextEdge;
                q->nextEdge = tmp->nextEdge;
                free(tmp);
                continue;
            }
            q = q->nextEdge;
        }
        ptr = ptr->nextVertex;
    }
}

struct Vertex *findVertex(int vertex) {
    struct Vertex *ptr,*location;
    ptr = start;
    while(ptr != NULL) {
        if(ptr->info == vertex) {
            location = ptr;
            return location;
        }
        else {
            ptr = ptr->nextVertex;
        }
    }

    location = NULL;
    return location;
}

void insertEdge(int originVertex,int destinationVertex, int weightOfVertex) {
    struct Vertex *locationOriginVertex,*locationDestinationVertex;
    struct Edge *ptr,*tmp;

    locationOriginVertex = findVertex(originVertex);
    locationDestinationVertex = findVertex(destinationVertex);

    if(locationOriginVertex == NULL ) {
        printf("\nStart vertex is not present. Please insert first Vertex %d.\n", originVertex);
        return;
    }
    if(locationDestinationVertex == NULL ) {
        printf("\nEnd vertex is not present. Please insert first Vertex %d.\n", destinationVertex);
        return;
    }
    tmp = malloc(sizeof(struct Edge));
    tmp->destVertex = locationDestinationVertex;
    tmp->nextEdge = NULL;
    tmp->weight = weightOfVertex;

    if(locationOriginVertex->firstEdge == NULL) {
        locationOriginVertex->firstEdge = tmp;
        return;
    }

    ptr = locationOriginVertex->firstEdge;
    while(ptr->nextEdge!=NULL) {
        ptr = ptr->nextEdge;
    }
    ptr->nextEdge = tmp;

}

void deleteEdge(int originVertex,int destinationVertex) {
    struct Vertex *locationOriginVertex;
    struct Edge *tmp,*q;

    locationOriginVertex = findVertex(originVertex);

    if(locationOriginVertex == NULL) {
        printf("\nStart vertex is not present on the memory list.\n");
        return;
    }
    if(locationOriginVertex->firstEdge == NULL) {
        printf("\nEdge is not present on the memory list.\n");
        return;
    }

    if(locationOriginVertex->firstEdge->destVertex->info == destinationVertex) {
        tmp = locationOriginVertex->firstEdge;
        locationOriginVertex->firstEdge = locationOriginVertex->firstEdge->nextEdge;
        free(tmp);
        return;
    }

    q = locationOriginVertex->firstEdge;

    while(q->nextEdge != NULL) {
        if(q->nextEdge->destVertex->info == destinationVertex) {
            tmp = q->nextEdge;
            q->nextEdge = tmp->nextEdge;
            free(tmp);
            return;
        }
        q = q->nextEdge;
    }

    printf("\nThe edge %d is not present on the graph. Please check again.\n", q->nextEdge);
}

void displayResults() {
    struct Vertex *ptr;
    struct Edge *q, *weight;

    printf("As of the moment, here is the graph in adjacency list:\n");
    ptr = start;
    while(ptr!=NULL)
    {
        printf("Vertex %d -> ",ptr->info);
        q = ptr->firstEdge;
        while(q!=NULL)
        {
            printf("[Vertex %d(%d)]",q->destVertex->info, q->weight);
            q = q->nextEdge;
        }
        printf("\n");
        ptr = ptr->nextVertex;
    }
}

int main() {
    int option;
    int vertex, originVertex, destinationVertex, weightOfVertex;

    while(1) {
        printf("Options:");
        printf("\n1. Insert a new vertex\n");
        printf("2. Insert an edge to a vertex\n");
        printf("3. Delete an existing vertex\n");
        printf("4. Delete an existing edge\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);


        switch(option) {
            case 1:
                printf("\nInsert a vertex to the graph"
                       "\nEnter a vertex to be inserted: ");
                scanf("%d",&vertex);
                insertVertex(vertex);
                printf("\n");
                displayResults();
                printf("\n");
                break;
            case 2:
                printf("\nInsert an edge to a vertex");
                printf("\nEnter the original vertex: ");
                scanf("%d", &originVertex);
                printf("Enter the destination vertex: ");
                scanf("%d", &destinationVertex);
                printf("Enter the weight of the designated vertex: ");
                scanf("%d", &weightOfVertex);
                if (weightOfVertex <= 0) {
                    printf("You entered a weight number less than or equal to zero. Please try again.\n");
                }
                else {
                    insertEdge(originVertex, destinationVertex, weightOfVertex);
                }
                printf("\n");
                displayResults();
                printf("\n");
                break;
            case 3:
                printf("\nDeleting an existing vertex\n"
                       "Sorry for inconvience but this function is not still available.\n\n");
                /*printf("\nEnter a vertex to be deleted: ");
                scanf("%d",&vertex);
                deleteIncomingEdges(vertex);
                deleteVertex(vertex);*/
                break;
            case 4:
                printf("\nDeleting an existing edge to a specific vertex\n"
                       "Sorry for inconvience but this function is not still available.\n\n");
                /*printf("\nEnter an edge to be deleted: ");
                scanf("%d %d",&originVertex,&destinationVertex);
                deleteEdge(originVertex,destinationVertex);*/
                break;
            case 5:
                printf("Good day!");
                exit(1);
            default:
                printf("\nYou entered a number that is not on the list. Try again.\n");
                break;
        }
    }
}