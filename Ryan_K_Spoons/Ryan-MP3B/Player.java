/** A representation of a player in the game of spoons
  * where a turn can be simulated using takeTurn() method
  * @author Keira Ryan
  * @version 1.0
 */
import java.util.LinkedList;
public class Player {
    private int playerNum;
    private Card cardtoAdd;
    private LinkedList<Card> hand;
    private LinkedList<Integer> matches;
    private boolean hasSpoon; 
    private boolean turnTaken;
    private boolean addMatch;

    public boolean winner;
    public static Card cardtoPass;
    public static Card passedCard;
    public static int passedValue = 0;

    /** Acessor for playerNum
     * @return the int representation of the Player's number
     */
    public int getPlayerNum() {
        return this.playerNum;
    }
    /** Acessor for hand
     * @return the LinkedList represenation of the Player's hand
     */
    public LinkedList<Card> getHand() {
        return this.hand;
    }
    /** Accessor for hasSpoon
     * @return boolean representation of if Player has a spoon or not
     */
    public boolean hasSpoon() {
        return this.hasSpoon;
    }
    /** Accessor for winner
     * @return boolean representation of if Player has 4 of a kind
     */
    public boolean getWinner() {
        return this.winner;
    }
    /** Accessor for matches
     * @return LinkedList represenation of the values Player has matches of in hand
     */
    public LinkedList<Integer> getMatches() {
        return this.matches;
    }
    /** Accessor for cardToPass
     * @return Card representation of the Card the player will pass at the end of their turn
     */
    public Card getCardtoPass() {
        return Player.cardtoPass;
    }

    /** stealSpoon method
     * when called, the Player's hasSpoon status is true and
     * the number of available spoons is decreased by 1
     */
    public void stealSpoon() {
        Game.nSpoons--;
        this.hasSpoon=true;
    }

    /** First overloaded constructor creates an Object for the player
     * @param playerNum an integer representation of the player's numbers
     * @param dealer Dealer object representing the round's dealer/deck
     * Overloaded constructor gives player a hand of 4 random cards from the deck
     * and storeds it in LinkedList called hand. This constructor also checks for 
     * matches in the inital hand and adds any matching values to LinkedList matches
     */
    public Player(int playerNum, Dealer dealer) {
        this.addMatch = false;
        this.turnTaken = false;
        this.playerNum = playerNum;
        this.winner = false;
        this.hand = new LinkedList<>();
        this.matches = new LinkedList<>();
        this.hasSpoon = false;
        for (int i = 0; i<4; i++) { //creates starting hand
            Card handCard = dealer.getM_Deck().deal();
            handCard.toString();
            this.hand.add(handCard);
        }
        for (Card c: this.hand) { //checks and adds matches to LinkedList
            for (Card d: this.hand) {
                if (c.equals(d)) {
                    continue;
                }
                else {
                    if (c.getValue() == d.getValue()) {
                        this.matches.add(d.getValue());
                    }
                    else {
                        continue;
                    }
                }
            }
        }
        if (this.matches.size() == 2) {
            this.matches.remove(1);
        }
        else if (this.matches.size() > 1) {
            this.matches.remove(3);
            this.matches.remove(1);
        }
    }

    /** Second overloaded constructor creates an Object for the player
     * @param playerNum an integer representation of the player's numbers
     * @param hand LinkedList representing simulated hand
     * Overloaded constructor is used to test functionality of takeTurn method
     */
    public Player(int playerNum, LinkedList<Card> hand) {
        this.playerNum = playerNum;
        this.hand = hand;
        this.hasSpoon = false;
        this.addMatch = false;
        this.turnTaken = false;
        this.matches = new LinkedList<>();
    }
    
    /** takeTurn method takes in a passedCard as a parameter 
     * and returns a Card to be passed to the next player
     * @param passedCard Card object representing Card taken to start turn
     * @return Card object of Card to be passed to next player
     * takeTurn accounts for 4 different cases: 
     * 1. if the player already has 4 of a kind, the passedCard is passed
     * 2. if the passedCard is in matches, the card is kept and another 
     * card in their hand that does not match is passed
     * 3. if the passedCard matches a single card in their hand, the 
     * passedCard is kept and another in their hand that does not match is passed
     * 4. if the passedCard does not match any in their hand, 
     * passsedCard is passed
     */
    
    public Card takeTurn(Card passedCard) {
        passedValue = passedCard.getValue();
        if (this.hasSpoon) { //employs case 1 mentioned above
            cardtoPass = passedCard;
            this.turnTaken = true;
        }
        else if (this.matches.contains(passedValue)) { //employs case 2 mentioned above
            for (int n=0;n < 4; n++) {
                if (this.matches.contains(this.hand.get(n).getValue()) == false) {
                    cardtoPass = this.hand.get(n);
                }
            }
            this.matches.add(passedValue);
            this.hand.remove(cardtoPass);
            this.hand.add(passedCard);
            this.turnTaken = true;
        }
        for (Card card: this.hand) { //checks if case 3 applies for this turn
            if (card.getValue() == passedCard.getValue()) {
                this.addMatch=true;
            }
        }
        if (this.addMatch == true && this.turnTaken ==false) { //if the above check identified turn as case 3, case 3 is employed
            for (Card card: this.hand) {
                if (card.getValue() == passedCard.getValue()) {
                    this.matches.add(card.getValue());
                    this.addMatch=true;
                    this.cardtoAdd = passedCard;
                }
                else {
                    cardtoPass = card;
                }
            }
            if (this.addMatch=true) {
                this.hand.add(this.cardtoAdd);
                this.addMatch = false;
            }
            this.hand.remove(cardtoPass);
        }
        else if (this.turnTaken==false) { //employs case 4 mentioned above
            cardtoPass = passedCard;

        }
        if (this.matches.size() >= 3 && this.hasSpoon == false) { //checks if upon their turn, the player has won
            this.winner = true;
            this.stealSpoon();
        }
        this.turnTaken = false;
        return cardtoPass;
    }
}