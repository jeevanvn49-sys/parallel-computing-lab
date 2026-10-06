#include <stdio.h>
#include <omp.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    printf("Enter upper limit: ");
    scanf("%d", &n);

    // Serial computation
    double start = omp_get_wtime();
    printf("\nSerial primes:\n");
    for (int i = 1; i <= n; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    double end = omp_get_wtime();
    printf("\nSerial Time: %f seconds\n", end - start);

    // Parallel computation
    start = omp_get_wtime();
    printf("\nParallel primes:\n");
    #pragma omp parallel for
    for (int i = 1; i <= n; i++) {
        if (is_prime(i)) {
            // Printing from multiple threads can mix output,
            // so use critical section to keep it clean
            #pragma omp critical
            {
                printf("%d ", i);
            }
        }
    }
    end = omp_get_wtime();
    printf("\nParallel Time: %f seconds\n", end - start);

    return 0;
}