/*
1.6 Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degrees. Can you do this in place?
_
*/

#include <iostream>
using namespace std;

const int N = 4;
void swapRow(int image[N][N]){
    for(int i = 0,j = N-1; i<j; i++,j--){
        for(int k = 0 ;  k < N ; k++){
            int temp = image[i][k];
            image[i][k] = image[j][k];
            image[j][k] = temp;
        }
    }
}

void print(int image[N][N]){
    cout << endl;
    for(int i = 0 ; i < N;i++){
        cout << endl;
        for(int j=0;j<N;j++){
                cout << image[i][j] << " ";
            }
        }
    cout << endl;
}

void diag(int image[N][N]){
    
    for(int i = 0 ; i < N;i++){
        for(int j=i;j<N;j++){
            int temp = image[i][j];
            image[i][j] = image[j][i];
            image[j][i] = temp;
        }
    }
    
}


void rotateLeft(int image[N][N]){
    print(image);
    diag(image);
    swapRow(image);
    print(image);
}




int main(){
    
    int image[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    rotateLeft(image);

    return 0;
}