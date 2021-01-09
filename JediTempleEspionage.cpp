#include<iostream>
#include<ctime>
#include<windows.h>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to the terminal
    std::cout << "\n" << R"(
           / __   __| / _ \ |  _ \
     ______> \ | |   |  _  ||    /_____________________________
    / _______/ |_|   |_| |_||_|\______________________________ \
   / /                                                        \ \
  | |                                                          | |
  | |                                                          | |
  | |                                                          | |
  | |                                                          | |
  | |                TROUBLE AT THE JEDI TEMPLE                | |
  | |                                                          | |
  | |                                                          | |
  | |                                                          | |
  | |                                                          | |
   \ \____________________________    _   ___   ____   _______/ /
    \___________________________  |  | | / _ \ |  _ \ / _______/
                                | |/\| ||  _  ||    / > \        
                                 \_/\_/ |_| |_||_|\_\|__/
    )" << "\n";

    std::cout << "You are trying to break into the Jedi Temple to steal ancient artefacts...\n";
    std::cout << "You need to enter the correct codes to open the blast door...\n";
    std::cout << "Current blast door security level: " << Difficulty << " out of 5.\n\n";
}

bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum & product to terminal
    std::cout << "* There are 3 numbers in the code";
    std::cout << "\n* Codes add-up to: " << CodeSum;    
    std::cout << "\n* The codes multiply to give: " << CodeProduct;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cout << "\n\nEnter your answer (separated by spaces): ";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nBlast door security level " << Difficulty << " deactivated.";
        return true;
    }
    else 
    {
        std::cout << "\nWrong answer! Try again or contact the Jedi Librarian. May the Force be with You.";
        return false;
    }
}

int main()
{
    srand(time(NULL));  //New random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxLevelDifficulty = 5;

    while (LevelDifficulty <= MaxLevelDifficulty)    // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();   // Clears any errors
        std::cin.ignore();  // Discard the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;  // Increase level difficulty
        }    
    }

    std::cout << "\nYou are in! The Jedi are doomed! \nMake your way to the shuttle and escape!";
    std::cout << "\n" << R"(                                        .
                              .-o
                 .           /  |
        .                 . /   |   .
                           /    |
                  .       /     |
  .                      /      /         .
             .          /    _./   .
                   _.---~-.=:_
                  (_.-=() <~`-`-.
                 _/ _() ~`-==-._,>
         ..--====--' `~-._.__()
     o===''~~             |__()
                .         \   |             .
                           \  \
                            \  \     .
        .                    \  \           
                 .            \  \          
                               \_ \        .
                                ~o

)" << "\n";
    Sleep(10000);
    return 0;                            
}