struct song_node {
  char song[100];
  char artist[100];
  struct song_node * next;
};
struct song_node * make(char * s, char * a);
struct song_node * insert_front(struct song_node * front, struct song_node * node);
struct song_node * compareNode(struct song_node * n1, struct song_node * n2);
struct song_node * insert_order(struct song_node * front, struct song_node * node);
void print_struct(struct song_node * node);
void print_list(struct song_node *list);
struct song_node * find_song(struct song_node * sn, char * s, char * a);
struct song_node * find_first(struct song_node * sn, char * a);
int node_size(struct song_node *sn);
struct song_node * random_node(struct song_node * sn);
struct song_node * remove_node(struct song_node * sn, char * s, char * a);
struct song_node * free_list(struct song_node * sn);