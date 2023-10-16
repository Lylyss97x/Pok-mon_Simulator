#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>


void CreateOurPokemon(int idPok, bool strenght, bool durability, const char* name, const char* type, bool inGame, struct Player* playerConcerned, int index);
char ActionChoose(struct Player* player1);
void PokemonChooseOrdi(struct Player* player2);
char RandomActionChoose(struct Player* player2);
void ActionOnPokemon(struct Player* player1, struct Player* player2, char* action);
void PokemonChoose(struct Player* player1);
void CheckIfIsDie(struct Player* player1);




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


};


struct Player {


	int id;
	char name;
	bool turn;
	bool cardPlayed;
	char action[50];
	struct Pokemon Deck[3];
	int PokemonPlay;

};


void ShieldTouched(int atkPokemon, struct Player* player2) {


	int leftdamage = player2->Deck[player2->PokemonPlay].shield - atkPokemon;

	if (leftdamage < 0) {
		player2->Deck[player2->PokemonPlay].shield = 0;

		player2->Deck[player2->PokemonPlay].healPoint = player2->Deck[player2->PokemonPlay].healPoint - abs(leftdamage);
		printf_s("Shield broken ! \n");
		printf_s("Pokemon Attacked : %d\n", player2->name);
		printf_s("Pokemon hp left :  %d \n", player2->Deck[player2->PokemonPlay].healPoint);
		printf_s("\n");

	}
	else {
		player2->Deck[player2->PokemonPlay].shield = leftdamage;

		printf_s("Shield Resist ! \n");
		printf_s("Pokemon shield resist left :  %d \n", player2->Deck[player2->PokemonPlay].shield);
		printf_s("\n");



	}


}



void EventDuringSimpleAttack( int atkPokemon, int idPoke2, int strenght1, int strenght2, int *shieldPokemon2,struct Player* player2) {

	if ((idPoke2) == strenght1 || (idPoke2) == strenght2) {

		int atk = atkPokemon * 2;
		if (shieldPokemon2 == 0) {
			player2->Deck[player2->PokemonPlay].healPoint = player2->Deck[player2->PokemonPlay].healPoint - atk;
			
			player2->Deck[player2->PokemonPlay].healPoint = player2->Deck[player2->PokemonPlay].healPoint;
			printf_s("Your damage is boost !\n");
			printf_s("Pokemon Attacked : %d\n", player2->name);
			printf_s("Pokemon hp left :  %d \n", player2->Deck[player2->PokemonPlay].healPoint);
			printf_s("\n");

		}
		else {

			ShieldTouched(atk,  player2);

		}
	}


	else {

		int atk = atkPokemon;
		if (shieldPokemon2 == 0) {
			player2->Deck[player2->PokemonPlay].healPoint = player2->Deck[player2->PokemonPlay].healPoint - atk;
			player2->Deck[player2->PokemonPlay].healPoint = player2->Deck[player2->PokemonPlay].healPoint;
			printf_s("Your damage is boost !\n");
			printf_s("Pokemon Attacked : %d\n", player2->name);
			printf_s("Pokemon hp left :  %d \n", player2->Deck[player2->PokemonPlay].healPoint);
			printf_s("\n");

		}
		else {

			ShieldTouched(atk, player2);
		}

	}

		
		

}


void Play(struct Player* player1, struct Player* player2) {


	PokemonChoose(&player1);
	RandomActionChoose(&player2);
	PokemonChooseOrdi(&player1, &player2);

	char action = ActionChoose(&player2);
	ActionOnPokemon(&player1, &player2, action);
	CheckIfIsDie(&player1);


}



void SimpleAttack(int idPoke1, int atkPokemon, int idPoke2,  int *shieldPokemon2, struct Player* player2) {

	if (idPoke1 == 1) {

		EventDuringSimpleAttack( atkPokemon, idPoke2, 3, 4, shieldPokemon2,player2);

	}

	if (idPoke1 == 2) {

		EventDuringSimpleAttack( atkPokemon, idPoke2, 3, 1, shieldPokemon2, player2);

	}

	if (idPoke1 == 3) {

		EventDuringSimpleAttack( atkPokemon, idPoke2,  1, 4, shieldPokemon2, player2);

	}

	if (idPoke1 == 4) {

		EventDuringSimpleAttack(atkPokemon, idPoke2,  2, 3, shieldPokemon2, player2);

	}

}



bool CheckIfGameisOver(struct Player* player1) {
	int nbDeath = 0;
	for (int i = 0; i < 3; i++) {
		if (player1->Deck[i].isDie == true) {
			nbDeath = nbDeath + 1;
		}
	}

	if (nbDeath == 3) {
		printf_s("PARTIE IS OVER");
		return true;
	}

	else {
		return false;
	}
}



void CheckIfIsDie(struct Player* player1) {
	for (int i = 0; i < 3; i++) {
		if (player1->Deck[i].healPoint <= 0) {
			player1->Deck[i].isDie = true;
			printf_s("Your Pokemon is die");
		}
	}
	
}




void Dodge(int idPoke1, struct Player* player1) {
	player1->Deck[idPoke1].dodge = true;
	printf_s("Dodge Mode activate ! \n");
	printf_s("\n");


}




void SpecialAttack(int idPoke1, int atkPokemon, int idPoke2,  int* hpPokemon, struct Player* player2, struct Player* player1, int *shieldPokemon) {

	if (idPoke1 == 1) {

		atkPokemon = atkPokemon * 3;
		printf_s("Fire Attack Increase !");
		printf_s("Attack %d \n", atkPokemon);


	}

	if (idPoke1 == 2) {
		player1->Deck[player1->PokemonPlay].healPoint = player1->Deck[player1->PokemonPlay].healPoint + 100;
		printf_s("Heal by Water ! \n");
		printf_s("HP %d \n", player1->Deck[player1->PokemonPlay].healPoint);
		printf_s("\n");

	}

	if (idPoke1 == 3) {
		printf_s(" EarthShake activate !\n");
		for (int i = 0; i < 3; i++) {
			player2->Deck[i].healPoint = player2->Deck[i].healPoint - 50;
			printf_s(" HP %d \n", player2->Deck[i].healPoint);
				
		}

	}


	if (idPoke1 == 4) {

		shieldPokemon = shieldPokemon + 50;
		printf_s(" Shield Reinforce !");
		printf_s(" Shield %d \n", shieldPokemon);


	}


}



void ActionOnPokemon( struct Player* player1, struct Player* player2, char *act) {
	char simpleAttack[] = "Simple Attack";
	char specialAttack[] = "Special Attack";
	char dodge[] = "Dodge";

	const char* ActionList[] = { "Simple Attack", "Special Attack"};


	int idPokemon1 = player1->Deck[player1->PokemonPlay].id;
	int atkPokemon1 = player1->Deck[player1->PokemonPlay].ptAttack;

	int hpPokemon1 = player1->Deck[player1->PokemonPlay].healPoint;
	int idPokemon2 = player2->Deck[player2->PokemonPlay].id;

	int atkPokemon2 = player2->Deck[player2->PokemonPlay].ptAttack;
	int hpPokemon2 = player2->Deck[player2->PokemonPlay].healPoint;
	int shieldPokemon2 = player2->Deck[player2->PokemonPlay].shield;



	printf_s("Pokemon Id for player 1 : %d \n", player1->name);
	printf_s("Pokemon Id for player 2 : %d \n", player2->name);
	printf_s("%s \n", player1->action);
	/*if action trigger is simple attack*/
	if ((strcmp(player1->action, simpleAttack) == 0)) {
		SimpleAttack(idPokemon1, atkPokemon1, idPokemon2, shieldPokemon2, player2);
		}


	if ((strcmp(player1->action, specialAttack) == 0)) {
		if ((player1->Deck[idPokemon1].powerUse) == false) {
			SpecialAttack(idPokemon1, atkPokemon1, idPokemon2, hpPokemon2,hpPokemon1, player2, shieldPokemon2);
			player1->Deck[idPokemon1].powerUse = true;

		}

		else {
			ActionChoose(player1);
		}

		if ((strcmp(player1->action, dodge) == 0)) {

			Dodge(idPokemon1, player1);


		}

	}


	}





char RandomActionChoose(struct Player* player2) {

	const char* ActionList[] = { "Simple Attack", "Special Attack" };
	int randomIndex = rand() % (sizeof(ActionList) / sizeof(ActionList[0]));
	const char* actionChoose = ActionList[randomIndex];
	printf_s("Ordi chose %s \n", actionChoose);
	strcpy(player2->action, actionChoose);

	return actionChoose;

}
	


char ActionChoose(struct Player* player1) {

	const char* ActionList[] = { "Simple Attack", "Special Attack", "Dodge" };
	char choiceAction[100];

	printf_s("Choose what you want to do: ");
	fgets(choiceAction, sizeof(choiceAction), stdin);
	choiceAction[strcspn(choiceAction, "\n")] = '\0';

	int validChoice = 0;

	for (int i = 0; i < 3; i++) {
		if (strcmp(choiceAction, ActionList[i]) == 0) {
			validChoice = 1;
			break;
		}
	}

	while (!validChoice) {
		printf_s("Invalid choice. Please choose again: ");
		printf_s("\n");

		fgets(choiceAction, sizeof(choiceAction), stdin);
		choiceAction[strcspn(choiceAction, "\n")] = '\0';

		for (int i = 0; i < 3; i++) {
			if (strcmp(choiceAction, ActionList[i]) == 0) {
				validChoice = 1;
				break;
			}
		}
	}

	printf_s("You chose %s.\n", choiceAction);
	printf_s("\n");

	strcpy(player1->action, choiceAction);

	return choiceAction;
}




void PokemonChoose(struct Player* player1) {
	if (player1->cardPlayed == false) {

		int choice;
		int min = 0;
		int max = 2;

		while (1) {
			printf_s("Select which Pokemon you want to play (0, 1 or 2) \n");
			printf_s("\n");


			if (scanf("%d", &choice) == 1) {
				if (choice >= min && choice <= max && player1->Deck[choice].isDie == false) {
					player1->cardPlayed = true;
					player1->Deck[choice].inGame = true;
					player1->PokemonPlay = choice;
					printf("You played a Pokemon type %s.\n", player1->Deck[choice].type);
					printf("His ID is  %d.\n", player1->Deck[choice].id);
					printf_s("\n");

					player1->PokemonPlay = choice;
					break; // La valeur est valide, sortir de la boucle
				}
				else {
					printf_s("Choose a Pokemon between 0 and 2 both include \n");
					printf_s("\n");

				}
			}
			else {
				// La saisie n'est pas un entier
				printf_s("Choose anotehr one \n");
				printf_s("\n");


				while (getchar() != '\n') {
					continue;
				}
			}
		}
		

	}


}




void PokemonChooseOrdi(struct Player* player2) {
	int randomPokemon = rand() % 3;
	player2->Deck[randomPokemon].inGame = true;
	player2->PokemonPlay = randomPokemon;
	printf("Ordi play a  Pokemon type %s.\n", player2->Deck[randomPokemon].type);
	printf("His ID is  %d.\n", player2->Deck[randomPokemon].id);
	printf_s("\n");

}




/*Generate a bool to decide who start*/
void defineWhoIsFirst(struct Player* player1, struct Player* player2) {
	srand(time(NULL));
	int nombreAleatoire = rand() % 2;
	bool choixAleatoire = (nombreAleatoire == 1);

	if (nombreAleatoire == 0) {
		player1->turn = choixAleatoire;
		printf_s("It's my turn \n");
		printf_s("\n");


	}

	else {
		player1->turn = choixAleatoire;
		printf_s("It's ordi turn \n");
		printf_s("\n");


	}

	}




void InitializeOurDeck(struct Player* playerConcerned, int NumbPlayer) {
	srand(time(NULL));

	/*We implement three card into the deck of the player */
	for (int i = 0; i <= 2; i++) {

		/*We generate a random ID */
		int indicePokemon = (rand() % 4) + 1;
		int indicePokemon2 = (rand() % 4) + 1;

		if (NumbPlayer == 1) {
			indicePokemon = indicePokemon2;
		}
		
		
		switch (indicePokemon) {

		case 1:
			CreateOurPokemon(indicePokemon, true, false, "Pokémon Feu", "FIRE", false, playerConcerned, i);

			break;

		case 2:

			CreateOurPokemon(indicePokemon, false, true, "Pokémon Eau", "WATER", false, playerConcerned, i);
			break;

		case 3:

			CreateOurPokemon(indicePokemon, false, true, "Pokémon Terre", "EARTH", false, playerConcerned, i);
			break;

		case 4:

			CreateOurPokemon(indicePokemon, true, true, "Pokémon Métal", "METAL", false, playerConcerned, i);
			break;
		}


	}
}

void displayInformation(struct Player* playerConcerned) {
	printf_s("YOUR DECK COMPOSITION IS : \n");
	for (int i = 0; i <= 2; i++) {
		if (playerConcerned->Deck[i].isDie == false) {
		printf_s("You drop a pokemon type :  %s\n", playerConcerned->Deck[i].type);
		printf_s("\n");
		}
		else {
			continue;
		}
		
	}



};





void CreateOurPokemon(int idPok, bool strenght, bool durability, const char* name, const char* type, bool inGame, struct Player* playerConcerned, int index)
{
	struct Pokemon P = { idPok, strenght, durability, inGame, 1000, 100, 50, 100,false };
	strncpy_s(P.name, sizeof(P.name), name, sizeof(P.name) - 1);
	strncpy_s(P.type, sizeof(P.type), type, sizeof(P.type) - 1);
	playerConcerned->Deck[index] = P;
	playerConcerned->Deck[index].id = idPok;
	playerConcerned->Deck[index].strenght = strenght;
	playerConcerned->Deck[index].durability = durability;
	playerConcerned->Deck[index].inGame = inGame;
	playerConcerned->Deck[index].healPoint = 1000;
	playerConcerned->Deck[index].ptAttack = 100;
	playerConcerned->Deck[index].shield = 50;
	playerConcerned->Deck[index].specialAttack = 100;
	playerConcerned->Deck[index].powerUse = false;
	playerConcerned->Deck[index].dodge = false;
	playerConcerned->Deck[index].isDie = false;












}



