#include<stdio.h>

void read(FILE *file, int arr[], int *size)
{
    *size = 0;
    while(fscanf(file,"%d",&arr[*size])!=EOF)
    {
         (*size)++;
    }
}

void write(FILE *file, int arr[],int size)
{
    for(int i = 0;i<size;i++)
    {
        fprintf(file,"%d \n",arr[i]);
    }
}

void bubble(int arr[],int size)
{
    for(int i = 0;i<size;i++)
    {
        for(int j = 0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{

 int arr[100],size;
    FILE *inputfile = fopen("input.txt","r");
    FILE *outputfile = fopen("output.txt","w");

    if(inputfile == NULL || outputfile == NULL)
    {
        printf("Error opening file !\n");
        return 1;
    }



    read(inputfile, arr, &size);

    fclose(inputfile);

    bubble(arr, size);

    write(outputfile, arr, size);

    fclose(outputfile);

    printf("Numbers stored !\n");

    return 0;

}
