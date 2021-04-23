	#include <stdio.h>
	#include <stdlib.h> //
	#include <time.h>   // used those libs for random initialization
	char matrix[7][7]; // actual board
	int curi = 0; // parameters that i used for keeping track on best moves
	int curj = 0;
	int nexti = 0;
	int nextj = 0;
	int curi2 = 0;
	int curj2 = 0;
	int nexti2 = 0;
	int nextj2 = 0;
	

	void printBoard(char matrix[7][7]){  //function that prints the actual board
		printf("    1   2   3   4   5   6   7   \n");
		printf("  _____________________________\n");
		printf("a | %c | %c | %c | %c | %c | %c | %c |\n",matrix[0][0],matrix[0][1],matrix[0][2],matrix[0][3],matrix[0][4],matrix[0][5],matrix[0][6]);
		printf("  _____________________________\n");
		printf("b | %c | %c | %c | %c | %c | %c | %c |\n",matrix[1][0],matrix[1][1],matrix[1][2],matrix[1][3],matrix[1][4],matrix[1][5],matrix[1][6]);
		printf("  _____________________________\n");
		printf("c | %c | %c | %c | %c | %c | %c | %c |\n",matrix[2][0],matrix[2][1],matrix[2][2],matrix[2][3],matrix[2][4],matrix[2][5],matrix[2][6]);
		printf("  _____________________________\n");
		printf("d | %c | %c | %c | %c | %c | %c | %c |\n",matrix[3][0],matrix[3][1],matrix[3][2],matrix[3][3],matrix[3][4],matrix[3][5],matrix[3][6]);
		printf("  _____________________________\n");
		printf("e | %c | %c | %c | %c | %c | %c | %c |\n",matrix[4][0],matrix[4][1],matrix[4][2],matrix[4][3],matrix[4][4],matrix[4][5],matrix[4][6]);	
		printf("  _____________________________\n");
		printf("f | %c | %c | %c | %c | %c | %c | %c |\n",matrix[5][0],matrix[5][1],matrix[5][2],matrix[5][3],matrix[5][4],matrix[5][5],matrix[5][6]);
		printf("  _____________________________\n");
		printf("g | %c | %c | %c | %c | %c | %c | %c |\n\n\n",matrix[6][0],matrix[6][1],matrix[6][2],matrix[6][3],matrix[6][4],matrix[6][5],matrix[6][6]);
	}

	void randominit(int x){ // random initialization function for the start config.
		srand(time(0));


		for(int i=0;i<x;i++){ // placing X pieces to board, getting random value making it i,j and if the position is already occupied getting random numbers until find a proper seat.
			int s1 = rand()%7;
			int s2 = rand()%7;
			if (matrix[s1][s2] != 'X' && matrix [s1][s2] != 'O'){
					matrix[s1][s2] = 'X';
			}
			else{
				while(matrix[s1][s2] == 'X' || matrix [s1][s2] == 'O') {
					s1 = rand()%7;
					s2 = rand()%7;
				}
				matrix[s1][s2] = 'X';
			}
		}


		for(int i=0;i<x;i++){ //same operation for O pieces
			int s1 = rand()%7;
			int s2 = rand()%7;
			if (matrix[s1][s2] != 'X' && matrix [s1][s2] != 'O'){
					matrix[s1][s2] = 'O';
			}
			else{
				while(matrix[s1][s2] == 'X' || matrix [s1][s2] == 'O') {
					s1 = rand()%7;
					s2 = rand()%7;
				}
				matrix[s1][s2] = 'O';
			}
		}



	}

	void selectinginit(int x){ // function that allows player to initiating the game by selecting the config.

		int flag = 1;
		char in[2];
		printf("Please enter the coordinates for X pieces(for example:a4,b3 etc.)\n");


		for(int i=0;i<x;i++) // getting piece number as parameter and placing X's to board until piece number is reached.
			{	
				printf("Coordinate for the next X piece: \n");

				flag = 1;
				scanf("%s" , in);

				while(flag){ // until the current piece is placed, this loop continues, and checking if the position is inside the board and also if it is already occupied by another piece.Place it if the position is empty and inside the board.

				if( (in[0] == 'a' || in[0] == 'A') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 0;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'X';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else if( (in[0] == 'b' || in[0] == 'B') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 1;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'X';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else if( (in[0] == 'c' || in[0] == 'C') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 2;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'X';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else if( (in[0] == 'd' || in[0] == 'D') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 3;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'X';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else if( (in[0] == 'e' || in[0] == 'E') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 4;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'X';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else if( (in[0] == 'f' || in[0] == 'F') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 5;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'X';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else if( (in[0] == 'g' || in[0] == 'G') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 6;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'X';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else{
					printf("invalid coordinate please re-enter:\n");
					scanf("%s", in);
				}

				}
				printBoard(matrix);
			}

			printf("Please enter the coordinates for O pieces(for example:a4,b3 etc.)\n");


		for(int i=0;i<x;i++) //same operation for O pieces.
			{	
				printf("Coordinate for the next O piece: \n");

				flag = 1;
				scanf("%s" , in);

				while(flag){

				if( (in[0] == 'a' || in[0] == 'A') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 0;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'O';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else if( (in[0] == 'b' || in[0] == 'B') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 1;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'O';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else if( (in[0] == 'c' || in[0] == 'C') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 2;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'O';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else if( (in[0] == 'd' || in[0] == 'D') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 3;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'O';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else if( (in[0] == 'e' || in[0] == 'E') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 4;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'O';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else if( (in[0] == 'f' || in[0] == 'F') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 5;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'O';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else if( (in[0] == 'g' || in[0] == 'G') && (in[1] - '0' <= 7 && in[1] - '0' >= 1) ){
					int val = 6;
					if(matrix[val][in[1] - '1'] != 'X' && matrix[val][in[1] - '1'] != 'O'){
					matrix[val][in[1] - '1'] = 'O';
					flag = 0;
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", in);
					}
				}
				else{
					printf("invalid coordinate please re-enter:\n");
					scanf("%s", in);
				}

				}
				printBoard(matrix);
			}

	}


	void player(int x){ // function that allows player to make a valid move. Getting parameter as player priority --> x.
		int flag = 1;
		char loc1[2]; // char array for the position of the piece.
		char loc2[2]; // char array for the target position. (i didnt expect users to type in more than it's size, a1,a2,b3 etc. are the proper inputs. Otherwise it will not accept the other inputs, it could basically checked if the size is larger, then it could be handled but i thought it doesnt so much matter to check in our project.)
		int val1; // integer representation of the rows (a,b,c,d,e,f,g)
		int val2; // same but for the target position
		char figure; // piece figure of the player
		char revfigure; // same but reversed.
		if(x == 1){  // based on player's decision if the player is player 1 then his/her figures will be X and the opponent's figure will be O.
			figure = 'X';
			revfigure = 'O';
		}
		else if(x == 2){ // same but reversed.
			figure = 'O';
			revfigure = 'X';
		}

		printf("Player's turn\n");
		printf("Choose %c piece to move: \n", figure);
		scanf("%s", loc1); // 


				while(flag){ // checking if the targeted piece is inside the borders, also if it is the figure of the player's.

				if( (loc1[0] == 'a' || loc1[0] == 'A') && (loc1[1] - '0' <= 7 && loc1[1] - '0' >= 1) ){
					val1 = 0;
					if(matrix[val1][loc1[1] - '1'] == figure){
					flag = 0;
					}
					else{
					printf("position is not valid (empty or %c at the square) please re-enter\n", revfigure);
					scanf("%s", loc1);
					}
				}
				else if( (loc1[0] == 'b' || loc1[0] == 'B') && (loc1[1] - '0' <= 7 && loc1[1] - '0' >= 1) ){
					val1 = 1;
					if(matrix[val1][loc1[1] - '1'] == figure){
					flag = 0;
					}
					else{
					printf("position is not valid (empty or %c at the square) please re-enter\n", revfigure);
					scanf("%s", loc1);
					}
				}
				else if( (loc1[0] == 'c' || loc1[0] == 'C') && (loc1[1] - '0' <= 7 && loc1[1] - '0' >= 1) ){
					val1 = 2;
					if(matrix[val1][loc1[1] - '1'] == figure){
					flag = 0;
					}
					else{
					printf("position is not valid (empty or %c at the square) please re-enter\n", revfigure);
					scanf("%s", loc1);
					}
				}
				else if( (loc1[0] == 'd' || loc1[0] == 'D') && (loc1[1] - '0' <= 7 && loc1[1] - '0' >= 1) ){
					val1 = 3;
					if(matrix[val1][loc1[1] - '1'] == figure){
					flag = 0;
					}
					else{
					printf("position is not valid (empty or %c at the square) please re-enter\n", revfigure);
					scanf("%s", loc1);
					}
				}
				else if( (loc1[0] == 'e' || loc1[0] == 'E') && (loc1[1] - '0' <= 7 && loc1[1] - '0' >= 1) ){
					val1 = 4;
					if(matrix[val1][loc1[1] - '1'] == figure){
					flag = 0;
					}
					else{
					printf("position is not valid (empty or %c at the square) please re-enter\n", revfigure);
					scanf("%s", loc1);
					}
				}
				else if( (loc1[0] == 'f' || loc1[0] == 'F') && (loc1[1] - '0' <= 7 && loc1[1] - '0' >= 1) ){
					val1 = 5;
					if(matrix[val1][loc1[1] - '1'] == figure){
					flag = 0;
					}
					else{
					printf("position is not valid (empty or %c at the square) please re-enter\n", revfigure);
					scanf("%s", loc1);
					}
				}
				else if( (loc1[0] == 'g' || loc1[0] == 'G') && (loc1[1] - '0' <= 7 && loc1[1] - '0' >= 1) ){
					val1 = 6;
					if(matrix[val1][loc1[1] - '1'] == figure){
					flag = 0;
					}
					else{
					printf("position is not valid (empty or %c at the square) please re-enter\n", revfigure);
					scanf("%s", loc1);
					}
				}
				else{
					printf("invalid coordinate please re-enter:\n");
					scanf("%s", loc1);
				}

				}

		flag = 1;
		printf("choose the new position for %s:",loc1);
		scanf("%s",loc2);

		

		while(flag){ // checking if the target location is inside the board, also if its empty , and also if the move is valid(1 right,1 left,1 up, or 1 down)

				if( (loc2[0] == 'a' || loc2[0] == 'A') && (loc2[1] - '0' <= 7 && loc2[1] - '0' >= 1) ){
					val2 = 0;
					if(matrix[val2][loc2[1] - '1'] != revfigure && matrix[val2][loc2[1] - '1'] != figure){ 
						if( ( (val1 + 1 == val2 || val1 - 1 == val2) && (loc2[1] - '1' == loc1[1] - '1') ) || (  (val2 == val1) && ((loc1[1] - '1') + 1 == loc2[1] - '1'  || (loc1[1] - '1') - 1 == loc2[1] - '1') )  ){ // no need for extra border check cause i dont accept picking a piece out of borders already.	
							matrix[val2][loc2[1] - '1'] = figure;
							matrix[val1][loc1[1] - '1'] = ' ';
							flag = 0;
						}
						else{
							printf("You cannot move it to that position please re-enter a proper position to move your piece\n");
							scanf("%s", loc2);
						}
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", loc2);
					}
				}
				else if( (loc2[0] == 'b' || loc2[0] == 'B') && (loc2[1] - '0' <= 7 && loc2[1] - '0' >= 1) ){
					val2 = 1;
					if(matrix[val2][loc2[1] - '1'] != revfigure && matrix[val2][loc2[1] - '1'] != figure){
						if( ( (val1 + 1 == val2 || val1 - 1 == val2) && (loc2[1] - '1' == loc1[1] - '1') ) || (  (val2 == val1) && ((loc1[1] - '1') + 1 == loc2[1] - '1'  || (loc1[1] - '1') - 1 == loc2[1] - '1') )  ) { // no need for extra border check cause i dont accept picking a piece out of borders already.	
							matrix[val2][loc2[1] - '1'] = figure;
							matrix[val1][loc1[1] - '1'] = ' ';
							flag = 0;
						}
						else{
							printf("You cannot move it to that position please re-enter a proper position to move your piece\n");
							scanf("%s", loc2);
						}
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", loc2);
					}
				}
				else if( (loc2[0] == 'c' || loc2[0] == 'C') && (loc2[1] - '0' <= 7 && loc2[1] - '0' >= 1) ){
					val2 = 2;
					if(matrix[val2][loc2[1] - '1'] != revfigure && matrix[val2][loc2[1] - '1'] != figure){
						if( ( (val1 + 1 == val2 || val1 - 1 == val2) && (loc2[1] - '1' == loc1[1] - '1') ) || (  (val2 == val1) && ((loc1[1] - '1') + 1 == loc2[1] - '1'  || (loc1[1] - '1') - 1 == loc2[1] - '1') )  ){ // no need for extra border check cause i dont accept picking a piece out of borders already.	
							matrix[val2][loc2[1] - '1'] = figure;
							matrix[val1][loc1[1] - '1'] = ' ';
							flag = 0;
						}
						else{
							printf("You cannot move it to that position please re-enter a proper position to move your piece\n");
							scanf("%s", loc2);
						}
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", loc2);
					}
				}
				else if( (loc2[0] == 'd' || loc2[0] == 'D') && (loc2[1] - '0' <= 7 && loc2[1] - '0' >= 1) ){
					val2 = 3;
					if(matrix[val2][loc2[1] - '1'] != revfigure && matrix[val2][loc2[1] - '1'] != figure){
						if( ( (val1 + 1 == val2 || val1 - 1 == val2) && (loc2[1] - '1' == loc1[1] - '1') ) || (  (val2 == val1) && ((loc1[1] - '1') + 1 == loc2[1] - '1'  || (loc1[1] - '1') - 1 == loc2[1] - '1') )  ){ // no need for extra border check cause i dont accept picking a piece out of borders already.	
							matrix[val2][loc2[1] - '1'] = figure;
							matrix[val1][loc1[1] - '1'] = ' ';
							flag = 0;
						}
						else{
							printf("You cannot move it to that position please re-enter a proper position to move your piece\n");
							scanf("%s", loc2);
						}
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", loc2);
					}
				}
				else if( (loc2[0] == 'e' || loc2[0] == 'E') && (loc2[1] - '0' <= 7 && loc2[1] - '0' >= 1) ){
					val2 = 4;
					if(matrix[val2][loc2[1] - '1'] != revfigure && matrix[val2][loc2[1] - '1'] != figure){
						if( ( (val1 + 1 == val2 || val1 - 1 == val2) && (loc2[1] - '1' == loc1[1] - '1') ) || (  (val2 == val1) && ((loc1[1] - '1') + 1 == loc2[1] - '1'  || (loc1[1] - '1') - 1 == loc2[1] - '1') )  ){ // no need for extra border check cause i dont accept picking a piece out of borders already.	
							matrix[val2][loc2[1] - '1'] = figure;
							matrix[val1][loc1[1] - '1'] = ' ';
							flag = 0;
						}
						else{
							printf("You cannot move it to that position please re-enter a proper position to move your piece\n");
							scanf("%s", loc2);
						}
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", loc2);
					}
				}
				else if( (loc2[0] == 'f' || loc2[0] == 'F') && (loc2[1] - '0' <= 7 && loc2[1] - '0' >= 1) ){
					val2 = 5;
					if(matrix[val2][loc2[1] - '1'] != revfigure && matrix[val2][loc2[1] - '1'] != figure){
						if( ( (val1 + 1 == val2 || val1 - 1 == val2) && (loc2[1] - '1' == loc1[1] - '1') ) || (  (val2 == val1) && ((loc1[1] - '1') + 1 == loc2[1] - '1'  || (loc1[1] - '1') - 1 == loc2[1] - '1') )  ){ // no need for extra border check cause i dont accept picking a piece out of borders already.	
							matrix[val2][loc2[1] - '1'] = figure;
							matrix[val1][loc1[1] - '1'] = ' ';
							flag = 0;
						}
						else{
							printf("You cannot move it to that position please re-enter a proper position to move your piece\n");
							scanf("%s", loc2);
						}
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", loc2);
					}
				}
				else if( (loc2[0] == 'g' || loc2[0] == 'G') && (loc2[1] - '0' <= 7 && loc2[1] - '0' >= 1) ){
					val2 = 6;
					if(matrix[val2][loc2[1] - '1'] != revfigure && matrix[val2][loc2[1] - '1'] != figure){
						if( ( (val1 + 1 == val2 || val1 - 1 == val2) && (loc2[1] - '1' == loc1[1] - '1') ) || (  (val2 == val1) && ((loc1[1] - '1') + 1 == loc2[1] - '1'  || (loc1[1] - '1') - 1 == loc2[1] - '1') )  ){ // no need for extra border check cause i dont accept picking a piece out of borders already.	
							matrix[val2][loc2[1] - '1'] = figure;
							matrix[val1][loc1[1] - '1'] = ' ';
							flag = 0;
						}
						else{
							printf("You cannot move it to that position please re-enter a proper position to move your piece\n");
							scanf("%s", loc2);
						}
					}
					else{
					printf("position is already occupied please re-enter\n");
					scanf("%s", loc2);
					}
				}
				else{
					printf("invalid coordinate please re-enter:\n");
					scanf("%s", loc2);
				}

				}

				printf("Player moves the piece at:%c%d to %c%d\n",'a'+val1,(loc1[1] - '1')+1,'a'+val2,(loc2[1] - '1')+1);	
	}


	int evaluation(char x[7][7]){ // evaluation function that returns our algorithm a value that helps ai to make a proper move.
		int xmoves = 0; // total x moves available (inside the x moves if there is a common square to move then i counted the square as 1, between the opposite figures if there is a common square to make move for both sides then i counted it for each side. As shown in pdf example of the term project)
		int omoves = 0; // total o moves available 
		int res = 0; // xmoves+omoves
		for(int i=0;i<7;i++){ // checking the available move spaces and count them for X. Common squares inside X moves counted as 1 so, i marked those squares with 1 until the loop is over, then i unmarked the squares that had 1.
				for(int j=0;j<7;j++){
					if (x[i][j] == 'X'){
						if(i+1<=6){
							if(x[i+1][j] == ' '){
								x[i+1][j] = '1';
								xmoves++;
							}
						}
						if(i-1>=0){
							if(x[i-1][j] == ' '){
								x[i-1][j] = '1';
								xmoves++;
							}
						}
						if(j+1<=6){	
							if(x[i][j+1] == ' '){
								x[i][j+1] = '1';
								xmoves++;
							}
						}
						if(j-1>=0){	
							if(x[i][j-1] == ' '){
								x[i][j-1] = '1';
								xmoves++;
							}
						}	
					}
				}
			}
			for(int i=0;i<7;i++){ // unmarking the squares that has 1
				for(int j=0;j<7;j++){
					if(x[i][j] == '1'){
						x[i][j] = ' ';
					}
				}
			}
			for(int i=0;i<7;i++){ // same operation for O pieces
				for(int j=0;j<7;j++){
					if (x[i][j] == 'O'){
						if(i+1<=6){
							if(x[i+1][j] == ' '){
								x[i+1][j] = '1';
								omoves++;
							}
						}
						if(i-1>=0){
							if(x[i-1][j] == ' '){
								x[i-1][j] = '1';
								omoves++;
							}
						}
						if(j+1<=6){	
							if(x[i][j+1] == ' '){
								x[i][j+1] = '1';
								omoves++;
							}
						}
						if(j-1>=0){	
							if(x[i][j-1] == ' '){
								x[i][j-1] = '1';
								omoves++;
							}
						}	
					}
				}
			}
			for(int i=0;i<7;i++){ // same unmarking for O pieces
				for(int j=0;j<7;j++){
					if(x[i][j] == '1'){
						x[i][j] = ' ';
					}
				}
			}
				
	 res = xmoves-omoves; 
	 return res;

	}

	int minimax(char board[7][7],int depth, int maxplayer, int alpha, int beta, int tc){ // alpha-beta pruning to calculate the best move available in an efficent manner. depth starts from 0 and it goes until the var tc tc is (2*turncount)-1 which is the maximum depth
		int maxeval; // max evaluation value
		int mineval; // min evaluation value
		int eval; // current evaluation value
		int breakflag = 0; //breakflag for breaking the outer loop if the search process should be ended.
		

		if(depth == tc){ // returning evaluation value for the leafs.
			return (evaluation(board)); //return evaluation function on the max depth reached.
		}

		if(maxplayer == 1){ // if the ai is maximizing player
			
			maxeval = -9999; // max evaluation value starts from a big number that cant be possible for our heuristic.
			breakflag = 0; 
			for(int i=0;i<7;i++){ //visiting all squares inside the imaginery board that we sent here as a parameter
				for(int j=0;j<7;j++){
					if (board[i][j] == 'X'){ // if the figure is X.
						if(i+1<=6){ // if it is possible movement for i+1 is inside the board.
							if(board[i+1][j] == ' '){ // and if it is empty.
								board[i][j] = ' '; //make the move
								board[i+1][j] = 'X';
								eval = minimax(board, depth+1, 0, alpha, beta, tc); // call the function recursively so that evaluate the value that we need for that move.
								
								board[i][j] = 'X'; //undo the move.
								board[i+1][j] = ' ';
								if(eval > maxeval){ // if the eval value is larger than max evaluation value then update it, and mark the move dedicated in the depth 0.
									maxeval = eval; 
									if(depth == 0){
									curi2 = i;
									curj2 = j;
									nexti2 = i+1;
									nextj2 = j; }
								}
								if(eval > alpha){ // if evaluation value is larger than alpha value then update the alpha
									alpha = eval;
								}
								
								if(beta <= alpha){ // if beta is smaller or equal to the alpha then stop traversing.
									breakflag = 1;
									break;
								}
							}
						}
						if(i-1>=0){ // same operations for i-1
							if(board[i-1][j] == ' '){
								board[i][j] = ' ';
								board[i-1][j] = 'X';
								eval = minimax(board, depth+1, 0, alpha, beta, tc);
								
								board[i][j] = 'X';
								board[i-1][j] = ' ';
								if(eval > maxeval){
									maxeval = eval;	
									if(depth == 0){
									curi2 = i;
									curj2 = j;
									nexti2 = i-1;
									nextj2 = j; }
								}

								if(eval > alpha){
									alpha = eval;
								}
							
								if(beta <= alpha){
									breakflag = 1;
									break;
								}
							}
						}
						if(j+1<=6){	// same operations for j+1
							if(board[i][j+1] == ' '){
								board[i][j] = ' ';
								board[i][j+1] = 'X';
								eval = minimax(board, depth+1, 0, alpha, beta, tc);
								
								board[i][j] = 'X';
								board[i][j+1] = ' ';
								if(eval > maxeval){
									maxeval = eval;
									if(depth == 0){
									curi2 = i;
									curj2 = j;
									nexti2 = i;
									nextj2 = j+1; }
								}
								if(eval > alpha){
									alpha = eval;
								}
								
								if(beta <= alpha){
									breakflag = 1;
									break;
								}
							}
						}
						if(j-1>=0){	// same operations for j-1
							if(board[i][j-1] == ' '){
								board[i][j] = ' ';
								board[i][j-1] = 'X';
								eval = minimax(board, depth+1, 0, alpha, beta, tc);
								
								board[i][j] = 'X';
								board[i][j-1] = ' ';
								if(eval > maxeval){
									maxeval = eval;	
								if(depth == 0){
									curi2 = i;
									curj2 = j;
									nexti2 = i;
									nextj2 = j-1; }
								}
								
								if(eval > alpha){
									alpha = eval;
								}
								if(beta <= alpha){
									breakflag = 1;
									break;
								}
							}
						}	
					}
				}
				if(breakflag==1){ // break the outer loop.
					break;
				}
			}
		return maxeval; // returning the best value.

		}

		else{ // same operations for the minimizing turn.
			mineval = 9999;
			breakflag = 0;
			for(int i=0;i<7;i++){
				for(int j=0;j<7;j++){
					if (board[i][j] == 'O'){
						if(i+1<=6){
							if(board[i+1][j] == ' '){
								board[i][j] = ' ';
								board[i+1][j] = 'O';
								
								eval = minimax(board, depth+1, 1, alpha, beta, tc);
			
								board[i][j] = 'O';
								board[i+1][j] = ' ';

								if(eval < mineval){
									mineval = eval;

									if(depth == 0){
									curi = i;
									curj = j;
									nexti = i+1;
									nextj = j; }

								}
								
								if(eval < beta){
									beta = eval;
								}
						
								if(beta <= alpha){
									breakflag = 1;
									break;
								}
							}
						}
						if(i-1>=0){
							if(board[i-1][j] == ' '){
								board[i][j] = ' ';
								board[i-1][j] = 'O';

								eval = minimax(board, depth+1, 1, alpha, beta, tc);
								
								board[i][j] = 'O';
								board[i-1][j] = ' ';

								if(eval < mineval){

									mineval = eval;
	
									if (depth == 0){
										curi = i;
									curj = j;
									nexti = i-1;
									nextj = j; }

								}
								if(eval < beta){
									beta = eval;
								}
								
								if(beta <= alpha){
									breakflag = 1;
									break;
								}
							}
						}
						if(j+1<=6){	
							if(board[i][j+1] == ' '){
								board[i][j] = ' ';
								board[i][j+1] = 'O';

								eval = minimax(board, depth+1, 1, alpha, beta, tc);
								
								board[i][j] = 'O';
								board[i][j+1] = ' ';

								if(eval < mineval){
	
									mineval = eval;
				
									if(depth == 0){
									curi = i;
									curj = j;
									nexti = i;
									nextj = j+1;}
					
								}
								if(eval < beta){
									beta = eval;
								}
								if(beta <= alpha){
									breakflag = 1;
									break;
								}
							}
						}
						if(j-1>=0){	
							if(board[i][j-1] == ' '){
								board[i][j] = ' ';
								board[i][j-1] = 'O'; 

								eval = minimax(board, depth+1, 1, alpha, beta, tc);

								board[i][j] = 'O';
								board[i][j-1] = ' ';
	
								if(eval < mineval){
		
									mineval = eval;
									if(depth == 0){
										curi = i;
									curj = j;
									nexti = i;
									nextj = j-1;}

								}
								if(eval < beta){
									beta = eval;
								}
								
								if(beta <= alpha){
									breakflag = 1;
									break;
								}
							}
						}	
					}
				}
				if(breakflag==1){
					break;
				}
			}
		return mineval;
		}

	}

	void AI(int x, int y){ // function that finally ai decides to make the move
		int maximizing; // variable that indicates if the ai is maximizing or the minimizing player. (1 or 2)
		char board [7][7]; // imaginery board that we will send it to the alpha-beta prun algorithm
		int alpha = -9999; // initial alpha value
		int beta  =  9999; // initial beta value
		char figure; // figure for our ai if it is 1 or 2
		if(x == 1){ // if the player is player 1  then our ai will be the minimizing player so maximizing set to 0 and figure is set to O.
			maximizing = 0;
			figure = 'O';
		}
		else if(x == 2){ // if the player is player 2 then our ai will be the maximizing player so maximizing set to 1 and figure is set to X.
			maximizing = 1;
			figure = 'X';
		}
		
		for (int i = 0;i<7;i++){ // filling the imaginery board before send it to alpha-beta func.
			for(int j=0;j<7;j++){
				board[i][j]=matrix[i][j];
			}
		}
		y = y > 4 ? 4 : y; // limit the maximum number of depth to (4*2)-1 , so that it doesnt take more than 5 sec to play.

		if(maximizing == 1){
		minimax(board ,0, maximizing, alpha, beta, (y*2)-1); // initial call for the alpha-beta sending (y*2)-1 
		}
		else{
		minimax(board ,0, maximizing, alpha, beta, (y*2)-1); // initial call for the alpha-beta sending (y*2)-1
		}
		
		

		
		printf("Computer is making the move\n");

		if(maximizing == 1){ // making the best move available on the real board, if our ai is maximizing player.
		printf("Computer moves the piece at:%c%d to %c%d\n",'a'+curi2,curj2+1,'a'+nexti2,nextj2+1);			


		matrix[curi2][curj2] = ' ';
		//curi2 = nexti2;
		//curj2 = nextj2;



		matrix[nexti2][nextj2] = figure;	
		}
		else{ // making the best move available on the real board, if our ai is minimizing player.
		printf("Computer moves the piece at:%c%d to %c%d\n",'a'+curi,curj+1,'a'+nexti,nextj+1);		
		matrix[curi][curj] = ' ';
		//curi = nexti;
		//curj = nextj;



		matrix[nexti][nextj] = figure;
		
		}

	}

	int checkgameend(int x){ // checking the game end conditions, works so similar to evaluation func
		int result = 3;
		int xmoves = 0;
		int omoves = 0;

		for(int i=0;i<7;i++){ // marking moveable spaces for X pieces as 1 and count them so that common squares between X pieces are counted as 1. However if there is a common moveable square between X and O it will be counted for each side.
				for(int j=0;j<7;j++){
					if (matrix[i][j] == 'X'){
						if(i+1<=6){
							if(matrix[i+1][j] == ' '){
								matrix[i+1][j] = '1';
								xmoves++;
							}
						}
						if(i-1>=0){
							if(matrix[i-1][j] == ' '){
								matrix[i-1][j] = '1';
								xmoves++;
							}
						}
						if(j+1<=6){	
							if(matrix[i][j+1] == ' '){
								matrix[i][j+1] = '1';
								xmoves++;
							}
						}
						if(j-1>=0){	
							if(matrix[i][j-1] == ' '){
								matrix[i][j-1] = '1';
								xmoves++;
							}
						}	
					}
				}
			}
			for(int i=0;i<7;i++){ // deleting the marks from the board after the count
				for(int j=0;j<7;j++){
					if(matrix[i][j] == '1'){
						matrix[i][j] = ' ';
					}
				}
			}
			for(int i=0;i<7;i++){ // same operation for O pieces
				for(int j=0;j<7;j++){
					if (matrix[i][j] == 'O'){
						if(i+1<=6){
							if(matrix[i+1][j] == ' '){
								matrix[i+1][j] = '1';
								omoves++;
							}
						}
						if(i-1>=0){
							if(matrix[i-1][j] == ' '){
								matrix[i-1][j] = '1';
								omoves++;
							}
						}
						if(j+1<=6){	
							if(matrix[i][j+1] == ' '){
								matrix[i][j+1] = '1';
								omoves++;
							}
						}
						if(j-1>=0){	
							if(matrix[i][j-1] == ' '){
								matrix[i][j-1] = '1';
								omoves++;
							}
						}	
					}
				}
			}
			for(int i=0;i<7;i++){ // deleting marks.
				for(int j=0;j<7;j++){
					if(matrix[i][j] == '1'){
						matrix[i][j] = ' ';
					}
				}
			}

		if (x > 0){ // deciding the result if the game moves on and one of the (or both? somehow) sides has no moveable space to move. 1 = player 1 won, 2= player 2 won, 0 = draw
			if(xmoves == 0 && omoves == 0){ // i dont think this can happen but anyway just in case.
				result = 0;
				printf("Both has no moveable space\n");
			}
			else if(xmoves == 0){
				result = 2;
				printf("Player1 has no moveable space\n");
			}
			else if(omoves == 0){
				result = 1;
				printf("Player2 has no moveable space\n");
			}


		}
		else if (x == 0){ // if the turn count is reached then based on moveable spaces of both side it decides to who won. or ended up draw.
			if(xmoves > omoves){
				result = 1;
				printf("Player1 point:%d\nPlayer2 point:%d\n",xmoves,omoves);
			}
			else if(omoves > xmoves){
				result = 2;
				printf("Player1 point:%d\nPlayer2 point:%d\n",xmoves,omoves);
			}
			else if(omoves == xmoves){
				result = 0;
				printf("Player1 point:%d\nPlayer2 point:%d\n",xmoves,omoves);
			}
		}
		
		return result;
	}

		int burdenifs(int x){ // bunch of conditions to check if the game is terminated, and printing the result.(For main loop)
			if (checkgameend(x) == 0){
				printf("draw\n");
				return 0;
			}
			else if (checkgameend(x) == 1){
				printf("Player 1 won\n");
				return 0;
			}
			else if (checkgameend(x) == 2){
				printf("player 2 won\n");
				return 0;
			}
			return 1;
		}

	int main(){
		int turnCount = 0; // turn number both sides will play
		int pieceCount = 0; // piece number for both sides
		int menu1 = 0; // menu option variable
		int flag = 1; // flag for menu
		int gameflag = 1; // flag for main loop
		int playerprio = 0; // player 1 or player 2 variable.

		for(int i=0;i<7;i++){ // init the board as empty
			for(int j=0;j<7;j++){
				matrix[i][j] = ' ';
			}
		}
		
		printf("Please enter the maximum turnnumber\n"); // bunch of parameters taken from user and menu options
		scanf("%d", &turnCount);
		printf("Please enter the piecenumber for each player\n");
		scanf("%d", &pieceCount);
		
		printf("Press 1 or 2 to make selection\n1-)Select Player1\n2-)Select Player2\n");
		scanf("%d", &playerprio);
		
		while(playerprio!=1 && playerprio!=2){
			printf("Wrong option.Press 1 or 2 to make selection\n1-)Select Player1\n2-)Select Player2\n");
			scanf("%d", &playerprio);
		}


		printf("1-)Initialize board randomly\n2-)Initialize board by selecting\n");
		scanf("%d", &menu1);

		while(flag){
		if(menu1 == 1){
			randominit(pieceCount);
			printBoard(matrix);
			flag = 0;
			}
		else if(menu1 == 2){
			selectinginit(pieceCount);
			
			flag = 0;
			}
		else {
			printf("invalid menu option please re-enter\n1-)Initialize board randomly\n2-)Initialize board by selecting\n");
			scanf("%d", &menu1);
			}

		}


		while(gameflag){ // main loop game runs here


			if (checkgameend(turnCount) == 0){ // After the init if there is no moveable space for at least 1 side, it ll terminate the game and request you to re-run it.
				printf("Unfortunate initialization, re-run the game\n");
				break;
			}
			else if (checkgameend(turnCount) == 1){
				printf("Unfortunate initialization, re-run the game\n");
				break;
			}
			else if (checkgameend(turnCount) == 2){
				printf("Unfortunate initialization, re-run the game\n");
				break;
			}


			if(playerprio == 1){ // if user selected to be player 1 game flows go like this
			printf("Remaining Turn:%d\n",turnCount);
			player(playerprio);
			printBoard(matrix);
			gameflag = burdenifs(turnCount); 
			if(gameflag == 0){ // checking for on-going end.
				break;
			}

			AI(playerprio,turnCount);
			printBoard(matrix);
			gameflag = burdenifs(turnCount);
			if(gameflag == 0){ // checking for on-going end.
				break;
			}

			turnCount--;
			
			if(turnCount == 0){
				gameflag = 0;
				burdenifs(turnCount);
			}
			
			}
			else if(playerprio == 2){ // game flows go like this if player selected to be player 2
			printf("Remaining Turn:%d\n",turnCount);
			AI(playerprio,turnCount);
			printBoard(matrix);
			gameflag = burdenifs(turnCount);
			if(gameflag == 0){
				break;
			}
			player(playerprio);
			printBoard(matrix);
			gameflag = burdenifs(turnCount);
			if(gameflag == 0){
				break;
			}
			turnCount--;
			
			if(turnCount == 0){
				gameflag = 0;
				burdenifs(turnCount);
			}
			}
		} 
	}