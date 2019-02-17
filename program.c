#include <gtk/gtk.h>
#include "frame.h"

static void save_picture(const Frame *f);
static void activate(GtkApplication *app, gpointer user_data);

static Frame frame;

int main(int argc, char *argv[])
{
  GtkApplication *app;
  int status;
  app = gtk_application_new("info.videosharp.chip.wordsgrid",
                            G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  frame_destructor(&frame);
  return status;
}

static void activate(GtkApplication *app, gpointer user_data)
{
  frame_constructor(&frame, app, "Words in Boxes");
  save_picture(&frame);
}

static void save_picture(const Frame *f)
{
  cairo_surface_write_to_png(f->panel.picture.surface, "words.png");
}
