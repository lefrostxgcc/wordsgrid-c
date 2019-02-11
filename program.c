#include <gtk/gtk.h>
#include "frame.h"

static void activate(GtkApplication *app, gpointer user_data);

static Frame *frame;

int main(int argc, char *argv[])
{
  GtkApplication *app;
  int status;
  app = gtk_application_new("info.videosharp.chip.wordsgrid",
			    G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  return status;
}

static void activate(GtkApplication *app, gpointer user_data)
{
  frame = frame_new(app);
  frame_constructor(frame, "Words in Boxes");
}
