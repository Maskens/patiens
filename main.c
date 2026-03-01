#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#include "main.h"
#include "assets.h"

#define SF (SCREEN_HEIGHT / SCREEN_WIDTH)

enum DragState {
  NOP,
  BEGIN_DRAG,
  DRAG,
  DROP
};

Card cards[NO_OF_CARDS];

Card* find_clicked_card() {
  for (int i = 0; i < NO_OF_CARDS; i++) {
    Card card = cards[i];

    if(CheckCollisionPointRec(GetMousePosition(), card.rect_world)) {
      return &cards[i];
    }
  }

  return NULL;
}

int main(int argc, char *argv[]) {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cards!");

  SetTargetFPS(60);

  enum DragState ds = NOP;

  // Load all card textures
  Image card_sprite_sheet = LoadImage("resources/classic_13x4x560x780.png");
  Texture2D cards_texture = LoadTextureFromImage(card_sprite_sheet);
  SetTextureFilter(cards_texture, TEXTURE_FILTER_BILINEAR);
  UnloadImage(card_sprite_sheet);

  load_assets(cards);

  Card* active_card = NULL;

  Vector2 mouseOffset;

  while(!WindowShouldClose()) {
    float screen_w = GetScreenWidth();
    float screen_h = GetScreenHeight();
    float scale_factor = screen_w / screen_h;

    float card_width = (float)screen_w * 0.12;
    float card_height = card_width * 1.4;
    float offset = card_width * 0.15;

    int second_row_offset = card_height + offset;

    for (int i = 0; i < NO_OF_CARDS; i++) {
      Card card = cards[i];

      float pos_x = offset + (i * (card_width + offset));
      float pos_y = offset + second_row_offset;

      Rectangle dest = { 
        pos_x, 
        pos_y, 
        card_width,
        card_height
      };

      cards[i].rect_world = dest;
    }
    // *** Input ***
    Vector2 mpos = GetMousePosition();

    switch (ds) {
      case NOP:
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
          if ((active_card = find_clicked_card()) != NULL) {
            TraceLog(LOG_INFO, "%d", active_card->value);

            ds = BEGIN_DRAG;
          }
        }
        break;
      case BEGIN_DRAG:
        mouseOffset.x = mpos.x - active_card->rect_world.x;
        mouseOffset.y = mpos.y - active_card->rect_world.y;
        ds = DRAG;
      break;
      case DRAG:
        active_card->rect_world.x = mpos.x - mouseOffset.x;
        active_card->rect_world.y = mpos.y - mouseOffset.y;

        TraceLog(LOG_INFO, "%d", active_card->rect_world.x);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
          ds = NOP;
        }
        break;
      default:
        break;
    }

    // *** Drawing ***
    BeginDrawing();
    ClearBackground(BLACK);

    // Draw first row
    // DrawRectangleLines(offset, offset, card_width, card_height, GRAY);
    //
    // float w = (card_width + offset);
    // DrawRectangleLines(offset + 3 * w, offset, card_width, card_height, GRAY);
    // DrawRectangleLines(offset + 4 * w, offset, card_width, card_height, GRAY);
    // DrawRectangleLines(offset + 5 * w, offset, card_width, card_height, GRAY);
    // DrawRectangleLines(offset + 6 * w, offset, card_width, card_height, GRAY);

    // Draw second row
  
    for (int i = 0; i < NO_OF_CARDS; i++) {
      Rectangle card_rect = cards[i].rect_texture;
      Rectangle rect_world = cards[i].rect_world;

      DrawTexturePro(cards_texture, card_rect, rect_world, (Vector2){0,0}, 0.0f, WHITE);
    }

    EndDrawing();
  }

  CloseWindow();
  UnloadTexture(cards_texture);

  return 0;
}
