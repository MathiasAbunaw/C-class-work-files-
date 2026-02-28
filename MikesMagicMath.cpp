#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    unsigned long long int maxValue = 100000000;//This will be the max value it will iterate throughout the code

    vector<int>arr(maxValue+1,0); //This creates and array with the maxValue of index all set to the number 0

    for(unsigned long long int i =1; i <= maxValue; i++){//This iterate through the number from 1- maxValues 

        unsigned long long int currentNum;//used inroder to store in the current values until it reaches 1

        currentNum = i; //sets the currentNum equal to the i which is the number we are starting withinorder to find if it reaches 1
        vector<int>path; // this creates an array names path inorder to store the path of number from i--> 1 
        
        while (currentNum != 1){

            if ( (currentNum <= maxValue) && (arr[currentNum] != 0)){; //This checks whether the currentNum does not surpass the max amount of index as well as the value at that index does  not equal 1 
                arr[i] = 1;
                break;
                //If the current number already has 1 stored then it was just set the i equal to 1 or "magic"
            }
            if ((currentNum & 1) == 0){ // This is the same as checking whether it is even but faster. because for byest if is it even the bits would end with zero else it would end in 1
                currentNum >>=1;//this just the same as moving the bit by 1 place for example 8= 1000bit so when you move it by one you get 4 = 0100 which is just the same as 8/2 but faster
                
                path.push_back(currentNum);//Stores the current value within the path array
            }
            else{
                currentNum = (((currentNum * 3) + 1)) / 2;
                path.push_back(currentNum); //Stores the current value within the path array
            }
    }
        if (currentNum == 1){//if current equal to one then we set the index of i equal to 1 or magic
            arr[i] = 1; 
        }
        for (unsigned long long int j=0; j < path.size(); j++){ // Goes through the entire path array and get its value
            if (path[j] <= maxValue){//this checks whether if the value in path is creater than maxValue so we know its index is not greater than max value
                arr[path[j]] = 1;
            }
        }
        
    }   
}
