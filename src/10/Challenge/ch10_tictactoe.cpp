// C++ Code Challenges, LinkedIn Learning

// Challenge #10: Playing Tic-Tac-Toe
// Write an application that plays Tic-Tac-Toe against the user.

#include <iostream>
#include <string>

// ask_for_move()
// Summary: This function asks the user to make a move.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The user's mark: 'X' or 'O'.
// Returns: Nothing.
void ask_for_move(char game[][3], char mark){
    std::string str;
    int row, col;
    do{
        std::cout << "Place your mark (" << mark << ") in row: " << std::flush;
        std::cin >> str;
        row = stoi(str);
        std::cout << "Place your mark (" << mark << ") in column: " << std::flush;
        std::cin >> str;
        col = stoi(str);
    }while(game[row-1][col-1]!=' ');
    game[row-1][col-1] = mark;
    return;
}

bool try_to_win(char game[][3], char mark){
    int mark_count = 0, empty_index = -1;

    //checks for winning move
    for (size_t i = 0; i < 3; i++)
    {
        mark_count = 0, empty_index = -1;
        for (size_t j = 0; j < 3; j++)
        {
            if (game[i][j] == mark) mark_count ++;
            else if(game[i][j] == ' ') empty_index = j;
        }
        if(mark_count == 2 && empty_index != -1)
        {
            game[i][empty_index] = mark;
            return true;
        }

        mark_count = 0, empty_index = -1;
        for (size_t j = 0; j < 3; j++)
        {
            if (game[j][i] == mark) mark_count ++;
            else if(game[j][i] == ' ') empty_index = j;
        }
        if(mark_count == 2 && empty_index != -1)
        {
            game[empty_index][i] = mark;
            return true;
        }
    }

    mark_count = 0, empty_index = -1;
    for (size_t i = 0; i < 3; i++)
    {
        if(game[i][i] == mark) mark_count ++;
        else if (game[i][i] == ' ') empty_index = i;
    }
    if(mark_count == 2 && empty_index != -1)
    {
        game[empty_index][empty_index] = mark;
        return true;
    }

    mark_count = 0, empty_index = -1;
    for (size_t i = 0; i < 3; i++)
    {
        if(game[2 - i][i] == mark) mark_count ++;
        else if (game[2 - i][i] == ' ') empty_index = i;
    }
    if(mark_count == 2 && empty_index != -1)
    {
        game[empty_index][empty_index] = mark;
        return true;
    }

    return false;
}

bool try_to_block(char game[][3], char mark, char oppMark){
    int oppmark_count = 0, empty_index = -1;

    //checks for winning move
    for (size_t i = 0; i < 3; i++)
    {
        oppmark_count = 0, empty_index = -1;
        for (size_t j = 0; j < 3; j++)
        {
            if (game[i][j] == oppMark) oppmark_count ++;
            else if(game[i][j] == ' ') empty_index = j;
        }
        if(oppmark_count == 2 && empty_index != -1)
        {
            game[i][empty_index] = mark;
            return true;
        }

        oppmark_count = 0, empty_index = -1;
        for (size_t j = 0; j < 3; j++)
        {
            if (game[j][i] == oppMark) oppmark_count ++;
            else if(game[j][i] == ' ') empty_index = j;
        }
        if(oppmark_count == 2 && empty_index != -1)
        {
            game[empty_index][i] = mark;
            return true;
        }
    }

    oppmark_count = 0, empty_index = -1;
    for (size_t i = 0; i < 3; i++)
    {
        if(game[i][i] == oppMark) oppmark_count ++;
        else if (game[i][i] == ' ') empty_index = i;
    }
    if(oppmark_count == 2 && empty_index != -1)
    {
        game[empty_index][empty_index] = mark;
        return true;
    }

    oppmark_count = 0, empty_index = -1;
    for (size_t i = 0; i < 3; i++)
    {
        if(game[2 - i][i] == oppMark) oppmark_count ++;
        else if (game[2 - i][i] == ' ') empty_index = 2 - i;
        if(oppmark_count == 2 && empty_index != -1)
        {
            game[empty_index][i] = mark;
            return true;
        }
    }

    return false;
}

void last_resort_placement(char game[][3], char mark)
{
    int mark_count = 0, empty_index = -1;
    if (game[1][1] == ' ')
    {
        game[1][1] = mark;
        return;
    }else
    {
        for (size_t i = 0; i < 3; i++)
        {
            if (game[i][i] == ' ')
            {
                game[i][i] = mark;
                return;
            }
            else if(game[2 - i][i] == ' ')
            {
                game[2 - i][i] = mark;
                return;
            }
        }

        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                if (game[i][j] == ' ')
                {
                    game[i][j] = mark;
                    return;
                }else if (game[j][i] == ' ')
                {
                    game[j][i] = mark;
                    return;
                }
            }
            
        }
        
    }
}

// make_move()
// Summary: This AI function makes a move on behalf of the computer in an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The AI's mark: 'X' or 'O'.
// Returns: Nothing.

void make_move(char game[][3], char mark){ 
    // Write your code here and comment out the definition of TWO_PLAYERS above
    char oppMark = mark == 'X' ? 'O' : 'X';
    
    if (try_to_win(game, mark))
    {
        return;
    }
    
    if (try_to_block(game, mark, oppMark))
    {
        return;
    }

    last_resort_placement(game, mark);

    return;
}

// game_state()
// Summary: This function returns the state of a game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: A character encoded as:
//                                  'a': An active game.
//                                  'X': X won.
//                                  'O': O won.
//                                  't': A tie.
char game_state(char game[][3]){
    int TotalSquares;
    char gameStat = 't';

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (game[i][j] == ' ')
            {
                gameStat = 'a';
            }
            
        }
        
    }
    
    // Write your code here
    for (size_t i = 0; i < 3; i++)
    {
        if(game[i][0] != ' ' && (game[i][0] == game[i][1]) && (game[i][0] == game[i][2]))
        {
            gameStat = game[i][0];
        }else if(game[0][i] != ' ' && (game[0][i] == game[1][i]) && (game[0][i] == game[2][i])){
            gameStat = game[0][i];
        }
        
    }

    if (game[1][1] != ' ' && (((game[0][0] == game[1][1]) && (game[1][1] == game[2][2])) || ((game[2][0] == game[1][1]) && (game[1][1] == game[0][2]))))
    {
        gameStat = game[1][1];
    }
    return gameStat;
}

// print_game()
// Summary: This function prints an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: Nothing.
void print_game(char game[][3]){
    std::cout << std::endl << std::endl;
    std::cout << "    1   2   3\n\n";
    std::cout << "1   " << game[0][0] << " | "<< game[0][1] << " | " << game[0][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "2   " << game[1][0] << " | "<< game[1][1] << " | " << game[1][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "3   " << game[2][0] << " | "<< game[2][1] << " | " << game[2][2] << "\n";

    std::cout << std::endl << std::endl;
    return;
}

// Main function
int main(){
    char game[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char user_mark = 'X', ai_mark = 'O', turn = 'X';
    std::string str;

    std::cout << "Pick your mark (X goes first): " << std::flush;
    std::cin >> str;
    if(str[0]== 'O' || str[0]== 'o'){
        user_mark = 'O';
        ai_mark = 'X';
    }
    std::cout << "      User: " << user_mark << "     AI: " << ai_mark << "\n";    

    print_game(game);

    while(game_state(game)=='a'){
        std::cout << turn << "'s turn...\n";    
        if(turn==user_mark)
            ask_for_move(game,user_mark);
        else
            make_move(game,ai_mark);
        print_game(game);
        turn = turn == 'X' ? 'O' : 'X';
    }
    if(game_state(game)=='t')
        std::cout << "It's a tie.\n\n";
    else    
        std::cout << game_state(game) << " is the winner.\n\n";
    std::cout << std::flush;
    return 0;
}
