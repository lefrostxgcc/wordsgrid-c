#ifndef CHIP_FRAME_H
#define CHIP_FRAME_H

#include <gtk/gtk.h>
#include "panel.h"

typedef struct
{
  GtkWidget *base;
  Panel panel;
} Frame;

Frame frame_new(GtkApplication *app);
void frame_constructor(Frame * const this, const char *caption);

#endif
