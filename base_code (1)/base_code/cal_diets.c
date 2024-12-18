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
     while (fscanf(file, "%s %d", diet_list[diet_list_size].food_name, &diet_list[diet_list_size].calories_intake) != EOF)
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

void inputDiet(HealthData* health_data) 
{
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    for (i=0; i < diet_list_size; i++)
     // Run iterative loops to process all data sequentially. Processes from i=0 until less than diet_list_size - Minseo/ 2024.12.11
    {
    	printf("%d. %s (%d kcal)\n", i + 1 , diet_list[i].food_name, diet_list[i].calories_intake);
    	 // Output of data for array index "(integer - List number, string - foodname, integer - calories information for current food) " Output in form - Minseo/ 2024.12.11
    	 // For statement i is a variable representing the number of the list, so write i rather than i+1 - Minseo/ 2024.12.11
    	 // The above sentence is incorrect - Minseo / 2024.12.18
    	 // To display list numbers starting from 1, add 1 to i, which represents the index, and output it as i+1 - Minseo / 2024.12.18
	}
	
	printf("0. Exit\n"); // "0. Exit" Create exit options by printing exit options. - Minseo/ 2024.12.11
    
    
	// ToCode: to enter the diet to be chosen with exit option
    printf("Select a diet by number: ");
     // Select food by number - Minseo/ 2024.12.11
    scanf("%d", &choice);
     //Read the entered numeric variable in integer form and save it in the choice variable - Minseo/2024.12.11
    if (choice == 0)
	    return;     // If the number entered by the user is 0, exit the selection and exit immediately - Minseo/ 2024.12.11
	if (choice < 1 || choice > diet_list_size) 
	 // The condition that the input is invalid when the number entered by the user is less than 1 or greater than the number in diet_list_size - Minseo/ 2024.12.11
	 // If the number 0 is entered, it is processed in the previous if statement, so 0 is excluded from the condition. - MINSEO/ 2024.12.11
	{
		printf("[Error] Invalid choice. Please try again.\n");
		//Statement output that informs incorrect input and prompts retries. - Minseo/ 2024.12.11
		return;
	}
	    

    // ToCode: to enter the selected diet in the health data
    health_data->diet[health_data->diet_count] = diet_list[choice - 1];
     //Specify an index to store the content by pointing to the diet_count variable in the health_data structure in the diet array in the health_data structure. - Minseo/ 2024.12.15
     // To get the index of the number selected by the user, use 'choice -1' - Minseo / 2024.12.18  
	health_data->diet_count++;
	 //Increase diet_count variable by 1 in health_data structure: increase number of indexes. - Minseo/ 2024.12.15 


    // ToCode: to enter the total calories intake in the health data
    health_data->total_calories_intake += diet_list[choice - 1].calories_intake;
     //Calculate the final calories intake by adding the calories intake of the food entered by the user to the total_calories_intake variable in the health_data structure. - Minseo / 2024.12.15
     // To get the index of the number selected by the user, use 'choice -1' - Minseo / 2024.12.18 
	
	printf("You comsumed %d kcal from %s.\n", diet_list[choice - 1].calories_intake, diet_list[choice - 1].food_name);
	 //Calories intake from the selected food in the food list is displayed on the screen. - Minseo / 2024.12.15
	 // To get the index of the number selected by the user, use 'choice -1' - Minseo / 2024.12.18 


}

