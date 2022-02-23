#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "binary_tree.h"





void      test_destroy_node(node_t *node)
{
  assert(strncmp(node->data, "world", 5) == 0);
  free(node->key);
  free(node->data);
}
void      destroy_node(node_t *node)
{
  free(node->key);
  free(node->data);
}

int       test_visiting()
{
  node_t  *root;
  char    *key;
  char    *val;

  root = NULL;
  for (int i = 0; i <= 100; i++) {
    asprintf(&key, "%s%05d", "hello", i);
    asprintf(&val, "%s%05d", "world", i);
    root = insert(root, key, val);
  }
  
  visit_tree(root, &print_node);
  destroy_tree(root, &test_destroy_node);

  return (0);
}




char*    random_str_gen(const int len){
  char* str ; 
  srand(time(NULL)*len);
  str = (char*)malloc(sizeof(char)*(len));

  for(int i = 0 ; i < len ; i++){
      str[i] = (32 + (rand()%95));
  }
  str[len] = '\0';
  return str ;
}

int       test_tree_building(){
  node_t  *root;
  char    *key;
  char    *val;
  srand(time(NULL));
  root = NULL;
  
  for(int i = 0 ; i <= 15 ; i++){
   asprintf(&val, "%s%0d", "value", i);
   asprintf(&key ,"%c%c%s" ,(char)(32 + (rand()%95)),(char)(32 + (rand()%95)),  "-key");
   root = insert(root, key, val);
  }
  visit_tree(root, &print_node);
  destroy_tree(root,&destroy_node);
  return 0x0; 
}
int     test_searching(){
  node_t  *root;
  char    *key;
  char    *val;
  root = NULL;
  clock_t start,end;
 
  srand(time(NULL));
  
  for(int i = 0 ; i < 500 ; i++){
   asprintf(&val, "%s%0d", "value", i);
   asprintf(&key ,"%c%c%c%c%s" ,(char)(32 + (rand()%95)),(char)(32 + (rand()%95)),(char)(32 + (rand()%95)),(char)(32 + (rand()%95)),  "-key");
   root = insert(root, key, val);
  }
   asprintf(&val, "%s", "find me please");
   asprintf(&key ,"se1");
   root = insert(root, key, val);
  for(int i = 500 ; i < 1000 ; i++){
   asprintf(&val, "%s%0d", "value", i);
   asprintf(&key ,"%c%c%c%c%s" ,(char)(32 + (rand()%95)),(char)(32 + (rand()%95)),(char)(32 + (rand()%95)),(char)(32 + (rand()%95)),  "-key");
   root = insert(root, key, val);
  }
  asprintf(&val, "%s", "And me");
  asprintf(&key ,"rand");
  root = insert(root, key, val);
  for(int i = 1000; i <= 1500 ; i++){
   asprintf(&val, "%s%0d", "value", i);
   asprintf(&key ,"%c%c%c%c%s" ,(char)(32 + (rand()%95)),(char)(32 + (rand()%95)),(char)(32 + (rand()%95)),(char)(32 + (rand()%95)),  "-key");
   root = insert(root, key, val);
  }

  start = clock();
  if(strcmp(Search(root,"se1")->key,"se1")!=0)
    return -1; 
  end = clock();
  printf("First search in 1500 elements time : %fs\n",(double)(end - start) / CLOCKS_PER_SEC);

  start = clock();
  if( strcmp(Search(root,"rand")->key,"rand")!=0)
    return -1 ;
  end = clock();
  printf("Second search in 1500 elements time : %fs\n",(double)(end - start) / CLOCKS_PER_SEC);

  //visit_tree(root, &print_node);
  destroy_tree(root,&destroy_node);
  return 0x0; 


}




int       test_allocation()
{
  node_t  *p;
  int     success;

  success = 1;
  p = allocnode();
  success = (p != 0);
  free(p);
  assert(success == 1);

  return (0);
}

void      remove_static()
{
  NULL;
}

int       test_prototyping()
{
  node_t  *root;

  root = insert(NULL, "hello", "world");
  insert(root, "world", "hello");
  print_node(root);
  print_node(NULL);
  assert(strcmp(root->key, "hello") == 0);
  assert(strcmp(root->data,  "world") == 0);
  assert(strcmp(root->right->key, "world") == 0);
  assert(strcmp(root->right->data, "hello") == 0);
  destroy_tree(root, &remove_static);

  return (0);
}

void      assert_node(node_t *node)
{
  assert(node->key != NULL);
  assert(node->data != NULL);
  assert(strcmp(node->data, "testvalue") == 0);
}

int       test_smalltree()
{
  node_t  *root;

  root = insert(NULL, "j47hl3", "testvalue");
  insert(root, "36hj43", "testvalue");
  insert(root, "a6hje4", "testvalue");
  insert(root, "46hjv2", "testvalue");
  insert(root, "46hjv2", "testvalue");
  insert(root, "46hjv2", "testvalue");
  visit_tree(root, &assert_node);
  destroy_tree(root, &remove_static);

  return (0);
}

int   main(void)
{
  test_allocation();
  assert(test_prototyping() == 0);
  assert(test_smalltree() == 0);
  assert(test_visiting() == 0);
  assert(test_tree_building() == 0); 
  assert(test_searching() == 0);
  return (0);
}
