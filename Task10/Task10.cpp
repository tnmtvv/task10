// Task10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>
#include <string>

int ifs(char curletter, const char* separators)
{
    for (int i = 0; i < strlen(separators); i++) {
        if (curletter == separators[i])
            return 1;
    }
    return 0;
}

char** task10_01(char* str_01, char** words, int n, FILE* file)
{

    printf_s("\nСтрока без лишних пробелов:\n");
    char* nextword;
    char* curword;
    curword = strtok_s(str_01, " .\n", &nextword);
    //words[0] = curword;
    int k = 0;
    while (curword != NULL && curword != "." && k < n) {

        printf_s(curword);
        words[k] = curword;
        curword = strtok_s(NULL, " \n.", &nextword);
        if (curword != NULL) {

            if (strcmp(curword, ".") == 1)
                printf_s(" ");
        }
        k++;
    }
    for (int i = 0; i < n; i++) {
        fputs(words[i], file);
        fputs(" ", file);
    }

    //printf_s("\n");
    fputs("\n", file);
    return words;


}



void task10_02_03(char* str_02, int n, char** words, FILE* file) {

    printf_s("\nСтрока без повторяющихся последних слов:\n");

    char* nextword;

    char str_03[80] = "\0";
    char* lastword;
    char* curword;

    if (strcmp(words[n - 1], ".\n") == 0)
        lastword = words[n - 2];
    else lastword = words[n - 1];
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(words[i], lastword) != 0)
        {
            fputs(words[i], file);
            fputs(" ", file);
            printf_s(words[i]);
            printf_s(" ");
        }
    }
    printf_s("\n");
    fputs("\n", file);


    printf_s("\nСлова, в которых последняя буква встречается не более 2 раз\n");
    char lastchar;


    int k = 0;
    for (int i = 0; i < n; i++) {
        lastchar = words[i][strlen(words[i]) - 1];
        for (int j = 0; j < strlen(words[i]); j++)
        {
            if (int(words[i][j]) == int(lastchar))
            {
                k++;
            }
        }

        if (k <= 2)
        {
            fputs(words[i], file);
            fputs(" ", file);
            printf_s(words[i]);
            printf_s(" ");
        }
        k = 0;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    char* nextword;
    char* curword;
    char str_01[80];
    char str_01withspase[80];
    char* str_03;
    char str_02[80];
    const char* separators = " \n.";




    printf_s("Введите строку\n");
    
    FILE* newfile;
    const char* fname = "strings.txt";
    fopen_s(&newfile, fname, "w+");
    fgets(str_01, 80, stdin);
    fputs(str_01, newfile);
    fclose(newfile);
    


    fopen_s(&newfile, fname, "r+");
    fscanf_s(newfile, " [^\n]", str_01);
    fclose(newfile);
    strcpy_s(str_02, str_01);
    str_01withspase[0] = ' ';
    strcat_s(str_01, " ");

    int n = 0;
    for (int i = 0; i < strlen(str_01) - 1; i++)
    {
        if (ifs(str_01[i],separators) != 1 &&  ifs(str_01[i + 1], separators) == 1)
        {

            n++;
        }
    }

    char** words = (char**)malloc(n * sizeof(char*)); {
        for (int i = 0; i < n; i++)
        {
            words[i] = (char*)malloc(n * sizeof(char));
        }
    }
    for (int i = 0; i < n; i++) {
        words[i] == "\0";
    }


    fopen_s(&newfile, fname, "w+");
    task10_01(str_01, words, n, newfile);
    task10_02_03(str_02, n, words, newfile);
    fclose(newfile);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
