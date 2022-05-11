#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct author {
  struct author *next;
  char name[20];
  char spec[30];
  char year[5];
  char pages[10];
} t_list;
// typedef struct author Author;
void show(t_list c);
// struct author inpstud(void);

t_list *create_node(char *name, char *spec, char *year, char *pages) { /*Создание элемента*/
  t_list *node = (t_list *)malloc(sizeof(t_list));
  strcpy(node -> name, name);
  strcpy(node -> spec,spec);
  strcpy(node -> year, year);
  strcpy(node -> pages,pages);
  node -> next = NULL;  /*Следующий указатель будет нулевым*/
  return node;
}

// void push_front(t_list **list, char *name, char *spec, char *year, char *pages) { /*Создание следующего элемента*/
//   t_list *new_element = create_node(name, spec, year, pages);
//   new_element -> next = *list;  /*Присваивания предыдущего указателя указателем на этот элемент*/
//   *list = new_element;
// }

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
    // push_front(&list, &name, &spec, &year, &pages);
    if (!strcmp(napr, p->spec)) {
      printf("%s %s %s %s\n", list -> name, list -> spec, list -> year, list -> pages);
      fprintf(vybor, "%s %s %s %s\n", list -> name, list -> spec, list -> year, list -> pages);
      // list = list -> next;
    }
  }

  fclose(authors);
  fclose(vybor);
  return 0;
}
