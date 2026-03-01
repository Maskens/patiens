#import "raylib.h"
#import "main.h"

void load_assets(Card cards[52]) {

  int card_value = 1;

  // Load clubs
  for (int i = 0; i < CARD_SPRITE_SHEET_WIDTH; i++) {
    Card card;
    card.rect_texture.x = 0 + i * CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.y = 0;
    card.rect_texture.width = CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.height = CARD_SIZE_IMAGE_HEIGHT;

    card.type = CLUBS;
    card.value = card_value;
    card_value += 1;

    cards[i] = card;
  }

  card_value = 1;

  // Load diamonds
  for (int i = 13; i < CARD_SPRITE_SHEET_WIDTH * 2; i++) {
    Card card;
    card.rect_texture.x = 0 + i * CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.y = 0;
    card.rect_texture.width = CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.height = CARD_SIZE_IMAGE_HEIGHT;

    card.type = DIAMONDS;
    card.value = card_value;
    card_value += 1;

    cards[i] = card;
  }

  card_value = 1;

  // Load hearts
  for (int i = 26; i < CARD_SPRITE_SHEET_WIDTH * 3; i++) {
    Card card;
    card.rect_texture.x = 0 + i * CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.y = 0;
    card.rect_texture.width = CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.height = CARD_SIZE_IMAGE_HEIGHT;

    card.type = HEARTS;
    card.value = card_value;
    card_value += 1;

    cards[i] = card;
  }

  card_value = 1;

  // Load spades
  for (int i = 39; i < CARD_SPRITE_SHEET_WIDTH * 4; i++) {
    Card card;
    card.rect_texture.x = 0 + i * CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.y = 0;
    card.rect_texture.width = CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.height = CARD_SIZE_IMAGE_HEIGHT;

    card.type = SPADES;
    card.value = card_value;
    card_value += 1;

    cards[i] = card;
  }
}
