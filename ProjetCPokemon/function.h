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
	int healPoint;
	int ptAttack;
	int shield;
	int specialAttack;
	bool powerUse;
	bool dodge;
	bool isDie;
	int index;





};

struct Player {


	int id;
	bool turn;
	bool cardPlayed;
	char action[50];
	struct Pokemon Deck[3];
	int PokemonPlay;



};

void CreateOurPokemon(int idPok, bool strenght, bool durability, const char* name, const char* type, bool inGame, struct Player* playerConcerned, int index);

void displayInformation(struct Player* playerConcerned);

void InitializeOurDeck(struct Player* playerConcerned, int NumbPlayer);

void defineWhoIsFirst(struct Player* player1, struct Player* player2);

void PokemonChoose(struct Player* player1);

char ActionChoose(struct Player* player1);

void PokemonChooseOrdi(struct Player* player2);

void ShieldTouched(int atkPokemon, struct Player* player2);

void RandomActionChoose(struct Player* player2);

void EventDuringSimpleAttack( int atkPokemon, int idPoke2,  int strenght1, int strenght2, int *shieldPokemon2, struct Player* player2);

void Dodge(int idPoke1, struct Player* player1);

void SimpleAttack(int idPoke1, int atkPokemon, int idPoke2,  int *shieldPokemon2, struct Player* player2);

void ActionOnPokemon(struct Player* player1, struct Player* player2, char* action);

void SpecialAttack(int idPoke1, int* atkPokemon, int idPoke2, int* hpPokemon2, int* hpPokemon, struct Player* player2, int* shieldPokemon);

void CheckIfIsDie(struct Player* player1);

bool CheckIfGameisOver(struct Player* player1);

void Play(struct Player* player1, struct Player* player2);










#endif