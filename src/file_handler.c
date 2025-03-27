#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/file_handler.h"
#include "../include/student.h"

void saveToFile(Student *students, int count) {
    // Use a more flexible path approach
    const char* filename = "students.txt";  // File in current directory
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        perror("Error opening file for writing");
        printf("Failed to open file: %s\n", filename);
        return;
    }

    printf("💾 Saving %d student records to %s...\n", count, filename);

    // Write header for better file readability
    fprintf(file, "# Student Records - Name,RollNumber,Marks\n");

    int successCount = 0;
    for (int i = 0; i < count; i++) {
        if (fprintf(file, "%s,%d,%.2f\n",
                   students[i].name,
                   students[i].rollNumber,
                   students[i].marks) > 0) {
            successCount++;
        }
    }

    fclose(file);
    printf("✅ Successfully saved %d/%d student records\n", successCount, count);
}

int loadFromFile(Student **students) {
    // Use a more flexible path approach
    const char* filename = "students.txt";  // File in current directory
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file for reading");
        printf("Could not open file: %s (this is normal for first run)\n", filename);
        return 0;
    }

    int count = 0;
    int capacity = 10; // Initial capacity
    char line[256];

    // Allocate initial memory
    *students = malloc(sizeof(Student) * capacity);
    if (*students == NULL) {
        printf("❌ Memory allocation failed\n");
        fclose(file);
        return 0;
    }

    printf("📂 Loading student records from %s...\n", filename);

    // Skip header if present
    if (fgets(line, sizeof(line), file) != NULL && line[0] == '#') {
        // Line was a header, continue to next line
    } else {
        // Line wasn't a header, rewind to process it
        rewind(file);
    }

    while (fgets(line, sizeof(line), file)) {
        // Skip empty lines or comments
        if (strlen(line) <= 1 || line[0] == '#') continue;

        // Expand array if needed
        if (count >= capacity) {
            capacity *= 2;
            Student *temp = realloc(*students, sizeof(Student) * capacity);
            if (temp == NULL) {
                printf("❌ Memory reallocation failed\n");
                break;
            }
            *students = temp;
        }

        // Initialize the name buffer
        memset((*students)[count].name, 0, sizeof((*students)[count].name));

        // Parse the line with size limits to prevent buffer overflow
        if (sscanf(line, "%99[^,],%d,%f",
                  (*students)[count].name,
                  &(*students)[count].rollNumber,
                  &(*students)[count].marks) == 3) {
            count++;
        } else {
            printf("⚠️ Warning: Invalid format in line: %s", line);
        }
    }

    fclose(file);
    printf("✅ Successfully loaded %d student records\n", count);

    // Resize array to actual count
    if (count > 0) {
        Student *temp = realloc(*students, sizeof(Student) * count);
        if (temp != NULL) {
            *students = temp;
        }
    } else if (count == 0) {
        free(*students);
        *students = NULL;
    }

    return count;
}