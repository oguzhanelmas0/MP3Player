#include "player.h"
#include <gst/gst.h>

Player* player_new() {
    Player *player = malloc(sizeof(Player));
    if (!player) {
        g_printerr("Failed to allocate memory for Player\n");
        return NULL;
    }
    player->pipeline = gst_element_factory_make("playbin", "playbin");
    if (!player->pipeline) {
        g_printerr("Failed to create pipeline\n");
        free(player);
        return NULL;
    }
    player->is_playing = FALSE;
    return player;
}

void player_set_playlist(Player *player, Playlist *playlist) {
    player->playlist = playlist;
}

void player_play(Player *player) {
    const char *current_song = playlist_get_current_song(player->playlist);
    g_object_set(player->pipeline, "uri", current_song, NULL);
    gst_element_set_state(player->pipeline, GST_STATE_PLAYING);
    player->is_playing = TRUE;
}

void player_stop(Player *player) {
    gst_element_set_state(player->pipeline, GST_STATE_NULL);
    player->is_playing = FALSE;
}

void player_next(Player *player) {
    gst_element_set_state(player->pipeline, GST_STATE_NULL);
    const char *next_song = playlist_get_next_song(player->playlist);
    g_object_set(player->pipeline, "uri", next_song, NULL);
    gst_element_set_state(player->pipeline, GST_STATE_PLAYING);
    player->is_playing = TRUE;
}

void player_free(Player *player) {
    gst_object_unref(player->pipeline);
    free(player);
}