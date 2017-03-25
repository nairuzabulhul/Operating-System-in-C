import java.util.Scanner;


class JavaPrimes{   

   public static void main (String[] args) {	


    Thread thread = new Thread(new PrimeNumbers());
    thread.start();

     }

}


class PrimeNumbers implements Runnable {

   public void run (){       

    // capture user input
    Scanner scanner = new Scanner(System.in);

    int i =0;
    int num =0;

    String  primeNumbers = ""; // holder for all prime numbers at the end
    System.out.println("Enter the value of n:");
    int n = scanner.nextInt();

    for (i = 1; i <= n; i++)  { 

        int counter=0; 	

        for(num =i; num>=1; num--) {

	   if(i%num==0){

                counter = counter + 1;

	   }
         }

	    
	    if (counter ==2){

	    //Appended the Prime number to the String
	    primeNumbers = primeNumbers + i + " ";

	 }	
	
    }	

    // print out all prime numbers 
    System.out.print("Prime numbers: ");
    System.out.println(primeNumbers);

    }

}
