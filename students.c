#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Student {
    char *name;
    int age;
    int numCourses;
    float GPA;
    char *courses[10];
    void (*printStudentInfo)(struct Student, int studentNum);
} Student;

//function prototypes
void printStudentInfo(Student s, int studentNum);
Student* getStudents(char *fileName);
bool addStudent(char *filename, Student newStudent, Student *studentList);
int getTotalNumStudents(char *filename);

int main(void) {
	Student *students = getStudents("studentrecords.csv");
	Student bob = {"Bob", 23, 3, 3.4, {"History of Japan", "Sociology 2", "Intro Guitar"}};
	Student jane = {"Jane", 19, 2, 3.4, {"Precalculus", "Robotics"}};
    if(addStudent("studentrecords.csv", bob, students) && addStudent("studentrecords.csv",jane, students))
    for(int i = 0; i < getTotalNumStudents("studentrecords.csv"); i++) {
	    students[i].printStudentInfo(students[i],i);
	}
	else printf("\nCould not add students.");
	return 0;
}

void printStudentInfo(Student s, int studentNum) {
    printf("\nStudent %d\nName: %s\nAge: %d\nGPA: %1.1f\nNumber of courses: %d", (studentNum + 1), s.name, s.age, s.GPA, s.numCourses);
    for(int i = 0; i < s.numCourses; i++) {
        printf("\nCourse %d: %s", i + 1, s.courses[i]);
    }
}

Student* getStudents(char *fileName) {
    int numStudents = 0;
    Student *students = malloc(100 * sizeof(Student));
    FILE *file = fopen(fileName, "r");
    if(file == NULL) {
        printf("\nError. Cannot read file");
        return NULL;
    }
    char line[256];
    while(fgets(line, 1024,file) != NULL) {
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        float GPA = atof(strtok(NULL, ","));
        int numCourses = atoi(strtok(NULL, ","));
        students[numStudents].name = malloc(sizeof(char) * 128);
        strcpy(students[numStudents].name, name);
        students[numStudents].age = age;
        students[numStudents].GPA = GPA;
        students[numStudents].numCourses = numCourses;
        students[numStudents].printStudentInfo = printStudentInfo;
        for(int i = 0; i < numCourses; i++) {
            char* course = strtok(NULL,",");
            students[numStudents].courses[i] = malloc(sizeof(char) * 128);
            strcpy(students[numStudents].courses[i], course);
        }
        numStudents++;
    }
    fclose(file);
    return students;
}

int getTotalNumStudents(char *filename) {
    int numStudents = 0;
    FILE *file = fopen(filename, "r");
    char line[256];
    while(fgets(line,1024,file) != NULL) {
        numStudents++;
    }
    fclose(file);
    return numStudents;
}

bool addStudent(char *filename, Student newStudent, Student *studentList) {
    FILE *file = fopen(filename, "a");
    if(file == NULL) {
        return false;
    }
    char *courses = malloc(sizeof(char) * 500);
    for(int i = 0; i < newStudent.numCourses; i++) {
        strcat(courses, ",");
        strcat(courses, newStudent.courses[i]);
    }
    fprintf(file, "\n%s,%d,%1.1f,%d%s", newStudent.name, newStudent.age, newStudent.GPA, newStudent.numCourses, courses);
    fclose(file);
    newStudent.printStudentInfo = printStudentInfo;
    studentList[getTotalNumStudents(filename) - 1] = newStudent;
    return true;
}
