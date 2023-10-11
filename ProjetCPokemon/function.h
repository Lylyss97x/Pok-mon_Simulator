#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdbool.h>


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
	struct Pokemon Deck[2];


};

void CreateOurPokemon(int idPok, bool strenght, bool durability, const char* name, const char* type, bool inGame, struct Player* playerConcerned, int index);

void displayInformation(struct Player* playerConcerned);

void InitializeOurDeck(struct Player* playerConcerned);

void defineWhoIsFirst(struct Player* playerConcerned);

/*void ActionChoose(struct Player* playerConcerned);*/





#endif