# CS455 : COURSE REGISTRATION AND SCHEDULE BUILDING SYSTEM
This repository contains the source code for the course registration and schedule building system, created as a class assignment for the course CS455 : Introduction to Software Engineering, by [Aditi Khandelia](https://github.com/AditiKhandelia) under the guidance of Prof. Sruti Ragavan.

## Project Description
The project provides interface to both administrators and students, where administrators can add courses, students can register for courses and build their schedule. The project is implemented in C++.

## Features
- **Administrator Interface**
  - Add courses
  - View all courses

- **Student Interface**
    - View all courses
    - Register for courses
    - Build schedule
    - View schedule

## Contents of the Repository
- **[main.cpp] :** Contains the main function which runs the program.
- **[interface.cpp] :** Contains the implementation of the interface class.
- **[commands.cpp] :** Contains the implementation of the commands class.
- **[course.cpp] :** Contains the implementation of the Course class, and the CourseStore class, which is used to maintain the record of all courses offered.
- **[schedule.cpp] :** Contains the implementation of the Schedule class, which is used to maintain the schedule of a student, and the ScheduleBuilder class, which is used to build the schedule.

## How to Run
1. Clone the repository
2. Run the following commands:
```bash
make
```
3. To clean the repository, run:
```bash
make clean
```