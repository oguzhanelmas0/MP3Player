#ifndef UI_H
#define UI_H

#include <gtk/gtk.h>
#include "player.h"

typedef struct {
    GtkWidget *main_window;
    GtkWidget *play_button;
    GtkWidget *stop_button;
    GtkWidget *next_button;
    GtkWidget *current_song_label; // for showing the current song
    Player *player;
} UI;

UI* ui_new();
void ui_set_player(UI *ui, Player *player);
void ui_show(UI *ui);
void ui_free(UI *ui);
void ui_update_current_song(UI *ui, const char *song_name);

#endif // UI_H