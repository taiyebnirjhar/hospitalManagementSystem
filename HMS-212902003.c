#include<stdio.h>

//Structure of patient
typedef struct
{
    char Name[20];
    char disease[20];
    char patient_status[10];
    char blood_group[5];
    char gender[5];                                           //String use
    int patient_bed_no;
    float patient_age;
    float phone_number;

} patient;
patient emp;

int main()
{
    patient patientDB[150];
    int n = 0, op;
    FILE *f;                                                 // communication between the file.
                                                            //open the file
    f = fopen("patient.dat", "r");                         //fopen() userdefin function its mean open for reading file.
    if(f!=NULL)
    {
                                                          //read the patient Database from the file
        ReadDB(f, patientDB, &n);
                                                          //close the file
        fclose(f);
    }
    printf("\n*****************************");
    printf("\n***                       ***");
    printf("\n***   Green Hospital      ***");
    printf("\n***                       ***");
    printf("\n*****************************\n");
    while(1)                                               //infinite loop
    {
                                                           //display the menu
        printf("\n1 : Add patient Details.");
        printf("\n2 : Update patient Record.");
        printf("\n3 : Find patient full Record.");
        printf("\n4 : Monitor patients.");
        printf("\n5 : List Record.");
        printf("\n6 : Exit.");

        printf("\nEnter option: ");
        scanf("%d", &op);
        if(op==6)
            break;

        switch(op)
        {
        case 1:
                                                           // add patient details
            addpatientDetails(patientDB, n);
            n++;
            break;

        case 2:
                                                         //Update patient Record
            updatepatient(patientDB, n);
            break;

        case 3:
                                                        //Find patient Record
            findpatient(patientDB, n);
            break;

        case 4:
                                                         //Count patients
            countpatients(n);
            break;

        case 5:
                                                          //Print the Database
            printDB(patientDB, n);
            break;
        }
    }

                                                           //open the file in write mode
    f = fopen("patient.dat", "w");
                                                         //write the patient Database to the file
    WriteDB(f, patientDB, n);
                                                          //close the file
    fclose(f);

    return 0;
}



                                                           //Function to add patient details//
void addpatientDetails(patient patientDB[], int n)
{
    
    int fg, i;
    do
    {   printf("-----------------------------------------\n");
        printf("-----------------------------------------\n");
        printf("Enter patient-bed-number: ");
        scanf("%d", &emp.patient_bed_no);
        fg = 0;
        for(i=0; i<n; i++)
        {
            if(patientDB[i].patient_bed_no == emp.patient_bed_no)
            {
                printf("patient already exist on this bed! please try another\n");
                fg = 1;
            }
        }
    }
    while(fg!=0);
    getchar();
    printf("Enter patient Full Name: ");
    scanf("%[^\n]", emp.Name);                                //%[^\n] using for sting
     printf("Enter patient disease: ");
    scanf("%s", emp.disease); 
     printf("Enter patient status (status should be 'sick/improved'. defualt option is 'sick'): ");
    scanf("%s", emp.patient_status); 
     printf("Enter patient gender: ");
    scanf("%s", emp.gender); 
    printf("Enter patient blood group: ");
    scanf("%s", emp.blood_group);
    printf("Enter patient patient_age: ");
    scanf("%f", &emp.patient_age);
     printf("Enter patient Contact number: ");
    scanf("%f", &emp.phone_number);

    patientDB[n] = emp;
}  

                                                                  //Function to update a patient record
void updatepatient(patient patientDB[], int n)
{
    int id, i, op;
     printf("-----------------------------------------\n");
      printf("-----------------------------------------\n");
    printf("Enter patient-bed-number to update: ");
    scanf("%d", &id);
    for(i=0; i<n; i++)
    {
        if(patientDB[i].patient_bed_no == id)
        {
            printf("\n1. Update patient status: ");
            printf("\n2. exit ");
            printf("\nEnter option: ");
            scanf("%d", &op);
            if(op==1)
            {
                printf("Enter status (status should be 'sick/improved'. defualt option is 'sick') : ");
                getchar();
                scanf("%[^\n]", patientDB[i].patient_status);
            }
            else
            {
                return;
            }
            
        }
    }
}
                                                              //Function to find patient record
void findpatient(patient patientDB[], int n)
{
    int i, id;
     printf("-----------------------------------------\n");
      printf("-----------------------------------------\n");
    printf("Enter patient-bed-number to search: ");
    scanf("%d", &id);
    for(i=0; i<n; i++)
    {
        if(patientDB[i].patient_bed_no == id)
        {
            printf("patient Name: %s\n", patientDB[i].Name);
            printf("patient disease: %s\n", patientDB[i].disease);
            printf("patient status: %s\n", patientDB[i].patient_status);
            printf("patient Gender: %s\n", patientDB[i].gender);
            printf("patient Blood group: %s\n", patientDB[i].blood_group);
            printf("patient Bed Number : %d\n", patientDB[i].patient_bed_no);
            printf("patient_age : %.f\n", patientDB[i].patient_age);
            printf("patient Contact Number : %.f\n", patientDB[i].phone_number);
            return;
        }

    }
    printf("Not found\n");
}


                                                           //Function to count and print the total number of patients in the system
void countpatients(int n)
{
    printf("Total number of patients in the system = %d\n", n);
}

                                                             //Function to print the patient Database
void printDB(patient patientDB[], int n)
{
    int i;
     printf("-----------------------------------------\n");
      printf("-----------------------------------------\n");
    printf("patient-Name  patient-bed-number  disease  \n");
    printf("............................................................................\n");
    for(i=0; i<n; i++)
    {
        printf("%-20s%-15d%s\n", patientDB[i].Name, patientDB[i].patient_bed_no, patientDB[i].disease);
    }
}


                                                           //Function to read the patient Database from the file
void ReadDB(FILE *f, patient patientDB[], int *n)
{
    char line[100];
    int i = 0;

    while(!feof(f))
    {
        fgets(patientDB[i].Name, 20, f);
        if(feof(f))
            break;
        fscanf(f, "%d%s\n", &patientDB[i].patient_bed_no, &patientDB[i].disease);
        i++;
    }
    *n = i;
}

                                                                          //Function to write the patient Database to the file
void WriteDB(FILE *f, patient patientDB[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        fprintf(f, "%-20s\n%d\t%s\n", patientDB[i].Name, patientDB[i].patient_bed_no, patientDB[i].disease);
    }
}


