// 12S23001 - Kevin Gultom
// 12S23033 - Oloan Nainggolan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main(int _argc, char **_argv) {
    char input[75];  
    int dorm_count = 0;   
    int dorm_capacity = 0;  
    struct dorm_t *dorms = malloc(dorm_capacity * sizeof(struct dorm_t));
    
    int student_count = 0;  
    int student_capacity = 0;
    struct student_t *students = malloc(student_capacity * sizeof(struct student_t));

    FILE *dorm_file = fopen("storage/dorm-repository.txt", "r");
    FILE *student_file = fopen("storage/student-repository.txt", "r");

   
    while (fgets(input, sizeof(input), dorm_file)) {
        dorm_capacity++;
        dorms = realloc(dorms, dorm_capacity * sizeof(struct dorm_t));
        dorms[dorm_count++] = create_dorm_repository(input);
    }

   
    while (fgets(input, sizeof(input), student_file)) {
        student_capacity++;
        students = realloc(students, student_capacity * sizeof(struct student_t));
        students[student_count++] = create_student_repository(input);
    }

    fclose(dorm_file);  
    fclose(student_file);  

 
    while (1) {
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

      
        input[strcspn(input, "\r\n")] = '\0';

        char *command = strtok(input, "#");  

        if (strcmp(command, "---") == 0) {  
            break;
        }

        if (strcmp(command, "dorm-add") == 0) {
            dorm_capacity++;
            dorms = realloc(dorms, dorm_capacity * sizeof(struct dorm_t));
            dorms[dorm_count++] = create_dorm(input);  
        } else if (strcmp(command, "dorm-print-all") == 0) {
            for (int i = 0; i < dorm_count; i++) {
                print_dorm(dorms[i]);  
            }
        } else if (strcmp(command, "dorm-print-all-detail") == 0) {
            for (int i = 0; i < dorm_count; i++) {
                print_dorm_detail(dorms[i]);  
            }
        } else if (strcmp(command, "student-add") == 0) {
            student_capacity++;
            students = realloc(students, student_capacity * sizeof(struct student_t));
            students[student_count++] = create_student(input); 
        } else if (strcmp(command, "student-print-all") == 0) {
            for (int i = 0; i < student_count; i++) {
                print_student(students[i]);  
            }
        } else if (strcmp(command, "student-print-all-detail") == 0) {
            for (int i = 0; i < student_count; i++) {
                print_student_detail(students[i]);  
            }
        } else if (strcmp(command, "assign-student") == 0) {
            char *student_id = strtok(NULL, "#");
            char *dorm_name = strtok(NULL, "#");
            assign_student(dorms, students, student_id, dorm_name, student_count, dorm_count, find_id, find_dorm);  
        } else if (strcmp(command, "move-student") == 0) {
            char *student_id = strtok(NULL, "#");
            char *dorm_name = strtok(NULL, "#");
            move_student(dorms, students, student_id, dorm_name, student_count, dorm_count, find_id, find_dorm); 
        } else if (strcmp(command, "dorm-empty") == 0) {
            char *dorm_name = strtok(NULL, "#");
            dorm_empty(dorm_name, student_count, dorm_count, students, dorms, find_dorm);  
        }
    }

    free(students);  
    free(dorms);  

    return 0;
}
