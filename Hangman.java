package hangman;
import java.util.Scanner;
public class Hangman {

	private int remValues[] = new int[26];
	public String playerNames[] = {"",""};
	public String player1String = "";
	public String player2String = "";
	public int numberOfAttemptsLeft = 7;
	private char inputChar = '\0';
	private int success = 0;
	
	public void gameStart(Scanner s) {
		System.out.println("\n\t\tHANGMAN WORLD\n\n");
		System.out.print("Enter the player 1 name: ");
		playerNames[0] = s.nextLine().toUpperCase();
		System.out.print("Enter the player 2 name: ");
		playerNames[1] = s.nextLine().toUpperCase();
	}
	
	public void takePlayer1String(Scanner s) {
		System.out.print(playerNames[0]+" Enter the string: ");
		player1String = s.nextLine().toUpperCase();
		for(int i = 0;i<30;i++)
			System.out.println();
		for(int i = 0; i<player1String.length();i++) {
			player2String += "_";
			System.out.print(" "+player2String.charAt(i));
		}
	}
	
	public void takeInputPlayer2(Scanner s) {
		System.out.print(playerNames[1] +" Enter the character: "); 
		String inputString = s.next().toUpperCase();
		inputChar = inputString.charAt(0);
	}
	
	private void inPlay() {
		int matched = 0;
		for(int i = 0; i<player1String.length();i++) {
			if(inputChar == player1String.charAt(i)) {
				matched = 1;
				player2String = player2String.substring(0, i) + inputChar + player2String.substring(i+1, player1String.length());
			}
			System.out.print(" "+player2String.charAt(i));
		}
		remValues[(int)(inputChar) - 65] = 1;
		if(matched==0)
			numberOfAttemptsLeft--;		
		if(player1String.equals(player2String))
			success = 1;		
	}
	
	public void printValues() {
		for(int i = 0; i<26; i++) {
			if(i%5==0)
				System.out.println();
			if(i==25)
				System.out.print("    ");
			if(remValues[i]==0)			
				System.out.print(" "+(char)(65+i));
			else
				System.out.print(" -");
		}
		System.out.println("\nNumber of attempts left: "+numberOfAttemptsLeft);
	}
	
	public void endGame(Scanner s) {
		while(true) {
			this.takeInputPlayer2(s);
			this.inPlay();
			this.printValues();
			if(numberOfAttemptsLeft==0 && success==0) { 
				System.out.println("\t\tGame Over");
				System.out.println(playerNames[0]+ " entered this: "+player1String);
				System.out.println("Better Luck Next Time!!");
				break;
			}
			if(success == 1) {
				System.out.println("!!Well Played "+playerNames[1] +"!!");
				System.out.println("You Guessed it correct!");
				System.out.println(player1String+"\n");
				break;
			}
		}
	}
	
	public void launchGame(Scanner s) {
		this.gameStart(s);
		this.takePlayer1String(s);
		this.printValues();
		this.endGame(s);
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		Hangman game1 = new Hangman();
		game1.launchGame(s);
	}
}
