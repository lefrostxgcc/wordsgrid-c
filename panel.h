#ifndef CHIP_PANEL_H
#define CHIP_PANEL_H

#include <gtk/gtk.h>

typedef struct
{
  GtkWidget *base;
} Panel;

Panel panel_new(void);
void panel_constructor(Panel * const this);

#endif
