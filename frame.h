#ifndef CHIP_FRAME_H
#define CHIP_FRAME_H

#include <gtk/gtk.h>

typedef struct
{
  GtkApplicationWindow base;
} Frame;

Frame *const frame_new(GtkApplication *app);

void frame_constructor(Frame * const this, const char *caption);

#endif
