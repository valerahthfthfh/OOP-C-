#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Game {
private:
    string title;
    string developer;

public:
    Game(const string& title, const string& developer) {
        this->title = title;
        this->developer = developer;
    }

    string getTitle() const {  
        return title;
    }

    string getDeveloper() const {  
        return developer;
    }
};

class GameLibrary {
private:
    vector<Game> games;

public:
    void addGame(const Game& game) {  
        games.push_back(game);
    }

    void listGames() const {
        for (int i = 0; i < games.size(); i++) {
            cout << "Title: " << games[i].getTitle() << ", Developer: " << games[i].getDeveloper() << endl;  
        }
    }
};

class GameLibraryManager {
public:
    void addGameToLibrary(GameLibrary& library, const Game& game) {
        library.addGame(game);
    }

    void showLibraryGames(const GameLibrary& library) const {
        library.listGames();
    }
};

int main() {
    GameLibrary library;
    GameLibraryManager manager;

    manager.addGameToLibrary(library, Game("The Witcher 3: Wild Hunt", "CD Projekt Red"));
    manager.addGameToLibrary(library, Game("Dark Souls", "FromSoftware"));

    cout << "Games in the library:" << endl;
    manager.showLibraryGames(library);

    
}

// i use SRP, OCP, LSP - mb.
/*
* to be honest, I chose them for nothing, 
* but if the requirements are related,
* then it's just the right thing to do.
*/
