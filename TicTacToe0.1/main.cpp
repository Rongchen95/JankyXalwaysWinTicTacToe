#include <iostream>

//global values
char matrix [3][3] = {'1','2','3','4','5','6','7','8','9'}; //creates the board 3x3 and using char because its a just for looks
char player = 'x'; //constructor

void draw();
void inputVal();
void TogglePlayer();
char checkWin();
int main(){

    system("CLS");// does not work for clion

    std::cout<<"Tic Tac Toe \n";
    //create tally aka counter
    //create game start option

    int starter, tcnt = 0, xcnt = 0, ocnt = 0, ttcnt = 0; //used for tally marks on winner
    /*std::cout <<"press 1 to start \n";
    std::cin>>starter;*/ //make this game endless so i can use tally marks
    draw();

    while(1){
        inputVal();
        draw();
        tcnt++;
        if(checkWin() == 'x') {
            std::cout << "x wins\n";
            xcnt++;
            break;
        }
        if(checkWin() == 'o') {
            std::cout << "o wins\n";
            ocnt++;
            break;
        }
        if(checkWin() != 'x' && checkWin() != 'o' && tcnt == 9){
            std::cout <<" tie\n"; //drawbacks are that at exactly 9 moves game ends in tie no matter what
            ttcnt++;
            break;
        }
        TogglePlayer();
    }
    return 0;
}
void draw(){ //draws the board using 2d array filling every space

    for (int i= 0; i<3; i++){
        for(int j = 0; j <3; j++){
            std::cout << matrix[i][j] << " ";
        }
            std::cout<< std::endl; // to separate
    }
}
void inputVal() {
    int PosValue;
    std::cout << "Player enter position \n";
    std::cin >> PosValue;

    if(PosValue == 1){ //checks location
        if(matrix[0][0] == '1'){ //checks to see if space is filled
            matrix[0][0] = player; //insert value in space
        }
        else
            std::cout<<"spot taken \n";
    }
    else if (PosValue == 2) {
        if (matrix[0][1] == '2') {
            matrix[0][1] = player;
        }
        else
            std::cout<<"spot taken \n";
    }
    else if (PosValue == 3) {
        if (matrix[0][2] == '3') {
            matrix[0][2] = player;
        }
        else
            std::cout<<"spot taken \n";
    }
    else if (PosValue == 4) {
        if (matrix[1][0] == '4') {
            matrix[1][0] = player;
        }
        else
            std::cout<<"spot taken \n";
    }
    else if (PosValue == 5) {
        if (matrix[1][1] == '5') {
            matrix[1][1] = player;
        }
        else
            std::cout<<"spot taken \n";
    }
    else if (PosValue == 6) {
        if (matrix[1][2] == '6') {
            matrix[1][2] = player;
        }
        else
            std::cout<<"spot taken \n";
    }
    else if (PosValue == 7) {
        if (matrix[2][0] == '7') {
            matrix[2][0] = player;
        }
        else
            std::cout<<"spot taken \n";
    }
    else if (PosValue == 8) {
        if (matrix[2][1] == '8') {
            matrix[2][1] = player;
        }
        else
            std::cout<<"spot taken \n";
    }
    else if (PosValue == 9) {
        if (matrix[2][2] == '9') {
            matrix[2][2] = player;
        }
        else
            std::cout<<"spot taken \n";
    }


//hopefully find a solution for case
/*
    switch (PosValue) {
        case 1:
            matrix[0][0] = player;// this changes the tile to X
            break;
        case 2:
            matrix[0][1] = player;
            break;
        case 3:
            matrix[0][2] = player;
            break;
        case 4:
            matrix[1][0] = player;
            break;
        case 5:
            matrix[1][1] = player;
            break;
        case 6:
            matrix[1][2] = player;
            break;
        case 7:
            matrix[2][0] = player;
            break;
        case 8:
            matrix[2][1] = player;
            break;
        case 9:
            matrix[2][2] = player;
            break;
    }

 */

}
void TogglePlayer(){

    if(player == 'x') { //set x to o after using x in rotation
        player = 'o';
    }
    else {
        player = 'x'; // change it back to x
    }

}
char checkWin(){

    //need to create a spot to check tie win condition to see if every space is taken then return tie


    //check X win conditions
    //horizontal

    if(matrix[0][0] == 'x' && matrix[0][1] == 'x' && matrix[0][2] == 'x'){
        return 'x'; // 1,2,3
    }
    if(matrix[1][0] == 'x' && matrix[1][1] == 'x' && matrix[1][2] == 'x'){
        return 'x'; // 4,5,6
    }
    if(matrix[2][0] == 'x' && matrix[2][1] == 'x' && matrix[2][2] == 'x'){
        return 'x'; // 7,8,9
    }
    //vertical
    if(matrix[0][0] == 'x' && matrix[1][0] == 'x' && matrix[2][0] == 'x'){
        return 'x';//1,4,7
    }
    if(matrix[0][1] == 'x' && matrix[1][1] == 'x' && matrix[2][1] == 'x'){
        return 'x'; //2,5,8
    }
    if(matrix[0][2] == 'x' && matrix[1][2] == 'x' && matrix[2][2] == 'x'){
        return 'x'; //3,6,9
    }
    //diaganol
    if(matrix[0][0] == 'x' && matrix[1][1] == 'x' && matrix[2][2] == 'x'){
        return 'x';// 1,5,9
    }
    if(matrix[0][2] == 'x' && matrix[1][1] == 'x' && matrix[2][0] == 'x'){
        return 'x';// 3,5,7
    }

    //check o win condition
    //horizontal

    if(matrix[0][0] == 'o' && matrix[0][1] == 'o' && matrix[0][2] == 'o'){
        return 'o'; // 1,2,3
    }
    if(matrix[1][0] == 'o' && matrix[1][1] == 'o' && matrix[1][2] == 'o'){
        return 'o'; // 4,5,6
    }
    if(matrix[2][0] == 'o' && matrix[2][1] == 'o' && matrix[2][2] == 'o'){
        return 'o'; // 7,8,9
    }
    //vertical
    if(matrix[0][0] == 'o' && matrix[1][0] == 'o' && matrix[2][0] == 'o'){
        return 'o';//1,4,7
    }
    if(matrix[0][1] == 'o' && matrix[1][1] == 'o' && matrix[2][1] == 'o'){
        return 'o'; //2,5,8
    }
    if(matrix[0][2] == 'o' && matrix[1][2] == 'o' && matrix[2][2] == 'o'){
        return 'o'; //3,6,9
    }
    //diaganol
    if(matrix[0][0] == 'o' && matrix[1][1] == 'o' && matrix[2][2] == 'o'){
        return 'o';// 1,5,9
    }
    if(matrix[0][2] == 'o' && matrix[1][1] == 'o' && matrix[2][0] == 'o'){
        return 'o';// 3,5,7
    }
}
