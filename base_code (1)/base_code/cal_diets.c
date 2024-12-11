//
//  cal_diets.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt"
*/

void loadDiets(const char* DIETFILEPATH)
{
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) 
	{
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while (fscanf(file, "%s %d", diet_lsit[diet_list_size].food_name, &diet_list[diet_list_size].calories_intake) != EOF)
     // Read the food name data as a string from the file and save it to diet_list[diet_list_size].food_name - Minseo/ 2024.12.11
     // Read the calorie information in integer form from the file and save it to diet_list[diet_list_size].calories_intake - Minseo/ 2024.12.11
    
	 {  diet_list_size++; // When a pair of data is read, it moves to the next index in the array. - Minseo/2024.12.11
    	
        if (diet_list_size >= MAX_DIETS)
		{
        	break;
		}
    }
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    for (i=0; i < diet_list_size; i++)
     // Run iterative loops to process all data sequentially. Processes from i=0 until less than diet_list_size - Minseo/ 2024.12.11
    {
    	printf("%d. %s (%d kcal)\n", i, diet_list[i].food_name, diet_list[i].calories_intake);
    	 // Output of data for array index "(integer - List number, string - foodname, integer - calories information for current food) " Output in form - Minseo/ 2024.12.11
	}
	
	printf("0. Exit\n"); // "0. Exit" Create exit options by printing exit options. - Minseo/ 2024.12.11
    
    
	// ToCode: to enter the diet to be chosen with exit option
    printf("Select a diet by number: ");
     // Select food by number - Minseo/ 2024.12.11
    scanf("%d", &choice);
     //Read the entered numeric variable in integer form and sane it in the choice variable - Minseo/2024.12.11
    if (choice == 0)
	    return;     // If the number entered by the user is 0, exit the selection and exit immediately - Minseo/ 2024.12.11
	if (choice < 1 || choice > diet_list_size) 
	 // The condition that the input is invalid when the number entered by the user is less than 1 or greater than the number in diet_list_size - Minseo/ 2024.12.11
	 // If the number 0 is entered, it is processed in the previous if statement, so 0 is excluded from the condition. - MINSEO/ 2024.12.11
	{
		printf("[Error] Invalid choice. Please try again.\n");
		//Statement output that informs incorrect input and prompts retries. - Minseo/ 2024.12.11
	}
	    

    // ToCode: to enter the selected diet in the health data
    

    // ToCode: to enter the total calories intake in the health data


}

