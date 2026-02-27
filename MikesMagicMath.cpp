#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


int main(){
    map<int, vector<int>> dict;
    unsigned long long int maxValue = 100;

    for(unsigned long long i =1; i <= maxValue; i++){
        int currentNum;
        currentNum = i;
        while (currentNum != 1){
            if (dict.find(currentNum) != dict.end()){
                dict[i].insert(dict[i].end(), dict[currentNum].begin(), dict[currentNum].end());
                break;
            }
            dict[i].push_back(currentNum); 
            if ((currentNum % 2) == 0){
                    currentNum = currentNum / 2;
            }
            else{
                currentNum = ((currentNum * 3) + 1);
            }
            dict[i].push_back(currentNum);
        }
        dict[i].push_back(1);
    }   
    for (const auto &pair : dict){
        cout << "Keys: "<< pair.first<< " | ";
        for (int num : pair.second){
            cout<<num<< "-->";
        }
        cout<<endl;
    }
}
