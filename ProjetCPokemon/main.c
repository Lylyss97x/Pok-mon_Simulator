#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "function.h"



int main() {

	struct Player Play1 = { 0, false, false };
	struct Player Play2 = { 1 , false, false };

	InitializeOurDeck(&Play1);
	InitializeOurDeck(&Play2);

	displayInformation(&Play1);

	/*Define who start*/
	/*defineWhoIsFirst(&Play1);*/

	return 0;

}






