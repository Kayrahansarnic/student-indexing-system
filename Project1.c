#include <stdio.h>
#include <stdlib.h>
#include <string.h>






struct student{
	int StudentNumber;
	char *StudentName;
};

typedef struct student Student;

struct StudentNumberLL{
	int StudentNumber;
	Student *addr;
	struct StudentNumberLL *next;
};

struct StudentNumberLL *NumberListHEAD=NULL; 

struct StudentNameLL{
	char *StudentName;
	Student *addr;
	struct StudentNameLL *next;
};

struct StudentNameLL *NameListHEAD=NULL;


void AddStudent(int Number, char *Name){
	
	Student *NewStudent = (Student*)malloc(sizeof(Student));
	NewStudent->StudentNumber = Number;
	
	
	NewStudent->StudentName = (char*)malloc(strlen(Name) + 1);
	strcpy(NewStudent->StudentName, Name);
	
	
	struct StudentNumberLL *NewNumberNode = (struct StudentNumberLL*)malloc(sizeof(struct StudentNumberLL));
	NewNumberNode->StudentNumber = Number;
	NewNumberNode->addr  = NewStudent;
	NewNumberNode->next = NULL;
	
	if(NumberListHEAD == NULL || NumberListHEAD->StudentNumber > Number) {
		
		NewNumberNode->next = NumberListHEAD;
		NumberListHEAD = NewNumberNode;
	}
	else{
		struct StudentNumberLL *current = NumberListHEAD;
		for (current=NumberListHEAD;current->next != NULL && current->next->StudentNumber < Number; current = current->next){
		}
		NewNumberNode->next = current->next;
		current->next = NewNumberNode;
	}
	
		struct StudentNameLL *NewNameNode = (struct StudentNameLL*)malloc(sizeof(struct StudentNameLL));
	NewNameNode->StudentName = NewStudent->StudentName;
	NewNameNode->addr = NewStudent;
	NewNameNode->next = NULL;
	
	if (NameListHEAD == NULL || strcmp(NameListHEAD->StudentName, Name) > 0) {
    	NewNameNode->next = NameListHEAD;
	    NameListHEAD = NewNameNode;
	}
	else {
    	struct StudentNameLL *currentName;
    	for (currentName = NameListHEAD; 
    	     currentName->next != NULL && strcmp(currentName->next->StudentName, Name) < 0; 
    	     currentName = currentName->next) {
    	}
    	NewNameNode->next = currentName->next;
    	currentName->next = NewNameNode;
	}
}
	
void SearchByStudentNumber(int StudentNumber) {
    struct StudentNumberLL *current;
    int found = 0;

    for (current = NumberListHEAD; current != NULL; current = current->next) {
        if (current->StudentNumber == StudentNumber) {
            printf("----------Student Found!!!----------\n");
            printf("Number: %d\n", current->addr->StudentNumber);
            printf("Name: %s\n", current->addr->StudentName);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with number %d is not found\n", StudentNumber);
    }
}

void dispAllViaStudentNumber() {
    struct StudentNumberLL *current;
    printf("-------Students Sorted by Number-------\n");
    for (current = NumberListHEAD; current != NULL; current = current->next) {
        printf("ID: %d | Name: %s\n", current->addr->StudentNumber, current->addr->StudentName);
    }
}

void dispAllViaStdudentName() {
    struct StudentNameLL *currentName;
    printf("-------Students Sorted by Name--------\n");
    for (currentName = NameListHEAD; currentName != NULL; currentName = currentName->next) {
        printf("Name: %s | ID: %d\n", currentName->addr->StudentName, currentName->addr->StudentNumber);
    }
}

void DeleteStudent(int Number) {
    struct StudentNumberLL *currentNum, *previousNum = NULL;
    Student *targetStudent = NULL;

    for (currentNum = NumberListHEAD; currentNum != NULL; previousNum = currentNum, currentNum = currentNum->next) {
        if (currentNum->StudentNumber == Number) {
            targetStudent = currentNum->addr;
            
            if (previousNum == NULL){
			NumberListHEAD = currentNum->next;}
			
            else {
			previousNum->next = currentNum->next;}
        
            free(currentNum);
            break;
        }
    }

    if (targetStudent == NULL) {
        printf("-----Student with number %d not found-----\n", Number);
        return;
    }
    
    struct StudentNameLL *currentName, *previousName = NULL;
    for (currentName = NameListHEAD; currentName != NULL; previousName = currentName, currentName = currentName->next) {
        if (currentName->addr == targetStudent){
            if (previousName == NULL) NameListHEAD = currentName->next;
            else previousName->next = currentName->next;
            
            free(currentName); 
            break;
        }
    }

    free(targetStudent->StudentName);
    free(targetStudent);

    printf("---Student %d has been deleted from the List---\n", Number);
}

void UpdateStudent(int oldNumber, int newNumber, char *newName) {
	
    DeleteStudent(oldNumber);
    
    AddStudent(newNumber, newName);
    
    printf("---Student %d updated to %d - %s---\n", oldNumber, newNumber, newName);
}

void SearchByStudentName(char *Name) {
    struct StudentNameLL *current;
    int found = 0;

    for (current = NameListHEAD; current != NULL; current = current->next) {
        if (strcmp(current->StudentName, Name) == 0) {
            printf("-------------Student Found!-------------\n");
            printf("Number: %d\n", current->addr->StudentNumber);
            printf("Name: %s\n", current->addr->StudentName);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with name %s not found\n", Name);
    }
}


int main()
{
	
	
	
	
	
	return 0;
}