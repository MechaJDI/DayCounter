#include <stdio.h>

struct date
{
       int month;
       int day;
       int year;
       };

 
// Creates a date based on input       
struct date createDate()
{
       struct date time;
       printf("Enter the month.\n");
       scanf("%i", &time.month);   
       printf("Enter the day.\n");
       scanf("%i", &time.day);
       printf("Enter the year.\n");
       scanf("%i", &time.year);        
       
       return time;   
}       

//Calculates the number of days betweens dates
int calculate(struct date date1, struct date date2)
{
    int n1;
    int n2;
    int f1;
    int f2;
    int g1;
    int g2;
    
    if(date1.month <= 2)
    {
                   f1 = date1.year - 1;
                   g1 = date1.month + 13;
    }
    else
    {
        f1 = date1.year;
        g1 = date1.month + 1;
    }
    
    if(date2.month <= 2)
    {
                   f2 = date2.year - 1;
                   g2 = date2.month + 13;
    }
    else
    {
        f2 = date2.year;
        g2 = date2.month + 1;
    }
    
    n1 = 1461 * f1 / 4 + 153 * g1 / 5 + date1.day;
    n2 = 1461 * f2 / 4 + 153 * g2 / 5 + date2.day; 
    
    return n2 - n1;   
}
       
//find number of days between dates after Mar. 1 1900
int main(void)
{
    struct date test = createDate();
    struct date test2 = createDate();
    printf("There are %i days between the two dates.\n", calculate(test,test2));

    return 0;
}
