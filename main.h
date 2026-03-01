#include "raylib.h"

#ifndef MAIN_H
#define MAIN_H

#define SCREEN_WIDTH 1536/2
#define SCREEN_HEIGHT 768*1.5/2

#define SNAP_DISTANCE 100
#define NO_OF_CARDS 52
#define CARD_SIZE_IMAGE_HEIGHT 780
#define CARD_SIZE_IMAGE_WIDTH 560
#define CARD_SPRITE_SHEET_WIDTH 13

typedef enum Type {
  SPADES,
  DIAMONDS,
  CLUBS,
  HEARTS
} Type;

typedef struct Card {
  Rectangle rect_world;
  Rectangle rect_texture;
  Type type;
} Card;

#endif

