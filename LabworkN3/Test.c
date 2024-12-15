#include <stdio.h>
#include "Students.h"
#include "Course.h"

// Позитивный тест для функции изменения средней оценки студента
void TestChangeAverage() {
    Student CurrentStudent = {"Иван", 21, 3.0}; // Создаем студента с именем Иван и средней оценкой 3.0
    DeltaAverageScore(&CurrentStudent, 4.0); // Изменяем среднюю оценку на 4.0
    
    // Проверяем, что средняя оценка изменилась на 4.0
    if (CurrentStudent.AverageScore == 4.0) {
        printf("Тест ChangeAverageScore: УСПЕХ\n");
    } else {
        printf("Тест ChangeAverageScore: ПРОВАЛ\n");
    }
}

// Позитивный тест для функции проверки, является ли студент отличником
void TestIsHonorsStudent() {
    Student CurrentStudent = {"Анна", 22, 4.6}; // Создаем студентку с именем Анна и средней оценкой 4.6
    
    // Проверяем, что студентка является отличником
    if (IsExcellentStudent(&CurrentStudent) == 1) {
        printf("Тест IsHonorsStudent: УСПЕХ\n");
    } else {
        printf("Тест IsHonorsStudent: ПРОВАЛ\n");
    }
}

// Позитивный тест для функции добавления студента на курс
void TestAddStudentToCourse() {
    Course CurrentCourse = {"Математика", 0, 2}; // Создаем курс "Математика" с нулевым количеством студентов
    Student CurrentStudent = {"Светлана", 20, 4.5}; // Создаем студентку с именем Светлана и средней оценкой 4.5
    
    int result = AddStudentToCourse(&CurrentCourse, CurrentStudent); // Добавляем студентку на курс
    
    // Проверяем, что студентка была успешно добавлена и количество студентов увеличилось на 1
    if (result == 1 && CurrentCourse.StudentCount == 1) {
        printf("Тест AddStudentToCourse: УСПЕХ\n");
    } else {
        printf("Тест AddStudentToCourse: ПРОВАЛ\n");
    }
}

// Позитивный тест для функции поиска лучшего студента на курсе
void TestFindTopStudent() {
    Course CurrentCourse = {"Физика", 0, 5}; // Создаем курс "Физика" с нулевым количеством студентов
    Student student1 = {"Сергей", 20, 4.5}; // Создаем первого студента с именем Сергей
    Student student2 = {"Елена", 22, 4.8}; // Создаем второго студента с именем Елена
    
    AddStudentToCourse(&CurrentCourse, student1); // Добавляем первого студента на курс
    AddStudentToCourse(&CurrentCourse, student2); // Добавляем второго студента на курс
    
    Student* topStudent = FindTopStudent(&CurrentCourse); // Находим лучшего студента
    
    // Проверяем, что лучший студент имеет среднюю оценку 4.8
    if (topStudent->AverageScore == 4.8) {
        printf("Тест FindTopStudent: УСПЕХ\n");
    } else {
        printf("Тест FindTopStudent: ПРОВАЛ\n");
    }
}

// Запуск всех тестов
int main() {
    TestChangeAverage(); // Запускаем тест изменения средней оценки
    TestIsHonorsStudent(); // Запускаем тест проверки отличника
    TestAddStudentToCourse(); // Запускаем тест добавления студента на курс
    TestFindTopStudent(); // Запускаем тест поиска лучшего студента
    
    return 0; // Завершаем программу
}