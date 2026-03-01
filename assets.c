#import "raylib.h"
#import "main.h"

void load_assets(Card cards[52]) {
  TraceLog(LOG_INFO, "Loading assets");

  // Load clubs
  for (int i = 0; i < CARD_SPRITE_SHEET_WIDTH; i++) {
    Card card;
    card.rect_texture.x = 0 + i * CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.y = 0;
    card.rect_texture.width = CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.height = CARD_SIZE_IMAGE_HEIGHT;

    card.type = CLUBS;

    cards[i] = card;
  }

  // Load diamonds
  for (int i = 13; i < CARD_SPRITE_SHEET_WIDTH * 2; i++) {
    Card card;
    card.rect_texture.x = 0 + i * CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.y = 0;
    card.rect_texture.width = CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.height = CARD_SIZE_IMAGE_HEIGHT;

    card.type = DIAMONDS;

    cards[i] = card;
  }

  // Load hearts
  for (int i = 26; i < CARD_SPRITE_SHEET_WIDTH * 3; i++) {
    Card card;
    card.rect_texture.x = 0 + i * CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.y = 0;
    card.rect_texture.width = CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.height = CARD_SIZE_IMAGE_HEIGHT;

    card.type = HEARTS;

    cards[i] = card;
  }

  // Load spades
  for (int i = 39; i < CARD_SPRITE_SHEET_WIDTH * 4; i++) {
    Card card;
    card.rect_texture.x = 0 + i * CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.y = 0;
    card.rect_texture.width = CARD_SIZE_IMAGE_WIDTH;
    card.rect_texture.height = CARD_SIZE_IMAGE_HEIGHT;

    card.type = SPADES;

    cards[i] = card;
  }
}
