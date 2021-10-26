#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include <time.h>
#include "linkedlist.h"
//ctype.h is for isalpha
#include <ctype.h>


struct song_node ** make_lib() {
  struct song_node ** library;
  library = calloc(27, sizeof(struct song_node *));
  return library;
}

// helper function for add_song
// converts artist name to an integer
int artist_toIndex(char *artist){
  if(isalpha(artist[0])) return ((int) tolower(artist[0]))-97;
  else return 26;
}

struct song_node ** add_song(struct song_node **library, struct song_node * node){
  int i = artist_toIndex(node->artist);
  library[i] = insert_order(library[i], node);
  return library;
}

// returns pointer to a song based on artist and song name
struct song_node * search_song(struct song_node ** library, char * song, char * artist) {
  char tL = artist[0];
  if (tL < 97) tL += 32;
  
  // find_song is from linkedlist
  return find_song(library[tL - 97], song, artist);
}

struct song_node * search_artist(struct song_node ** library, char * artist) {
  char tL = artist[0];
  if (tL < 97) tL += 32;
  
  return find_first(library[tL-97], artist);
}

void print_letter(struct song_node ** library, char letter) {

  if (letter < 97) letter += 32;
  printf("%c: ", letter);
  print_list(library[letter-97]);

}

void print_artist(struct song_node ** library, char * artist) {

  char tL = artist[0];
  if (tL < 97) tL += 32;
  
  struct song_node * list = library[tL-97];
  printf("%s songs: ", artist);
  if (!strcmp(list->artist, artist)) print_struct(list);
  
  while (list->next) {
    list = list->next;
    if (!strcmp(list->artist, artist)) print_struct(list);
  }
}

void print_library(struct song_node ** library) {

  int i;
  for (i = 0; i < 27; i++) {
    if(i != 26) printf("%c: ", i+97);
    else printf("special character: ");
    print_list(library[i]);
    printf("\n");
  }
}

void shuffle_songs(struct song_node ** library) {
  srand(time(NULL));
  int i = 0;
  struct song_node * temp;
  for (i = 0; i < 5; i++) {
    // returns an int between 0 and 26
    int r = rand() % 27;
    if (library[r] == NULL) i--;  
    else {
      temp = random_node(library[r]);
      print_struct(temp);
    }
  }
}

struct song_node ** remove_song(struct song_node ** library, char *s, char *a) {
  int i = artist_toIndex(a);
  library[i] = remove_node(library[i], s, a);

  return library;
}

struct song_node ** clear(struct song_node ** library) {
  int i;
  for (i=0; i<27; i++) library[i] = free_list(library[i]);
  
  return library;
}
