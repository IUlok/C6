#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct author {
  struct author *next;
  struct student *prev;
  char name[20];
  char spec[30];
  char year[5];
  char pages[10];
} t_list;
void show(t_list c);

t_list *create_node(char *name, char *spec, char *year, char *pages) { /*Создание элемента*/
  t_list *node = (t_list *)malloc(sizeof(t_list));
  strcpy(node -> name, name);
  strcpy(node -> spec,spec);
  strcpy(node -> year, year);
  strcpy(node -> pages,pages);
  node -> next = NULL;
  node -> prev = NULL;
  return node;
}

t_list * push_front(t_list *lst, char *name, char *spec, char *year, char *pages) { /*Создание следующего элемента*/
  t_list *temp, *p;
  temp = (t_list*)malloc(sizeof(t_list));
  p = lst -> next;
  lst -> next = temp;
  strcpy(temp -> name, name);
  strcpy(temp -> spec,spec);
  temp -> next = p;
  temp -> prev = lst;
  if (p != NULL) {
    p -> prev = temp;
  }
  return(temp);
}

int main() {
  FILE *authors = fopen("authors.txt", "r");
  FILE *vybor = fopen ("vybor.txt", "w");
  char napr[100];
  char name, spec, year, pages;
  t_list x;
  struct author *p = &x;

  printf("%s", "Write napravlenye:\nMath\nPhysics\nProgramming\n");
  scanf("%s", napr);
  printf("Your enter: %s. Results copy to vybor.txt\n", napr);
  t_list *list = create_node("TEST", "TEST", 0, 0);
  while (!feof(authors)) {
    fscanf(authors, "%s %s %s %s", name, spec, year, pages);
    if (!strcmp(napr, p->spec)) {
      printf("%s %s %s %s\n", list -> name, list -> spec, list -> year, list -> pages);
      fprintf(vybor, "%s %s %s %s\n", list -> name, list -> spec, list -> year, list -> pages);
    }
  }

  fclose(authors);
  fclose(vybor);
  return 0;
}
