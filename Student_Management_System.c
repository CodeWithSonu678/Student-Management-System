#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{

    int roll;
    char name[25];
    float marks;
};

void Termnewline(char *str)
{
    size_t len = strlen(str);
    if (len && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
}


void Addstudent()
{
    struct student s;

    FILE *fp;
    fp = fopen("sonu.txt", "ab");
    if (fp == NULL)
    {
        printf("\033[0;31mFile not found!\033[0m\n");
    }

    printf("Enter Your Roll No. :");
    scanf("%d", &s.roll);
    getchar();

    printf("Enter Your Name :");
    fgets(s.name, sizeof(s.name), stdin);
    Termnewline(s.name);

    printf("Enter Your Marks :");
    scanf("%f", &s.marks);
    getchar();

    fwrite(&s, sizeof(s), 1, fp);

    fclose(fp);

    printf("\033[0;32mStudent added successfully !\033[0m\n");
}

void Viewstudent()
{
    struct student s;

    FILE *fp;
    fp = fopen("sonu.txt", "r");
    if (fp == NULL)
    {
        printf("\033[0;31mFile not found!\033[0m\n");
        return;
    }

    printf("\n\033[1;36mAll Student Records:\033[0m\n");
    printf("----------------------------");

    while (fread(&s, sizeof(s), 1, fp))
    {
        printf("\n Student's Roll No. : %d", s.roll);
        printf("\n Student's Name : %s", s.name);
        printf("\n Student's Marks : %.2f ", s.marks);
        printf("\n ----------------------------\n");
    }

    fclose(fp);
}

void Searchstudent()
{
    FILE *fp;
    struct student s;
    int roll, found = 0;

    fp = fopen("sonu.txt", "rb");
    if (fp == NULL)
    {
        printf("\033[0;31mData not found!\033[0m\n");
    }

    printf("Enter your roll number to search :");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll == roll)
        {
            printf("\nStudent found :--\n");
            printf("\n Student's Roll No. : %d\n", s.roll);
            printf("\n Student's Name : %s\n", s.name);
            printf(" Student's Marks : %.2f\n", s.marks);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\033[0;31mStudent not found !\033[0m\n");
    }

    fclose(fp);
}

void Deletestudent()
{
    FILE *fp = fopen("sonu.txt", "rb");
    FILE *temp = fopen("temprory.txt", "wb");
    struct student s;
    int roll, found = 0;

    if (fp == NULL || temp == NULL)
    {
        printf("\033[0;31mFile not found !\033[0m\n");
        return;
    }

    printf("Enter your roll number to delete : ");
    scanf("%d", &roll);
    getchar();
    printf("\n");

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll != roll)
        {
            fwrite(&s, sizeof(s), 1, temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("sonu.txt");
    rename("temprory.txt", "sonu.txt");

    if (found)
    {
        printf("\033[0;32mStudent deleted successfully !\033[0m\n");
    }
    else
    {
        printf("\033[0;31mStudent not found !\033[0m\n");
    }
}

void Updatestudent()
{
    FILE *fp = fopen("sonu.txt", "rb+");
    struct student s;
    int roll, found = 0;

    if (fp == NULL)
    {
        printf("\033[0;31mData not found!\033[0m\n");
        return;
    }

    printf("Enter your roll number to update :");
    scanf("%d", &roll);
    getchar();
    printf("\n");

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll == roll)
        {
            printf("Enter your new roll number :");
            scanf("%d", &s.roll);
            getchar();
            printf("\n");

            printf("Enter your new name : ");
            fgets(s.name, sizeof(s.name), stdin);
            Termnewline(s.name);
            printf("\n");

            printf("Enter your new marks : ");
            scanf("%f", &s.marks);
            getchar();

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            printf("\n\033[0;32mStudent updated successfully !\033[0m\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\033[0;31mStudent not found !\033[0m\n");
    }

    fclose(fp);
}

void ConverToCSV()
{
    FILE *fp = fopen("sonu.txt", "rb");
    FILE *csv = fopen("sonu.csv", "w");
    struct student s;

    if (fp == NULL || csv == NULL)
    {
        printf("\033[0;31mFile not found !\033[0m\n");
        return;
    }

    fprintf(csv, "Student's Roll,Student's Name,Student's Marks\n");

    while (fread(&s, sizeof(s), 1, fp))
    {
        fprintf(csv, "%d ,%s ,%.2f", s.roll, s.name, s.marks);
    }

    fclose(fp);
    fclose(csv);
    printf("\033[0;32mSuccessfully ! Exported to sonu.csv\033[0m\n");
}

int main()
{
   
    int choice;
    do
    {
        printf("\n\033[1;36m---------------------------\033[0m\n");

        printf("\033[1;36m Student Management System\033[0m\n");

        printf("\033[1;36m---------------------------\033[0m\n");

        printf("\n\033[0;33m 1. Add Student\033[0m");
        printf("\n\033[0;33m 2. View Student\033[0m");
        printf("\n\033[0;33m 3. Search Student\033[0m");
        printf("\n\033[0;33m 4. Delete Student\033[0m");
        printf("\n\033[0;33m 5. Update Student\033[0m");
        printf("\n\033[0;33m 6. Convert To CSV\033[0m");
        printf("\n\033[0;33m 7. Exit Student\033[0m\n");

        printf("\n\033[0;34mEnter your choice : \033[0m");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            Addstudent();
            break;

        case 2:
            Viewstudent();
            break;

        case 3:
            Searchstudent();
            break;

        case 4:
            Deletestudent();
            break;

        case 5:
            Updatestudent();
            break;

        case 6:
            ConverToCSV();
            break;

        case 7:
            printf("\n\033[0;32mExiting Program.\033[0m\n");
            break;

        default:

            printf("\033[0;31mPlease enter the valid choice !\033[0m\n");
            printf("\n");
            break;
        }

    } while (choice != 7);

    return 0;
}
