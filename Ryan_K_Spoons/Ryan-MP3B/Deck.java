import java.util.LinkedList;
import java.util.Random;
public class Deck {
    private LinkedList<Card> m_cards;
    private Random randy = new Random();
    private Card cardtoRemove;

    /** Default constructor creates a standard
     * playing card deck of 52 cards of all suits
     * and values in the format of a LinkedList
     */
    public Deck() {
        m_cards = new LinkedList<Card>();
        for (int i = 0; i <4; i++) {
            for (int j = 2; j<15; j++) {
                Card currentCard = new Card(j,i);
                m_cards.add(currentCard);
            }
        }
    }

    public Deck(LinkedList<Card> m_cards) {
        this.m_cards = m_cards;
    }

    /** Copy constructor makes duplicate Deck object
     * @param deckToCopy the Deck object which will be copied
     */
    public Deck(Deck deckToCopy) {
        for (int k = 0; k<53; k++) {
            Card copyCard = new Card(deckToCopy.m_cards.get(k));
            this.m_cards.add(copyCard);
        }
    }

    /** The toString() method which is the text representation 
     * of the Deck
     * @return the text representation of a Deck
     */
    public String toString() {
        return this.m_cards.toString();
    }

    /** The size method which returns an integer representation
     * of the amount of cards in a Deck
     * @return the int representation of the Deck size
     */
    public int size() {
        return this.m_cards.size();
    }

    /** The deal method which selects and returns a random card from the deck
     * @return the card that was randomly selected from the Deck
     */
    public Card deal() {
        //woop de doo 
        this.cardtoRemove = this.m_cards.get(randy.nextInt(this.m_cards.size()));
        this.m_cards.remove(this.cardtoRemove);
        return this.cardtoRemove;
    }
}
