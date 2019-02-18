#include "picture.h"
#include <string.h>
#include <stdbool.h>

static const char *abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void picture_constructor(Picture * const this, int N, int D)
{
  this->surface = cairo_image_surface_create(
                                             CAIRO_FORMAT_ARGB32,
                                             N * D + 1, N * D + 1);
  this->g = cairo_create(this->surface);
  this->random = g_rand_new();
  this->abc = abc;
  this->word = "IMPLEMENTATION";
  this->N = N;
  this->D = D;
  picture_clear(this);
  picture_init(this);
  picture_draw(this);
}

void picture_clear(Picture * const this)
{
  cairo_save(this->g);
  cairo_set_source_rgba(this->g, 1.0, 1.0, 1.0, 1.0);
  cairo_paint(this->g);
  cairo_restore(this->g);
}

void picture_init(Picture * const this)
{
  this->box = g_slice_alloc(sizeof(*this->box) * this->N);
  for (int row = 0; row < this->N; row++)
    {
      this->box[row] = g_slice_alloc(sizeof(*this->box[row]) * this->N);
      for (int col = 0; col < this->N; col++)
        box_constructor(&this->box[row][col], this->g, this->D);
    }
}

void picture_draw(Picture * const this)
{
  int **map = g_slice_alloc(sizeof(*map) * this->N);
  for (int row = 0; row < this->N; row++)
    {
      map[row] = g_slice_alloc(sizeof(*map[row]) * this->N);
      for (int col = 0; col < this->N; col++)
        map[row][col] = 0;
    }
  int word_length = strlen(this->word);
  while (true)
    {
      for (int row = 0; row < this->N; row++)
        for (int col = 0; col < this->N; col++)
          map[row][col] = -1;
      int row = g_rand_int_range(this->random, 0, this->N);
      int col = g_rand_int_range(this->random, 0, this->N);
      int index;
      for (index = 0; index < word_length; index++)
        {
          if (row < 0 || row >= this->N || col < 0 || col >= this->N)
            break;
          if (map[row][col] >= 0)
            break;
          map[row][col] = index;
          switch (g_rand_int_range(this->random, 0, 4))
            {
            case 0: row++; break;
            case 1: row--; break;
            case 2: col++; break;
            case 3: col--; break;
            }
        }
      if (index >= word_length)
        break;
    }
  for (int row = 0; row < this->N; row++)
    for (int col = 0; col < this->N; col++)
      {
        char *letter = NULL;
        bool hint = false;
        if (map[row][col] >= 0)
          {
            letter = g_slice_alloc(sizeof(*letter) * 2);
            letter[0] = this->word[map[row][col]];
            letter[1] = '\0';
            hint = true;
          }
        else
          letter = picture_get_random_letter(this);
        box_draw(&this->box[row][col], letter, hint,
                 row * this->D, col * this->D);
        g_slice_free1(sizeof(*letter) * 2, letter);
      }
  for (int row = 0; row < this->N; row++)
    g_slice_free1(sizeof(*map[row]) * this->N, map[row]);
  g_slice_free1(sizeof(*map) * this->N, map);
}

char *picture_get_random_letter(Picture * const this)
{
  gint32 index = g_rand_int_range(this->random, 0, strlen(this->abc));
  char *p = g_slice_alloc(sizeof(*p) * 2);
  p[0] = this->abc[index];
  p[1] = '\0';
  return p;
}

cairo_surface_t *picture_get_surface(Picture * const this)
{
  return this->surface;
}

void picture_destructor(Picture * const this)
{
  for (int row = 0; row < this->N; row++)
    g_slice_free1(sizeof(*this->box[row]) * this->N, this->box[row]);
  g_slice_free1(sizeof(*this->box) * this->N, this->box);
  g_rand_free(this->random);
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

