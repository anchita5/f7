

#include <stdio.h>

#pragma warning(disable : 4996) // required by Visual Studio

int main(void)
{
    FILE* fptr = NULL; // File pointer for text file

    FILE* fbPtr = NULL;

    const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };

    /*Text file open */
    if ((fptr = fopen("myTextFile.txt", "w")) != NULL) 
    {
        int counter = 0;

        while (counter < 2)
        {
            if (fprintf(fptr, "This is line %d\n", counter + 1) < 0) 
            {
                printf("Error writing to file"); 
                return -2;
            }
            counter++;
        }

        if (fclose(fptr) != 0)
        {
            printf("Error closing file"); 
            return -1;
        }
    }
    else
    {
        printf("Error opening file"); 
        return -1;
    }


    /*Writing to binary file functionality */

    if ((fbPtr = fopen("myEvenDataList.data", "wb")) != NULL)
    {
        int lengthOfArray = sizeof(kBinaryData) / sizeof(kBinaryData[0]);
        int counter = 0;

        while (counter < lengthOfArray)
        {
            if (kBinaryData[counter] % 2 == 0)
            {
                if ((fwrite(&kBinaryData[counter], sizeof(unsigned short), 1, fbPtr)) < 1)
                {
                    printf("Error writing to file");
                    return -1;
                }
            }
            counter++;
        }

        if (fclose(fbPtr) != 0)
        {
            printf("Error closing file");
            return -1;
        }
    }
    else
    {
        printf("Error opening binary file");
        return -1;
    }


    return 0;
}