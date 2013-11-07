#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long long int bignum;

// Linked-list list element
typedef struct 
{
    bignum val_x;
    bignum val_y;
    struct list_el* next;
} list_el;

// Function prototype
void factor(bignum* number, bignum* divisor, list_el** current, list_el** curr_head);


int main(void)
{
	bignum value = 0;
	bignum root  = 0;
	list_el* curr = NULL, * head = NULL, * temp = NULL;
	
	// Get a number to factor from user should be less than (2^64)-1
	printf("Enter a number: ");
	scanf("%llu",&value);
	// Get the square root
	root = sqrt(value) +1;
	
	// Get the list of factors and store them in the linked list
	factor(&value, &root, &curr, &head);
	
	// Iterate through linked list of factors and display results
	while (curr)
	{
		// If the current factor is 1 and  next pointer is null, value is prime	
		if ( curr->val_x == 1 && !curr->next )
		{
			printf("The value you entered is prime!\n");
		}
		else
		{
			printf("The factors are %llu and %llu\n", curr->val_x, curr->val_y);
		}

		temp = curr;
		curr = (list_el*) curr->next;
		free(temp);
	}

	return 0;
}

// Definition of factors function
void factor(bignum* number, bignum* divisor, list_el** current, list_el** curr_head)
{
	while (*divisor ^ 0)
	{
		// If current root is a factor, add to linked list
		if (*number % *divisor == 0)
		{
			*current = (list_el*) malloc(sizeof(list_el));
			(*current)->val_x = *divisor;
			(*current)->val_y = *number / *divisor;
			(*current)->next = (list_el*) *curr_head;
			*curr_head = *current;
		}
		--(*divisor);
	}
}
