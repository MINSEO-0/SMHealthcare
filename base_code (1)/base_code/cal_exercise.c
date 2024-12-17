//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;


/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char* EXERCISEFILEPATH) 
{
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) 
	{
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while (fscanf(file, "%s %d", exercise_list[exercise_list_size].exercise_name, &exercise_list[exercise_list_size].calories_burned_per_minute) != EOF)
     //Read the exercise_name data as a string from the file and save it to exercise_list[exercise_list_size].exercise_name - Minseo / 2024.12.15
     //Read the calorie information in integer form from the file and save it to exercise_list[exercise_list_size].calories_burned_per_minute. - Minseo / 2024.12.15
     
	{ exercise_list_size++;  // When a pair of data is read, it moves to the next index the array. - Minseo / 2024.12.15
    	
        if (exercise_list_size >= MAX_EXERCISES)
		{
        	break;
		}
    }

    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/

void inputExercise(HealthData* health_data)
{
    int choice, duration, i;
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    for(i=0; i < exercise_list_size; i++)
     //Run iterative loops to process all data sequentially. Processes from i=0 until less than exercise_list_size - Minseo / 2024.12.15 
    {
    	printf("%d. %s (%d kcal/min)\n", i + 1 , exercise_list[i].exercise_name, exercise_list[i].calories_burned_per_minute);
    	 // Output of data for array index "(integer - list numbeer, string - exercise_name, integer - calories_burned_per_minute information for current exercise)" Output in form - Minseo / 2024.12.15 
         // To display list numbers starting from 1, add 1 to i, which represents the index, and output it as i+1 - Minseo / 2024.12.18
	}
	printf("0. Exit\n");
	 //"0. Exit" create exit options by printing exit options. - Minseo / 2024.12.15
    

    // ToCode: to enter the exercise to be chosen with exit option
    printf("Select an exercise by number: ");
     // Select exercise by number - Minseo / 2024.12.15
	scanf("%d", &choice);
	 //Read the entered numeric variable in the integer form and save it in the choice variable - Minseo / 2024.12.15  
	if(choice == 0)
	  return;       // If the number entered by the user is 0, exit the selection and exit immediately - Minseo / 2024.12.15
	if(choice < 1 || choice > exercise_list_size)
	 // The condition that the input is invalid when the number entered by the user is less than 1 or greater than the number in exerxise_list_size - Minseo / 2024.12.15
	 // If the number 0 is entered, it is processed in the previous if statement, so 0 is excluded from the condition. - Minseo / 2024.12.15
	{
		printf("[Error] Invalid choice. Please try again.\n");
		return;      // Statement output that informs incorrect input and prompts retries. - Minseo / 2024.12.15
	}  

 
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    int calories_burned;  // Declaration of Variables - Minseo / 2024.12.15
    calories_burned = exercise_list[choice].calories_burned_per_minute * duration;
     //Calculate the total calories burned by multiplying the calories burned per minute for the exercise type selected by the user by the duration entered by the user. - Minseo / 2024.12.15
    health_data->exercises[health_data->exercise_count] = exercise_list[choice];
	 //Specify an index to store the content by pointing to the exercise_count variable in the health_data structure in the exercises array in the health_data structure. - Minseo / 2024.12.15
	health_data->exercise_count++;
	 //Increase exercise_count variable by 1 in health_data structure: increase number of indexes. - Minseo / 2024.12.15
	health_data->total_calories_burned += calories_burned;
	 // Calculate the final calories burned by adding the calories_burned to the total_calories_burned  variable in the health data structure - Minseo / 2024.12.15
    
    
	printf("You burned %d kcal by %s for %d minutes.\n", calories_burned, exercise_list[choice].exercise_name, duration);
	 // Calories burned in the exercise selected by the user are displayed in integer type, exercise name is displayed in string type, and duration is displayed in integer type. - Minseo / 2024.12.15	    


}
