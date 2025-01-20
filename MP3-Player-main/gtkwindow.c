#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    GtkWidget *window; // Pencere widget'ı

    // GTK+ başlatılıyor
    gtk_init(&argc, &argv);

    // Yeni bir pencere oluşturuluyor
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Pencere başlığı ayarlanıyor
    gtk_window_set_title(GTK_WINDOW(window), "Merhaba GTK+");

    // Pencere boyutu ayarlanıyor
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Pencereyi kapatınca uygulamanın çıkmasını sağlıyor
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Pencereyi göster
    gtk_widget_show(window);

    // GTK ana döngüsünü başlat
    gtk_main();

    return 0;
}