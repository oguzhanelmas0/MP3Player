
#ifndef PLAYLIST_H
#define PLAYLIST_H

typedef struct {
    char **songs;
    int count;
    int current_index;
} Playlist;

Playlist* playlist_new();
void playlist_add_song(Playlist *playlist, const char *song);
const char* playlist_get_next_song(Playlist *playlist);
const char* playlist_get_current_song(Playlist *playlist);
void playlist_free(Playlist *playlist);

#endif