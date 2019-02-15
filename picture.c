#include "picture.h"

void picture_constructor(Picture * const this)
{
  this->surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 600, 400);
  this->g = cairo_create(this->surface);
  box_constructor(&this->box, this->g);
  picture_clear(this);
  picture_draw(this);
}

void picture_clear(Picture * const this)
{
  cairo_save(this->g);
  cairo_set_source_rgba(this->g, 1.0, 1.0, 1.0, 1.0);
  cairo_paint(this->g);
  cairo_restore(this->g);
}

void picture_draw(Picture * const this)
{
  box_draw(&this->box, "Q", 50, 80, 40, 40);
  box_draw(&this->box, "I", 50, 120, 40, 40);
}

cairo_surface_t *picture_get_surface(Picture * const this)
{
  return this->surface;
}

void picture_destructor(Picture * const this)
{
  cairo_surface_destroy(this->surface);
  cairo_destroy(this->g);
}

int picture_get_width(Picture * const this)
{
  return cairo_image_surface_get_width(this->surface);
}

int picture_get_height(Picture * const this)
{
  return cairo_image_surface_get_height(this->surface);
}

