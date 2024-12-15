#include <stdio.h>
#include "Course.h"


int CourseCheckData(Course* CurrentCourse)
{
    if (CurrentCourse == NULL) 
    {
        printf("Error: course is NULL\n");
        return 0;
    }
    else if(CurrentCourse == NULL || CurrentCourse -> StudentCount == 0) 
    {
        printf("Error: course || current  is NULL\n");
        return 0;
    }
    else 
    {
        // if curse is not null  
        printf("Data load...");
    }
}
int AddStudentToCourse(Course* CurrentCourse, Student CurrentStudent)
{
    // if (CurrentCourse == NULL) return 0; // Проверка на дурака
    if (CourseCheckData(CurrentCourse))
    {
        if (CurrentCourse -> StudentCount < CurrentCourse -> MaxStudents)
        {
        CurrentCourse -> Students[CurrentCourse -> StudentCount++] = CurrentStudent;
        }
        else 
        {
            // return 0; // Ошибка: превышено максимальное количество студентов
            printf("Error Max count of students");
            return 0;
        }
    }
    
    
}

Student* FindTopStudent(Course* CurrentCourse) 
{
    // if (CurrentCourse == NULL || CurrentCourse->StudentCount == 0) return NULL; // Проверка на дурака
    if (CourseCheckData(CurrentCourse))
    {
            Student* topStudent = &CurrentCourse -> Students[0];
        for (int i = 1; i < CurrentCourse->StudentCount; i++) {
            if (CurrentCourse -> Students[i].AverageScore > topStudent->AverageScore) 
            {
            topStudent = &CurrentCourse -> Students[i];
            }
    }
    // удобно даже не нужно дописовать else - условие если никого нет то значение и так будет 0 
    return topStudent;
    }
}