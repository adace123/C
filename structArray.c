#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char *name;
    int age;
    int numCourses;
    float GPA;
    char *courses[10];
    void (*printStudentInfo)(struct Student, int studentNum);
} Student;

void printStudentInfo(Student s, int studentNum);
Student* getStudents(char *fileName, int *numStudents);

int main(void) {
  int numStudents = 0;
  Student *students = getStudents("studentrecords.csv", &numStudents);
  for(int i = 0; i < numStudents; i++) {
     students[i].printStudentInfo(students[i],i);
  }
}

void printStudentInfo(Student s, int studentNum) {
    printf("\nStudent %d\nName: %s\nAge: %d\nGPA: %1.1f\nNumber of courses: %d", (studentNum + 1), s.name, s.age, s.GPA, s.numCourses);
    for(int i = 0; i < s.numCourses; i++) {
        printf("\nCourse %d: %s", i + 1, s.courses[i]);
    }
}

Student* getStudents(char *fileName, int *numStudents) {
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
        students[*numStudents].name = malloc(sizeof(char) * 128);
        strcpy(students[*numStudents].name, name);
        students[*numStudents].age = age;
        students[*numStudents].GPA = GPA;
        students[*numStudents].numCourses = numCourses;
        students[*numStudents].printStudentInfo = printStudentInfo;
        for(int i = 0; i < numCourses; i++) {
            char* course = strtok(NULL,",");
            students[*numStudents].courses[i] = malloc(sizeof(char) * 128);
            strcpy(students[*numStudents].courses[i], course);
        }
        (*numStudents)++;
    }
    fclose(file);
    return students;
}
