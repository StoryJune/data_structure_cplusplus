/*
Lab 1 
Problem 1
CS 008 - Jason Li
*/

#include <iostream>
#include <fstream>
using namespace std;

//Constraints: use a static array of size 20 

//Function that returns file name
string fileName(){
    string name;
    cout << "Enter input file name: ";
    cin >> name; 

    return name;
}

//Function that sorts out the array passed 
//Numb of int needs to be reset after every sequence check 
void longestSeqNumb(int arr[], int size){
    int seqIndex = 0;
    int numbOfIntCurr = 1;
    int numbOfIntGlobal = 1;

    for(int i = 0; i < size - 1; i++){
        //Point to first in array and the integer next to it, and traverse through array
        int* ptr = arr + i; 
        int* next = ptr + 1;

        //If the the number is less than the next, increment to
        //keep track # of int in sequence
        if(*next > *ptr){
            numbOfIntCurr++;
        }else{//Reset in search
            numbOfIntCurr = 1;
        }

        //Check for the highest number in sequence
        //and set the index to print the sequence
        if(numbOfIntCurr > numbOfIntGlobal){
            numbOfIntGlobal = numbOfIntCurr;
            seqIndex = (i + 2) - numbOfIntGlobal;
        }
    }

    //Brute check for this particular scenerio where theres only 1 sequence
    if(numbOfIntGlobal == 1){
        seqIndex = 0;
    }

    //Print statements
    cout << "Longest consecutive increasing sequence: ";

    for(int i = seqIndex; i < seqIndex + numbOfIntGlobal; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Number of integers in longest sequence: " << numbOfIntGlobal;
}


int main() {
    //Initialize array for data 
    int size = 20;
    int numbArr[size];
    int data; 

    //Opens file corresponding to fileName
    ifstream file(fileName());

    //Check
    if(!file){
        cout << "Failed to open file, fileName invalid" << endl;
    }

    //Transporting by index
    for(int i = 0; i < size; i++){
        file >> numbArr[i];
    }

    longestSeqNumb(numbArr, size);

    file.close();

    return 0;
}