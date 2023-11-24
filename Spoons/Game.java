/** A representation of a game of spoons
  * where a round can be simulated using play() method
  * @author Keira Ryan
  * @version 1.0
 */
import java.util.LinkedList;
import java.util.Random;
public class Game {
    /* BEGIN CODE WITH HELP OF STUDENT GABI BEKHRAD: she helped 
     * by showing me I should use Player[] instead of player ArrayList
     */
    private Player[] players;
    /* END OF CODE WITH HELP OF STUDENT GABI BEKHRAD */
    private Dealer dealer;
    private int numPlayers;
    private int loser;
    private Card startCard;
    private LinkedList<Card> discards;
    private Random randy;

    public static int nSpoons;

    /** Acessor for players
     * @return Player Array representation of players in the game
     */
    public Player[] getPlayers() {
        return this.players;
    }
    /** Accessor for dealer
     * @return Dealer representation of game's dealer
     */
    public Dealer getDealer() {
        return this.dealer;
    }
    /** Accessor for numPlayers
     * @return int representation of number of players in the game
     */
    public int getNumPlayers() {
        return this.numPlayers;
    }
    /** Accessor for nSpoons
     * @return int representation of the number of spoons available
     */
    public int getSpoons() {
        return Game.nSpoons;
    }
    /** Accessor for loser
     * @return int representation of the player number of the player that lost
     */
    public int getLoser() {
        return this.loser;
    }
    /** Accessor for startCard
     * @return Card representation of the Card drawn from the deck
     */
    public Card getStartCard() {
        return this.startCard;
    }
    /** Accessor for discards
     * @return LinkedList representation of the Cards that have been discarded by the last player
     */
    public LinkedList<Card> getDiscards() {
        return this.discards;
    }
    /** Accessor for randy
     * @return Random representation of the object that will determine 1/3 odds of noticing spoon theft
     */
    public Random getRandy() {
        return this.randy;
    }

    /** Default Game constructor 
     * creates a default game of 4 players with 3 spoons available 
     */
    public Game() {
        this.dealer = new Dealer();
        this.loser = 0;
        this.numPlayers = 4;
        this.randy = new Random();
        this.discards = new LinkedList<>();
        Game.nSpoons = this.numPlayers - 1;
        this.players = new Player[4];
        for (int i = 1; i <= this.numPlayers; i++) {
            this.players[i-1] = new Player(i,this.dealer);
        }
    }

    /** Overload Game constructor takes in an integer representing the 
     * number of players in the game, creating a game with the specified
     * amount of players and one spoon less than the total player count
     * @param numPlayers int representation of the number of players
     */
    public Game(int numPlayers) {
        this.dealer = new Dealer();
        this.loser = 0;
        this.numPlayers = numPlayers;
        this.discards = new LinkedList<>();
        this.randy = new Random();
        Game.nSpoons = this.numPlayers - 1;
        this.players = new Player[numPlayers];
        for (int j = 1; j <= this.numPlayers; j++) {
            this.players[j-1] = new Player(j,this.dealer);
        }
    }

    /** Play() method simulates one round of the game Spoons, going
     * in order of the player numbers using a Player[]. The round
     * continues until all spoons are gone. If the player gets 4 of
     * a kind when they take their turn, all players have a 1/3 chance
     * of noticing and taking a spoon when all spoons are gone, the 
     * while loop stops and the player number of the player without a
     * spoon is returned
     * @return int representation of the number of the player who lost the round
     */
    public int play() {
        while (Game.nSpoons != 0) {
            for (int m = 0; m < this.numPlayers; m++) {
                if (this.dealer.size() == 0) {
                    this.dealer.m_deck = new Deck(this.discards);
                }
                if (m == 0) {
                    this.startCard = this.dealer.getM_Deck().deal();
                    this.players[m].takeTurn(this.startCard);
                }
                else if (m == (this.numPlayers-1)) {
                    this.players[m].takeTurn(Player.cardtoPass);
                    this.discards.add(Player.cardtoPass);
                }
                else {
                    this.players[m].takeTurn(Player.cardtoPass);
                }
                if (this.players[m].winner = true) {
                    if (Game.nSpoons == 0) {
                        break;
                    }
                    for (Player pl: this.players) {
                        int chance = this.randy.nextInt(3);
                        if (chance == 1 && pl.hasSpoon() == false) {
                            pl.stealSpoon();
                            if (Game.nSpoons == 0) {
                                break;
                            }
                        }
                    }
                }
                if (Game.nSpoons == 0) {
                break;
                }
            }
            if (Game.nSpoons == 0) {
                break;
            }
        }
        for (Player pla: this.players) {
            if (pla.hasSpoon() == false) {
                this.loser = pla.getPlayerNum();
            }
        }
        return this.loser;
    }
}