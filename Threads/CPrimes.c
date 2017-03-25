#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//call PrimeNumbers function
void *PrimeNumbers(void *param); 


int main(int argc, char *argv[]) {

   //Check two arguments were passed in
   if(argc < 2) {
      fprintf(stderr, "USAGE: ./a.out <Integer value>\n");
      exit(1);
   }

   //the input is greater then or equal to two
   if(atoi(argv[1]) < 2) {
      fprintf(stderr, "USAGE: %d must be >= 2\n", atoi(argv[1]));
      exit(1);
   }

   pthread_t tid;       //Thread ID
   pthread_attr_t attr; //Set of thread attributes

   printf("Prime Numbers: ");

   //Get the default attributes
   pthread_attr_init(&attr);

   //Create the thread
   pthread_create(&tid,&attr,PrimeNumbers,argv[1]);

   //Joing the thread
   pthread_join(tid,NULL);

   //DONE
   printf("\nDONE\n");

}




// A function return prime numbers
void *PrimeNumbers(void *param) {   

   int i, j, max_number = atoi(param);

   /* Checking if a number is prime */
   for(i = 2; i < max_number; i++) {
        int number = 0;

      /* Check each number for divisibility */

      for(j = 2; j < i; j++) {          

         int result = i % j;

         if(result == 0) {

            number = 1;

            break;

         }

      }

      //No numbers divided cleanly so this number must be prime

      if(number == 0) {

         printf("[%d] ", i);

      }

   }

   //Exit the thread
   pthread_exit(0);

}
