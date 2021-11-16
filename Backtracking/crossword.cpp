// Crossword Problem
// Send Feedback
// Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
// For example, The following is an example for the input crossword grid and the word list.
// +-++++++++
// +-++-+++++
// +-------++
// +-++-+++++
// +-++-+++++
// +-++-+++++
// ++++-+++++
// ++++-+++++
// ++++++++++
// ----------
// CALIFORNIA;NIGERIA;CANADA;TELAVIV
// Output for the given input should be:
// +C++++++++
// +A++T+++++
// +NIGERIA++
// +A++L+++++
// +D++A+++++
// +A++V+++++
// ++++I+++++
// ++++V+++++
// ++++++++++
// CALIFORNIA
// Note: We have provided such test cases that there is only one solution for the given input.
// Input format:
// The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
// The next line of input contains the word list, in which each word is separated by ';'. 
// Output format:
// Print the crossword grid, after placing the words of word list in '-' cells.  
// Constraints
// The number of words in the word list lie in the range of: [1,6]
// The length of words in the word list lie in the range: [1, 10]
// Time Limit: 1 second
// Sample Input 1:
// +-++++++++
// +-++-+++++
// +-------++
// +-++-+++++
// +-++-+++++
// +-++-+++++
// ++++-+++++
// ++++-+++++
// ++++++++++
// ----------
// CALIFORNIA;NIGERIA;CANADA;TELAVIV
// Sample Output 1:
// +C++++++++
// +A++T+++++
// +NIGERIA++
// +A++L+++++
// +D++A+++++
// +A++V+++++
// ++++I+++++
// ++++V+++++
// ++++++++++
// CALIFORNIA

#include<bits/stdc++.h>
using namespace std;

#define N 10

bool isSafeInRow(char grid[N][N], int row, int col, string currentWord){
    int j = col;
    for(int i=0;i<currentWord.length();i++){
        if(j>9){
            return false;
        }
        if(grid[row][j]=='+' || (grid[row][j]!='-' && grid[row][j] != currentWord[i])){
            return false;
        }
        if(grid[row][j]=='-' || grid[row][j]==currentWord[i]){
            j++;
        }
    }
    return true;
}
bool isSafeInColumn(char grid[N][N], int row, int col, string currentWord){
    int j = row;
    for(int i=0;i<currentWord.length();i++){
        if(j>9){
            return false;
        }
        if(grid[j][col]=='+' || (grid[j][col]!='-' && grid[j][col] != currentWord[i])){
            return false;
        }
        if(grid[j][col]=='-' || grid[j][col]==currentWord[i]){
            j++;
        }
    }
    return true;
}

void setHorizontal(char grid[N][N], string currentWord, int row, int col, vector<bool>& v){

    for(int i=0;i<currentWord.length();i++){
        if(grid[row][col+i]=='-'){
            grid[row][col+i]=currentWord[i];
            v.push_back(true);
        }
        else{
            v.push_back(false);
        }
    }  

}
void unsetHorizontal(char grid[N][N], string currentWord, int row, int col, vector<bool>& v){

    for(int i=0;i<v.size();i++){
        if(v[i]){
            grid[row][i+col]='-';
        }
    }  

}

void setVertical(char grid[N][N], string currentWord, int row, int col, vector<bool>& v){

    for(int i=0;i<currentWord.length();i++){
        if(grid[row+i][col]=='-'){
            grid[row+i][col]=currentWord[i];
            v.push_back(true);
        }
        else{
            v.push_back(false);
        }
    }


}

void unsetVertical(char grid[N][N], string currentWord, int row, int col, vector<bool>& v){

    for(int i=0;i<v.size();i++){
        if(v[i]){
            grid[row+i][col]='-';
        }
    }

}

bool solveCrossword(char grid[N][N], vector<string> words, int index){
   
    if(index>=words.size()){
        for(int i = 0 ; i<N ; i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
        return true;
    }

    for(int i = 0 ; i<N ; i++){

        for(int j = 0 ; j<N ; j++){

            if(grid[i][j]=='-' || grid[i][j]==words[index][0]){

                if(isSafeInRow(grid,i,j,words[index])){

                    vector<bool> helper;

                    setHorizontal(grid,words[index], i, j, helper);

                    if(solveCrossword(grid, words, index+1)){
                        return true;
                    }

                    unsetHorizontal(grid,words[index], i, j, helper);

                } 
                if(isSafeInColumn(grid,i,j,words[index])){

                    vector<bool> helper;

                    setVertical(grid,words[index], i, j, helper);

                    if(solveCrossword(grid, words,index+1)){
                        return true;
                    }
                    
                    unsetVertical(grid,words[index], i, j, helper);
                } 
            }
        }
    }

    return false;
}

int main(){

    //crossword grid
    char grid[N][N]; 

    //reading crossword values
    for(int i = 0 ; i<N ; i++){
        for(int j=0;j<N;j++){
            cin>>grid[i][j];
        }
    }

    //reading words
    string str;
    cin>>str;

    //splitting the string 
    vector<string> words;
	for (int i = 0; i < str.length(); i++)
	{
		int j = i;
		while (str[j] != ';' && j < str.length())
		{
			j++;
		}
		words.push_back(str.substr(i, j - i));
		i = j;
		j++;
	}
    

    //calling solve corssword function
    bool x = solveCrossword(grid, words, 0);

    //printing solved crossword
    
    
    return 0;
}