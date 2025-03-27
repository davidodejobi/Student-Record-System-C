
* * *

📘 Student Record System
------------------------

### 🔍 Overview

The **Student Record System** is a simple C-based application that allows users to manage student information. It supports adding, editing, searching, and sorting student records with an easy-to-use terminal interface.

* * *

### 🚀 Features

*   User-friendly interface for managing student records.
    
*   Input student marks and determine pass/fail status based on thresholds.
    
*   Dynamic memory allocation for handling records.
    
*   File operations: save and load student data.
    
*   Search by roll number.
    
*   Calculate average marks.
    
*   Sort records based on marks.
    

* * *

### 🛠️ System Architecture (Text Summary)

```
[Functions]
     |
     |---> Student Management (Add, Edit, Delete, Search, Sort)
     |
     |---> File Operations (Save, Load)
     |
     ---> Data Structures (Dynamic Arrays, Student Struct)
```


[Architecture Diagram](https://excalidraw.com/#json=ckG_SyjsADjs2U_0_dLcK,nw4arQDPmLURHkWsgi8DJQ)


* * *

### ➕ Add Student – Process Summary

1.  Allocate memory for new student.
    
2.  Input roll number.
    
    *   Check if valid.
        
    *   Check if it already exists.
        
3.  Input student name.
    
4.  Input marks.
    
    *   Validate marks (0–100).
        
5.  Add student to list.
    
6.  Increment student count.
    
7.  Show success message and return to main menu.
    

* * *

### 📦 Getting Started

#### Prerequisites

*   A C compiler (e.g., GCC)
    
*   `make` utility (if using Makefile)
    

#### Compilation

```bash
make
```

* * *
