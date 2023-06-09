#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

sem_t forks[NUM_PHILOSOPHERS];
sem_t mutex;
int state[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philosopherIndex = *(int *)arg;
    int leftFork = philosopherIndex;
    int rightFork = (philosopherIndex + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking\n", philosopherIndex);

        sleep(1); // Simulating thinking

        sem_wait(&mutex);
        state[philosopherIndex] = HUNGRY;
        printf("Philosopher %d is hungry\n", philosopherIndex);
        sem_post(&mutex);

        
        sem_wait(&forks[leftFork]);
        sem_wait(&forks[rightFork]);
        
        sem_wait(&mutex);
        state[philosopherIndex] = EATING;
        printf("Philosopher %d is eating\n", philosopherIndex);
        sem_post(&mutex);

        sleep(2);

        sem_post(&forks[leftFork]);
        sem_post(&forks[rightFork]);
        sem_wait(&mutex);
        state[philosopherIndex] = THINKING;
        printf("Philosopher %d finished eating and is thinking again\n", philosopherIndex);
        sem_post(&mutex);
    }
}

int main() {
    int i;
    int philosopherIndex[NUM_PHILOSOPHERS];
    pthread_t philosophers[NUM_PHILOSOPHERS];

    sem_init(&mutex, 0, 1);

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopherIndex[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopherIndex[i]);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

sem_t forks[NUM_PHILOSOPHERS];
sem_t mutex;
int state[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philosopherIndex = *(int *)arg;
    int leftFork = philosopherIndex;
    int rightFork = (philosopherIndex + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking\n", philosopherIndex);

        sleep(1); // Simulating thinking

        sem_wait(&mutex);
        state[philosopherIndex] = HUNGRY;
        printf("Philosopher %d is hungry\n", philosopherIndex);
        sem_post(&mutex);

        
        sem_wait(&forks[leftFork]);
        sem_wait(&forks[rightFork]);
        
        sem_wait(&mutex);
        state[philosopherIndex] = EATING;
        printf("Philosopher %d is eating\n", philosopherIndex);
        sem_post(&mutex);

        sleep(2);

        sem_post(&forks[leftFork]);
        sem_post(&forks[rightFork]);
        sem_wait(&mutex);
        state[philosopherIndex] = THINKING;
        printf("Philosopher %d finished eating and is thinking again\n", philosopherIndex);
        sem_post(&mutex);
    }
}

int main() {
    int i;
    int philosopherIndex[NUM_PHILOSOPHERS];
    pthread_t philosophers[NUM_PHILOSOPHERS];

    sem_init(&mutex, 0, 1);

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopherIndex[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopherIndex[i]);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

sem_t forks[NUM_PHILOSOPHERS];
sem_t mutex;
int state[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philosopherIndex = *(int *)arg;
    int leftFork = philosopherIndex;
    int rightFork = (philosopherIndex + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking\n", philosopherIndex);

        sleep(1); // Simulating thinking

        sem_wait(&mutex);
        state[philosopherIndex] = HUNGRY;
        printf("Philosopher %d is hungry\n", philosopherIndex);
        sem_post(&mutex);

        
        sem_wait(&forks[leftFork]);
        sem_wait(&forks[rightFork]);
        
        sem_wait(&mutex);
        state[philosopherIndex] = EATING;
        printf("Philosopher %d is eating\n", philosopherIndex);
        sem_post(&mutex);

        sleep(2);

        sem_post(&forks[leftFork]);
        sem_post(&forks[rightFork]);
        sem_wait(&mutex);
        state[philosopherIndex] = THINKING;
        printf("Philosopher %d finished eating and is thinking again\n", philosopherIndex);
        sem_post(&mutex);
    }
}

int main() {
    int i;
    int philosopherIndex[NUM_PHILOSOPHERS];
    pthread_t philosophers[NUM_PHILOSOPHERS];

    sem_init(&mutex, 0, 1);

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopherIndex[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopherIndex[i]);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

sem_t forks[NUM_PHILOSOPHERS];
sem_t mutex;
int state[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philosopherIndex = *(int *)arg;
    int leftFork = philosopherIndex;
    int rightFork = (philosopherIndex + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking\n", philosopherIndex);

        sleep(1); // Simulating thinking

        sem_wait(&mutex);
        state[philosopherIndex] = HUNGRY;
        printf("Philosopher %d is hungry\n", philosopherIndex);
        sem_post(&mutex);

        
        sem_wait(&forks[leftFork]);
        sem_wait(&forks[rightFork]);
        
        sem_wait(&mutex);
        state[philosopherIndex] = EATING;
        printf("Philosopher %d is eating\n", philosopherIndex);
        sem_post(&mutex);

        sleep(2);

        sem_post(&forks[leftFork]);
        sem_post(&forks[rightFork]);
        sem_wait(&mutex);
        state[philosopherIndex] = THINKING;
        printf("Philosopher %d finished eating and is thinking again\n", philosopherIndex);
        sem_post(&mutex);
    }
}

int main() {
    int i;
    int philosopherIndex[NUM_PHILOSOPHERS];
    pthread_t philosophers[NUM_PHILOSOPHERS];

    sem_init(&mutex, 0, 1);

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopherIndex[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopherIndex[i]);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}
