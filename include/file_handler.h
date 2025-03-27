#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "student.h"

// Function prototypes for file operations
void saveToFile(Student *students, int count);
int loadFromFile(Student **students);

#endif // FILE_OPERATIONS_H