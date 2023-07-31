#include<bits/stdc++.h>
using namespace std;
void printMatrix(char board[3][3]){
    cout<<"Current state of the game:\n\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%c",board[i][j]);
            if(j==2 && i!=2)    cout<<"\n _  _  _\n";
            if(j!=2)        cout<<" | ";
        }
        cout<<"\n";
    }
}
void insertAtPos(char board[3][3], int pos, bool flag[9],char plyr){
    while(flag[pos-1]){
        cout << "Position already occupied\n" ;
        cout << "Enter another position\n";
        cin >> pos;
    }
    flag[pos-1]=true;
    board[(pos-1)/3][((pos-1)%3)]=plyr;
}
bool rowWin(char board[3][3], char plyr){
    for(int i=0;i<3;i++){
        int c = 0;
        for(int j=0;j<3;j++){
            if(board[i][j]==plyr)   c++;
        }
        if(c==3) return true;
    }
    return false;
}
bool colWin(char board[3][3], char plyr){
    for(int i=0;i<3;i++){
        int c=0;
        for(int j=0;j<3;j++) {
            if(board[j][i]==plyr)   c++;
        }
        if(c==3) return true;
    }
    return false;
}
bool diagWin(char board[3][3], char plyr){
    int c = 0;
    for(int i=0;i<3;i++){
        if(board[i][i]==plyr){
            c++;
        }
    }
    if (c == 3) return true;
    c=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i+j==2){
                if(board[i][j]==plyr){
                    c++;
                }
            }
        }
    }
    if (c == 3) return true;
    return false;
}
void play_game(){
    char board[3][3] = 
    {' ',' ',' ',
     ' ',' ',' ',
     ' ',' ',' '};
    bool flag[9];
    for(int i=0;i<9;i++)    flag[i]=false;
    int pos,c=0;
    bool plyr1 = false, plyr2 = false;
    while(c<9){
        cout<<"\n\nFirst player Position:";
        cin>>pos;
        insertAtPos(board,pos,flag,'X');
        printMatrix(board);
        c++;
        if(rowWin(board,'X') || colWin(board,'X') || diagWin(board,'X')){
            plyr1 = true;
            break;
        }
        if(c==9)    break;    
        cout<<"\n\nSecond player Position:";
        cin>>pos;
        insertAtPos(board,pos,flag,'O');
        printMatrix(board);
        c++;
        if(rowWin(board,'O') || colWin(board,'O') || diagWin(board,'O')){
            plyr2 = true;
            break;
        }
        if(c==9)    break;
    }
    if(plyr1){
        cout<<"\nPlayer 1 Won\n";
    }
    else if (plyr2){
        cout<<"\nPlayer 2 Won\n";
    }
    else if(!plyr1 && ! plyr2){
        cout<<"Game Draw\n";
    }
    cout<<"1) Play Again??\n";
    cout<<"2) Quit\n";
    int op;cin>>op;
    if(op==1)   play_game();
    else    exit(-1);
}
int main() {
    cout<<"Welcome to Tic-Tac-Toe\n";
    cout<<"1) Play Game\n";
    cout<<"2) Exit\n";
    cout<<"Choose any Option: ";
    int op;
    while(cin>>op){
        switch(op){
            case 1:play_game();
            break;
            case 2:exit;
            break;
            default :cout<<"\nInvalid Option!!!\a"<<endl;
        }
    }
}