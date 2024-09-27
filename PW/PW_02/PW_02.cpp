#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <filesystem>

using namespace std;

void cerateFile(string fileName) {    

    ofstream outputFile(fileName);
    
    if (outputFile.is_open()) {
        
        outputFile << "Азаров А. А. Группа - 1623." << endl;        
        outputFile.close();

        cout << "Новый файл " << fileName << " успешно создан!" << endl;
    }
    else {
        cerr << "Ошибка открытия файла!" << endl;
    }

}

void renameFile(string fileName, string newFileName) {

    const int maxPath = 256;

    char old_path[maxPath];
    char new_path[maxPath];
  
    strcpy_s(old_path, fileName.c_str());
    strcpy_s(new_path, newFileName.c_str());

    if (rename(old_path, new_path) == 0) {
        cout << "Файл '" << old_path << "' переименован в '" << new_path << "'" << endl;
    }
    else 
    {
        cerr << "Ошибка переименования файла!" << endl;
    }
}

void createDir(string dirName) {
    
    if (!CreateDirectory(wstring(dirName.begin(), dirName.end()).c_str(), NULL)) {
        cerr << "Ошибка создания каталога!" << endl;
    }
    else
    {
        cout << "Каталог " << dirName << " создан!" << endl;
    }
}

void deleteDir(string dirName) { 

    if (!RemoveDirectory(wstring(dirName.begin(), dirName.end()).c_str())){
        cerr << "Ошибка удаления каталога!" << endl;
    }
    else
    {
        cout << "Каталог " << dirName << " удален!" << endl;
    }
}

void printDir(const filesystem::path& path) {
    for (const auto& entry : filesystem::directory_iterator(path)) {
        cout << entry.path() << endl;
        if (entry.is_directory()) {
            printDir(entry.path());
        }
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string fileName = "FileText.txt";
    string newFileName = "NewFileText.txt";
    string dirName = "newFolder";

    //cerateFile(fileName);
    //renameFile(fileName,newFileName);

    //createDir(dirName);
    //deleteDir(dirName);
    
    printDir(filesystem::current_path());
    return 0;
}
