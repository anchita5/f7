

#include <stdio.h>

#pragma warning(disable : 4996) // required by Visual Studio

int main(void)
{
    FILE* fptr = NULL; // File pointer for text file

    /*Text file open */
    if ((fptr = fopen("myTextFile.txt", "w")) != NULL) // Open file and check for error
    {
        int counter = 0;

        while (counter < 2)
        {
            if (fprintf(fptr, "This is line %d\n", counter + 1) < 0) // Write file and check for error simultaneously
            {
                printf("Error writing to file"); // If error in writing to file, print error message and exit code
                return -2;
            }
            counter++;
        }

        if (fclose(fptr) != 0)
        {
            printf("Error closing file"); // Print error message and exit if file failed to close
            return -1;
        }
    }
    else
    {
        printf("Error opening file"); // Print error message and exit if file failed to open
        return -1;
    }


    return 0;
}