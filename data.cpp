 
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;

int main(int argc,char* argv[]) 
{
    vector<string> ids;
    vector<string> idsData;
    string data;
    string repetitive;
    string arguments;
    string actualData;
    int position = 0;
    int finalPosition = 0;
    ifstream inputFile;

    inputFile.exceptions(std::ifstream::failbit|std::ifstream::badbit);
    try {
        inputFile.open(argv[1],ios::in);
        getline(inputFile,data,'\0');
        repetitive = data;
    }catch(...){//std::ifstream::failure e){
        std::cerr << "Exception opening /reading /closing file\n";
    }
    //cout << data << endl;
    if(inputFile.is_open()){
        inputFile.close();
    }
    string delimiter = ": ";
    string lineDelimiter = "\n";
    ofstream id_file;
    id_file.open("vehicle_ids.txt",std::ofstream::out);
    while(data.length() > 0)
    {   
        position = data.find(delimiter);
        finalPosition = data.find(lineDelimiter);
        arguments = data.substr(0,position);
        if(arguments == "Standard ID"){
            actualData = ("Standard ID: " + data.substr(position + delimiter.length(),5));
        }else if(arguments == "Extended ID"){
            actualData = ("Extended ID: " + data.substr(position + delimiter.length(),10));
        } 

        data.erase(0,finalPosition + 1);  
        std::vector<string>::iterator itr = std::find(ids.begin(), ids.end(), actualData);
        if(itr == ids.end()){
            ids.push_back(actualData);
            id_file << ids.back() << endl;
            cout << ids.back() << endl;
        }
        //std::cout << "Data.length(): " << data.length() << std::endl;
    }
    id_file.close();

    cout << "---------- Particular Data --------- \n";

    std::vector<string>::iterator it = ids.begin();

    cout << "Ids size:" << ids.size() << endl;
    while(ids.size() > 0){
        string aux = repetitive;
        while(aux.length()>0){
            position = aux.find(ids.front());
            aux.erase(0,position);
            finalPosition = aux.find(lineDelimiter);
            arguments = aux.substr(0,finalPosition+1);
            cout << arguments ;
            aux.erase(0,finalPosition+1);
        }
        ids.erase(it);
        it = ids.begin();
        cout << "---------- ---------- ---------- \n";
    }
    
    return 0;
}