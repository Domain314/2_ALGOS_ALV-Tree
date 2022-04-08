#include "AVLManager.hpp"

AVLManager::AVLManager() {
    setupTree();
}

void AVLManager::setupTree() {
    feedNewTree();
    display = new Display();
    display->printTree(holders.at(0));
    display->printDisplays();
    delete display;
    holders.clear();
    setupTree();
}

void AVLManager::feedNewTree() {
    string path;
//    path = "/home/domain/Nextcloud/Documents/Technikum/2_Semester/ALGOS/AVLTree/IMPORT-DATA5.txt";
    cout << "Feed the tree! (Drag&Drop): ";
    cin >> path;

    ifstream inFile(path, ios::in);
    if( inFile.fail( ) ) {
        cerr << "Error: Datei nicht gefunden oder kann nicht geöffnet werden:\n->" << path <<endl;
        feedNewTree();  // Error;
    } else {
        Holder* holder = new Holder();

        string lineStr;
        while (getline(inFile, lineStr)) {
            int error = holder->insertNode(stoi(lineStr));
            if (error == 0) continue;
            else printError(error);
        }
        holders.push_back(holder);
    }
}

void AVLManager::printError(int error) {
    switch (error) {
        case 1: std::cout << "Error 1: Duplicate Numbers >:(" << endl; break;
        case 2: std::cout << "Error 2: Internal Error :(" << endl; break;
        case 3: std::cout << "Error 1: Unexpected Error oO" << endl; break;
    }
}