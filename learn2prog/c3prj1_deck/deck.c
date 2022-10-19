#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
	for (int i = 0; i < hand->n_cards; ++i) {
	  printf("%c%c ", value_letter(*(hand->cards[i])), suit_letter(*(hand->cards[i])));
	}
}

int deck_contains(deck_t * d, card_t c) {
  for (int i = 0; i < d->n_cards; ++i) {
    if ((*(d->cards[i])).value == c.value && (*(d->cards[i])).suit == c.suit) {
		return 1;
	}
  }	
  	return 0;
}

void shuffle(deck_t * d){
	card_t * temp = NULL;
	for (int i = 0; i < d->n_cards; ++i) {
		int num_shuffle = rand() % d->n_cards;
		temp = d->cards[i];
		d->cards[i] = d->cards[(i + num_shuffle) % d->n_cards];
		d->cards[(i + num_shuffle) % d->n_cards] = temp;
	}
}

void assert_full_deck(deck_t * d) {
  for(unsigned i = 0; i < 52; i++) {
    card_t temp = card_from_num(i);
    if(!deck_contains(d, temp)) {
      printf("The deck does not contain the card: %c%c", temp.value, temp.suit);
      exit(EXIT_FAILURE);
    }
  }
}
