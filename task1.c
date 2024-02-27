/* Задача 1. Пары соседних символов
В файле .txt записаны символы. Необходимо разработать функцию, которая
меняет местами пары соседних символов не обращая внимание на символы
пробел. Если количество символов нечетно (пробелы не считаем), то
последний символ не меняем. Результат записать в файл .txt.
Данные на входе: Строка из английских букв, пробелов и знаков
препинания. Не более 1000 символов.
Данные на выходе: Строка из английских букв, пробелов и знаков
препинания.
Пример №1
Данные на входе: Hello world!
Данные на выходе: eHllw orodl!
Пример №2
Данные на входе: abc def
Данные на выходе: bad cfe */
#include <stdio.h>
#include <string.h>

#define SIZE 1000

int main(void)
{
    FILE *f_in, *f_out;

    char string[SIZE] = {0};

    f_in = fopen("in.txt", "r");
    fscanf(f_in, "%[^\n]", string);
    fclose(f_in);

    int len = strlen(string);

    for (int i = 0; i < len - 1 && string[i] != ' '; i++)
    {
        int j = i + 1;
        while (string[j] == ' ')
            j++;

        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i = j;
    }

    f_out = fopen("out.txt", "w");
    fputs(string, f_out);
    fclose(f_out);

    return 0;
}