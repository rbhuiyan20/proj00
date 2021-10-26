#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// song_node struct
struct song_node {
  char song[100];
  char artist[100];
  struct song_node * next;
};

// makes song node given song and artist

struct song_node * make(char * s, char * a){ // tested
  struct song_node * sn;
  sn = malloc(sizeof(struct song_node));

  strcpy(sn->song, s);
  strcpy(sn->artist, a);

  sn->next = NULL;
  
  return sn;
}

// inserts a song node at the front of a list
struct song_node * insert_front(struct song_node * sn, struct song_node * node) { //tested
	node->next = sn;
	return node;
}

// helper function to insert alphabetically
struct song_node * compareNode(struct song_node * n1, struct song_node * n2) { 

  // to compare the artists
	int aValue = strcmp(n1->artist, n2->artist);
	// to compare the songs
  int sValue = strcmp(n1->song, n2->song);
	
  // second artist comes before first
  if (aValue < 0) return 1;
  // first artist comes before second
	else if (aValue > 0)	return -1;
	
	else {
    // second song comes before first
		if (sValue < 0) return 1;
		// first song comes before second
		else return -1;
	}
}


struct song_node * insert_order(struct song_node * front, struct song_node * n) { //tested
  //if front is empty then dont do anything (library is filled with null)
  if (!front) return n;
  
	struct song_node * sn = front;
	struct song_node * temp;

	if (compareNode(front, n) == front){
		n->next = front;
		sn = n;
		return sn;
	}

	else {
		while(front->next) {
			temp = front->next;

			if (compareNode(temp, n) == temp) {
				front->next = n;
				n->next = temp;
				return sn;
			}
      
			else front = front->next;
		}
		front->next = n;
		return sn;
	}
}


// helper function to print out the list, this prints out a indivudual song artist + name
void print_struct(struct song_node * sn){ //tested
  //if node doesnt exist, dont do anything cuz library is filled w nulls
  if (!sn) {}
  else printf("{%s, %s}", sn->artist,sn->song);
  
}


void print_song(struct song_node *sn) {
    printf("{%s, %s}", sn->song, sn->artist);
}

void print_list(struct song_node *sn) {
    while (sn) {
        print_song(sn);
        sn = sn->next;
    }
}


// looks through list, finds a pointer to a node based on a given artist and song
struct song_node * find_song(struct song_node * sn, char * s, char * a){ //
  
  // if song name and artist name of input is equal to front node return it
  if (!strcmp(sn->song,s) && !strcmp(sn->artist, a)) return sn;
  
  // go through the list till we find the match
  while (sn->next){
    sn = sn->next;
    if (!strcmp(sn->song,s) && !strcmp(sn->artist,a)) return sn;
  }

  return NULL;
}

// finds the first instance of a song of an artist 
struct song_node * find_first(struct song_node * sn, char * a){
  while(sn && strcmp(sn->artist, a)) sn = sn->next;
  return sn;
  
}

// helper function for random_node
// returns size of the node
int node_size(struct song_node *sn){
  int size = 0;
  while(sn){
    size++;
    sn = sn->next;
  }
  return size;
}

//generates random song
struct song_node * random_node(struct song_node * sn) {
  int size = node_size(sn);
  int i = rand () % size;
  
  while(i){
    sn = sn->next;
    i--;
  }
  return sn;
}

// removes a node given the artist and song name
struct song_node * remove_node(struct song_node * sn, char * s, char * a) {
  struct song_node *temp;

  // if artist name is the same     and    song is the same
  if (strcmp(sn->artist, a) == 0 && strcmp(sn->song, s) == 0) {
    temp = sn->next;
    // remove the instance of the what we want to
    free(sn);
    return temp;
  }
  
  temp = sn;

  
  while (temp->next) {
    if (strcmp(temp->next->artist, a) == 0 && strcmp(temp->next->song, s) == 0) {
      struct song_node *c = temp->next;
      temp->next = temp->next->next;
      free(c);
      return sn;
    }
    temp = temp->next;
  }
  return sn;
}

struct song_node * free_list(struct song_node * sn) {
  while (sn) {
    struct song_node *next = sn -> next;
    free(sn);
    sn = next;
  }
  return sn;
}