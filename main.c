#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i = 0;
struct studentinfo {
	char fname[50];                   //1
    char lname[50];                   //1
	int roll;                         //4
	float cgpa;                       //4
	float attendence;                 //4
	long long int mobile_number;      //10
} st;

FILE *ptr;
long sz=sizeof(st);

void reset () {
  printf("\033[0m");
}

void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[0;32m");
}

void yellow() {
  printf("\033[1;33m");
}

void blue () {
  printf("\033[1;34m");
}

void purple() {
  printf("\033[1;35m");
}

void cyan() {
  printf("\033[1;36m");
}

void welcome(){
    red();
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    blue();
    printf("\n\t\t\t        *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n\t\t\t        *                  WELCOME                  *");
    printf("\n\t\t\t        *                    TO                     *");
    printf("\n\t\t\t        *               Student Record              *");
    printf("\n\t\t\t        *                 MANAGEMENT                *");
    printf("\n\t\t\t        *                   SYSTEM                  *");
    printf("\n\t\t\t        *           GLA UNIVERSITY MATHURA          *");
    printf("\n\t\t\t        *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    red();
    printf("\n\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n\n");
    reset();
}

void clscr(){
    system("@cls||clear");
}



void add_student()
{
    char fn[50];
    char ln[50];
    ptr=fopen("data.txt","ab+");
    red();
	printf("Add the Students Details\n");
	blue();
	printf("-------------------------\n");
	purple();
   printf("Enter the first name of student\n");
	reset();
	scanf("%s",fn);                                             //gets(name)
    strcpy(st.fname,fn);
	purple();
	printf("Enter the last name of student\n");
	reset();
	scanf("%s",ln);
    strcpy(st.lname,ln);
    purple();
	printf("Enter the Roll Number\n");
	reset();
	scanf("%d", &st.roll);
    purple();
	printf("Enter the CGPA you obtained\n");
	reset();
	scanf("%f", &st.cgpa);
	purple();
	printf("Enter the overall attendence\n");
	reset();
	scanf("%f", &st.attendence);
	purple();
	printf("Enter the Mobile number\n");
    reset();
	scanf("%lld", &st.mobile_number);
    fwrite(&st,sizeof(st),1,ptr);
    fclose(ptr);

}


void view()
{
	ptr=fopen("data.txt","rb");
    purple();
	printf("Enter the Roll Number of the student which you want to search\n");
	reset();
    int x,c=0;
    scanf("%d", &x);

    while(fread(&st,sizeof(st),1,ptr)==1)
    {
        if(x == st.roll)
        {
            c=c+1;
		    blue();
			printf("The Students Details are\n");
			yellow();
			printf("The First name is %s\n",st.fname);
			printf("The Last name is %s\n",st.lname);
			printf("The CGPA is %f\n",st.cgpa);
			printf("overall attendence is %f\n",st.attendence);
			printf("mobile number is %lld\n",st.mobile_number);
			reset();
        }
    }
    fclose(ptr);
    if(c==0){
		    red();
		    printf("No such roll number found\n");
		    reset();
	}
}


void removed()
{
	purple();
	printf("Enter the roll number to delete the entry : ");
	reset();
    int x,c=0;
    scanf("%d", &x);
    FILE *temp;
    ptr=fopen("data.txt","rb");
    temp=fopen("remove.txt","ab");
    while(fread(&st,sizeof(st),1,ptr)==1)
    {
        if(x==st.roll)
        {
            c=1;
        }
        else{
            fwrite(&st,sizeof(st),1,temp);
        }
    }
    fclose(ptr);
    fclose(temp);
    remove("data.txt");
    rename("remove.txt","data.txt");
    if(c==0){
		    red();
		    printf("No such roll number found\n");
		    reset();
	    }
	else{
	    	red();
			printf("The Roll Number is removed Successfully\n");
			reset();
		}

}


void modify()
{
	purple();
	printf("Enter the roll number to update the entry : ");
	reset();
    int x,c=0;
    scanf("%d", &x);
    ptr=fopen("data.txt","rb+");
    while(fread(&st,sizeof(st),1,ptr)==1)
    {
        if(x == st.roll)
        {
            c=c+1;
		    cyan();
			printf("1. first name\n2. last name\n3. roll no.\n4. CGPA\n5. overall attendence\n6. Mobile number\n");
			reset();
			int z;
			scanf("%d", &z);
			switch (z) {
			case 1:
			purple();
				printf("Enter the new first name : \n");
				reset();
				scanf("%s", st.fname);
				red();
				printf("Your data is updated sucessfully\n");
				reset();
				break;
			case 2:
			purple();
				printf("Enter the new last name : \n");
				reset();
				scanf("%s", st.lname);
				red();
				printf("Your data is updated sucessfully\n");
				reset();
				break;
			case 3:
			purple();
				printf("Enter the new roll numnber : \n");
				reset();
				scanf("%d", &st.roll);
				red();
				printf("Your data is updated sucessfully\n");
				reset();
				break;
			case 4:
			purple();
				printf("Enter the new CGPA : \n");
				reset();
				scanf("%f", &st.cgpa);
				red();
				printf("Your data is updated sucessfully\n");
				reset();
				break;
			case 5:
			purple();
				printf("Enter the new overall attendence : \n");
				reset();
				scanf("%f", &st.attendence);
				red();
				printf("Your data is updated sucessfully\n");
				reset();
				break;
			case 6:
			purple();
				printf("Enter the new mobile number \n");
				reset();
				scanf("%lld", &st.mobile_number);
				red();
				printf("Your data is updated sucessfully\n");
				reset();
				break;
			default :
			red();
			printf("You enter a wrong key\n");
			break;
			}
            fseek(ptr,-sz,1);
            fwrite(&st,sizeof(st),1,ptr);
            fclose(ptr);
            break;
        }
    }
    if(c==0){
		    red();
		    printf("No such roll number found\n");
		    reset();
	    }
}



void all_details()
{
	int c=1,k=0;
    red();
    printf("***STUDENT INFO***\n\n");
    reset();
    ptr=fopen("data.txt","rb");
    while(fread(&st,sizeof(st),1,ptr)==1)
    {
    	    k=1;
            blue();
            printf("Details of student-%d is--\n",c);
            yellow();
            printf("The First name is %s\n",st.fname);
		    printf("The Last name is %s\n",st.lname);
		    printf("Roll number is %d\n",st.roll);
		    printf("The CGPA is %f\n",st.cgpa);
		    printf("overall attendence is %f\n",st.attendence);
		    printf("mobile number is %lld\n",st.mobile_number);
		    reset();
		    c=c+1;
    }
    fclose(ptr);
    if(k==0){
    	red();
    	printf("No data entered yet\n");
    	reset();
	}
}

void main()

{
	int choice, count;
	welcome();
	while(i!=100000) {
	    green();
		printf("\n\t\t\t\t\tThe Task that you want to perform\n");
		cyan();
		printf("\n\t\t\t\t\tPress 1 to add the Student Details\n");
		printf("\n\t\t\t\t\tPress 2 to find the Student Details by Roll Number\n");
		printf("\n\t\t\t\t\tPress 3 to Delete the Students Details by Roll Number\n");
		printf("\n\t\t\t\t\tPress 4 to Update the Students Details by Roll Number\n");
		printf("\n\t\t\t\t\tPress 5 to Details of all students\n");
		printf("\n\t\t\t\t\tPress 6 to Exit\n\n");
		reset();
		yellow();
		printf("Enter your choice to perform a task\n");
		reset();
		scanf("%d", &choice);
		switch (choice) {
		case 1:
		    clscr();
			add_student();
			clscr();
			red();
			printf("Your data for student is saved SUCCESSFULLY\n");
			reset();
			break;
		case 2:
		    clscr();
			view();
			break;
		case 3:
		    clscr();
			removed();
			break;
		case 4:
		    clscr();
			modify();
			break;
		case 5:
		    clscr();
		    all_details();
		    break;
		case 6:
		    clscr();
		    red();
		    printf("You have Successfully exited from the system\n");
		    reset();
			exit(0);
			break;
		}
	}
}
