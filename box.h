#ifndef CHIP_BOX_H
#define CHIP_BOX_H

#include <gtk/gtk.h>
#include <stdbool.h>

typedef struct {
  cairo_t *g;
  cairo_font_face_t *font;
  int D;
} Box;

void box_constructor(Box * const this, cairo_t *graphics, int D);
void box_draw(Box * const this, const char *letter, bool hint, int x, int y);

#endif
