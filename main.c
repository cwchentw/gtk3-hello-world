#include <gtk/gtk.h>
#ifdef _WIN32
#include <windows.h>
#endif

static void activate(GtkApplication* app, gpointer user_data)
{
    GtkWidget *window;
    
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "Window");
    gtk_window_set_default_size(GTK_WINDOW (window), 400, 300);
    gtk_widget_show_all(window);
}

#ifdef _WIN32
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
#else
int main(int argc, char **argv)
#endif
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK(activate), NULL);
#ifdef _WIN32
    status = g_application_run (G_APPLICATION (app), 0, NULL);
#else
    status = g_application_run (G_APPLICATION (app), argc, argv);
#endif
    g_object_unref (app);

    return status;
}
