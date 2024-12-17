//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
     //Import data from external files - Minseo / 2024.12.18
    loadExercises(EXERCISEFILEPATH);
	 // Import exercise data from external files. - Minseo / 2024.12.18
	loadDiets(DOETFILEPATH);
	 //Import diets data from external files. - Minseo / 2024.12.18  

    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do {
    	int remaining_calories;        // Specify remaining_calories variable - Minseo / 2024.12.18
        remaining_calories = health_data->total_calories_intake - BASAL_METABOLIC_RATE - health_data->total_calories_burned;
         // How to calculate remaining calories - Minseo / 2024.12.18
         // The remaining calories are calculated as tatal_calories_intake - BASAL_METABOLIC_RATE - total_calories_burned - Minseo / 2024.12.18
    		
    	if (remaining_calories == 0) // When remaining_calories are 0 - Minseo / 2024.12.18
		{
            printf("You have consumed all your calories for today! \n");
             // Displays on the screen that all calories for today have been consumed - Minseo / 2024.12.18
            break;
             // If the remaining calories are 0, the program ends immediately. - Minseo / 2024.12.18
		} 
		
		else
		{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	
                break;
                
            case 2:
            	
                break;
                
            case 3:
            	
                break;
                
            case 4:
            	
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while ( );

    return 0;
}

