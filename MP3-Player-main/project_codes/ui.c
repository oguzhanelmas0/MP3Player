#include <gtk/gtk.h>
#include "ui.h"
#include "player.h"

void ui_update_current_song(UI *ui, const char *song_name);

static void on_play_button_clicked(GtkWidget *button, gpointer user_data) {
    UI *ui = (UI *)user_data;
    Player *player = ui->player;
    
    player_play(player);
    const char *current_song = playlist_get_current_song(player->playlist);
    ui_update_current_song(ui, current_song);
}

static void on_stop_button_clicked(GtkWidget *button, gpointer user_data) {
    UI *ui = (UI *)user_data;
    Player *player = ui->player;
    player_stop(player);
    ui_update_current_song(ui, NULL);
}

static void on_next_button_clicked(GtkWidget *button, gpointer user_data) {
    UI *ui = (UI *)user_data;
    Player *player = ui->player;
    player_next(player);
    const char *current_song = playlist_get_current_song(player->playlist);
    ui_update_current_song(ui, current_song);
}

UI* ui_new() {
    UI *ui = malloc(sizeof(UI));
    if (!ui) {
        g_printerr("Failed to allocate memory for UI\n");
        return NULL;
    }

    ui->main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(ui->main_window), "MP3 Player");
    gtk_window_set_default_size(GTK_WINDOW(ui->main_window), 300, 100);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(ui->main_window), box);

    ui->play_button = gtk_button_new_with_label("Play");
    ui->stop_button = gtk_button_new_with_label("Stop");
    ui->next_button = gtk_button_new_with_label("Next");
    ui->current_song_label = gtk_label_new("No song playing");

    gtk_box_pack_start(GTK_BOX(box), ui->play_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), ui->stop_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), ui->next_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), ui->current_song_label, TRUE, TRUE, 0);

    g_signal_connect(ui->main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(ui->main_window);

    return ui;
}

void ui_set_player(UI *ui, Player *player) {
    ui->player = player;
    g_signal_connect(ui->play_button, "clicked", G_CALLBACK(on_play_button_clicked), ui);
    g_signal_connect(ui->stop_button, "clicked", G_CALLBACK(on_stop_button_clicked), ui);
    g_signal_connect(ui->next_button, "clicked", G_CALLBACK(on_next_button_clicked), ui);
}

void ui_free(UI *ui) {
    free(ui);
}

void ui_update_current_song(UI *ui, const char *song_name) {
    if (song_name) {
        gtk_label_set_text(GTK_LABEL(ui->current_song_label), song_name);
    } else {
        gtk_label_set_text(GTK_LABEL(ui->current_song_label), "No song playing");
    }
}