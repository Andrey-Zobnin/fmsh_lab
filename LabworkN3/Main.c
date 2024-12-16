#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Students.h"
#include "Course.h"
// to do функция выевляющая неккоректное имя 

int GetStudentData(Student* CurrentStudent, int id);
void PrintStudentData(Student* CurrentStudent);

int IsValidName(const char* name) 
{
    if (name == NULL || strlen(name) == 0) 
    {
         // Имя пустое
        printf("Name is empty\n");
        printf("Имя пустое || равно нулю\n");
        return 0;
    }
    else
    {
        printf("Имя принято || Имя корректное\n");
        // Имя корректное
    }
    // при завершении логического блока мы пропускаем программу дальше и ничего не возврощаем кроме описания пунктов о продолжении ввода
    printf("Продолжайте ввод");

}
int GetStudentData(Student* CurrentStudent, int id) 
{
    if (CurrentStudent == NULL) return 0;

    CurrentStudent -> id = id; // Устанавливаем уникальный идентификатор

    printf("Введите имя студента: ");
    fgets(CurrentStudent -> Name, sizeof(CurrentStudent -> Name), stdin);
    CurrentStudent -> Name[strcspn(CurrentStudent->Name, "\n")] = '\0'; // Удаление символа новой строки
    IsValidName(CurrentStudent -> Name); // Проверка имени
    if (IsValidName(CurrentStudent -> Name) == 0) return 0;
    // Проверяем корректность имени

    printf("Введите возраст студента: ");
    
    char input[10];
    fgets(input, sizeof(input), stdin);
    
    if (sscanf(input, "%d", &CurrentStudent -> Age) != 1 || CurrentStudent->Age <= 0 || CurrentStudent->Age < 18) 
    {
        printf("Ошибка: некорректный ввод возраста.\n");
        return 0; // Ошибка ввода
    }
    printf("Введите средний балл студента: ");
    float avgGrade;
    if (scanf("%f", &avgGrade) != 1 || avgGrade < 0 || avgGrade > 5) {
        printf("Ошибка: некорректный ввод среднего балла.\n");
        return 0; // Ошибка ввода
    }
    
    DeltaAverageScore(CurrentStudent, avgGrade);
    return 1; // Успех
}

void PrintStudentData(Student* CurrentStudent) 
{
    if (CurrentStudent == NULL) 
    {
        printf("Ошибка: студент не найден.\n");
        return;
    }
    printf("ID: %d\n", CurrentStudent -> id);
    printf("Имя: %s\n", CurrentStudent -> Name);
    printf("Возраст: %d\n", CurrentStudent -> Age);
    printf("Средний балл: %.2f\n", CurrentStudent -> AverageScore);
}

int main() 
{
    Course curCourse = {"Computer Science - C", 0, 5};
    Student CurrentStudent;
    static int studentId = 1; // Статическая переменная для уникального ID студентов
/*
Idea to do in that project

CurrentStudent.id = studentId;
studentId++;
    while (1)
    {
        printf("1. Добавить студента\n");
        printf("2. Вывести данные студента\n");
        printf("3. Выход\n");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                AddStudent(&CurrentStudent);
                break;
            case 2:
                PrintStudentData(&CurrentStudent);
                break;
            case 3:
                return 0;
            default:
                printf("Некорректный выбор. Повторите попытку.\n");
            }
    }


*/    

    if (GetStudentData(&CurrentStudent, studentId++)) 
    {
        AddStudentToCourse(&curCourse, CurrentStudent);
        
        Student* topStudent = FindTopStudent(&curCourse);
        if (topStudent != NULL) {
            printf("Лучший студент: %s\n", topStudent -> Name);
            PrintStudentData(topStudent); // Выводим данные о лучшем студенте
        }
    }

    return 0;
}