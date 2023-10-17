#include <iostream>
using namespace std;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
string name1,name2;
int choice;
int row,column;
char turn = 'X';
bool draw = false;
char response('y');

// This function is used to make the basic structure of the game

void structure(){

    //Game Board LAYOUT
    cout<<"\n\n";
    cout<<name1<<" is [X]\t"<<name2<<" is [O]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}

//Function to get the player input and update the board

void player_turn(){
    if(turn == 'X'){
        cout<<"\n"<<name1<<"'s turn [X] : ";
    }
    else if(turn == 'O'){
        cout<<"\n"<<name2<<"'s turn [O] : ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    cin>> choice;

    //switch case to get which row and column will be update

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[row][column] = 'O';
        turn = 'X';
    }else {
        //if input position already filled
        cout<<"Box already filled!\nPlease choose another!!\n\n";
        player_turn();
    }
    structure();
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool checking(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //Checking the if game already draw
    draw = true;
    return false;
}
//resetting the gameboard to play again
void reset_board()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j]='1'+i*3+j;
        }
    }
}
void play()
{
    cout<<"Enter the name of first player:";
    cin>>name1;
    cout<<"Enter the name of second player:";
    cin>>name2;
    while(checking()){
        structure();
        player_turn();
        checking();
    }
    if(turn == 'X' && draw == false){
        cout<<name2<<" has won the game!!!!";
    }
    else if(turn == 'O' && draw == false){
        cout<<name1<<" has won the game!!!!";
    }
    else 
    {
    cout<<"\n\n It's a DRAW!!!\n\n";
    }
    //play again funtion
   char res;
    int count=0;
    while(count==0)
    {
        cout<<"\nDo you want to play again(y/n)?";
        cin>>res;
        if(res=='y'|| res=='Y')
        {
            reset_board();
            turn = 'X';
            play();
        }
        else
        {
            cout<<"Thanks for playing!!!";
            count++;
        }
        count++;
    }
}

int main()
{
    cout<<"Do you want to play the game(y/n)?";
    cin>>response;
    if(response=='y'|| response=='Y')
    {
        play();
    }
    else
    {
        cout<<"Thanks for playing!!!";
}
}
