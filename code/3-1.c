#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student{
    char name[10];
    int score;
    struct Student* next;
};


int main(){
    struct Student* head=NULL;
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    char *ptr = strtok(str, " ");

    while(strcmp(ptr, "quit") != 0){
        if(strcmp(ptr, "add") == 0){
            struct Student *newStudent = (struct Student*)malloc(sizeof(struct Student));
            strcpy(newStudent->name, strtok(NULL, " "));
            newStudent->score = atoi(strtok(NULL, " "));
            newStudent->next = NULL;
            if(head == NULL){
                head = newStudent;
            }
            else{
                struct Student* p = head;
                while(p->next != NULL){
                    p = p->next;
                }
                p->next = newStudent;
                p=NULL;
            }
        }
        if(strcmp(ptr, "delete") == 0){
            struct Student* p = head;
            char* name = strtok(NULL, " ");
            if(strcmp(p->name, name) == 0){
                struct Student* tmp = head;
                head = head->next;
                free(tmp);
            }
            else{
                while(p->next != NULL && (strcmp(name, p->next->name) != 0)){
                    p = p->next;
                }

                struct Student* tmp = p->next;
                p->next = tmp->next;
                free(tmp);

            }
            p=NULL;

        }
        if(strcmp(ptr, "print") == 0){
            struct Student* p = head;
            while(p != NULL){
                printf("%s %d\n", p->name, p->score);
                p = p->next;
            }
            p=NULL;
        }
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
        ptr = strtok(str, " ");
    }

    struct Student* p = head;
    while(p != NULL){
        p = head->next;
        free(head);
        head = p;
    }
    head = NULL;
    p=NULL;

}
