#include <stdio.h>
#include <stdlib.h>
#include "../include/student.h"

#include <string.h>

void addStudent(Student **students, int *count) {
    *students = realloc(*students, (*count + 1) * sizeof(Student));
    if (*students == NULL) {
        printf("❌ Memory allocation failed!\n");
        return;
    }

    int rollNumber, exists;
    char buffer[100];

    // ✅ Validate Roll Number with do-while
    do {
        exists = 0; // Reset flag
        printf("🆔 Enter Roll Number (positive integer): ");

        // Use fgets for safer input handling
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("⚠️ Input error occurred. Please try again.\n");
            continue;
        }

        // Check if input is a valid positive integer
        if (sscanf(buffer, "%d", &rollNumber) != 1 || rollNumber <= 0) {
            printf("⚠️ Invalid input! Roll number must be a **positive integer**. Try again.\n");
            continue;  // Retry input
        }

        // ✅ Check if roll number already exists
        for (int i = 0; i < *count; i++) {
            if ((*students)[i].rollNumber == rollNumber) {
                printf("🚨 Roll Number %d already exists! Please enter a unique roll number.\n", rollNumber);
                exists = 1;
                break;
            }
        }
    } while (exists || rollNumber <= 0);

    (*students)[*count].rollNumber = rollNumber;

    // ✅ Validate Name
    printf("📝 Enter Name: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("⚠️ Input error occurred.\n");
        return;
    }

    // Remove newline if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n')
        buffer[len-1] = '\0';

    strncpy((*students)[*count].name, buffer, sizeof((*students)[*count].name) - 1);
    (*students)[*count].name[sizeof((*students)[*count].name) - 1] = '\0';

    // ✅ Validate Marks with do-while
    do {
        printf("📊 Enter Marks (0-100): ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("⚠️ Input error occurred. Please try again.\n");
            continue;
        }

        float marks;
        if (sscanf(buffer, "%f", &marks) != 1 || marks < 0 || marks > 100) {
            printf("⚠️ Invalid marks! Please enter a **number between 0 and 100**.\n");
            continue;  // Retry input
        }

        (*students)[*count].marks = marks;
        break;

    } while (1);

    (*count)++;
    printf("✅ Student added successfully! 🎉\n");
}

void modifyStudent(Student *students, int count) {
    int rollNumber, found = 0;
    char buffer[100];

    // Validate Roll Number
    do {
        printf("🔄 Enter Roll Number of the student to modify: ");

        // Use fgets for safer input handling
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("⚠️ Input error occurred. Please try again.\n");
            continue;
        }

        // Check if input is a valid positive integer
        if (sscanf(buffer, "%d", &rollNumber) != 1 || rollNumber <= 0) {
            printf("⚠️ Invalid input! Roll number must be a **positive integer**. Try again.\n");
            continue;
        }

        break;  // Valid input received
    } while (1);

    // Search for the student
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("✏️ Modifying student record for Roll Number %d...\n", rollNumber);

            // Validate Name
            printf("📝 Enter New Name: ");
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("⚠️ Input error occurred.\n");
                return;
            }

            // Remove newline if present
            size_t len = strlen(buffer);
            if (len > 0 && buffer[len-1] == '\n')
                buffer[len-1] = '\0';

            strncpy(students[i].name, buffer, sizeof(students[i].name) - 1);
            students[i].name[sizeof(students[i].name) - 1] = '\0';

            // Validate Marks
            do {
                printf("📊 Enter New Marks (0-100): ");

                if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                    printf("⚠️ Input error occurred. Please try again.\n");
                    continue;
                }

                float marks;
                if (sscanf(buffer, "%f", &marks) != 1 || marks < 0 || marks > 100) {
                    printf("⚠️ Invalid marks! Please enter a **number between 0 and 100**.\n");
                    continue;
                }

                students[i].marks = marks;
                break;

            } while (1);

            found = 1;
            printf("✅ Student record updated successfully! 🎉\n");
            break;
        }
    }

    if (!found) {
        printf("❌ Student with Roll Number %d not found.\n", rollNumber);
    }
}

// void displayStudent(const Student *students, int count) {
//     if (count == 0) {
//         printf("No students to display.\n");
//         return;
//     }
//     for (int i = 0; i < count; i++) {
//         printf("\nStudent %d:\n", i + 1);
//         printf("Name: %s\n", students[i].name);
//         printf("Roll Number: %d\n", students[i].rollNumber);
//         printf("Marks: %.2f\n", students[i].marks);
//     }
// }
void displayStudent(const Student *students, int count) {
    if (count == 0) {
        printf("\n==================================================\n");
        printf("No students to display.\n");
        printf("==================================================\n");
        return;
    }

    printf("\n=============================================================\n");
    printf("| %-5s | %-20s | %-10s | %-6s |\n", "No.", "Name", "Roll Number", "Marks");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("| %-5d | %-20s | %-10d | %-6.2f |\n",
               i + 1, students[i].name, students[i].rollNumber, students[i].marks);
    }

    printf("=============================================================\n");
}

const Student* searchStudent(const Student *students, int count, int rollNumber) {
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            return &students[i];  // No warning now
        }
    }
    return NULL;
}