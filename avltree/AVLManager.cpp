#include "AVLManager.hpp"

AVLManager::AVLManager() {}

// try to load tree from save, by index. make a new tree, if not saved yet
Holder* AVLManager::getTree(string command) {
    try {
        int index = stoi(command);
        if (command.length() == 1 && (holders.size()-1) >= index) {
            return holders.at(stoi(command));
        }
    } catch (...) {}
    int res = feedNewTree(command);
    if (res != -1) return holders.at(res);
    else return nullptr;
}

// feed a tree with data
int AVLManager::feedNewTree(string path) {
    ifstream inFile(path, ios::in);
    if( inFile.fail( ) ) {
        cerr << "Error: Datei nicht gefunden oder kann nicht geöffnet werden:\n->" << path <<endl;
        return -1;  // Error;
    } else {
        Holder* holder = new Holder();
        string lineStr;
        while (getline(inFile, lineStr)) {
            int error = holder->insertNode(stoi(lineStr));
            if (error == 0) continue;
            else printError(error);
        }
        holders.push_back(holder);
        holder->getAVLCondition(holder->getHead());
        std::cout << "\nTree successfully added and saved at " << holders.size()-1 << ".\n\n";
        return (holders.size()-1);
    }
}

// some error prints
void AVLManager::printError(int error) {
    switch (error) {
        case 1: std::cout << "Error 1: Duplicate Numbers >:(" << endl; break;
        case 2: std::cout << "Error 2: Internal Error :(" << endl; break;
        case 3: std::cout << "Error 1: Unexpected Error oO" << endl; break;
    }
}