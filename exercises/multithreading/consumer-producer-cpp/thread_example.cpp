#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <queue>
#include <semaphore.h>

#define MAX_QUEUE_SIZE    20

std::queue<int> myQueue;
sem_t semaphore_full;
sem_t semaphore_empty;
sem_t semaphore_mutex;
bool stop_consumer_flag = false;
bool stop_producer_flag = false;

void set_thread_name() {
    pthread_t thread = pthread_self();
    char threadName[16];
    pthread_getname_np(thread, threadName, sizeof(threadName));
    std::cout << "Hello from " << std::string(threadName) << " with tid: " 
              << "0x" << std::hex << thread <<std::endl;
}

void* stop_producer(void* ptr) {
    sleep(3);
    stop_producer_flag = true;
    return NULL;
}

void drainQueue() {
    // Extraer datos de la cola myQueue     
    int data = 0;
    while (!myQueue.empty()) { // para asegurar que se consuman todos los datos despues del stop
        sem_wait(&semaphore_full);        // Stay here if the buffer is empty
        sem_wait(&semaphore_mutex);
        data = myQueue.front();           // Obtiene el elemento "mas viejo" de la cola FIFO
        myQueue.pop();                    // Remueve el elemento "mas viejo" de la cola
        std::cout << "CONSUMER: Printing data: " << data 
                        <<  " now the size of the queue is: " << myQueue.size() << std::endl;
        sem_post(&semaphore_mutex);
        sem_post(&semaphore_empty);        // Incrementa el valor de este semaforo
    }
}

void postMessage() {
    int randomNumber = 0;
    randomNumber = rand() % 100;    // genera un numero entero aleatorio entre 0 y 100
    sem_wait(&semaphore_empty);     // stay here if the buffer is full, sem = 0, inicialmente vale 10 -> 9
    sem_wait(&semaphore_mutex); 
    myQueue.push(randomNumber);     // Introduce el numero aleatorio generado a la cola
    std::cout << "PRODUCER: Generated random number is: " << randomNumber
                << " now the queue size is: " << myQueue.size() << std::endl;
    sem_post(&semaphore_mutex); 
    sem_post(&semaphore_full);      // increment the buffer counter for this semaphore
}

void* producer(void* ptr) {
    set_thread_name();

    while (!stop_producer_flag) {
        postMessage();
    }
    // Consume any leftover messages
    stop_consumer_flag = true;
    std::cout << "PRODUCER: Stopped producing items " << std::endl;
    return NULL;
}

void* consumer(void* ptr) {
    set_thread_name();

    while (!stop_consumer_flag) {
        drainQueue();
    }
    std::cout << "CONSUMER: Queue empty, goodbye " << std::endl;
    return NULL;
}

int main() {
    std::cout << "hello from main" << std::endl;
    //Initialize sempahore
    sem_init(&semaphore_full, 0, 0);
    sem_init(&semaphore_empty, 0, MAX_QUEUE_SIZE);
    sem_init(&semaphore_mutex, 0, 1);
    
    // creamos los trheads
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    
    // ejecutamos los threads
    pthread_create(&thread1, NULL, &producer, NULL);
    pthread_create(&thread2, NULL, &consumer, NULL);
    pthread_create(&thread3, NULL, &stop_producer, NULL);
    
    // nombramos los threads
    pthread_setname_np(thread1, "Producer thread");
    pthread_setname_np(thread2, "Consumer thread");
    pthread_setname_np(thread3, "Stop producer");
    
    // esperamos a que los trheads terminen
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    
    return 0;
}