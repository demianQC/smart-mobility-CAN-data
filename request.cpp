 
 
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char* argv[]) 
{
    vector<string> ids;
    vector<string> idsData;
    string data;
    string repetitive;
    string arguments;
    string actualData;
    string id_argument;
    int position = 0;
    int finalPosition = 0;
    ifstream inputFile;

    if(argc < 3){
        cerr << "Usage: request DataFile ID\n";
        cerr << "Example: request asdf.txt 0x199\n";
        exit(1);
    }else{
        id_argument.assign(argv[2]);
    }

    inputFile.exceptions(std::ifstream::failbit|std::ifstream::badbit);
    try {
        inputFile.open(argv[1],ios::in);
        getline(inputFile,data,'\0');
        repetitive = data;
    }catch(...){
        std::cerr << "Exception opening /reading /closing file\n";
    }
    //cout << data << endl;
    if(inputFile.is_open()){
        inputFile.close();
    }
    string delimiter;
    if(id_argument.length() == 5){
        delimiter = "Standard ID: "+id_argument;
    }else if(id_argument.length() == 10){
        delimiter = "Extended ID: "+id_argument;
    }else{
        cerr << "Invalid ID argument\n";
        cerr << "Valid ID format: 0xYYY or 0xZZZZZZZZ \n";
        exit(1);
    }
    ofstream file_out;
    //file_out.open("ID_"+id_argument+".new");
    string lineDelimiter = "\n";

    while(data.length()>0){
        position = data.find(delimiter);
        data.erase(0,position);
        finalPosition = data.find(lineDelimiter);
        arguments = data.substr(0,finalPosition+1);
       // file_out << arguments ;
        cout << arguments;
        data.erase(0,finalPosition+1);
    }
    //file_out.close();
    return 0;
}
