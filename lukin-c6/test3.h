#include "config.h"
void menu() { /*Вывод меню*/
  printf("Вас приветствует программа Себастьян!\n");
  printf("Выберите необходимый пункт:\n\n");
  printf("1. Вывести инструкцию по использованию программой;\n");
  printf("2. Запустить шарманку!\n");
  printf("3. Выйти из программы (Внимание! При выборе данного варианта Себастьян на вас обидится!)\n");
  printf("Ваш вариант: ");
}
int get_variant (int count) { // Считывание варианта, который укажет пользователь. Без проверки на криворукость
  int variant;
  scanf("%d", &variant);
  return variant;
}