#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/student.h"
#include "../include/file_handler.h"
#include "../include/utils.h"

#define MAX_STUDENTS 100

int main() {
    char name[50];
    Student *students = (Student *)malloc(MAX_STUDENTS * sizeof(Student));
    int studentCount = 0;
    int choice;

    // Welcome message with a personal touch
    printf("🎓📖 Welcome to the PLay play player Student Record System! 🎉\n");
    printf("👋 Please enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character
    printf("Hello, %s! 😊 Ready to manage your student records? Let's get started! 🚀\n", name);

    do {
        // Menu with improved readability and emojis
        printf("\n==============================\n");
        printf("📌 Student Record System Menu\n");
        printf("==============================\n");
        printf("1️⃣  ➤ Add a New ALPHA MALE Student 🆕\n");
        printf("2️⃣  ➤ Modify Student Information ✏️\n");
        printf("3️⃣  ➤ View All Students 👀\n");
        printf("4️⃣  ➤ Search for a Student 🔍\n");
        printf("5️⃣  ➤ Save Records to File 💾\n");
        printf("6️⃣  ➤ Load Records from File 📂\n");
        printf("7️⃣  ➤ Calculate Average Marks 📊\n");
        printf("8️⃣  ➤ Sort Students by Marks 📑\n");
        printf("9️⃣  ➤ Exit the System ❌\n");
        printf("==============================\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("\n🆕 Adding a new student...\n");
                addStudent(&students, &studentCount);
                break;
            case 2:
                printf("\n✏️ Modifying student details...\n");
                modifyStudent(students, studentCount);
                break;
            case 3:
                printf("\n👀 Displaying all students...\n");
                displayStudent(students, studentCount);
                break;
            case 4:
            {
                printf("\n🔍 Searching for a student...\n");
                int rollNumber;
                printf("Enter Roll Number to Search: ");
                scanf("%d", &rollNumber);
                getchar(); // Consume newline character

                const Student *foundStudent = searchStudent(students, studentCount, rollNumber);
                if (foundStudent) {
                    printf("\n✅ Student Found! 🎉\n");
                    printf("📛 Name: %s\n", foundStudent->name);
                    printf("🔢 Roll Number: %d\n", foundStudent->rollNumber);
                    printf("📊 Marks: %.2f\n", foundStudent->marks);
                } else {
                    printf("\n❌ Student with Roll Number %d not found. Try again! 🔄\n", rollNumber);
                }
            }
                break;
            case 5:
                printf("\n💾 Saving student records to file...\n");
                saveToFile(students, studentCount);
                break;
            case 6:
                printf("\n📂 Loading student records from file...\n");
                studentCount = loadFromFile(&students);
                break;
            case 7:
                printf("\n📊 Calculating the average marks of students...\n");
                calculateAverage(students, studentCount);
                break;
            case 8:
            {
                int sortOrder;
                printf("\n📑 SORT STUDENTS BY MARKS\n");
                printf("------------------------\n");
                printf("1. Sort in Ascending Order (lowest to highest marks)\n");
                printf("2. Sort in Descending Order (highest to lowest marks)\n");
                printf("------------------------\n");
                printf("Enter your choice (1-2): ");

                // Get and validate user input
                if (scanf("%d", &sortOrder) != 1 || (sortOrder != 1 && sortOrder != 2)) {
                    printf("⚠️ Invalid choice. Defaulting to ascending order.\n");
                    sortOrder = 1;
                    while (getchar() != '\n'); // Clear input buffer
                } else {
                    while (getchar() != '\n'); // Clear input buffer
                }

                // Convert user selection to the appropriate parameter (1=ascending, 0=descending)
                int ascending = (sortOrder == 1) ? 1 : 0;

                printf("\n📑 Sorting students by marks in %s order...\n",
                       ascending ? "ascending" : "descending");
                sortStudents(students, studentCount, ascending);
            }
                break;
            case 9:
                printf("\n👋 Thank you for using the Student Record System! 🎓\n");
                printf("🚀 See you next time. Have a great day! 😊\n");
                break;
            default:
                printf("\n⚠️ Invalid choice! Please enter a number between 1-9. Try again! 🔄\n");
        }
    } while (choice != 9);

    free(students);
    return 0;
}