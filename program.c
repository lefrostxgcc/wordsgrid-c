#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data);

static GtkWidget *jframe;

int main(int argc, char *argv[])
{
  GtkApplication *app;
  int status;
  app = gtk_application_new("info.videosharp.chip.wordsgrid",
			G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  return status;
}

static void activate(GtkApplication *app, gpointer user_data)
{
  jframe = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(jframe), "Words in Boxes");
  gtk_window_set_default_size(GTK_WINDOW(jframe), 600, 400);
  gtk_window_set_resizable(GTK_WINDOW(jframe), FALSE);
  gtk_window_set_position(GTK_WINDOW(jframe), GTK_WIN_POS_CENTER);
  gtk_widget_show_all(jframe);
}
