#include <iostream>
#include <cstdlib> // Pentru rand() si srand()
#include <chrono> // Pentru masurarea timpului
#include <thread> // Pentru sleep (pauza)

using namespace std::this_thread;
using namespace std::chrono;

void run_coin_toss(int number_of_heads) {
	int coin_position;
	bool game_status = true; // Bool pentru a vedea daca mai continua functia while (adica jocul) sau nu, deoarece daca pica CAP de 5 ori sau se opreste jocul, acest bool devine false
	
	while (game_status == true) {
		coin_position = rand() % 2; // Genereaza un numar aleatoriu intre 0 si 1
		
		if (coin_position == 1) {
			std::cout << "\nA picat CAP! Se arunca banul din nou.\n";
			number_of_heads++; 
			
			if (number_of_heads >= 5) {
				std::cout << "\nA picat CAP de 5 ori! Jocul s-a terminat!\n";
				std::cout << "------------------------------------------";
				game_status = false;
			}

			sleep_for(seconds(2)); 
		}
		
		else {
			std::cout << "\nA picat PAJURA!\n";
			std::string play_again;
			std::cout << "\tVrei sa mai joci din nou? (Scrie 'Y'): ";
			std::cin >> play_again;
			
			if (play_again == "Y" || play_again == "y") {
				std::cout << "\nReinitializam jocul!\n";
				number_of_heads = 0; // Daca ai ales sa rejoci jocul, acest index se reseteaza pentru a numara din nou de cate ori va pica CAP
				sleep_for(seconds(2));
			}
			
			else {
				std::cout << "\nJocul s-a terminat!\n";
				std::cout << "-------------------";
				game_status = false;
			}
		}
	}

}


void start_game() {
	char game_start; // Necesara pentru ca utilizatorul sa porneasca programul cand vrea el
	int number_of_heads = 0; // Acest index e pentru a numara de cate ori a picat CAP

	do {
		std::cout << "---------- Aruncarea banului ----------\n";
		std::cout << "Introdu litera 'S' pentru a incepe jocul : ";
		std::cin >> game_start;

		if (game_start != 'S' && game_start != 's' && game_start > 1) {
			std::cout << "Valoarea incorecta!\n";
			sleep_for(seconds(1)); // Aceasta comanda face o mica pauza de x secunde pentru a crea atmosfera unui joc si de a nu grabi lucrurile
			std::cout << "Reinitializam programul...\n";
			std::cout << "--------------------------\n\n";
			sleep_for(seconds(1));
		}

		std::cin.ignore(1000, '\n'); // Curata bufferul de restul caracterelor

	} while (game_start != 'S' && game_start != 's');

	srand(time(0)); // Initializeaza generatorul de numere aleatoare cu timpul curent, ca rezultatele sa fie diferite la fiecare rulare
	sleep_for(seconds(1));
	run_coin_toss(number_of_heads);
}

int main() {
	start_game();
}