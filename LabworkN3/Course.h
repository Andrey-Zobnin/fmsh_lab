#ifndef CourseInHEAD
#define CourseHead
#include "Students.h"
// структура для курса массив заголовочный
typedef struct 
{
    char Title[100];
    int StudentCount;
    int MaxStudents;
    Student Students[100]; // Максимум 100 студентов на курс
} Course;

// Функции для работы со структурой Course
int CourseCheckData(Course* CurrentCourse);
int AddStudentToCourse(Course* CurrentCouurse, Student CurrentStudent);
Student* FindTopStudent(Course* curCourse);
#endif
