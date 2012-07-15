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
double get_double(void);
char get_char(void);
void clear_buffer(void);


void main ()
{
    double school, living, transp, otherExp;
    double employ, otherInc;

    printf("Student Budget Planner\n~~~~~~~~~~~~~~~~~~~~~~\n");

    get_expenses(&school, &living, &transp, &otherExp);
    //get_income(&employ, &otherInc);
    //report(school, living, transp, otherExp, employ, otherInc);
    return;
}

//functions
void get_expenses(double *p_School, double *p_Living, double *p_Trans, double *p_Other)
{
    *p_School = *p_Living = *p_Trans = *p_Other = 0;

    printf("School Expenses:\n~~~~~~~~~~~~~~~~\n");
    printf("Tuition (per semester):");
    *p_School += get_double();
    printf("Textbooks (per semester):");
    *p_School += get_double();
    printf("Supplies:");
    *p_School += get_double();

    printf("Living Expenses\n~~~~~~~~~~~~~~~\n");
    printf("Residence/Rent/Mortgage:");
    *p_Living += get_double();
    printf("Utilities:");
    *p_Living += get_double();
    printf("Phone/Internet:");
    *p_Living += get_double();
    printf("Groceries/Eating Out:");
    *p_Living += get_double();
    printf("Entertainment:");
    *p_Living += get_double();

}







//validation
double get_double(void) {
    int  valid_input = 1, temp;
    double num;
    char letter;

do {
	temp = scanf("%lf%c",&num, &letter);

	if (temp == 0) {
		printf("Only postive numbers are allowed.\nPlease re-enter:");
		clear_buffer();
	} else if (letter != '\n') {
		printf("Only postive numbers are allowed.\nPlease re-enter:");
		clear_buffer();
	} else
		valid_input = 0;
	} while (valid_input == 1);
	return num;
}

 void clear_buffer(void) {

     while ( getchar() != '\n' ) ;  /* null statement intentional */
 }
