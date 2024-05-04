#include<iostream>
#include<iomanip>
#include<cstdlib>   // For using rand and srand functions.
#include<ctime>     // For using time function.
#include<windows.h>     // For using sleep function.
using namespace std;

bool main_menu();
void how_to_play();

int main(){
    bool start_game=1;

    // Runs the main menu
    start_game=main_menu();

    if(start_game){
        start: 
        string play_again;
        int bet=0, your_return=0, your_account=1000;
    
    // Main Game loop
    do{
            system("CLS");  //  Clearing the screen for new game.
            bet=your_return=0; 
            Sleep(1000);
            cout<<"\n\t\tStarting the game!"<<endl;
            cout<<setw(100)<<"Your Account: "<<your_account<<"$"<<endl<<endl;
        while(true){
            Sleep(1000);
            cout<< setw(30) <<"\n\t\tPlace the Bet"<< endl << setw(10) <<"5$    10$    20$    50$    100$    200$    500$    1000$"<<endl
                <<"---->  ";
            cin>> bet;

            // Checking if bet placed is correct
            if ((bet==5) || (bet==10) || (bet==20) || (bet==50) || (bet==100) || (bet==200) || (bet==500) || (bet==1000)){
                if(bet>your_account){
                    cout<<"\n\tSorry, you don't have enough money in your account."<<endl;
                    if(your_account<5){
                        Sleep(500);
                        cout<<"\tQuitting the game!";
                        Sleep(750);
                        goto end;
                    }
                    continue;
                }
                break;
            }
            else{
                cin.clear();
                cin.ignore(INT32_MAX, '\n');
                cout<<setw(30)<<"Invalid amount"<<endl;
            }
        }

        Sleep(250);
        your_account-=bet;
        cout<<setw(100)<<"Your Account: "<<your_account<<"$"<<endl<<endl;
    // Taking cards array and their scores 
    int array_size=13;
    string typecards[]={"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int scorecards[]={2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

    // Producing player's random cards
    srand((time(nullptr)));
    int player_random_card1 = rand() % array_size;
    int player_random_card2 = rand() % array_size;

    // Displaying Player's cards and score 
    Sleep(750);   // Delay for showing player's cards
    cout<<"\n\t\tPlayer's Cards: ";
    cout<< setw(10) << typecards[player_random_card1] << setw(10) << typecards[player_random_card2];
    int player_score=0;
    player_score += scorecards[player_random_card1];
    // Checking if by 'Ace', score exceeds 21.
    if(player_random_card2==12 && player_score+11>21)
        player_score += 1;
    else
        player_score += scorecards[player_random_card2];

    cout<<"\t\t(Score: "<< player_score<<')';


    // Producing Computer's random cards
    int computer_random_card1 = rand() % array_size;
    int computer_random_card2 = rand() % array_size;
   
    // Displaying Computer's cards and score 
    Sleep(1000);   // Delay for showing computer's cards
    cout<<"\n\t\tComputer's Cards: ";
    cout<< setw(8) << typecards[computer_random_card1] << setw(10) <<"?";
    int computer_score = scorecards[computer_random_card1];
    cout<<"\t\t(Score: "<< computer_score<<')';

    // Checking if for first two cards, the player has a score equal to 21.
    if(player_score==21){
        Sleep(1000);   // Delay for showing computer's cards
        cout<<"\n\t\tComputer's Cards: ";
        cout<< setw(8) << typecards[computer_random_card1] << setw(10) <<typecards[computer_random_card2];
        // Checking if by 'Ace', score exceeds 21.
        if(computer_random_card2==12 && computer_score+11>21)
            computer_score += 1;
        else
            computer_score += scorecards[computer_random_card2];
        cout<<"\t\t(Score: "<< computer_score<<')';

        if(computer_score==player_score){
            cout<<"\n\n\t\t---> DRAW!!"
                <<"\n\t\t Your Bet: "<<bet
                <<"\n\t\t Your Return: "<<bet<<endl;
            your_return=bet;
        }
        else{
            cout<<"\n\n\t\t---> Black Jack - You Win!!"
                <<"\n\t\t Your Bet: "<<bet
                <<"\n\t\t Your Return: "<<bet*2<<endl;
            your_return=bet*2;
        }
        // Displaying total money in your account after return
        your_account+=your_return;
        cout<<setw(100)<<"Your Account: "<<your_account<<"$"<<endl<<endl;

        // Asking if user wants to play again
            again1:
            cout<<"\n\nDo you want to play again (Yes or No)?  ";      cin>> play_again;
            if(play_again=="No" || play_again=="no" || play_again=="N" || play_again=="n"){
                cout<<"Quitting the game!"<<endl;
                Sleep(1000);
                break;
            }
            else if(play_again=="Yes" || play_again=="yes" || play_again=="Y" || play_again=="y")
                goto start;
            else{ 
                cin.clear();
                cin.ignore(INT32_MAX,'\n');
                cout<<setw(30)<<"Invalid Input!"<<endl;
                goto again1;
            }

    }

    decision:
    int i=0; 
    string your_decision, computer_decision;

    // Asking user for his decision
    do{
    cout<<"\n\n\t\t\tYour Decision (Hit or Stand)?"<<endl<<"\t\t\t";        cin>> your_decision;
    
    // If user's decision is hit
    if(your_decision=="hit" || your_decision=="Hit" || your_decision=="h" || your_decision=="H"){
            ++i;
            int player_random_card3, player_random_card4, player_random_card5;

        // 1st player hit - Third card
        if(i==1){
            player_random_card3 = rand() % array_size;

            // Displaying player's cards and score after 1st hit
            Sleep(500);
            cout<<"\n\t\tPlayer's Cards: ";
            cout<< setw(10) << typecards[player_random_card1] << setw(10) << typecards[player_random_card2]
                << setw(10)<< typecards[player_random_card3];
            // Checking if by 'Ace', score exceeds 21.
            if(player_random_card3==12 && player_score+11>21)
                player_score += 1;
            else
                player_score += scorecards[player_random_card3];
            cout<<"\t\t(Score: "<< player_score <<')';

            // If player's score exceeds 21
            if(player_score>21){
                // Displaying computer's cards
                Sleep(1000);
                cout<<"\n\t\tComputer's Cards: ";
                cout<< setw(8) << typecards[computer_random_card1] << setw(10) <<typecards[computer_random_card2];
            // Checking if by 'Ace', score exceeds 21.
                if(computer_random_card2==12 && computer_score+11>21)
                    computer_score += 1;                
                else
                    computer_score += scorecards[computer_random_card2];
                cout<<"\t\t\t(Score: "<< computer_score<<')';

                cout<<"\n\n\t\t---> You BUST - Computer Win!!"
                    <<"\n\t\t Your Bet: "<<bet
                    <<"\n\t\t Your Return: "<<bet*0<<endl;
                your_return=bet*0;
                break;
            }
            // If player's score equals 21
            if(player_score==21){
                // Displaying computer's cards
                Sleep(1000);
                cout<<"\n\t\tComputer's Cards: ";
                cout<< setw(8) << typecards[computer_random_card1] << setw(10) <<typecards[computer_random_card2];
                // Checking if by 'Ace', score exceeds 21.
                if(computer_random_card2==12 && computer_score+11>21)
                    computer_score += 1;                
                else
                    computer_score += scorecards[computer_random_card2];
                cout<<"\t\t\t(Score: "<< computer_score<<')';
                
                cout<<"\n\n\t\t---> Black Jack - You Win!!"
                    <<"\n\t\t Your Bet: "<<bet
                    <<"\n\t\t Your Return: "<<bet*2<<endl;
                your_return=bet*2;
                break;
            }
        }

        // 2nd player hit - 4th card
        if(i==2){
            player_random_card4 = rand() % array_size;

            // Displaying player's cards and score after 2nd hit
            Sleep(500);
            cout<<"\n\t\tPlayer's Cards: ";
            cout<< setw(10) << typecards[player_random_card1] << setw(10) << typecards[player_random_card2]
                << setw(10)<< typecards[player_random_card3]<< setw(10)<< typecards[player_random_card4];
            // Checking if by 'Ace', score exceeds 21.
            if(player_random_card4==12 && player_score+11>21)
                player_score += 1;
            else
                player_score += scorecards[player_random_card4];
            cout<<"\t\t(Score: "<< player_score <<')';
        
            // If player's score exceeds 21
            if(player_score>21){
                // Displaying computer's cards
                Sleep(1000);
                cout<<"\n\t\tComputer's Cards: ";
                cout<< setw(8) << typecards[computer_random_card1] << setw(10) <<typecards[computer_random_card2];
                // Checking if by 'Ace', score exceeds 21.
                if(computer_random_card2==12 && computer_score+11>21)
                    computer_score += 1;                
                else
                    computer_score += scorecards[computer_random_card2];
                cout<<"\t\t\t\t\t(Score: "<< computer_score<<')';

                cout<<"\n\n\t\t---> You BUST - Computer Win!!"
                    <<"\n\t\t Your Bet: "<<bet
                    <<"\n\t\t Your Return: "<<bet*0<<endl;
                your_return=bet*0;
                break;
            }
            // If player's score equals 21
            if(player_score==21){
                // Displaying computer's cards
                Sleep(1000);
                cout<<"\n\t\tComputer's Cards: ";
                cout<< setw(8) << typecards[computer_random_card1] << setw(10) <<typecards[computer_random_card2];
                // Checking if by 'Ace', score exceeds 21.
                if(computer_random_card2==12 && computer_score+11>21)
                    computer_score += 1;                
                else
                    computer_score += scorecards[computer_random_card2];
                cout<<"\t\t\t\t\t(Score: "<< computer_score<<')';

                cout<<"\n\n\t\t---> Black Jack - You Win!!"
                    <<"\n\t\t Your Bet: "<<bet
                    <<"\n\t\t Your Return: "<<bet*2<<endl;
                your_return=bet*2;
                break;
            }
            }

        // 3rd player hit - 5th card
        if(i==3){
            player_random_card5 = rand() % array_size;

            // Displaying player's cards and score after 3rd hit
            Sleep(500);
            cout<<"\n\t\tPlayer's Cards: ";
            cout<< setw(10) << typecards[player_random_card1] << setw(10) << typecards[player_random_card2]
                << setw(10)<< typecards[player_random_card3]<< setw(10)<< typecards[player_random_card4]
                << setw(10)<< typecards[player_random_card5];
            // Checking if by 'Ace', score exceeds 21.
            if(player_random_card5==12 && player_score+11>21)
                player_score += 1;
            else
                player_score += scorecards[player_random_card5];
            cout<<"\t\t(Score: "<< player_score <<')';
        
            // If player's score exceeds 21
            if(player_score>21){
                // Displaying computer's cards
                Sleep(1000);
                cout<<"\n\t\tComputer's Cards: ";
                cout<< setw(8) << typecards[computer_random_card1] << setw(10) <<typecards[computer_random_card2];
                // Checking if by 'Ace', score exceeds 21.
                if(computer_random_card2==12 && computer_score+11>21)
                    computer_score += 1;                
                else
                    computer_score += scorecards[computer_random_card2];
                cout<<"\t\t\t\t\t\t(Score: "<< computer_score<<')';

                cout<<"\n\n\t\t---> You BUST - Computer Win!!"
                    <<"\n\t\t Your Bet: "<<bet
                    <<"\n\t\t Your Return: "<<bet*0<<endl;
                your_return=bet*0;
                break;
            }
            // If player's score equals 21
            if(player_score==21){
                // Displaying computer's cards
                Sleep(1000);
                cout<<"\n\t\tComputer's Cards: ";
                cout<< setw(8) << typecards[computer_random_card1] << setw(10) <<typecards[computer_random_card2];
               // Checking if by 'Ace', score exceeds 21.
                if(computer_random_card2==12 && computer_score+11>21)
                    computer_score += 1;                
                else
                    computer_score += scorecards[computer_random_card2];

                cout<<"\t\t\t\t\t\t(Score: "<< computer_score<<')';

                cout<<"\n\n\t\t---> Black Jack - You Win!!"
                    <<"\n\t\t Your Bet: "<<bet
                    <<"\n\t\t Your Return: "<<bet*2<<endl;
                your_return=bet*2;
                break;
            }
            }
                    
    }

    // // If user's decision is stand
    if(your_decision=="stand" || your_decision=="Stand" || your_decision=="s" || your_decision=="S"){
        i=0;
        // Displaying Computer's cards and score
        Sleep(500);
        cout<<"\n\t\tComputer's Cards: ";
        cout<< setw(8) << typecards[computer_random_card1] << setw(10) <<typecards[computer_random_card2];
        // Checking if by 'Ace', score exceeds 21.
                if(computer_random_card2==12 && computer_score+11>21)
                    computer_score += 1;                
                else
                    computer_score += scorecards[computer_random_card2];
        cout<<"\t\t\t\t(Score: "<< computer_score<<')';     

    do{
        if(computer_score<=16){     // Pre established condition for computer's decision
            computer_decision="Hit";
            
        // If computer's decision is hit
            if(computer_decision=="Hit"){
                ++i;
                int computer_random_card3, computer_random_card4, computer_random_card5;

                // Computer's 1st hit - 3rd card
                if(i==1){
                    computer_random_card3 = rand() % array_size;

                    // Displaying Computer's cards and score after 1st hit
                    Sleep(1000);
                    cout<<"\n\t\tComputer's Cards: ";
                    cout<< setw(8) << typecards[computer_random_card1] << setw(10) <<typecards[computer_random_card2]
                        << setw(10) <<typecards[computer_random_card3];
                    // Checking if by 'Ace', score exceeds 21.
                    if(computer_random_card3==12 && computer_score+11>21)
                        computer_score += 1;                
                    else
                        computer_score += scorecards[computer_random_card3];
                    cout<<"\t\t\t(Score: "<< computer_score<<')';

                    // If computer's score exceeds 21
                    if(computer_score>21){
                        cout<<"\n\n\t\t---> Computer BUST - You Win!!"
                            <<"\n\t\t Your Bet: "<<bet
                            <<"\n\t\t Your Return:"<<bet*2<<endl;
                        your_return=bet*2;
                        break;
                    }
                    // If computer's score equals 21
                    if(computer_score==21){
                        cout<<"\n\n\t\t---> Black Jack - Computer Win!!"
                            <<"\n\t\t Your Bet: "<<bet
                            <<"\n\t\t Your Return:"<<bet*0<<endl;
                        your_return=bet*0;
                        break;
                    }
                }

                // Computer's 2nd hit - 4th card
                if(i==2){
                    computer_random_card4 = rand() % array_size;

                    // Displaying Computer's cards and score after 2nd hit
                    Sleep(1000);
                    cout<<"\n\t\tComputer's Cards: ";
                    cout<< setw(8) << typecards[computer_random_card1] << setw(10) <<typecards[computer_random_card2]
                        << setw(10) <<typecards[computer_random_card3]<< setw(10) <<typecards[computer_random_card4];
                    // Checking if by 'Ace', score exceeds 21.
                    if(computer_random_card4==12 && computer_score+11>21)
                        computer_score += 1;                
                    else
                        computer_score += scorecards[computer_random_card4];
                    cout<<"\t\t(Score: "<< computer_score<<')';

                    // If computer's score exceeds 21
                    if(computer_score>21){
                        cout<<"\n\n\t\t---> Computer BUST - You Win!!"
                            <<"\n\t\t Your Bet: "<<bet
                            <<"\n\t\t Your Return:"<<bet*2<<endl;
                        your_return=bet*2;
                        break;
                    }
                    // If computer's score equals 21
                    if(computer_score==21){
                        cout<<"\n\n\t\t---> Black Jack - Computer Win!!"
                            <<"\n\t\t Your Bet: "<<bet
                            <<"\n\t\t Your Return:"<<bet*0<<endl;
                        your_return=bet*0;
                        break;
                    }
                }

                // Computer's 3rd hit - 5th card
                if(i==3){
                    computer_random_card5 = rand() % array_size;

                    // Displaying Computer's cards and score after 3rd hit
                    Sleep(1000);
                    cout<<"\n\t\tComputer's Cards: ";
                    cout<< setw(8) << typecards[computer_random_card1] << setw(10) <<typecards[computer_random_card2]
                        << setw(10) <<typecards[computer_random_card3]<< setw(10) <<typecards[computer_random_card4]
                        << setw(10) <<typecards[computer_random_card5];
                    // Checking if by 'Ace', score exceeds 21.
                    if(computer_random_card5==12 && computer_score+11>21)
                        computer_score += 1;                
                    else
                        computer_score += scorecards[computer_random_card5];
                    cout<<"\t(Score: "<< computer_score<<')';

                    // If computer's score exceeds 21
                    if(computer_score>21){
                        cout<<"\n\n\t\t---> Computer BUST - You Win!!"
                            <<"\n\t\t Your Bet: "<<bet
                            <<"\n\t\t Your Return:"<<bet*2<<endl;
                        your_return=bet*2;
                        break;
                    }
                    // If computer's score equals 21
                    if(computer_score==21){
                        cout<<"\n\n\t\t---> Black Jack - Computer Win!!"
                            <<"\n\t\t Your Bet: "<<bet
                            <<"\n\t\t <<endl:"<<bet*0<<endl;
                        your_return=bet*0;
                        break;
                    }
                }
            }
        }
    
        if(computer_score>16){
            computer_decision="Stand";

        // If computer's decision is stand
            if(computer_decision=="Stand"){
                
                // If computer's score exceeds 21
                if(computer_score>21){
                    cout<<"\n\n\t\t---> Computer BUST - You Win!!"
                        <<"\n\t\t Your Bet: "<<bet
                        <<"\n\t\t Your Return:"<<bet*2<<endl;
                    your_return=bet*2;
                    break; 
                }
                // If computer's score equals 21
                if(computer_score==21){
                    cout<<"\n\n\t\t---> Black Jack - Computer Win!!"
                        <<"\n\t\t Your Bet: "<<bet
                        <<"\n\t\t Your Return:"<<bet*0<<endl;
                    your_return=bet*0;
                    break;
                }
                // If computer's score is greater than player's score
                if(computer_score>player_score){
                    cout<<"\n\n\t\t---> You Lose - Computer Win!!"
                        <<"\n\t\t Your Bet: "<<bet
                        <<"\n\t\t Your Return:"<<bet*0<<endl;
                    your_return=bet*0;
                    break;
                }
                // If computer's score is less than player's score
                if(computer_score<player_score){
                    cout<<"\n\n\t\t---> Computer lose - You Win!!"
                        <<"\n\t\t Your Bet: "<<bet
                        <<"\n\t\t Your Return:"<<bet*2<<endl;
                    your_return=bet*2;
                    break;
                }
                // If computer's score is equal to player's score
                if(computer_score==player_score){
                    cout<<"\n\n\t\t---> DRAW!!"
                        <<"\n\t\t Your Bet: "<<bet
                        <<"\n\t\t Your Return:"<<bet<<endl;
                    your_return=bet;
                    break;
                }
            }
        }
    
    
    }while(computer_score<=16); 
    }

    // If user's decision is not valid 
    if(cin.fail() || (your_decision!="hit" && your_decision!="Hit" && your_decision!="h" && your_decision!="H" && your_decision!="stand" && your_decision!="Stand" && your_decision!="s" && your_decision!="S")){
        cin.clear();
        cin.ignore(INT32_MAX, '\n');
        cout<<setw(40)<<"Invalid Input!"<<endl;
        goto decision;
    }

    }while(your_decision=="hit" || your_decision=="Hit" || your_decision=="h" || your_decision=="H");
    
    // Displaying total money in your account after return
    your_account+=your_return;
    cout<<setw(100)<<"Your Account: "<<your_account<<"$"<<endl<<endl;
    if(your_account==0){
        Sleep(500);
        cout<<"\n\tYou can't play more since you ran out of money!"<<endl;
        Sleep(500);
        cout<<"\tQuitting the game!";
        Sleep(750);
        break;
    }


    // Asking if user wants to play again 
        again2: 
        cout<<"\n\nDo you want to play again (Yes or No)?  ";      cin>> play_again;
        if(play_again=="No" || play_again=="no" || play_again=="N" || play_again=="n"){
            cout<<"Quitting the game!"<<endl;
            Sleep(1000);
            goto end;
        }
        else if(cin.fail() || (play_again!="Yes" && play_again!="yes" && play_again!="Y" && play_again!="y")){
            cin.clear();
            cin.ignore(INT32_MAX,'\n');
            cout<<setw(30)<<"Invalid Input!"<<endl;
            goto again2;
        }

    }while(play_again=="Yes" || play_again=="yes" || play_again=="Y" || play_again=="y");

    }
    
    end: 
    return 0;
}

bool main_menu(){
    system("CLS");      // Clearing the screen
    int user_option;

    // Displaying the menu
    cout<<"\n\t\tWelcome To  BlackJack Game!"
            "\t\t   _________\n"
            "\t\t\t\t\t\t\t  | A       |\n"
            "\t\t\t\t\t\t\t  |         |\n"
            "\t\t\t\t\t\t\t  |    "<<char(6)<<"    |\n"
            "\t\t\t\t\t\t\t  |         |\n"
            "\t\t\t\t\t\t\t  |       A |\n"
            "\t\t\t\t\t\t\t  |_________|\n"<<endl;
    Sleep(500);
    cout<<"\t1. Start Game\n"
        <<"\t2. How to Play\n"
        <<"\t3. Exit Game"<<endl;
    Sleep(500);
    again: 
    cout<<setw(46)<<"\nEnter Your Option : ";       cin>>user_option;
    
    if(cin.fail() || (user_option<1 || user_option>3)){
        cin.clear();
        cin.ignore(INT32_MAX, '\n');
        cout<<"\n\t Invalid Input! Try Again.\n";
        goto again;
    }

    switch(user_option){
        case 1:                 // Starts the game
            return 1;       
        case 2:                 // Opens help menu
            how_to_play();      break;
        case 3:                 // Exit from the game
            Sleep(500);
            cout<<"\n\t\tExiting the Game!"<<endl;
            Sleep(1000);
            return 0;       
    }
}

void how_to_play(){
    system("CLS");
    // Displaying the instruction manual
    cout<<"\n\t\tHow to play:\n\n"; 
    Sleep(700);

    cout <<
        "Table of Contents:\n"
        "    Introduction\n"
        "        1.1 Objective of the Game\n"
        "        1.2 Components\n"
        "        1.3 Setup\n"
        "        1.4 Game Flow\n\n"

        "    Game Rules\n"
        "        2.1 Card Values\n"
        "        2.2 Dealing\n"
        "        2.3 Player's Turn\n"
        "        2.4 computer's Turn\n"
        "        2.5 Winning and Losing\n"
        "        2.6 Draw \n"
        "        2.7 Blackjack (Natural 21)\n"

        "Introduction\n"
        "    1.1 Objective of the Game:\n"
        "        The objective of Blackjack is to beat the computer(computer) by having a hand value closer to 21 without exceeding it.\n\n"
        
        "    1.2 Components:\n"
        "        - Standard 52-card deck(s)\n"
        "        - Blackjack table\n\n"

        "    1.3 Setup:\n"
        "        - Each player is dealt two cards.\n"
        "        - The computer receives one card face up and one face down.\n\n"

        "    1.4 Game Flow:\n"
        "        - Players take turns deciding whether to \"hit\" (take another card) or \"stand\" (keep their current hand).\n"
        "        - The computer follows a specific set of rules when revealing their face-down card and drawing additional cards.\n\n"

        "Game Rules\n"
        "    2.1 Card Values:\n"
        "        - Number cards (2-10) are worth their face value.\n"
        "        - Face cards (Jack, Queen, King) are worth 10.\n"
        "        - Aces can be worth 1 or 11, depending on which value benefits the hand more. If the score by adding 11 exceeds 21, "
        "          ace will worth 1.\n\n"

        "    2.2 Dealing:\n"
        "        - Players and the computer are dealt two cards each.\n"
        "        - Players' cards are usually dealt face up, while one of the computer's cards remains face down.\n\n"

        "    2.3 Player's Turn:\n"
        "        - Players can choose to \"hit\" (take another card) or \"stand\" (keep their current hand).\n\n"

        "    2.4 Computer's Turn:\n"
        "        - The computer reveals their face-down card once player has completed his turn.\n"
        "        - The computer must follow a specific set of rules for drawing additional cards.\n\n"

        "    2.5 Winning and Losing:\n"
        "        - Players win if their hand is closer to 21 than the computer's without exceeding 21 and the player's return is double his original bet.\n"
        "        - Players lose if their hand exceeds 21 or if the computer's hand is closer to 21 and the player's return is zero\n\n"

        "    2.6 Draw:\n"
        "        - If a player and the computer have the same hand value, the result is a draw, and the player's bet is returned.\n\n"

        "    2.7 Blackjack (Natural 21):\n"
        "        - A \"Blackjack\" is an Ace and a 10-value card.\n\n"
        
        "Press b or B to go Back to mian menu: ";

        again: 
        char go_back;           cin>> go_back;
        if(cin.fail() || (go_back!='b' && go_back!='B')){
            cin.clear();
            cin.ignore(INT32_MAX,'\n');
            cout<< "\nWrong input!\nPlease enter 'b' or 'B'\n";
            goto again;
        }
        main_menu();


}
