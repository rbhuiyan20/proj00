struct song_node ** make_lib();

struct song_node ** add_song(struct song_node ** library, struct song_node * node);

struct song_node * search_song(struct song_node ** library, char * song, char * artist);

struct song_node * search_artist(struct song_node **library, char * artist);

void print_letter(struct song_node ** library, char letter);

void print_artist(struct song_node ** library, char * artist);

void print_library(struct song_node ** library);

void shuffle_songs(struct song_node ** library);

struct song_node ** remove_song(struct song_node ** library, char *s, char *a);

struct song_node ** clear(struct song_node ** library);