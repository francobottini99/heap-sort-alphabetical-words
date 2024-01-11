#include <sstream>
#include <fstream> 
#include "Heap.h"

string dirInput = "D:/009) FRANCO/04) FACULTAD/22) ALGORITMOS Y ESTRUCTURAS DE DATOS/Segundo Parcial/Input.txt";
string dirOutput = "D:/009) FRANCO/04) FACULTAD/22) ALGORITMOS Y ESTRUCTURAS DE DATOS/Segundo Parcial/Output.txt";

string correctString(string str);
list<string> readFile(string dir);
void writeFile(list<pair<string, int>> data, string dir);

int main() {    
    int words;
    int comparisons;
    Heap heap(4);
    list<string> data = readFile(dirInput);
    list<pair<string, int>> results;

    words = data.size();

    list<string> :: iterator it;
    for(it = data.begin(); it != data.end(); ++it) {
        heap.insert(*it);
    } 
    heap.print();

    system("PAUSE");
    system("CLS");

    comparisons = heap.sort();   

    heap.print();

    results = heap.breadth();

    results.push_front({"N° DE COMPARACIONES REALIZADAS: " + to_string(comparisons) + "\n", 0}); 
    results.push_front({"N° DE PALABRAS TOTALES: " + to_string(words), 0}); 
    results.push_front({"N° DE PALABRAS SIN REPETIR: " + to_string(heap.size()), 0}); 
    writeFile(results, dirOutput);

    system("PAUSE");
    return 0;
} 

void writeFile(list<pair<string, int>> data, string dir) {
    ofstream writer(dir);
    writer.clear();

    list<pair<string, int>> :: iterator it;
    for(it = data.begin(); it != data.end(); ++it) {
        if((*it).second > 0){
            writer << (*it).first + " (" + to_string((*it).second) + ")" + "\n";
        } else {
            writer << (*it).first + "\n";
        }

    } 
    writer.close();
}

list<string> readFile(string dir) {
    list<string> data;
    ifstream reader(dir);
    string line;

    while(getline(reader, line)) {
        istringstream isstream(line);
        
        while(!isstream.eof()){
            string tempStr;
            isstream >> tempStr; 

            tempStr = correctString(tempStr);
            if(tempStr != "") {
                data.push_back(tempStr);
            }    
        }
    }   
    reader.close();

    return data;
}

string correctString(string str) {
    string result = "";

    if(str.find("á") != string::npos){
        str.replace(str.find("á"), 1, "a");
    }

    if(str.find("é") != string::npos){
        str.replace(str.find("é"), 1, "e");
    }

    if(str.find("í") != string::npos){
        str.replace(str.find("í"), 1, "i");
    }

    if(str.find("ó") != string::npos){
        str.replace(str.find("ó"), 1, "o");
    }

    if(str.find("ö") != string::npos){
        str.replace(str.find("ö"), 1, "o");
    }

    if(str.find("ú") != string::npos){
        str.replace(str.find("ú"), 1, "u");
    }

    if(str.find("ü") != string::npos){
        str.replace(str.find("ü"), 1, "u");
    }

    if(str.find("ñ") != string::npos){
        str.replace(str.find("ñ"), 1, "n");
    }

    if(str.find("Á") != string::npos){
        str.replace(str.find("Á"), 1, "A");
    }

    if(str.find("É") != string::npos){
        str.replace(str.find("É"), 1, "E");
    }

    if(str.find("Í") != string::npos){
        str.replace(str.find("Í"), 1, "I");
    }

    if(str.find("Ó") != string::npos){
        str.replace(str.find("Ó"), 1, "O");
    }

    if(str.find("Ö") != string::npos){
        str.replace(str.find("Ö"), 1, "O");
    }

    if(str.find("Ú") != string::npos){
        str.replace(str.find("Ú"), 1, "U");
    }

    if(str.find("Ü") != string::npos){
        str.replace(str.find("Ü"), 1, "U");
    }

    if(str.find("Ñ") != string::npos){
        str.replace(str.find("Ñ"), 1, "Ñ");
    }

    for(int i = 0; i < str.size(); i++) {
        if((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90)) {
            result += str[i];
        } 
    }

    return result;
}