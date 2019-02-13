#include "panel.h"

static gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer data)
{
  (void) widget;
  (void) data;
  cairo_move_to(cr, 200, 150);
  cairo_show_text(cr, "ABC");
  return FALSE;
}

Panel panel_new(void)
{
  return (Panel) { .base = gtk_drawing_area_new() };
}

void panel_constructor(Panel * const this)
{
  gtk_widget_set_size_request(this->base, 600, 400);
  g_signal_connect(G_OBJECT(this->base), "draw",
		   G_CALLBACK(on_draw), NULL);
}
