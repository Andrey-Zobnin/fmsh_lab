#ifndef STUDENTS_H
#define STUDENTS_H

typedef struct {
    char Name[100];
    int Age;
    float AverageScore;
    int id; // id - идентификатор студента
} Student;

// Функции для работы с данными student
int IdentificationInCurrentStudent(Student* CurrentStudent);
void DeltaAverageScore(Student* CurrentStudent, float NewScore);
int IsExcellentStudent(Student* CurrentStudent);
int StudentsDataCheck(Student* CurrentStudent);

#endif 