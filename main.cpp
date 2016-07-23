#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//A program to experiment to wonderfulness of pointers

void dtSize();
void passByRefAndValue(); 
void passByValue(int value);
void passByRef(int* refPass);
void arrays1D();
void heapDemo();
void arrays2D();

int main()
{
    //Prints the sizes of different data types
  // dtSize();

    //Example of passing a variable by value and by reference
   // passByRefAndValue();

    //Creating and manipulating 1D arrays
   // arrays1D();

    //Example of using the heap
   // heapDemo();

    //Creating and manipulating 2D arrays
   // arrays2D();

    return 0;

}

void dtSize()
{
    //Print out size of various datatypes
    char c = 'h';
    int i = 7;
    int *p = &i;
    float f = 12.511231541;
    double d = 27.123654789741257;
    short s = 5.65487;


    cout << "the size of char in bytes is: " << sizeof(c) << " bytes"<< endl;
    cout << "the size of int in bytes is: " << sizeof(i) << " bytes"<< endl;
    cout << "the size of float in bytes is: " << sizeof(f) << " bytes"<< endl;
    cout << "the size of double in bytes is: " << sizeof(d) << " bytes"<< endl;
    cout << "the size of short in bytes is: " << sizeof(s) << " bytes"<< endl;
    cout << "the size of pointer in bytes is: " << sizeof(p) << " bytes"<< endl;

}

void passByRefAndValue() 
{
        //Pass by value
    int meat = 7;
    int veg = 10;

    passByValue(meat);
    passByRef(&veg);

    cout << "The value of meat: " << meat << endl;
    cout << "The value of veg: " << veg << endl;
}

void add2dArrays(int* arrayA, int* arrayB)
{


}


void passByValue(int value)
{
// This function will use the pass by value with is just a copy
// Change the value of meat
    value = 27;

}

void passByRef(int *refPass)
{
//This function takes in a pointer to pass by reference
// Pass by reference changes the value of a variable by the memeory address
//Can be more unsafe but improved performance
    *refPass = 20;
}

void arrays1D()
{
    //fun with arrays

    int x[] = {1,5,7,12,13};
    double bigA[30];

    //number of elements in the array
    //cout << "number of elements in the array " << sizeof(bigA) / sizeof(bigA[0]) << endl;

    for(int i = 0; i < (sizeof(x) / sizeof(x[0])); i++ )
    {
        printf("x[%d] \t %p \t %d\n",i, &x[i], x[i]);
    }

    //dereference the pointer
    printf("x \t \t %p \n", x);

    //dereference the index of the array
    printf("x+2 \t \t %d \n",*(x+2));

    //Do some large matrix math
    unsigned short int arraySize= 10000;
    int *outputArray;
    int *inputArrayA;
    int *inputArrayB;

    //printf("Enter the size of the array");
    //scanf("%d", &arraySize);

    //Give them some space

    outputArray = (int *) malloc(arraySize* sizeof(int));
    inputArrayA = (int *) malloc(arraySize* sizeof(int));
    inputArrayB = (int *) malloc(arraySize* sizeof(int));

    //Seed the random numbers
    srand(time(NULL));

    //fill A and B with random numbers
    for(int i = 0; i < arraySize; i++){
        inputArrayA[i] = rand() % 50 + 1; //Between 1 and 50
        inputArrayB[i] = rand() % 50 + 1;

        //Add the numbers together
        outputArray[i] = inputArrayA[i] + inputArrayB[i];

        //print out the result
        printf("A: %d \t B: %d \t out: %d \n", inputArrayA[i], inputArrayB[i], outputArray[i]);
    }

    free(outputArray);
    free(inputArrayA);
    free(inputArrayB);
}

void heapDemo()
{
    //The HEAP!!

    int *points;

    points = (int *) malloc(5 * sizeof(int));

    free(points);
}

void arrays2D() 
{

    //now do some larger matrix math
    unsigned short int arraySize= 100;
    //printf("Enter the size of the array");
    //scanf("%d", &arraySize);

    int outputArray[arraySize][arraySize];
    int inputArrayA[arraySize][arraySize];
    int inputArrayB[arraySize][arraySize];

    //Seed the random numbers
    srand(time(NULL));

    //fill A and B with random numbers
    for(int i = 0; i < arraySize; i++){
        for (int j = 0 ; j < arraySize; j++) {
            inputArrayA[i][j] = rand() % 50 + 1; //Between 1 and 50
            inputArrayB[i][j] = rand() % 50 + 1;
        }
    }

    for (int i = 0; i < arraySize; i++){
        for (int j = 0; j < arraySize; j++){
             outputArray[i][j] = inputArrayA[i][j] + inputArrayB[i][j];
        }
    }

    for (int i = 0; i < arraySize; i++){
        for (int j = 0; j < arraySize; j++){
             printf("%d \t", outputArray[i][j]);
        }
        printf("\n");

    }

}


