#include "frame.h"

void
frame_constructor(Frame * const this,
		  GtkApplication *app,
		  const char *caption)
{
  this->base = gtk_application_window_new(app);
  panel_constructor(&this->panel);
  gtk_container_add(GTK_CONTAINER(this->base), this->panel.base);
  gtk_window_set_title(GTK_WINDOW(this->base), caption);
  gtk_window_set_resizable(GTK_WINDOW(this->base), FALSE);
  gtk_window_set_position(GTK_WINDOW(this->base), GTK_WIN_POS_CENTER);
  gtk_widget_show_all(GTK_WIDGET(this->base));
}

void frame_destructor(Frame * const this)
{
  panel_destructor(&this->panel);
}
