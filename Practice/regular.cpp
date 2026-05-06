#include<iostream>
#include<istream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

vector<double> readLine(istream & is){
    vector<double> row;
    string line;

    getline(is, line);

    istringstream tokenized(line);
    
    string word;

    while(tokenized >> word){

        row.push_back(stod(word));

        return row;
    }
}

vector<vector<double>> readMatrix(istream & is){
    vector<vector<double>> matrix;
    vector<double> row;

    while(! is.eof()){
        row =readLine(is);
        matrix.push_back(row);
    }

}

int main(){

    fstream myFile;
    myFile.open("double rows");

    vector<double> row =readLine(myFile);

    for(auto item : row){
        cout << item << " ";
    }

    cout << endl;

    cout<< "----------------MATRIX-------------"<<endl;
    myFile.seekg(0, std::iso::beg);

    vector<vector<double>> matrix;

    matrix = readMatrix(myFile);

    for (auto row: matrix){
        for (auto item: row){
            cout << item << " ";
        }
    }


    myFile.close();
    return 0;
}