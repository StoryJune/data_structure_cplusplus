/*
Lab 2 
Problem 1
CS 008 - Jason Li
*/

#include <iostream>

using namespace std;

/*Restraints:
    - must use two pointers
    - ptr1 points to first element
    - ptr2 points to the last 
    - if *ptr1 > *ptr2 swap values
    - move ptr1+1 n ptr2-1 until ptr1==ptr2
*/

void rearrange(int* firstIndex, int size){
    //head pointer
    int* ptr1 = firstIndex;
    //tail pointer
    int* ptr2 = (firstIndex + size) - 1;

    while(ptr1 < ptr2){
        if(*ptr1 > *ptr2){
            int temp = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = temp; 
        }
        ptr1++; 
        ptr2--;
    }
}

void print(int* firstIndex, int size){
    int* walk = firstIndex; 
    
    cout << "{ ";
    for(int i = 0; i < size; i++){
        cout << *walk << ", ";
        walk++;
    }
    cout << "}\n";
}

int main(){
    int data[] = { 3, 5, 7, 9, 2, 1, 8, 4, 6 }; 
    int size = sizeof(data) / sizeof(data[0]);

    print(data, size);
    rearrange(data, size);
    print(data, size);
    
    return 0;
}