// Gregory Smith
// You should NOT edit the main() function below

#include <stdio.h>

// YOUR TASK: Add the prototype and definition for the
// split function that makes the program work.
int split(double amount, int* ptrdollars, int* ptrcents);

int main() {
  /* DON'T CHANGE MAIN! Just write a good split() function
   * prototype and definition above and below.
   */
  printf("Enter amount: ");
  fflush(stdout);

  double amt;
  if (scanf(" $%lg", &amt) != 1) {
    printf("ERROR: must enter something like $3.50\n");
    return 1;
  }

  // FUNCTION CALL HERE!
  int dollars;
  int cents;
  split(amt, &dollars, &cents);

  printf("That's %i dollars and %i cents.\n", dollars, cents);

  return 0;
}

int split(double amount, int* ptrdollars, int* ptrcents){
	*ptrdollars = (int) amount;
	*ptrcents = (int) ((amount - *ptrdollars) * 100);
	return 0;
}
