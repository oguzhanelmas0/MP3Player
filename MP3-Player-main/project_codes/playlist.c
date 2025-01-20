
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

Playlist* playlist_new() {
    Playlist *playlist = malloc(sizeof(Playlist));
    playlist->songs = NULL;
    playlist->count = 0;
    playlist->current_index = 0;
    return playlist;
}

void playlist_add_song(Playlist *playlist, const char *song) {
    playlist->songs = realloc(playlist->songs, (playlist->count + 1) * sizeof(char *));
    playlist->songs[playlist->count] = strdup(song);
    playlist->count++;
}

const char* playlist_get_next_song(Playlist *playlist) {
    if (playlist->count == 0) return NULL;
    playlist->current_index = (playlist->current_index + 1) % playlist->count;
    return playlist->songs[playlist->current_index];
}

const char* playlist_get_current_song(Playlist *playlist) {
    if (playlist->count == 0) return NULL;
    return playlist->songs[playlist->current_index];
}

void playlist_free(Playlist *playlist) {
    for (int i = 0; i < playlist->count; i++) {
        free(playlist->songs[i]);
    }
    free(playlist->songs);
    free(playlist);
}