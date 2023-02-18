#include <stdio.h>
#include <stdlib.h>

int* getCollatzSet(int x) {
    int* collatzSet = malloc(x * sizeof(int));

    int index = 1;
    do {
        collatzSet[index] = x;
        index++;

        if (x % 2 == 0) x /= 2;
        else x = (3 * x) + 1;
    } while (x != 1);

    collatzSet[index] = x;

    collatzSet[0] = index;

    return collatzSet;
}

void printSet(int *set) {
    int length = set[0];

    printf("M = {");
    for (int i = 1; i <= length; i++) {
        if (i == length) {
            printf("%d}", set[i]);
            break;
        }
        printf("%d, ", set[i]);
    }
}

int main() {
    int num;

    printf("Enter a number > 0: ");
    scanf("%d", &num);

    int* collatzSet = getCollatzSet(num);
    printSet(collatzSet);

    return 0;
}
