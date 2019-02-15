#include "picture.h"

void box_constructor(Box * const this, cairo_t *graphics)
{
  this->g = graphics;
  this->font = cairo_toy_font_face_create("Liberation Serif",
					  CAIRO_FONT_SLANT_NORMAL,
					  CAIRO_FONT_WEIGHT_NORMAL);
}

void box_draw(Box * const this,
	      const char *letter, int x, int y, int sx, int sy)
{
  cairo_save(this->g);
  cairo_set_source_rgba(this->g, 0.0, 0.0, 0.0, 1.0);
  cairo_rectangle(this->g, x, y, sx, sy);
  cairo_stroke(this->g);
  cairo_set_font_face(this->g, this->font);
  cairo_set_font_size(this->g, 20);
  cairo_text_extents_t ex;
  cairo_text_extents(this->g, letter, &ex);
  double letter_x = x + 1 + (sx - 2 - ex.width) / 2 - ex.x_bearing;
  double letter_y = y + 1 + (sy - 2 - ex.height) / 2 - ex.y_bearing;
  cairo_set_source_rgba(this->g, 1.0, 0.0, 0.0, 1.0);
  cairo_move_to(this->g, letter_x, letter_y);
  cairo_show_text(this->g, letter);
  cairo_stroke(this->g);
  cairo_restore(this->g);
}
