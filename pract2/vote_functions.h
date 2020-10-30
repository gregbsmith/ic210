/* vote_functions.h
 * Gregory Smith
 */
#ifndef VOTE_FUNCTIONS_H
#define VOTE_FUNCTIONS_H
#include <stdbool.h>

void get_names(char* c1, char* c2);
bool update_counts(char* input, char* c1, int* ct1,
char* c2, int*ct2);
void display_results(char* c1, int ct1, char* c2, int ct2);

#endif // VOTE_FUNCTIONS_H
