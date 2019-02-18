#ifndef CHIP_PICTURE_H
#define CHIP_PICTURE_H

#include <gtk/gtk.h>
#include "box.h"

typedef struct {
  cairo_surface_t *surface;
  cairo_t *g;
  Box **box;
  const char *abc;
  const char *word;
  GRand *random;
  int N;
  int D;
} Picture;

void picture_constructor(Picture * const this, int N, int D);
void picture_destructor(Picture * const this);
void picture_clear(Picture * const this);
void picture_init(Picture * const this);
void picture_draw(Picture * const this);
char *picture_get_random_letter(Picture * const this);
cairo_surface_t *picture_get_surface(Picture * const this);
int picture_get_width(Picture * const this);
int picture_get_height(Picture * const this);

#endif
