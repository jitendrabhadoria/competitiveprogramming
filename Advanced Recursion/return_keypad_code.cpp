#include <iostream>
using namespace std;

int keypad(int code, string output[]) {
	if (code == 0 || code == 1) {
		output[0] = "";
		return 1;
	}

	int newNumber = code/10;
    int currentNumber = code%10;
	int tempOutputSize = keypad(newNumber, output);
    
    switch(currentNumber){
        case 2 :for(int j = 1; j<=3 ; j++ ){
            		for (int i = 0; i < tempOutputSize; i++) {
                        if(j==1){
                            output[i + (tempOutputSize*j)] = output[i] + "a";
                        } else if(j==2){
                            output[i + (tempOutputSize*j)] = output[i] + "b";
                        } else if(j==3){
                            output[i + (tempOutputSize*j)] = output[i] + "c";
                        }
					}
        		}
            	return 4 * tempOutputSize;
            	break;
        case 3 :for(int j = 1; j<=3 ; j++ ){
            		for (int i = 0; i < tempOutputSize; i++) {
                        if(j==1){
                            output[i + (tempOutputSize*j)] = output[i] + "d";
                        } else if(j==2){
                            output[i + (tempOutputSize*j)] = output[i] + "e";
                        } else if(j==3){
                            output[i + (tempOutputSize*j)] = output[i] + "f";
                        }
					}
        		}
            	return 4 * tempOutputSize;
            	break;
        case 4 :for(int j = 1; j<=3 ; j++ ){
            		for (int i = 0; i < tempOutputSize; i++) {
                        if(j==1){
                            output[i + (tempOutputSize*j)] =  output[i]+"g";
                        } else if(j==2){
                            output[i + (tempOutputSize*j)] =   output[i]+"h";
                        } else if(j==3){
                            output[i + (tempOutputSize*j)] =   output[i]+"i";
                        }
					}
        		}
            	return 4 * tempOutputSize;
            	break;
        case 5 :for(int j = 1; j<=3 ; j++ ){
            		for (int i = 0; i < tempOutputSize; i++) {
                        if(j==1){
                            output[i + (tempOutputSize*j)] =   output[i]+"j";
                        } else if(j==2){
                            output[i + (tempOutputSize*j)] =   output[i]+"k";
                        } else if(j==3){
                            output[i + (tempOutputSize*j)] =   output[i]+"l";
                        }
					}
        		}
            	return 4 * tempOutputSize;
            	break;
        case 6 :for(int j = 1; j<=3 ; j++ ){
            		for (int i = 0; i < tempOutputSize; i++) {
                        if(j==1){
                            output[i + (tempOutputSize*j)] =   output[i]+"m";
                        } else if(j==2){
                            output[i + (tempOutputSize*j)] =  output[i]+ "n";
                        } else if(j==3){
                            output[i + (tempOutputSize*j)] =  output[i]+"o";
                        }
					}
        		}
            	return 4 * tempOutputSize;
            	break;
        case 7 :for(int j = 1; j<=4 ; j++ ){
            		for (int i = 0; i < tempOutputSize; i++) {
                        if(j==1){
                            output[i + (tempOutputSize*j)] =   output[i]+"p";
                        } else if(j==2){
                            output[i + (tempOutputSize*j)] =   output[i]+"q";
                        } else if(j==3){
                            output[i + (tempOutputSize*j)] =   output[i]+"r";
                        } else if(j==4){
                            output[i + (tempOutputSize*j)] =   output[i]+"s";
                        }
					}
        		}
            	return 5 * tempOutputSize;
            	break;
        case 8 :for(int j = 1; j<=3 ; j++ ){
            		for (int i = 0; i < tempOutputSize; i++) {
                        if(j==1){
                            output[i + (tempOutputSize*j)] =   output[i]+"t";
                        } else if(j==2){
                            output[i + (tempOutputSize*j)] =   output[i]+"u";
                        } else if(j==3){
                            output[i + (tempOutputSize*j)] =   output[i]+"v";
                        }
					}
        		}
            	return 4 * tempOutputSize;
            	break;
        case 9 :for(int j = 1; j<=4 ; j++ ){
            		for (int i = 0; i < tempOutputSize; i++) {
                        if(j==1){
                            output[i + (tempOutputSize*j)] =   output[i]+"w";
                        } else if(j==2){
                            output[i + (tempOutputSize*j)] =   output[i]+"x";
                        } else if(j==3){
                            output[i + (tempOutputSize*j)] =   output[i]+"y";
                        } else if(j==4){
                            output[i + (tempOutputSize*j)] =   output[i]+"z";
                        }
					}
        		}
            	return 5 * tempOutputSize;
            	break;
    }
}

int main() {
    
    int t;
    cin >> t;
    while(t--){
        int code;
        cin >> code;
        int temp = code;
        int countDig = 0;
        while(temp>0){
            countDig++;
            temp= temp/10;
        }
        string* output = new string[1000000];
        int count = keypad(code, output);
        for (int i = 0; i <=count; i++) {
            if(output[i].size()==countDig)
           		cout << output[i] << endl;
        }
    }
	
}
