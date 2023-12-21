#include <stdio.h>
#define MAX_SIZE 100

// Function to perform union of two sets using bit strings
void unionSets(int set1[], int set2[], int size) {
    int resultSet[MAX_SIZE];
    for (int i = 0; i < size; i++) {
        resultSet[i] = set1[i] | set2[i];
    }
    
    printf("Union of the sets: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", resultSet[i]);
    }
    printf("\n");
}

// Function to perform intersection of two sets using bit strings
void intersectionSets(int set1[], int set2[], int size) {
    int resultSet[MAX_SIZE];
    for (int i = 0; i < size; i++) {
        resultSet[i] = set1[i] & set2[i];
    }
    
    printf("Intersection of the sets: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", resultSet[i]);
    }
    printf("\n");
}

// Function to perform difference of two sets using bit strings
void differenceSets(int set1[], int set2[], int size) {
    int resultSet[MAX_SIZE];
    for (int i = 0; i < size; i++) {
        resultSet[i] = set1[i] & ~set2[i];
    }
    
    printf("Difference of the sets: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", resultSet[i]);
    }
    printf("\n");
}

int main() {
    int set1[MAX_SIZE] = {0}; // Initialize sets as arrays of integers (bit strings)
    int set2[MAX_SIZE] = {0};
    int size;

    printf("Enter the size of sets: ");
    scanf("%d", &size);

    printf("Enter elements of set 1 as 0s and 1s: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &set1[i]);
    }

    printf("Enter elements of set 2 as 0s and 1s: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &set2[i]);
    }

    unionSets(set1, set2, size);
    intersectionSets(set1, set2, size);
    differenceSets(set1, set2, size);

    return 0;
}
