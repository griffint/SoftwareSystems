/*Griffin Tschurwald homework 1*/

#include <stdio.h>
#include <stdlib.h>

/*
* This function will determine the number value of the card based
* on the user's string input. 
* Returns: an integer
*/
int determine_card_number(char card_name[])
{
	puts("We are in determine_card_number");
	int val;

	switch(card_name[0])
	{
	
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break; 
		default:
			val = atoi(card_name);
			if ((val < 1) || (val > 10)) 
			{
				puts("I don't understand that value!");
			}
	}

	return val;
}

/* 
* This function will update the count based on the 
* value of the card
*/
int update_count(int old_count, int card_val)
{
	if ((card_val>2) && (card_val < 7))
		{
			old_count++;
		} else if (card_val == 10)
		{
			old_count--;
		}
	return old_count;
}


int main()
{
	char card_name[3];
	int count = 0;
	while (card_name[0] != 'x')
	{
		puts("Enter the card_name: ");
		scanf("%2s", card_name);
		int val = determine_card_number(card_name);
		printf("in main, the val is %i\n", val);
		count = update_count(count, val);
		printf("Current Count: %i\n", count);
	}
	return 0;
}