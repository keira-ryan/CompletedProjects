import java.util.LinkedList;

public class Dealer {
    public Deck m_deck;

    /** the Default constructor creates an Object
     * comprised of a default Deck
     */
    public Dealer() {
        Deck hand = new Deck();
        this.m_deck = hand;
    }

    public Deck getM_Deck() {
        return this.m_deck;
    }

    public LinkedList<Card> deals(int n) {
        LinkedList<Card> hand = new LinkedList<>();
        for (int i= 0; i< n; i++) {
            hand.add(this.m_deck.deal());
        }
        return hand;
    }
    
    /** The size method which returns an integer representation
     * of the amount of cards a Dealer has in their deck
     * @return the int representation of the Dealer's deck size
     */
    public int size() {
        return this.m_deck.size();
    }

    /** The toString() method which is the text representation of
     * the Dealer's hand
     * @return the textual representation of a dealer's hand 
     */
    public String toString() {
        return this.m_deck.toString();
    }
}
