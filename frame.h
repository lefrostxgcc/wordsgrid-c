#ifndef CHIP_FRAME_H
#define CHIP_FRAME_H

#include <gtk/gtk.h>
#include "panel.h"

typedef struct
{
  GtkWidget *base;
  Panel panel;
} Frame;

void frame_constructor(Frame * const this,
		       GtkApplication *app,
		       const char *caption);
void frame_destructor(Frame * const this);

#endif
