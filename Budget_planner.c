/*
 * Budget_Planner.c
 *
 * Copyright 2012 Luca Tenuta<luca.tenuta@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>


//function prototypes
void get_expenses(double *p_School, double *p_Living, double *p_Trans, double *p_Other);
void get_income(double *p_Employ, double *p_Other);
void report(double School, double Living, double Trans, double OtherExp, double Employ, double OtherInc);
void get_double();


void main ()
{
    double school, living, transp, otherExp;
    double employ, otherInc;

    printf("Student Budget Planner\n~~~~~~~~~~~~~~~~~~~~~~\n");

    get_expenses(&school, &living, &transp, &otherExp);
    get_income(&employ, &otherInc);
    report(school, living, transp, otherExp, employ, otherInc);
    return;
}

//functions
void get_expenses(double *p_School, double *p_Living, double *p_Trans, double *p_Other)
{
    *p_School = *p_Living = 0;
    *p_Trans = *p_Other = 0;

    printf("School Expenses:\n"
           "~~~~~~~~~~~~~~~~\n");
    printf("Tuition (per semester):");
    *p_School += get_double();
}

void get_double() {
    int  valid_input, temp;
    double num;
    char next;

while (valid_input == 0) {

	valid = scanf("lf%c",&num, &enter)
	if (temp

	printf("Error!\nPlease enter a positive number:");
	clear_buffer();
	return num;
}

/*double get_double(void) {

 int keeptrying = 1, rc;
     double value;
     char after;

do {
        rc = scanf("%lf%c", &value, &after);

          if (rc == 0)
          {

             printf("Invalid Input\n\n");
             clear_buffer();

         } else if (after != '\n') {

             printf("Invalid Input\n\n");
             clear_buffer();
         } else

             keeptrying = 0;

     } while (keeptrying == 1);

     return value;
}*/
 /* clear the input buffer of characters */
 void clear_buffer(void) {

     while ( getchar() != '\n' ) ;  /* null statement intentional */
 }
