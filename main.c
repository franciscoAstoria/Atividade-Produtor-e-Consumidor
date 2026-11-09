
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int saldo_vitrine = 0;

// Thread 1: Padeiro
void *padeiro(void *arg) {
    int produzidos = 0;

    while (1) {
        produzidos++;
        saldo_vitrine++;

        printf("PADEIRO: Pao #%d pronto (Saldo vitrine = %d)\n",
               produzidos, saldo_vitrine);

        sleep(1);
    }

    return NULL;
}

// Thread 2: Cliente
void *cliente(void *arg) {
    int consumidos = 0;

    while (1) {
        consumidos++;
        saldo_vitrine--;

        printf("CLIENTE: Peguei pao #%d (Saldo vitrine = %d)\n",
               consumidos, saldo_vitrine);

        usleep(1500000);
    }

    return NULL;
}

int main() {
    pthread_t thread_padeiro, thread_cliente;

    pthread_create(&thread_padeiro, NULL, padeiro, NULL);
    pthread_create(&thread_cliente, NULL, cliente, NULL);

    pthread_join(thread_padeiro, NULL);
    pthread_join(thread_cliente, NULL);

    return 0;
}
