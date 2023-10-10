#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "function.h"



int main() {

	/*Implementation of the players*/
	struct Player Play1 = { 0, false };
	struct Player Play2 = { 1 , false };

	/*Function to Implmement the card into the deck of the player*/
	InitializeOurDeck(&Play1);
	InitializeOurDeck(&Play2);

	/*Show the information abou our Pokemon*/
	displayInformation(&Play1);

	/*Define who start*/
	defineWhoIsFirst(&Play1);


}












