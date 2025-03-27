#include <stdio.h>
#include "../include/student.h"

float calculateAverage(Student *students, int count) {
    // Validate parameters
    if (students == NULL) {
        printf("❌ Error: NULL student array passed to calculateAverage()\n");
        return 0.0;
    }

    if (count <= 0) {
        printf("ℹ️ No students to calculate average for\n");
        return 0.0;
    }

    float total = 0.0;
    int validCount = 0;

    // Debug output to verify input data
    printf("📊 Calculating average for %d students...\n", count);

    for (int i = 0; i < count; i++) {
        // Check for invalid marks (optional)
        if (students[i].marks < 0 || students[i].marks > 100) {
            printf("⚠️ Warning: Student #%d has unusual marks: %.2f\n",
                   i+1, students[i].marks);
        }

        total += students[i].marks;
        validCount++;

        // Debug: Show running total
        // printf("Student %d marks: %.2f, Running total: %.2f\n",
        //        i+1, students[i].marks, total);
    }

    float average = total / validCount;
    printf("📈 Total marks: %.2f, Student count: %d, Average: %.2f\n",
           total, validCount, average);

    return average;
}

/**
 * Sort the student records by marks
 * @param students Array of student records
 * @param count Number of students
 * @param ascending 1 for ascending order, 0 for descending order
 */
void sortStudents(Student *students, int count, int ascending) {
    if (count <= 1) {
        printf("⚠️ Not enough students to sort.\n");
        return;
    }

    printf("🔄 Sorting %d students by marks in %s order...\n",
           count, ascending ? "ascending" : "descending");

    // Bubble sort implementation
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if ((ascending && students[j].marks > students[j + 1].marks) ||
                (!ascending && students[j].marks < students[j + 1].marks)) {
                // Swap students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
                }
        }
    }

    printf("✅ Sorting complete!\n\n");

    // Display sorted results
    printf("📋 Sorted Student List:\n");
    printf("+-----------+----------------------+--------+--------+\n");
    printf("| Roll No.  | Name                 | Marks  | Status |\n");
    printf("+-----------+----------------------+--------+--------+\n");

    for (int i = 0; i < count; i++) {
        // Determine status based on marks
        const char* status = students[i].marks >= 40 ? "PASS" : "FAIL";

        printf("| %-9d | %-20s | %6.2f | %-6s |\n",
               students[i].rollNumber,
               students[i].name,
               students[i].marks,
               status);
    }

    printf("+-----------+----------------------+--------+--------+\n");
}