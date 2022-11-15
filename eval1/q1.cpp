#include <iostream>
using namespace std;


int main(){
    int N, K;
    cin >> N >> K;
    int arr[N][N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                cin >> arr[i][j][k];
                // cout << arr[i][j][k] << endl;
            }
        }
    }

    for(int m = 0; m < K; m++){
        // Back Rotation
        int temp = arr[0][0][0];
        int t2;
        arr[0][0][0] = arr[N-1][N-1][N-1];
        for(int j = 0; j < N; j++){
            for(int i = 0, k = 0; i < N; i++, k++){
                if(i == 0 && j == 0 && k == 0) continue;
                t2 = arr[i][j][k];
                arr[i][j][k] = temp;
                temp = t2;
            }
            j++;
            if(j >= N) continue;
            for(int i = N-1, k = N-1; i >= 0; i--, k--){
                if(i == 0 && j == 0 && k == 0) continue;
                t2 = arr[i][j][k];
                arr[i][j][k] = temp;
                temp = t2;
            }
        }

        // Forward Rotation
        temp = arr[N-1][0][0];
        arr[N-1][0][0] = arr[0][N-1][N-1];
        for(int j = 0; j < N; j++){
            for(int i = N-1, k = 0; i >= 0; i--, k++){
                if(i == N-1 && j == 0 && k == 0) continue;
                t2 = arr[i][j][k];
                arr[i][j][k] = temp;
                temp = t2;
            }
            j++;
            if(j >= N) continue;
            for(int i = 0, k = N - 1; i < N; i++, k--){
                t2 = arr[i][j][k];
                arr[i][j][k] = temp;
                temp = t2;
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                cout << arr[i][j][k] << " ";
            }
        }
    }
    cout << '\b';

    return 0;
}