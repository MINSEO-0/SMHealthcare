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

int main() 
{
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
    
     //Import data from external files - Minseo / 2024.12.18
    loadExercises(EXERCISEFILEPATH);
	 // Import exercise data from external files. - Minseo / 2024.12.18
	loadDiets(DIETFILEPATH);
	 //Import diets data from external files. - Minseo / 2024.12.18  

    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do 
	{
    	int remaining_calories;        // Specify remaining_calories variable - Minseo / 2024.12.18
        remaining_calories = health_data.total_calories_intake - BASAL_METABOLIC_RATE - health_data.total_calories_burned;
         // How to calculate remaining calories - Minseo / 2024.12.18
         // The remaining calories are calculated as tatal_calories_intake - BASAL_METABOLIC_RATE - total_calories_burned - Minseo / 2024.12.18
         // Unless health_data is declared as a structure pointer, here it is a regular structure variable. - Minseo / 2024.12.18
    		
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
        	
        	 //An infinte loop occurs because no limit is set on the input value - Minseo / 2024.12.18
        	 //Condition setting process for input values - Minseo / 2024.12.18
        	while(scanf("%d", &choice) != 1)
        	 //Repeat input conditions until an integer is entered - Minseo / 2024.12.18
        	{
        		
			}
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice)
		 {
            case 1:
            	inputExercise(&health_data);
            	 //Receive exercise data and write it to the structure - Minseo / 2024.12.18
            	 // & is necessary because the memory address of the structure needs to be passed to the function - Minseo / 2024.12.18
                break;
                
            case 2:
            	inputDiet(&health_data);
            	 //Receive diet data anf write it to the structure - Minseo / 2024.12.18
            	 // & is necessary because the memory address of the structure to be passed to the function - Minseo / 2024.12.18
                break;
                
            case 3:
            	printHealthData(&health_data);
            	 // Output data stored in the structure to the screen - Minseo / 2024.12.18
            	 // Passing the address of a structure using & - Minseo / 2024.12.18
                break;
                
            case 4:
            	 //The data entered by the user must be saved before ending the program - Minseo / 2024.12.18
            	saveData(HEALTHFILEPATH, &health_data);
				 // Save entered data such as diet and exercise to a file - Minseo / 2024.12.18
				 // Use & to save data in the health_data structure to HEALTHFILEPATH - Minseo / 2024.12.18
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while (choice != 4);
       //Repeat the conditional statement until exit option 4 is not clicked - Minseo / 2024.12.18

    return 0;
}

