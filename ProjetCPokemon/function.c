#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>


void CreateOurPokemon(int idPok, bool strenght, bool durability, const char* name, const char* type, bool inGame, struct Player* playerConcerned, int index);


struct Pokemon
{
	int unsigned id;
	bool strenght;
	bool durability;
	char name[20];
	char type[20];
	bool inGame;
	int healPoint[1000];
	int ptAttack[100];
	int shield[50];
	int specialAttack[100];


};


struct Player {


	int id;
	bool turn;
	bool cardPlayed;
	char action[50];
	struct Pokemon Deck[3];

};


/*char ActionChoose(struct Player* playerConcerned) {
	if (playerConcerned->cardPlayed == false) {
		int choice;
		printf_s("Select which Pokemon you want to play %d.\n");
		scanf_s("%d", &choice);
		while (0>choice && choice>2)
		{
			printf_s("Select which Pokemon you want to play %d.\n");

		}

		scanf_s("%d", &choice);
		playerConcerned->Deck[choice].inGame = true;
		printf("You played a Pokemon type %d",playerConcerned->Deck[choice].type);

	}

	else {
		char action;
		printf_s("Choose what you want to do %s");
		scanf_s("%s", &action);
		while (action != "Simple Attack" && action != "Dodge" && action != "Special Attack") {
			printf_s("Choose what you want to do %s");

		}
		return action;

	}
}*/


/*Generate a bool to decide who start*/
void defineWhoIsFirst(struct Player* playerConcerned) {
	srand(time(NULL));
	int nombreAleatoire = rand() % 2;
	bool choixAleatoire = (nombreAleatoire == 1);
	playerConcerned->turn = choixAleatoire;
	if (playerConcerned->turn = true) {
		printf_s("It's my turn \n");

	}
	else {
		printf_s("It's ordi turn \n");

	}



}

void InitializeOurDeck(struct Player* playerConcerned) {


	srand(time(NULL));

	/*We implement three card into the deck of the player */
	for (int i = 0; i <= 2; i++) {

		/*We generate a random ID */
		int indicePokemon = (rand() % 4) + 1;
		switch (indicePokemon) {

		case 1:
			CreateOurPokemon(indicePokemon, true, false, "Pokémon Feu", "FEU", false, playerConcerned, i);

			break;

		case 2:

			CreateOurPokemon(indicePokemon, false, true, "Pokémon Eau", "EAU", false, playerConcerned, i);
			break;

		case 3:

			CreateOurPokemon(indicePokemon, false, true, "Pokémon Terre", "TERRE", false, playerConcerned, i);
			break;

		case 4:

			CreateOurPokemon(indicePokemon, true, true, "Pokémon Métal", "METAL", false, playerConcerned, i);
			break;
		}


	}
}

void displayInformation(struct Player* playerConcerned) {
	printf_s("Here is your deck \n");
	for (int i = 0; i <= 2; i++) {
		printf_s("You have one pokemon type :  %s\n", playerConcerned->Deck[i].type);
		printf_s("His ID is  %d\n", playerConcerned->Deck[i].id);
		printf_s("\n");
	}



};




void CreateOurPokemon(int idPok, bool strenght, bool durability, const char* name, const char* type, bool inGame, struct Player* playerConcerned, int index)
{
	struct Pokemon P = { idPok, strenght, durability, inGame };
	strncpy_s(P.name, sizeof(P.name), name, sizeof(P.name) - 1);
	strncpy_s(P.type, sizeof(P.type), type, sizeof(P.type) - 1);
	playerConcerned->Deck[index] = P;
}



