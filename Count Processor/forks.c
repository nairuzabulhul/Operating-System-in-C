#include <stdio.h>
#include <unistd.h>



int main(){

	int i;

	
	fork(); // first fork

	for (i = 1; i < 3; i ++){

		fork();

	fork();	

	printf("processor \n");

	}




	return 0;
}









