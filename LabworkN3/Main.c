#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Students.h"
#include "Course.h"
// to do функция выевляющая неккоректное имя 

int GetStudentData(Student* CurrentStudent, int id);
void PrintStudentData(Student* CurrentStudent);

int GetStudentData(Student* CurrentStudent, int id) 
{
    if (CurrentStudent == NULL) return 0;

    CurrentStudent -> id = id; // Устанавливаем уникальный идентификатор

    printf("Введите имя студента: ");
    fgets(CurrentStudent -> Name, sizeof(CurrentStudent -> Name), stdin);
    CurrentStudent -> Name[strcspn(CurrentStudent->Name, "\n")] = '\0'; // Удаление символа новой строки

    printf("Введите возраст студента: ");
    char input[10];
    fgets(input, sizeof(input), stdin);
    
    if (sscanf(input, "%d", &CurrentStudent->Age) != 1 || CurrentStudent->Age <= 0 || CurrentStudent->Age < 18) 
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

void PrintStudentData(Student* CurrentStudent) {
    if (CurrentStudent == NULL) {
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