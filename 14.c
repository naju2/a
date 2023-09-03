#include <stdio.h>

#define MAX_ELEMENTS 10

int set[MAX_ELEMENTS];
int subset[MAX_ELEMENTS];
int n, targetSum, count = 0;

void findSubsets(int currentSum, int index) {
    if (currentSum == targetSum) {
        count++;
        for (int i = 0; i < index; i++) {
            if (subset[i] != 0) {
                printf("%d ", subset[i]);
            }
        }
        printf("\n");
        return;
    }

    if (index >= n || currentSum > targetSum) {
        return;
    }

    subset[index] = set[index];
    findSubsets(currentSum + set[index], index + 1);


    subset[index] = 0;
    findSubsets(currentSum, index + 1);
}

int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set in ascending order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("The solution subsets are:\n");
    findSubsets(0, 0);

    if (count == 0) {
        printf("No solution exists.\n");
    }
    return 0;
}
