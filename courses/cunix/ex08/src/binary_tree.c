#include "../include/binary_tree.h"
#include "stddef.h"
#include "malloc.h"

int my_strlen(const char* str) {
    if (str == NULL)
        return 0;

    int len = 1;

    while (str[len - 1] != '\0')
        len++;
    return len;
}


int Compare(char* key1, char* key2)             // compare 2 char keyVal
{
    int size;
    if (my_strlen(key1) >= my_strlen(key2))
        size = my_strlen(key2);
    else
        size = my_strlen(key1);

    for (int i = 0; i < size; i++) {
        if ((int)key1[i] == (int)key2[i])
            continue;
        else if ((int)key1[i] > (int)key2[i])
            return 2;
        else if ((int)key1[i] < (int)key2[i])
            return 1;
    }

    return 0;
}
node_t* allocnode() {
    node_t* root= (node_t*)malloc(sizeof(node_t));
    if (root == NULL) {
        return NULL;
    }

    root->data = root->left = root->right = NULL; root->key = NULL;

    return root;
}

node_t* insert(node_t* root, char* key, void* data) {

    if (key == NULL) {          // invalid keyVal
        return NULL;
    }
    if (root != NULL && root->key == NULL) {  // Uninitalized root node
        root->key = key  ;
        root->data = data;
        return root;
    }

    node_t* tempNode = NULL;
    node_t* subTree = allocnode();
    if (subTree == NULL)
        return NULL;

    subTree->key =key;
    subTree->data = data;

    if (root == NULL) {         // don't alloced root
        return root = subTree;
    }
    
    tempNode = InsertSearch(root, key);     //normal search binary insert
    if (Compare(tempNode->key, key) == 1)
        tempNode->right = subTree;
    else if(Compare(tempNode->key, key) ==2)
        tempNode->left = subTree;
    else {
     free(subTree);
    }
    return root;
}
void    print_node(node_t* node) {
    if(node==NULL){
        return ;
    }
    printf("Key : %s   |    value : %s\n",node->key , (char*)node->data);
}
void    visit_tree(node_t* node, void (*fp)(node_t* root)) {
    if (node == NULL) {
        return;
    }
    visit_tree(node->left, fp);
    visit_tree(node->right,fp);
    fp(node);
}

void    destroy_tree(node_t* node, void (*fdestroy)(node_t* root)) {
    if (node == NULL) {
        return;
    }
   
    destroy_tree(node->left, fdestroy); 
    destroy_tree(node->right,fdestroy);
    fdestroy(node);
    free(node);
}

node_t* InsertSearch(node_t* subTree, char* key) {
    node_t* search = NULL;
    if(Compare(key,subTree->key)==1){
        if(subTree->left!=NULL){
            search = subTree->left;
        }
    }else{
        if(subTree->right!=NULL){
             search = subTree->right;
        }
    }

    if(search == NULL)
        return subTree;

    return InsertSearch(search , key);
}

node_t* Search(node_t* root, char* key) {
    if (Compare(root->key, key) == 0 || root == NULL)
        return (root);
    node_t* search = NULL;
    if(Compare(key , root->key)==1){
         if(root->left!=NULL){
            search = root->left;
        }
    }else if(Compare(key , root->key)==2){
        if(root->right!=NULL){
             search = root->right;
        }
    }
    
    return Search(search,key);
}
