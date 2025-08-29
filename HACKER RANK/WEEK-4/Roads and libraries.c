#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 100005

typedef struct AdjNode {
    int neighbor;
    struct AdjNode* next;
} AdjNode;

AdjNode* graph[MAX_CITIES];
int explored[MAX_CITIES];

void insertEdge(int from, int to) {
    AdjNode* newNode = (AdjNode*)malloc(sizeof(AdjNode));
    newNode->neighbor = to;
    newNode->next = graph[from];
    graph[from] = newNode;
}

void explore(int city, int* size) {
    explored[city] = 1;
    (*size)++;
    for (AdjNode* ptr = graph[city]; ptr != NULL; ptr = ptr->next) {
        if (!explored[ptr->neighbor]) {
            explore(ptr->neighbor, size);
        }
    }
}

long long calculateMinimumCost(int totalCities, int libCost, int roadCost, int numRoads, int connections[numRoads][2]) {
    if (libCost <= roadCost) {
        return (long long)totalCities * libCost;
    }
    for (int i = 1; i <= totalCities; ++i) {
        graph[i] = NULL;
        explored[i] = 0;
    }
    for (int i = 0; i < numRoads; ++i) {
        int cityA = connections[i][0];
        int cityB = connections[i][1];
        insertEdge(cityA, cityB);
        insertEdge(cityB, cityA);
    }
    long long minCost = 0;
    for (int city = 1; city <= totalCities; ++city) {
        if (!explored[city]) {
            int componentSize = 0;
            explore(city, &componentSize);
            minCost += libCost + (long long)(componentSize - 1) * roadCost;
        }
    }
    return minCost;
}

int main() {
    int queries;
    scanf("%d", &queries);
    while (queries--) {
        int n, m, costLibrary, costRoad;
        scanf("%d %d %d %d", &n, &m, &costLibrary, &costRoad);
        int pairs[m][2];
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &pairs[i][0], &pairs[i][1]);
        }
        long long answer = calculateMinimumCost(n, costLibrary, costRoad, m, pairs);
        printf("%lld\n", answer);
    }
    return 0;
}