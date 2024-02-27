/* Задача 2. Удалить пробелы из текста
В файле .txt необходимо удалить все лишние пробелы (в начале предложения
и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
записать в .txt.
Данные на входе: Строка из английских букв, знаков препинания и
пробелов. Не более 1000 символов.
Данные на выходе: Строка из английских букв, знаков препинания и
пробелов.
Пример
Данные на входе: Hello world!
Данные на выходе: Hello world!*/
#include <stdio.h>
#include <string.h>

#define SIZE 1000

int main(void)
{
    FILE *f_in, *f_out;

    char string[SIZE] = {0}, res[SIZE] = {0};

    f_in = fopen("in.txt", "r");
    fscanf(f_in, "%[^\n]", string);
    fclose(f_in);

    int len = strlen(string);

    for (int i = 0, j = 0; i < len; i++, j++)
    {
        if (i == 0)
        {
            while (string[i] == ' ')
                i++;
        }
        else
        {
            if (string[i] == ' ')
            {
                while (string[i + 1] == ' ')
                    i++;
            }
        }
        res[j] = string[i];
    }

    f_out = fopen("out.txt", "w");
    fputs(res, f_out);
    fclose(f_out);

    return 0;
}