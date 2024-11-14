#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define N 5

int numbers[N] = {17, 4, 23, 18, 29};  
bool is_prime[N];  // Store prime check results

// Prime number check function
void* check_prime(void* arg) {
    int index = *(int*)arg;
    int n = numbers[index];
    is_prime[index] = true;

    if (n <= 1) {
        is_prime[index] = false;
    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                is_prime[index] = false;
                break;
            }
        }
    }
    free(arg);
    return NULL;
}

int main() {
    pthread_t threads[N];

    // Create a thread for each number
    for (int i = 0; i < N; i++) {
        int* index = malloc(sizeof(int)); 
        *index = i;
        pthread_create(&threads[i], NULL, check_prime, index);
    }

    // Wait for all threads to finish execution
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print results
    for (int i = 0; i < N; i++) {
        printf("Number %d is %s\n", numbers[i], 
               is_prime[i] ? "prime" : "not prime");
    }

    return 0;
}

