#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

struct Pokemon
{
	int unsigned id;
	bool strenght;
	bool durability;
	char name[20];
	char type[20];
	int healPoint[1000];
	int ptAttack[100];
	int shield[50];
	int specialAttack[100];

};


struct Player {


	int id;
	bool turn;
	char action[50];
	struct Pokemon Deck[2];

};



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
		printf_s("It's computer turn \n");

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
			CreateOurPokemon(indicePokemon, true, false, "Pokémon Feu", "FEU", playerConcerned, i);

			break;

		case 2:

			CreateOurPokemon(indicePokemon, false, true, "Pokémon Eau", "EAU", playerConcerned, i);
			break;

		case 3:

			CreateOurPokemon(indicePokemon, false, true, "Pokémon Terre", "TERRE", playerConcerned, i);
			break;

		case 4:

			CreateOurPokemon(indicePokemon, true, true, "Pokémon Métal", "METAL", playerConcerned, i);
			break;
		}


	}
}

/*Show Informations*/
void displayInformation(struct Player* playerConcerned) {
	printf_s("Here is your deck \n");
	for (int i = 0; i <= 2; i++) {
		printf_s("You have one pokemon type :  %s\n", playerConcerned->Deck[i].type);
		printf_s("His ID is  %d\n", playerConcerned->Deck[i].id);
		printf_s("\n");
	}



};



void CreateOurPokemon(int idPok, bool strenght, bool durability, const char* name, const char* type, struct Player* playerConcerned, int index) {


	struct Pokemon P = { idPok, strenght, durability };
	strncpy_s(P.name, sizeof(P.name), name, sizeof(P.name) - 1);
	strncpy_s(P.type, sizeof(P.type), type, sizeof(P.type) - 1);
	playerConcerned->Deck[index] = P;


};
