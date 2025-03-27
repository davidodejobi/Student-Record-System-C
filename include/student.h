#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char name[100];
    int rollNumber;
    float marks;
} Student;

void addStudent(Student **students, int *count);
void modifyStudent(Student *students, int count);
void displayStudent(const Student *students, int count);
const Student* searchStudent(const Student *students, int count, int rollNumber);

#endif // STUDENT_H