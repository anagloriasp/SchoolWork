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
void get_expenses(double *p_School, double *p_Living, double *p_Trans, double *p_OtherExp);
void get_income(double *p_Employ, double *p_OtherInc);
void display_report(double school, double living, double trans, double otherExp, double employ, double otherInc);
double get_double(void);
char get_char(void);
void clear_buffer(void);

main () {
    double school, living, trans, otherExp;
    double employ, otherInc;
    int input_set = 0;


    printf("Student Budget Planner\n~~~~~~~~~~~~~~~~~~~~~~\n");

    get_expenses(&school, &living, &trans, &otherExp);
    //get_income(&employ, &otherInc);
    display_report(school, living, trans, otherExp, employ, otherInc);
    printf("\nSchool total: %.2lf", school/4);
    return;
}

//functions
void get_expenses(double *p_School, double *p_Living, double *p_Trans, double *p_OtherExp)
{
    *p_School = *p_Living = *p_Trans = *p_OtherExp = 0;

    printf("School Expenses:\n~~~~~~~~~~~~~~~~\n");
    printf("Tuition (per semester):");
    *p_School += get_double();
    printf("Textbooks (per semester):");
    *p_School += get_double();
    printf("Supplies:");
    *p_School += get_double() * 4;
    *p_School = *p_School/4;


    printf("\n\nLiving Expenses\n~~~~~~~~~~~~~~~\n");
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

    printf("\n\nTransportation\n~~~~~~~~~~~~~~\n");
    printf("Public Transportation:");
    *p_Trans += get_double();
    printf("Car:");
    *p_Trans += get_double();
    printf("Auto Insurance:");
    *p_Trans += get_double();
    printf("Gas/Maintence:");
    *p_Trans += get_double();

    printf("\n\nOther\n~~~~~\n");
    printf("Any other expenses:");
    *p_OtherExp += get_double();

}

void get_income(double *p_Employ, double *p_OtherInc) {
	*p_Employ = *p_OtherInc = 0;

	printf("Employment Income\n~~~~~~~~~~~~~~~~~\n");
	printf("Expected Wages/Tips:");
	*p_Employ += get_double();

	printf("\n\nOther Income\n~~~~~~~~~~~\n");
	printf("Family Support:");
	*p_OtherInc += get_double();
	printf("Scholarship/Bursaries (per semester):");
	*p_OtherInc += get_double();
	printf("Other:");
	*p_OtherInc += get_double();


}


//report
void display_report(double school, double living, double trans, double otherExp, double employ, double otherInc)
{
	printf("Student Budget Report\n");
	printf("~~~~~~~~~~~~~~~~~~~~~\n");
	printf("%25c MONTHLY %5c Annually\n", ' ', ' ');
	printf ("School Expenses: %13c%.2lf", school);
	return;
}


//validation
double get_double(void) {
    int  valid_input = 1, temp;
    double num;
    char letter;

do {
	temp = scanf("%lf%c",&num, &letter);

	if (temp == 0 || letter != '\n') {
		clear_buffer();
		printf("Error! Please enter a number:");
	} else if (num < 0) {
		printf("Only postive numbers are allowed.\nPlease re-enter:");
	} else
		valid_input = 0;
	} while (valid_input == 1);
	return num;
}


char get_char(){
    char letter1, letter2;

	scanf("%c%c", &letter1, letter2);
	while ( (letter1 != 'y' && letter1 != 'n' && letter1 != 'Y' && letter1 != 'N' ) || letter2 != '\n') {
		clear_buffer();
		printf("Error!! Please enter Y to recalculate or N to not recalculate: ");
		scanf("%c%c", &letter1, letter2);
    }
    return letter1;
}


 void clear_buffer(void) {

     while ( getchar() != '\n' ) ;  /* null statement intentional */
 }
