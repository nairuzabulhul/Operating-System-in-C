#include <stdio.h>

#include <ctype.h>

#include<string.h>



int main(){

  char sentence[100];
  int count, ch, i;

  printf("Enter a sentence: ");


  // first loop: 
  for(i=0; (sentence[i] = getchar())!='\n'; i++){

  }


  count = i; /*shows the number of chars accepted in a sentence*/

  printf("Output: %s",sentence);


  // second loop: 
  for(i=0; i < count; i++) {

    ch = islower(sentence[i]) ? toupper(sentence[i]) : tolower(sentence[i]);
    putchar(ch);

   }

 
    // add space after the last line 
    printf("\n");
    return 0;

} 
