#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>



// some macros to make the code more understandable

//  regarding which pipe to use to a read/write operation

//

//  Parent: reads from P1_READ, writes on P1_WRITE

//  Child:  reads from P2_READ, writes on P2_WRITE

#define P1_READ     0

#define P2_WRITE    1

#define P2_READ     2

#define P1_WRITE    3



// the total number of pipe *pairs* we need

#define NUM_PIPES   2



int main(int argc, char *argv[])

{

    int fd[2*NUM_PIPES];

    int val = 0, len, i;

    pid_t pid;

    
    char sentence[100];

    int count, ch, m;

   

   char *p, *k ;   



   

  printf("Enter a sentence: ");

  

  // first loop: 

  for(i=0; (sentence[i] = getchar())!='\n'; i++){



  }







    // create all the descriptor pairs we need

    for (i=0; i<NUM_PIPES; ++i)

    {

        if (pipe(fd+(i*2)) < 0)

        {

            perror("Failed to allocate pipes");

            exit(EXIT_FAILURE);

        }

    }



    // fork() returns 0 for child process, child-pid for parent process.

    if ((pid = fork()) < 0)

    {

        perror("Failed to fork process");

        return EXIT_FAILURE;

    }



    // if the pid is zero, this is the child process

    if (pid == 0)

    {

        // Child. Start by closing descriptors we

        //  don't need in this process

        close(fd[P1_READ]);

        close(fd[P1_WRITE]);



        // used for output

        pid = getpid();



        // wait for parent to send us a value

        len = read(fd[P2_READ], &val, sizeof(val));

        if (len < 0)

        {

            perror("Child: Failed to read data from pipe");

            exit(EXIT_FAILURE);

        }

        else if (len == 0)

        {

            // not an error, but certainly unexpected

            fprintf(stderr, "Child: Read EOF from pipe");

        }

        else

        {

            // report what we received

            printf("Child(%d): Received NewString %s\n", pid,  sentence);



            // now double it and send it back

            val *= 2;

        

            //MY LOOP

            count = m; /*shows the number of chars accepted in a sentence*/

           for(m=0; m < sentence[m]; m++) {

   		 sentence[m]  = islower(sentence[m]) ? toupper(sentence[m]) : tolower(sentence[m]);
    		//putchar(ch);

   }


      

              

            

            // printf("I am New P %s", p);



            printf("Child(%d): Sending back newSrting %s\n", pid,  sentence);

            if (write(fd[P2_WRITE], &val, sizeof(val)) < 0)

            {

                perror("Child: Failed to write response value");

                exit(EXIT_FAILURE);

            }

        }



        // k = p ;

        

        // printf("I am New P %s", k);

        

      

        // finished. close remaining descriptors.

        close(fd[P2_READ]);

        close(fd[P2_WRITE]);

        

        k = p ;

        



        return EXIT_SUCCESS;

    }



    // Parent. close unneeded descriptors

    close(fd[P2_READ]);

    close(fd[P2_WRITE]);



     

    // used for output

    pid = getpid();



    // send a value to the child

    val = 42;

   

    printf("Parent(%d): Sending to child String %s\n", pid,  sentence);

    

    if (write(fd[P1_WRITE], &val, sizeof(val)) != sizeof(val))

    {

        perror("Parent: Failed to send value to child ");

        exit(EXIT_FAILURE);

    }



    // now wait for a response

    len = read(fd[P1_READ], &val, sizeof(val));

    if (len < 0)

    {

        perror("Parent: failed to read value from pipe");

        exit(EXIT_FAILURE);

    }

    else if (len == 0)

    {

        // not an error, but certainly unexpected

        fprintf(stderr, "Parent(%d): Read EOF from pipe", pid);

    }

    else

    {

        // report what we received

        count = m; /*shows the number of chars accepted in a sentence*/

            for(m=0; m < sentence[m]; m++) {

      

                 sentence[m] = islower(sentence[m]) ? toupper(sentence[m]) : tolower(sentence[m]);

              

            }

        printf("Parent(%d): Received NewString %s\n", pid,  sentence);

    }



    // close down remaining descriptors

    close(fd[P1_READ]);

    close(fd[P1_WRITE]);



    // wait for child termination

   // wait(NULL);



	return 0 ;
}
