#include "config.h"

typedef struct student { /*Структура*/
  struct student *next; /*Ссылка на следующий элемент*/
  struct student *prev; /*Ссылка на предыдущий элемент*/
  char famil[50];
  char name[50];
  int year;
  int ozenka;
} t_list;

t_list *create_node(char *set_famil, char *set_name, int set_year, int set_ozenka) { /*Создание элемента*/
  t_list *node = (t_list *)malloc(sizeof(t_list));
  strcpy(node -> name, set_name);
  strcpy(node -> famil,set_famil);
  node -> year = set_year;
  node -> ozenka = set_ozenka;
  node -> next = NULL;  /*Следующий указатель будет нулевым*/
  node -> prev = NULL;  /*Предыдущий указатель будет нулевым*/
  return node;
}

t_list * push_front(t_list *lst, char *set_famil, char *set_name, int set_year, int set_ozenka) { /*Создание следующего элемента*/
  t_list *temp, *p;
  temp = (t_list*)malloc(sizeof(t_list));
  p = lst -> next;
  lst -> next = temp;
  strcpy(temp -> name, set_name);
  strcpy(temp -> famil,set_famil);
  temp -> year = set_year;
  temp -> ozenka = set_ozenka;
  temp -> next = p;
  temp -> prev = lst;
  if (p != NULL) {
    p -> prev = temp;
  }
  return(temp);
}
