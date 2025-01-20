#ifndef PLAYER_H
#define PLAYER_H

#include <gst/gst.h>
#include "playlist.h"

typedef struct {
    Playlist *playlist;
    GstElement *pipeline;
    gboolean is_playing;
} Player;

Player* player_new();
void player_set_playlist(Player *player, Playlist *playlist);
void player_play(Player *player);
void player_stop(Player *player);
void player_next(Player *player);
void player_free(Player *player);
const char* playlist_get_current_song(Playlist *playlist);
const char* playlist_get_next_song(Playlist *playlist);

#endif // PLAYER_H