#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*Question # 2 Create new process */
int main (int ac, char *av[]){

	//pid_t is data type to get PID #
	pid_t childPID = fork(); // create a new process
	
	//raise an error if the childPID is less than 0
	if (childPID < 0 ){

	     //raise error and exit using -1 to indicate error
	     perror("[*] ERROR: cannot create a new process");

	     //exit 
	     exit(-1);
	} 
	
	// if childPID is not 0, it means you are in the parent processor  
	if(childPID != 0 ){

	    printf("\n");
	    printf("Parent pid: %d, my child pid is %d\n", getpid(), childPID);	
	    wait(NULL); //wait for the child to join the parent
 	
	}else{
	    // if the childPID == 0, mean you in child processor
	    printf("\n"); 
	    printf("Child pid: %d, my parent pid is %d\n\n\n", getpid(), getppid());
	   //execute the
	  // execl("/bin/echo", "echo","Hello world", NULL); 
	  execl("/bin/ps","ps",NULL, NULL);
	   	   
	}	


	return 0 ;
}	


