#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

/* This is part 1 of day 1 */

// array must be sorted for this to work
int sumOfTwo(int* numArray, int length, int key){
    int left = 0;
    int right = length - 1;
    int sum = 0;
    while (left < right){
        sum = numArray[left] + numArray[right];
        if(sum == key){
            return numArray[left]*numArray[right]; 
        }
        if(sum < key){
            ++left;
        }
        else{
            --right;
        }
    }
}

int sumOfThree(int* numArray, int length, int key){
    int left = 0;
    int right = length - 1;
    int middle = 1;
    int sum = 0;
    while(left < middle){
        while(middle < right){
            sum = numArray[left] + numArray[middle] + numArray[right];
            if(sum == key){
                return numArray[left]*numArray[middle]*numArray[right];
            }
            if(sum < key){
                ++middle;
            }
            else{
                --right;
            }
        }
        // solution not found. move left pointer by one. Reset other pointers
        ++left;
        middle = left + 1;
        right = length - 1;

    }
}

int main(){
    int i = 0;
    int numbers[200]; // can try to genralize later
    std::ifstream inputFile("input.txt");
    while(!inputFile.eof()){
        inputFile >> numbers[i];
        ++i;
    }
    inputFile.close();

    // sort array
    int len = sizeof(numbers)/sizeof(numbers[0]);
    std::sort(numbers, numbers + len);

    std::cout << "Sum of two: " << sumOfTwo(numbers, len, 2020) << '\n';
    std::cout << "Sum of three: " << sumOfThree(numbers, len, 2020) << '\n';
}