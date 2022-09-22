#ifndef Intro_menu
#define Intro_menu

#include <iostream>
using namespace std;

class IntroMenu{
    private:

    public:

    IntroMenu();
    void enterGameMode();

};

IntroMenu::IntroMenu(){
    
}

void IntroMenu::enterGameMode(){
    cout << "██████╗░░█████╗░░██████╗░██████╗███████╗██████╗░   ░██████╗░░█████╗░███╗░░░███╗███████╗\n";
    cout << "██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██╔══██╗   ██╔════╝░██╔══██╗████╗░████║██╔════╝\n";
    cout << "██████╔╝███████║╚█████╗░╚█████╗░█████╗░░██████╔╝   ██║░░██╗░███████║██╔████╔██║█████╗░░\n";
    cout << "██╔═══╝░██╔══██║░╚═══██╗░╚═══██╗██╔══╝░░██╔══██╗   ██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░\n";
    cout << "██║░░░░░██║░░██║██████╔╝██████╔╝███████╗██║░░██║   ╚██████╔╝██║░░██║██║░╚═╝░██║███████╗\n";
    cout << "╚═╝░░░░░╚═╝░░╚═╝╚═════╝░╚═════╝░╚══════╝╚═╝░░╚═╝   ░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝\n";
    


    cout << "Which game mode would you like to play?\n";
    cout << 
    "1) Player VS Player\n" << 
    "2) Human Player VS Random Player\n" <<
    "3) Straight Line Player VS Random Player\n" <<
    "4) Random Player VS Random Player\n" <<
    "5) Human Player VS MonteCarlo Computer\n";
    cout << endl;
}


#endif