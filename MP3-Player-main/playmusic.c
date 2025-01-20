#include <gtk/gtk.h>
#include <gst/gst.h>

// GStreamer pipeline
GstElement *pipeline = NULL;

// Play butonuna tıklandığında çağrılacak fonksiyon
void on_play_button_clicked(GtkWidget *button, gpointer user_data) {
    if (!pipeline) {
        pipeline = gst_element_factory_make("playbin", "playbin");
        if (!pipeline) {
            g_printerr("Failed to create pipeline!\n");
            return;
        }

        // Çalınacak şarkının dosya yolu
        g_object_set(pipeline, "uri", "file:///home/vboxuser/Downloads/song1.mp3", NULL); // Tam dosya yolunu buraya yaz
    }

    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    g_print("Playing song...\n");
}

// Stop butonuna tıklandığında çağrılacak fonksiyon
void on_stop_button_clicked(GtkWidget *button, gpointer user_data) {
    if (!pipeline) {
        g_print("Pipeline not initialized!\n");
        return;
    }

    // Çalmayı durdur
    gst_element_set_state(pipeline, GST_STATE_PAUSED);
    g_print("Stopped playback.\n");
}

// Ana program
int main(int argc, char *argv[]) {
    // GTK+ ve GStreamer başlatılıyor
    gtk_init(&argc, &argv);
    gst_init(&argc, &argv);

    // GTK+ pencere oluşturuluyor
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "MP3 Player");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 100);

    // GTK+ kutu (box) layout'u
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Play ve Stop butonları
    GtkWidget *play_button = gtk_button_new_with_label("Play");
    GtkWidget *stop_button = gtk_button_new_with_label("Stop");

    // Butonları kutuya ekle
    gtk_box_pack_start(GTK_BOX(box), play_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), stop_button, TRUE, TRUE, 0);

    // Buton sinyallerini bağla
    g_signal_connect(play_button, "clicked", G_CALLBACK(on_play_button_clicked), NULL);
    g_signal_connect(stop_button, "clicked", G_CALLBACK(on_stop_button_clicked), NULL);

    // Pencereyi kapatınca uygulamanın çıkmasını sağlıyor
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Pencereyi göster
    gtk_widget_show_all(window);

    // GTK ana döngüsünü başlat
    gtk_main();

    return 0;
}
