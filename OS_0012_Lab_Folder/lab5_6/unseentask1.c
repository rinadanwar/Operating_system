#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} 
Calculator;

void *add(void* arg) {
    Calculator* temp  = arg;
    int ans = temp->a + temp->b;

    printf("Sum is %d\n", ans);

    return NULL;
}

void *subtract(void* arg) {
    Calculator* temp  = arg;
    int ans = temp->a - temp->b;

    printf("diff is %d\n", ans);

    return NULL;
}

void *multiply(void* arg) {
    Calculator* temp = arg;
    int ans = temp->a * temp->b;

    printf("product is %d\n", ans);

    return NULL;
}

void *divide(void* arg) {
    Calculator* temp = arg ;
    int ans = temp->a / temp->b;

    printf("division ans is %d\n", ans);

    return NULL;
}



int main(void) {
    pthread_t t1,t2,t3,t4; /* ...and so on */
    Calculator calc = { .a = 7, .b = 4 };

    pthread_create(&t1, NULL, add, &calc);
    pthread_create(&t2, NULL, subtract, &calc);
    pthread_create(&t3, NULL, divide, &calc);
    pthread_create(&t4, NULL, multiply, &calc);
    /* ...and so on */

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
     pthread_join(t3, NULL);
     pthread_join(t4, NULL);
    
    return 0;
    /* ...and so on */
}
