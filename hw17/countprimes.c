/* Gregory Smith
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Reads a single number from the terminal that is at least
// as large as the given integer.
// If the user enters a number too small, they will repeatedly
// be prompted again and again until they enter a number that
// is large enough.
int getnum(int atleast);

// Returns the number of primes between a and b.
// The count is inclusive meaning that if a or be is a prime,
// they should be included in the count.
int countprimes(int a, int b);

// provided in assignment
bool isprime(int n);

int main(){
	
	int least = getnum(1);
	int max = getnum(least);
	int primes = countprimes(least, max);
	printf("There are %d primes between %d and %d.",
	primes, least, max);
	
	printf("\n");
	return 0;
}



// Determines whether n is a prime number.
// If it is, true is returned, and if not, false is returned.
bool isprime(int n) {
  if (n < 2) {
    // 2 is the smallest prime.
    return false;
  }

  // try all possible divisors of n
  for (int fact=2; fact*fact <= n; ++fact) {
    if (n % fact == 0) {
      // n is divisible by fact, so not a prime
      return false;
    }
  }

  // n doesn't have ANY factors, so it's a prime.
  return true;
}


int getnum(int atleast){
	int input = 0;
	printf("Enter a number at least %d: ", atleast);
	scanf("%d", &input);
	if(input < atleast){
		printf("Too small!\n");
		return getnum(atleast);
		
	}else{
		return input;
	}
}

int countprimes(int a, int b){
	int primes = 0;
	
	primes += isprime(b);
	
	if(a == b){
		return primes;
	}else{
		// recursive case
		// b > a
		b = b - 1;
		return primes + countprimes(a, b);
	}
		
		
	
}
