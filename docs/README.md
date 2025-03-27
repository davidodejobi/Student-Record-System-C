# Student Record System

## Overview
The Student Record System is a simple application developed in C that allows users to manage student information. It provides functionalities to add, modify, display, and search for student records, as well as save and load records from a file.

## Features
- User-friendly interface to manage student records.
- Ability to input student marks and determine pass/fail status based on a threshold.
- Dynamic memory allocation for managing student records.
- File operations to save and load student data.
- Search functionality to find students by roll number.
- Calculation of average marks for all students.
- Sorting of student records based on marks.

## Getting Started

### Prerequisites
- A C compiler (e.g., GCC)
- Make utility (optional, for using the Makefile)

### Compilation
To compile the project, navigate to the root directory of the project and run the following command:

```
make
```

This will compile the source files and create an executable named `student_record_system`.

### Running the Program
After compilation, you can run the program using the following command:

```
./student_record_system
```

### Usage
1. Upon starting the program, you will be greeted with a welcome message and prompted to enter your name.
2. You can then choose to add, modify, display, or search for student records.
3. The program will allow you to input multiple student records until you decide to exit.
4. You can save the records to a file or load existing records from a file.

## File Structure
- `src/`: Contains all source code files.
- `data/`: Contains the text file for storing student records.
- `docs/`: Contains documentation files.
- `Makefile`: Contains build instructions.
- `README.md`: Overview of the project.

## Contributing
Contributions are welcome! Please feel free to submit a pull request or open an issue for any suggestions or improvements.

## License
This project is open-source and available under the MIT License.