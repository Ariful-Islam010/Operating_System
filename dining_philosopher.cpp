#include <stdio.h>

int chopstick[5] = {1, 1, 1, 1, 1};

void wait(int s_index) {
    while (chopstick[s_index] == 0); // busy wait
    chopstick[s_index] = 0;
}

void signal(int s_index) {
    chopstick[s_index] = 1;
}

void thinking(int id) {
    printf("Philosopher %d is thinking\n", id + 1);
}

void eat(int id) {
    printf("Philosopher %d is eating\n", id + 1);
}

void philosopher(int id) {
    int times;
    for (times = 0; times < 2; times++) {  // eats twice then stops
        thinking(id);
        wait(id);                  // pick left chopstick
        wait((id + 1) % 5);        // pick right chopstick
        eat(id);
        signal(id);                // put left down
        signal((id + 1) % 5);      // put right down
    }
}

int main() {
    int i;
    for (i = 0; i < 5; i++) {
        philosopher(i);
    }
    return 0;
}