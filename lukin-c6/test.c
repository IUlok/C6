#include "config.h"
#include "test1.h"
#include "test2.h"
#include "test3.h"


int main() {
int variant;
do {
  menu();
  variant = get_variant(3);
  switch (variant) {
    case 1: /*Инструкция*/
    {
      printf("\n");
      printf("Программа считывает с файла input.txt элементы, записывает их в динамический массив и перезаписывает их в файл output.txt\n");
      printf("\n");
      break;
    }

    case 2: { /*Запустить щарманку!*/
      FILE *rfile = fopen("input.txt","r");
      FILE *wfile = fopen("output.txt", "w");
      char famil[50], name[50];
      int ozenka, year;
      t_list *list = create_node("TEST", "TEST", 0, 0); /*Создание нулевого элемента динамического массива*/
      while (!feof(rfile)) {  /*Чтение с файла элементов структуры*/
        fscanf(rfile, "%s %s %d %d", famil, name, &year, &ozenka);
        push_front(list, famil, name, year, ozenka);
      }
      while (list != NULL) {  /*Запись в новый файл всех элементов структуры и вывод их в консоль*/
        printf("%s %s %d %d\n", list -> famil, list -> name, list -> year, list -> ozenka);
        fprintf(wfile, "%s %s %d %d\n", list -> famil, list -> name, list -> year, list -> ozenka);
        list = list -> next;
      }
      fclose(rfile);
      fclose(wfile);
      break;
    }

    case 3: /*Выход*/
    printf("Программа завершена\n");
    break;
    }
  } while (variant != 3);
}
