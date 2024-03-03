//============================================================================
// Name        : gully-cricket-app.cpp
// Author      : Tanisha Ali
//============================================================================

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
using namespace std;

class Team {

	public:
		string name;
		string players[3];
		int runs;
};

void welcomeUsers();
void startInning(int, string, string);
void displayPlayers(string[], string[]);
void selectBatsmanAndBowler(Team, Team);
string selectPlayer(string[]);
int playInning();
void displayScore(Team);
void decideWinner(int, int);

string currentBatsman, currentBowler;


int main() {

	welcomeUsers();

	Team teamA;
	teamA.players[0] = "Hina";
	teamA.players[1] = "Tina";
	teamA.players[2] = "Rina";
	teamA.name = "TeamA";

	Team teamB;
	teamB.players[0] =  "Sara";
	teamB.players[1] =  "Kiara";
	teamB.players[2] =  "Tori";
	teamB.name = "TeamB";

    displayPlayers(teamA.players, teamB.players);

    startInning(1, teamA.name, teamB.name);
    selectBatsmanAndBowler(teamA, teamB);
    teamA.runs = playInning();
    displayScore(teamA);

    cout << "\n*********** TeamB needs " << teamA.runs + 1 << " runs to win ***********" << endl << endl;

    startInning(2, teamB.name, teamA.name);
    selectBatsmanAndBowler(teamB, teamA);
    teamB.runs = playInning();
    displayScore(teamB);

    decideWinner(teamA.runs, teamB.runs);

    return 0;
}


void welcomeUsers() {

    cout << "---------------------------------------" << endl;
    cout << "|=========== GULLY CRICKET ===========|" << endl;
    cout << "|                                     |" << endl;
    cout << "|      Welcome to Gully Cricket       |" << endl;
    cout << "---------------------------------------" << endl;
}


void displayPlayers(string playersA[3], string playersB[3]) {

	cout << "\nPress Enter to display players: ";
	cin.get();

    cout << "Displaying players...\n";
    usleep(1000 * 1000);

    cout << "--------------------------\t\t--------------------------" << endl;
    cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
    cout << "--------------------------\t\t--------------------------" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "|\t";
        cout << "[" << i << "] " << playersA[i] << "\t |";
        cout << "\t\t|\t";
        cout << "[" << i << "] " << playersB[i] << "\t |";
        cout << endl;
    }
    cout << "--------------------------\t\t--------------------------" << endl << endl;
}


void selectBatsmanAndBowler(Team batTeam, Team bowlTeam) {

    cout << "Press Enter to select batsman and bowler: ";
    cin.get();

    cout << "Selecting batsman and bowler...\n";
    usleep(1000 * 1000);

    currentBatsman = selectPlayer(batTeam.players);
    currentBowler = selectPlayer(bowlTeam.players);

    cout << "----------------------------------------------------" << endl;
    cout << "\t\t " << batTeam.name << ": Batsman - " << currentBatsman <<endl;
    cout << "\t\t " << bowlTeam.name << ": Bowler - " << currentBowler <<endl;
    cout << "----------------------------------------------------" << endl << endl;
}


string selectPlayer(string players[3]) {

    int randomValue;

    srand(time(NULL));
    randomValue = rand() % 3;

    string selectedPlayerName = players[randomValue];
    return selectedPlayerName;
}


void startInning(int inning, string batTeam, string bowlTeam) {

	cout << "Press Enter to start inning " << inning;
    cin.get();
    usleep(1000 * 1000);

    cout << "|------------ Inning " << inning << " Starts ------------|" << endl;
    cout << "|----- " << batTeam << " is batting and " << bowlTeam << " is bowling -----|" << endl << endl;
}


int playInning() {

    int runs = 0;
    const int MAX_BALLS = 6;

    for (int i = 0; i < MAX_BALLS; i++) {

        cout << "Press Enter to bowl...";
        cin.get();

        cout << "Bowling..." << endl << endl;
        usleep(1000 * 1000);

        int randomValue;
        srand(time(NULL));
        randomValue = rand() % 7;
        runs = runs + randomValue;

        cout << "----------------------------------------------------" << endl;
        cout << "|\t\t" << currentBowler << " to " << currentBatsman << " " << randomValue << " runs" << endl;
        cout << "----------------------------------------------------" << endl << endl;
    }

    return runs;
}


void displayScore(Team team) {

    cout << "----------------------------------------------------" << endl;
    cout << "\t\t " << team.name << " scored " << team.runs << " runs." << endl;
    cout << "----------------------------------------------------" << endl << endl;
}


void decideWinner(int teamAScore, int teamBScore) {

	cout << "----------------------------------------------------" << endl;

    if (teamAScore > teamBScore) {
        cout << "\t\t Team A is the Winner" << endl;
    } else if (teamAScore < teamBScore) {
        cout<< "\t\t Team B is the Winner" << endl;
    } else {
        cout << "\t\t Match Draw" << endl;
    }

    cout << "----------------------------------------------------" << endl << endl;
}
