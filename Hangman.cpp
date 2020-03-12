#include<iostream>
#include<string>

using namespace std;

class Game1 {

	private:
		int remValues[26]={0};
		string playerNames[2] = {"",""};
		string player1String = "";
		string player2String = "";
		int numberOfAttemptsLeft = 7;
		char inputChar = '\0';
		int success = 0;
	
		void gameStart() {
			cout<<"\n\t\tHANGMAN WORLD\n\n"<<endl;
			cout<<"\tEnter the player 1 name: ";
			getline(cin,playerNames[0]);
			int i;
			for(i=0; i<playerNames[0].length();i++)
				playerNames[0][i] = toupper(playerNames[0][i]); 
			cout<<"\tEnter the player 2 name: ";
			getline(cin,playerNames[1]);
			for(i=0; i<playerNames[1].length();i++)
				playerNames[1][i] = toupper(playerNames[1][i]); 
		}	
	
		void takePlayer1String() {
			cout<<"\t"<<playerNames[0]<<" Enter the string: ";
			getline(cin,player1String);
			int i;
			for(i=0; i<player1String.length();i++)
				player1String[i] = toupper(player1String[i]);
			system("cls");
			for(i=0;i<5;i++)
				cout<<endl;
			cout<<"\t";
			player2String = player1String;
			for(i = 0; i<player1String.length();i++) {
				player2String[i]='_';
				cout<<" "<<player2String[i];
			}
		}	
	
		void takeInputPlayer2() {
			cout<<"\t"<<playerNames[1]<<" Enter the character: "; 
			string inputString;
			getline(cin,inputString);
			inputChar = toupper(inputString[0]);
			system("cls");
			for(int i=0;i<5;i++)
				cout<<endl;
		} 
		
	
		void inPlay() {
			int matched = 0;
			int i;
			cout<<"\t";
			for(i = 0; i<player1String.length();i++) {
				if(inputChar == player1String[i]) {
					matched = 1;
					player2String[i] = inputChar;
				}
				cout<<" "<<player2String[i];
			}
			remValues[(int)(inputChar) - 65] = 1;
			if(matched==0)
				numberOfAttemptsLeft--;		
			if(player1String.compare(player2String)==0)
				success = 1;		
		}	
	
		void printValues() {
			cout<<"\t";
			for(int i = 0; i<26; i++) {
				if(i%5==0){
					cout<<endl;
					cout<<"\t";
				}
				if(i==25)
					cout<<("    ");
				if(remValues[i]==0)			
					cout<<" "<<(char)(65+i);
				else
					cout<<" _";
				}
			cout<<"\n\tNumber of attempts left: "<<numberOfAttemptsLeft<<endl;
		}
	
		void endGame() {
		while(true) {
			this->takeInputPlayer2();
			this->inPlay();
			this->printValues();
			if(numberOfAttemptsLeft==0 && success==0) { 
				cout<<"\n\n\t\tGame Over"<<endl;
				cout<<"\t"<<playerNames[0]<<" entered this: "<<player1String<<endl;
				cout<<"\tBetter Luck Next Time!!"<<endl;
				break;
			}
			if(success == 1) {
				cout<<"\n\n\t!!Well Played "<<playerNames[1]<<"!!"<<endl;
				cout<<"\tYou Guessed it correct!"<<endl;
				cout<<"\t"<<player1String<<endl;
				break;
			}
		}
		}
	
	public:
		void launchGame() {
		this->gameStart();
		this->takePlayer1String();
		this->printValues();
		this->endGame();
	}
};

int main() {
	string ans;
	do{
		system("cls");
		Game1 g1;
		g1.launchGame();
		cout<<"\n\tDo you want to play again?(y/n): ";
		getline(cin,ans);
	}while(toupper(ans[0])=='Y');
	system("cls");
	cout<<"\tThanks for Playing!!"<<endl;
	cout<<"\n\tHope You Liked The Game!!"<<endl;
}


