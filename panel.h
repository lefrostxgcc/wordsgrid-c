#ifndef CHIP_PANEL_H
#define CHIP_PANEL_H

#include <gtk/gtk.h>
#include "picture.h"

typedef struct
{
  GtkWidget *base;
  Picture picture;
} Panel;

void panel_constructor(Panel * const this);
void panel_destructor(Panel * const this);

#endif
