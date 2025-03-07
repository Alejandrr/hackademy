#ifndef  BINARY_TREE_H_
#define  BINARY_TREE_H_

typedef struct  node {
  char          *key;
  void          *data;
  struct node   *left;
  struct node   *right;
}               node_t;

node_t  *allocnode();
node_t  *insert(node_t *root, char *key, void *data);
void    print_node(node_t *node);
void    visit_tree(node_t *node, void (*fp)(node_t *root));
void    destroy_tree(node_t *node, void (*fdestroy)(node_t *root));

int my_strlen(const char* str) ;
int Compare(char* key1, char* key2) ;
node_t* InsertSearch(node_t* subTree, char* key);
node_t* Search(node_t* root, char* key) ;
#endif
