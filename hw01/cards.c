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
	int val;
	while (card_name[0] != 'x')
	{
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
		case 'X':
			continue;
		default:
			val = atoi(card_name);
			if ((val < 1) || (val > 10)) 
			{
				puts("I don't understand that value!");
				continue;
			}
		}
	}
	
	return val;
}

int main()
{
	char card_name[3];
	int count = 0;
		puts("Enter the card_name: ");
		scanf("%2s", card_name);
		int val = determine_card_number(card_name);
		if ((val>2) && (val < 7))
		{
			count++;
		} else if (val == 10)
		{
			count--;
		}
		printf("Current Count: %i\n", count);
	return 0;
}