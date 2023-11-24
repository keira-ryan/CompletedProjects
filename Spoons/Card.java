/** A representation of a playing Card
  * where cards can be created with value and suit 
  * @author Keira Ryan
  * @version 1.0
 */

public class Card {
    private int suit;
    private int value;
    
    public static final int HEARTS = 0;
    public static final int SPADES = 1;
    public static final int CLUBS = 2;
    public static final int DIAMONDS = 3;

    public static final int JACK = 11;
    public static final int QUEEN = 12;
    public static final int KING = 13;
    public static final int ACE = 14;

    /** Default constructor creates and Object for the card
     * Default cards are all an Ace of Spades
     */
    public Card() {
        this.suit = SPADES;
        this.value = ACE;
    }

    /** Overload constructor takes in an integer repsresnting the 
     * card value and and integer representing the cards' suit:
     * 0 for hearts, 1 for spades, 2 for clubs, and 3 for diamonds
     * @param value int representation of card value
     * @param suit int representation of card suit
     */
    public Card(int value, int suit) {
        this.suit = suit;
        this.value = value;
    }

    /** Copy constructor makes duplictae of Card object
     * @param cardtoCopy Card to be copied
     */
    public Card(Card cardtoCopy) {
        this.suit = cardtoCopy.suit;
        this.value = cardtoCopy.value;
    }

    /** Accessor for the int representation of Card suit
     * @return the int representation of the card's suit
     */
    public int getSuit() {
        return this.suit;
    }

    /** Mutator for the int representation of the card suit
     * @param newSuit int representation of the new card suit
     */
    public void setSuit(int newSuit) {
        this.suit = newSuit;
    }

    /** Accessor for the int representation of the card value
     * @return the int representation of the card value
     */
    public int getValue() {
        return this.value;
    }

    /** Mutator for the int representation of the card value
     * @param newValue the int representation of the new card value
     */
    public void setValue(int newValue) {
        this.value = newValue;
    }

    /** the equals method comparing a Card object to other objects
     * two cards are equal if they have the same suit and value
     * @param o the Object that the card is compared to
     * @return true if the card and object are equal, false if they are not 
     */
    public boolean equals(Object o) {
        if (!(o instanceof Card)) {
            return false;
        }
        else {
            Card otherCard = (Card) o;
            return this.suit == otherCard.suit
            && this.value == otherCard.value;
        }
    }

    /** The toString() method which is the text representation 
     * of the card, including suit and value
     * @return the text representation of a Card
     */
    public String toString() {
        String suitString = "";
        if (this.suit == 0) {
            suitString = " of Hearts";
        }
        else if (this.suit == 1) {
            suitString = "of Spades";
        }
        else if (this.suit == 2) {
            suitString = "of Clubs";
        }
        else {
            suitString = "of Diamonds";
        }
        if (this.value == 11) {
            return "Jack " + suitString;
        }
        else if (this.value == 12) {
            return "Queen " + suitString;
        }
        else if (this.value == 13) {
            return "King " + suitString;
        }
        else if (this.value == 14) {
            return "Ace " + suitString;
        }
        else {
            return this.value + " " + suitString;
        }
    }
}
