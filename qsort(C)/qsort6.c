#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n = pow(10,6);
    int* a = malloc(n * sizeof(int));

    srand(time(NULL));
 
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000001 - 9000;

    clock_t start, end;

    start = clock();
    qsort(a, n, sizeof(int), cmpfunc);

    end = clock();
    float t = end - start;
    printf("%f", t / CLOCKS_PER_SEC);

    system("pause");

    printf("\nAfter sorting the list is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    free(a);
    return(0);
}



