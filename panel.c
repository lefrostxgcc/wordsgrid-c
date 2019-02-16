#include "panel.h"

static gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer data)
{
  (void) widget;
  cairo_set_source_surface(cr,
			   picture_get_surface((Picture * const) data),
			   0, 0);
  cairo_paint(cr);
  return FALSE;
}

void panel_constructor(Panel * const this)
{
  this->base = gtk_drawing_area_new();
  picture_constructor(&this->picture, 12, 40);
  gtk_widget_set_size_request(this->base,
			      picture_get_width(&this->picture),
			      picture_get_height(&this->picture));
  g_signal_connect(G_OBJECT(this->base), "draw",
		   G_CALLBACK(on_draw), (gpointer) &this->picture);
}

void panel_destructor(Panel * const this)
{
  picture_destructor(&this->picture);
}
