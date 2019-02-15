#ifndef CHIP_BOX_H
#define CHIP_BOX_H

#include <gtk/gtk.h>

typedef struct {
  cairo_t *g;
  cairo_font_face_t *font;
} Box;

void box_constructor(Box * const this, cairo_t *graphics);
void box_draw(Box * const this,
	      const char *letter, int x, int y, int sx, int sy);

#endif
