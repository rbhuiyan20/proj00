#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "library.h"

int main(){
    // testing linkedlist

  
  printf("=====================================================\n");
  printf("LINKED LIST TESTS: \n");

  printf("=====================================================\n");
  printf("Testing print_list: \n");
  struct song_node * list = make("thunderstruck","ac/dc");
  struct song_node * n1 = make("back in black","ac/dc");
  list = insert_front(list, n1);
  printf("\n");
  print_list(list);
  printf("\n");
  printf("=====================================================\n");

  printf("Testing Adding songs \n");
  struct song_node * add;
  add = make("yellow ledbetter","pearl jam");
  list = insert_order(list, add);
  printf("\n");
  print_list(list);
  printf("\n");
  printf("\n");
  printf("With order too ! \n");
  add = make("even flow","pearl jam");
  list = insert_order(list, add);
  printf("\n");
  print_list(list);
  printf("\n");
  printf("\n");
  printf("=====================================================\n");
  printf("Testing helper function to compare nodes \n \n");
  struct song_node *a1;
  a1 = make("Feelin Good", "Michael Buble");
  struct song_node *a2;
  a2 = make("Demons", "Alec Benjamin");

  printf("songs to compare \n");
  print_list(a1);
  print_list(a2);
  printf("\n");
  printf("%d\n", compareNode(a1,a2));  
  printf("\n");
  printf("=====================================================\n");

  printf("Testing  Random: \n");
  
  print_song(random_node(list));
  printf("\n");
  print_song(random_node(list));
  printf("\n");
  print_song(random_node(list));
  printf("\n");
  print_song(random_node(list));
  printf("\n");
  printf("\n");
  printf("=====================================================\n");

  printf("Testing find_song (finding a node) : \n");
  printf("Song found:");
  print_song(find_song(list,"even flow","pearl jam"));
  printf("\n");
  printf("\n");
  printf("=====================================================\n");

  printf("Testing find_first (finding first song from an artist) : \n");
  printf("Searching for ac/dc ");
  print_song(find_first(list,"ac/dc"));
  printf("\n");
  printf("\n");
  printf("Searching for pearl jam ");
  print_song(find_first(list,"pearl jam"));
  printf("\n");
  printf("\n");
  printf("=====================================================\n");

  printf("Testing Remove Node (taking out yellow ledbetter) \n");
  printf("Before Removal\n");
  print_list(list);
  printf("\n");
  list = remove_node(list, "yellow ledbetter", "pearl jam");
  printf("\n");
  printf("After Removal\n");
  printf("\n");
  print_list(list);
  printf("\n");
  printf("\n");

  printf("=====================================================\n");

  printf("Testing free_list: \n");
  printf("List 'List' before being freed \n");
  printf("\n");
  print_list(list);
  printf("\n");
  list = free_list(list);
  printf("List 'List' after being freed \n");
  print_list(list);

  printf("\n");
  printf("List 'a1' before being freed \n");
  printf("\n");
  print_list(a1);
  printf("\n");
  a1 = free_list(a2);
  printf("List 'List' after being freed \n");
  print_list(a1);
  printf("\n");
  printf("=====================================================\n");


  printf("\n");
  printf("\n");
  printf("*******************************************************************\n");
  printf("*******************************************************************\n");
  printf("\n");
  printf("\n");
  
  // testing library

  printf("TESTING LIBRARY !!!!!!!!!!!");
  struct song_node ** library = make_lib();

  struct song_node *a = make("thunderstruck","ac/dc");
  struct song_node *b = make("alive","pearl jam");
  struct song_node *c = make("even flow","pearl jam");
  struct song_node *d = make("yellow ledbetter","pearl jam");
  struct song_node *e = make("time", "pink floyd");
  struct song_node *f = make("paranoid android", "radiohead");
  struct song_node *g = make("street spirit (fade out)","radiohead");

  add_song(library, a);
  add_song(library, b);
  add_song(library, c);
  add_song(library, d);
  add_song(library, e);
  add_song(library, f);
  add_song(library, g);


  printf("\n");
  printf("=====================================================\n");
  printf("Printing out the library: \n");
  print_library(library);

  printf("\n");
  printf("=====================================================\n");
  printf("Testing adding a song into library (With special character!!: \n");
  struct song_node *h = make("ZAZA","6ix9ine");
  add_song(library, h);
  print_library(library);

  printf("\n");

  printf("=====================================================\n");
  printf("Finding songs under Letter: P\n");
  print_letter(library, 'p');
  printf("=====================================================\n");

  printf("=====================================================\n");
  printf("Testing print letter R \n");
  print_letter(library, 'r');
  printf("\n");
  printf("\n");
  printf("=====================================================\n");
  printf("Finding song with Title: Thunderstuck , Artist: ad/dc \n");
  print_struct(search_song(library, "thunderstruck","ac/dc"));
  printf("\n");

  printf("=====================================================\n");
  printf("Finding all songs by the Artist:Pearl Jam\n");
  print_artist(library, "pearl jam");
  printf("\n");

  printf("=====================================================\n");
  printf("Finding a song with Artist: Pink Floyd\n");
  print_struct(search_artist(library,"pink floyd"));
  printf("\n");

  printf("=====================================================\n");
  printf("Testing Shuffle Songs\n");
  shuffle_songs(library);
  printf("\n");
  printf("=====================================================\n");

  
  printf("Deleting Even Flow\n");
  remove_song(library, "even flow", "pearl jam");
  printf("\n");
  printf("All of the library: \n");
  print_library(library);
  printf("=====================================================\n");
  
  
  printf("Clearing the Library\n");
  printf("After Clearing\n");
  library = clear(library);
  printf("\n");
  print_library(library);
  
  printf("=====================================================\n");
  return 0;
}