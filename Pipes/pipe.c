#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



/*Create a program that pipes P1 with P2*/
int main(int arg, char *argv[] ){

	pid_t PID; // generate  a pid 
	int pipe1[2]; // initate a pipe
	char buffer[20];
	int resultPID;

	 
	/* Set up the pipe */
	resultPID =  pipe(pipe1); //create first pipe
	
	// if the processor PID less than 0 , return an error and exit 
	if(resultPID < 0){
		perror("[*] ERROR: cannot create a process");
		exit(-1);
	}

	/* Create a processor */ 
	PID = fork();

	// if processor PID equals to 0 
	if (PID == 0 ){
	      // child processor
		printf("Child Process :");
	     	write(pipe1[1], "Hello there!", 12);
	}else{
	      // parent processor 
		printf("Parent Process");
		read(pipe1[0],buffer, 15);
		printf("buffer: %s\n", buffer);
	}
	
	return 0;
}
















