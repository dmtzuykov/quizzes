#include <cstdlib>
#include <iostream>
#include <vector>       //for vector
#include <algorithm>    //min
using namespace std;


int MinCoins(vector<int> coins, int targetChange){
    //variable declarations
    int i, j;
    int uniqueCoins = coins.size();
    int table[uniqueCoins][targetChange+1];
    
    
    //Fill in base case --> 0 coins for 0 change 
    for(int i=0; i<uniqueCoins; i++){
        table[i][0]=0;
    }
    
    for(i=0; i<uniqueCoins; i++){ //making table
        for(j=0; j<=targetChange; j++){
            if(j>=coins[i]){ // only check values less then coin val
                for(int k=i; k<uniqueCoins; k++){ // update current value and all others below
                     table[k][j] = table[i][j-coins[i]]+1; //new min using new coin
                }
            }
        }
    }
     
    //uncomment below to print table
    for(i=0; i<uniqueCoins; i++){
        for(j=0; j<=targetChange; j++){
                cout<<table[i][j]<<" ";
        
        }         
        cout<<endl;
    }
    
    
    return table[uniqueCoins-1][targetChange];
}






int main() {
	// your code goes here
    static const int arr[] = {1,2,3,5};
    vector<int> coins (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    int targetChange=9;
    cout<<"Minimum coins needed to make "<<targetChange<<" is "<<MinCoins(coins, targetChange)<<endl;
    return 0;
}