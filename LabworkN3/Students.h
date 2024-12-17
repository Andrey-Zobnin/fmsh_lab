#ifndef STUDENTS_H
#define STUDENTS_H

typedef struct 
{
    char Name[100];
    // Name - array of students
    int Age;
    // Age - возраст студента 
    float AverageScore;
    // AveregeScore - средний бал студента 
    int id; // id - идентификатор студента
} Student;

// Функции для работы с данными student
int IdentificationInCurrentStudent(Student* CurrentStudent);
void DeltaAverageScore(Student* CurrentStudent, float NewScore);
int IsExcellentStudent(Student* CurrentStudent);
int StudentsDataCheck(Student* CurrentStudent);

#endif 