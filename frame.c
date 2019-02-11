#include <gtk/gtk.h>
#include "frame.h"

Frame *const frame_new(GtkApplication *app)
{
  return (Frame * const) gtk_application_window_new(app);
}

void frame_constructor(Frame * const this, const char *caption)
{
  gtk_window_set_title(GTK_WINDOW(this), caption);
  gtk_window_set_default_size(GTK_WINDOW(this), 600, 400);
  gtk_window_set_resizable(GTK_WINDOW(this), FALSE);
  gtk_window_set_position(GTK_WINDOW(this), GTK_WIN_POS_CENTER);
  gtk_widget_show_all(GTK_WIDGET(this));
}
