#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert();
void update(int usn);
void delete(int usn);
void select(int usn);

int main(){
	int usn, choice;
	while(1){
		printf("\nMenu\n");
		printf("1.Insert\n2.Update\n3.Delete\n4.Select\n5.Exit");
		printf("\nEnter choice : ");
		scanf("%d", &choice);
		switch(choice){
			case 1: insert();
			break;
			case 2: printf("Enter the usn to update : ");
			scanf("%d", &usn);
			update(usn);
			break;
			case 3: printf("Enter the usn to delete : ");
			scanf("%d", &usn);
			delete(usn);
			break;
			case 4: printf("Enter the usn to display record or for all records enter 0 : ");
			scanf("%d", &usn);
			select(usn);
			break;
			case 5: exit(0);
			default: printf("Invalid!");
		}
	}
	return 0;
}

struct student{
	int usn;
	char name[50];
	float marks;
};

void insert(){
	FILE *file = fopen("Student.txt", "a+");
	struct student stud;
	int flag = 0;
	int usn1;
	float marks1;
	char name1[50];
	printf("Enter the usn : ");
	scanf("%d", &usn1);
	printf("\nEnter the name : ");
	scanf("%s", name1);
	printf("\nEnter the marks : ");
	scanf("%f", &marks1);
	while(fscanf(file, "%d,%[^,],%f\n", &stud.usn, stud.name, &stud.marks) != EOF){
		if(stud.usn == usn1){
			printf("\nDuplicate Found!");
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		stud.usn = usn1;
		strcpy(stud.name, name1);
		stud.marks = marks1;
		fprintf(file, "%d, %s, %.2f\n", stud.usn, stud.name, stud.marks);
		printf("Record inserted");
	}
	fclose(file);
}

void update(int usn){
	FILE *file = fopen("Student.txt", "r");
	FILE *file1 = fopen("Student2.txt", "w");
	struct student stud;
	int flag = 0;
	char ch[2];
	while(fscanf(file, "%d,%[^,],%f\n", &stud.usn, stud.name, &stud.marks) != EOF){
		if(usn == stud.usn){
			flag = 1;
			printf("\nSelected usn is found");
			printf("\nUSN\tNAME\tMARKS");
			printf("\n%d\t%s\t%.2f", stud.usn, stud.name, stud.marks);
			printf("\nPress y to proceed, otherwise press n\n");
			scanf("%s", ch);
			if(strcmp(ch, "y") == 0){
				printf("\nUpdate usn: ");
				scanf("%d", &stud.usn);
	            printf("\nUpdate name: ");
	            scanf("%s", stud.name);
	            printf("\nUpdate marks: ");
	            scanf("%f", &stud.marks);
	            fprintf(file1, "%d, %s, %.2f\n", stud.usn, stud.name, stud.marks);
	            continue;
			}
		}
		fprintf(file1, "%d, %s, %.2f\n", stud.usn, stud.name, stud.marks);
	}
	fclose(file);
	fclose(file1);
	remove("Student.txt");
	rename("Student2.txt", "Student.txt");
	if(flag == 0){
		printf("\nNo record is found for given usn");
	}
	else{
		printf("Record updated ");
	}
}

void delete(int usn){
	FILE *file = fopen("Student.txt", "r");
	FILE *file1 = fopen("Student2.txt", "w");
	struct student stud;
	int flag = 0;
	char ch[2];
	while(fscanf(file, "%d,%[^,],%f\n", &stud.usn, stud.name, &stud.marks) != EOF){
		if(usn == stud.usn){
			flag = 1;
			printf("\nSelected usn is found");
			printf("\nUSN\tNAME\tMARKS");
			printf("\n%d\t%s\t%.2f", stud.usn, stud.name, stud.marks);
			printf("\nPress y to proceed, otherwise press n\n");
			scanf("%s", ch);
			if(strcmp(ch, "y") == 0){
				printf("\nRecord is deleted");
	            continue;
			}
		}
		fprintf(file1, "%d, %s, %.2f\n", stud.usn, stud.name, stud.marks);
	}
	fclose(file);
	fclose(file1);
	remove("Student.txt");
	rename("Student2.txt", "Student.txt");
	if(flag == 0){
		printf("\nNo record is found for given usn");
	}
}

void select(int usn){
	FILE *file = fopen("Student.txt", "r");
	struct student stud;
	int flag = 0;
	int count = 0;
	if(usn == 0){
		printf("\nAll Records");
		printf("\nUSN\tNAME\tMARKS\n");
		while(fscanf(file, "%d,%[^,],%f\n", &stud.usn, stud.name, &stud.marks) != EOF){
			printf("\n%d\t%s\t%.2f", stud.usn, stud.name, stud.marks);
		    count++;
		}
		printf("\nThe total number of records : %d", count);
	}
	else{
		while(fscanf(file, "%d,%[^,],%f\n", &stud.usn, stud.name, &stud.marks) != EOF){
			if(usn == stud.usn){
				printf("\nThe selected record :\n ");
				printf("USN\tNAME\tMARKS\n");
				printf("%d\t%s\t%.2f\n", stud.usn, stud.name, stud.marks);
				break;
			}
		}
	}
	fclose(file);
}
	
	
	
	
