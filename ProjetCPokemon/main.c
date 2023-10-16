#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "function.h"



int main() {

	struct Player Play1 = { 0, "player 1", false, false};
	struct Player Play2 = { 1 ,"IA", false, false};



	InitializeOurDeck(&Play1,0);
	InitializeOurDeck(&Play2,1);

	displayInformation(&Play1);




	for (int i = 0 ; i < 10; i++) {

		if (Play1.cardPlayed == false) {
		PokemonChoose(&Play1);
		PokemonChooseOrdi(&Play1,&Play2);
		}

	char action2 = RandomActionChoose(&Play2);
	ActionOnPokemon(&Play2, &Play1, action2);
	char action = ActionChoose(&Play1);
	ActionOnPokemon(&Play1,&Play2, action);
	
	CheckIfIsDie(&Play1);
	CheckIfIsDie(&Play2);



	}


	





}






