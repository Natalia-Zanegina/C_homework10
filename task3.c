/* Задача 3. Изменить расширение
В файле .txt записан полный адрес файла (возможно, без расширения).
Необходимо изменить его расширение на ".html" и записать результат в файл
.txt.
Данные на входе: Строка состоящая из символов: a-z, A-Z, 0-9, /
Данные на выходе: Исходная строка с измененным расширением.
Пример №1
Данные на входе: /DOC.TXT/qqq
Данные на выходе: /DOC.TXT/qqq.html
Пример №2
Данные на входе: /DOC.TXT/qqq.com
Данные на выходе: /DOC.TXT/qqq.html

*/
#include <stdio.h>
#include <string.h>

#define SIZE 1000

int main(void)
{
    FILE *f_in, *f_out;

    char string[SIZE] = { 0 }, res[SIZE] = { 0 };
    char extension[] = ".html";
   
    f_in = fopen("in.txt", "r");
    fscanf(f_in, "%[^\n]", string);
    fclose(f_in);

    int len = strlen(string), pos = 0;

    for (int i = len - 1; i >= 0; i--)
    {  
        if (string[i] == '.' && i >= len - 5)
            pos = i;
    }

    if (pos)
        strncpy(res, string, pos);

    else 
        strcpy(res, string);
    
    strcat(res, extension);

    f_out = fopen("out.txt", "w");
    fputs(res, f_out);
    fclose(f_out);

    
    return 0;
}
