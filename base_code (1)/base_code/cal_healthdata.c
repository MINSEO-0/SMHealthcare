//
//  cal_healthdata.c
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


/*
    description : enter the exercise and diet history in "health_data.txt" 
    input parameters : health_data - data object in which the selected exercise and diet is stored
    return value : No
    
    operation : 1. save the chosen exercise and total calories burned 
    			2. save the chosen diet and total calories intake 
    			3. save the total remaining calrories
*/

void saveData(const char* HEALTHFILEPATH, const HealthData* health_data) 
{
	int i;
    FILE* file = fopen(HEALTHFILEPATH, "w");
    if (file == NULL)
	{
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
    for(i = 0; i < health_data->exercise_count; i++)
     // Run iterative loops to process all data sequentially. Processes from i=0 until less than health_data->exercise_count(number of exercise) - Minseo / 2024.12.15
    {
    	fprintf(file, "%s - %d kcal\n", health_data->exercises[i].exercise_name, health_data->exercises[i].calories_burned_per_minute);
		 //Retrieves the exercise name from the exercise array in the health_data structure and the calories burned per minute information from the exercise array in the health_data structure and written to a file. - Minseo / 2024.12.18 
	}
	fprintf(file, "Total calories burned: %d kcal\n", healt_data->total_calories_burned);
	 // Take the total_calories_burned variable from the health_data structure and log the total calories burned to a file. - Minseo / 2024.12.18
    
    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");
    for(i = 0; i < health_data->diet_count; i++)
     // Run iterative loops to process all data sequentially. Processes from i=0 until less than health_data->diet_count(number of diets) - Minseo / 2024.12.18
	{	
    	fprintf(file, "%s - %d kcal\n", health_data->diet[i].food_name, health_data->diet[i].calories_intake);
    	 //Retrieves the diets name from the diet array in the health_data structure and the calories_intake information from the diet array in the health_data structure and written to a file. - Minseo / 2024.12.18
	}
	fprintf(file, "Total calories intake: %d kcal\n", health_data->total_calories_intake);
	 //Take the total_calories_intake variable from the health_data structure and log the total calories intake and kcal to a file - Minseo / 2024.12.18


    // ToCode: to save the total remaining calories
    fprintf(file, "\n[Total] \n");
    int remaining_calories;        // Specify remaining_calories variable - Minseo / 2024.12.18
    remaining_calories = health_data->total_calories_intake - BASAL_METABOLIC_RATE - health_data->total_calories_burned;
     // How to calculate remaining calories - Minseo / 2024.12.18
     // The remaining calories are calculated as tatal_calories_intake - BASAL_METABOLIC_RATE - total_calories_burned - Minseo / 2024.12.18
    fprintf(file, "Basal metabolic rate: %d kcal\n", BASAL_METABOLIC_RATE);
	 // Record basal metabolic rate in integer format to file - Minseo / 2024.12.18
	fprintf(file, "The remaining calories: %d kcal\n", remaining_calories);
	 // Record the remaining calories in integer format to file - Minseo / 2024.12.18
	 
	fclose(file);   
     // Close the file to finally save the data in the file - Minseo/ 2024.12.18
}

/*
    description : print the history of exercised and diets
    input parameters : health_data - data object in which the history of the exercise and diet is to be printed
    return value : No
    
    operation : 1. print out the saved history of exercises
    			2. print out the saved history of diets
    			3. print out the saved history of calories
*/

void printHealthData(const HealthData* health_data) {
	int i;
	
	// ToCode: to print out the saved history of exercises
	printf("=========================== History of Exercise =======================\n");
  
  
    printf("=======================================================================\n");

    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");


    printf("=======================================================================\n");


	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
 
 
    printf("=======================================================================\n \n");
    
	
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    
    
	 printf("=======================================================================\n");
}
