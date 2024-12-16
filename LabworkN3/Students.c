#include <stdio.h>
#include "Students.h"

// функция идентификации студента для сввязи нескольких структур
int IdentificationInCurrentStudent(Student* CurrentStudent) 
{
    if (CurrentStudent == NULL) 
    {
        printf("Error: CurrentStudent is NULL.\n");
        printf("Ошибка: CurrentStudent равен нулю.\n");
        return -1; 
    }
    else
    {
        return CurrentStudent -> id;    
    }
}

// проверка на дурака в функции StudentsDataCheck 
int StudentsDataCheck(Student* CurrentStudent) 
{
    if (CurrentStudent == NULL) 
    {
        printf("CurrentStudent is NULL\n");
        printf("Текущий студент не найден.\n");
        return 0; 
    } 
    else if (CurrentStudent->Age < 0 || CurrentStudent->Age > 100)
    {
        printf("Invalid age \n"); 
        return 0; 
    }
}

void DeltaAverageScore(Student* CurrentStudent, float NewScore) 
{
    if (StudentsDataCheck(CurrentStudent)) 
    {
        CurrentStudent -> AverageScore = NewScore;
    }
    else
    {
        printf("invalid student data\n");
        printf("невалидные данные студента\n");
    }
}

int IsExcellentStudent(Student* CurrentStudent) 
{
    if (StudentsDataCheck(CurrentStudent)) 
    { 
        return CurrentStudent -> AverageScore >= 4.5; 
        // Отличник, если средний балл 4.5 или выше
    }
    else
    {
        printf("invalid of student data\n");
        printf("невалидные данные студента в функции IsExcellentStudent\n");
        return 0;
    }   
}