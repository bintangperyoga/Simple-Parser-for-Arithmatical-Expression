#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main()
{
    string inputUser;
    int kb = 0;
    int kt = 0;
    int jumlahE = 0;
    int jumlahOp = 0;
    bool angka, op, error;
    angka = false;
    op = false;
    error = false;
    getline(cin,inputUser);
    for(int i = 0; i < inputUser.length(); i++){
        if(error == false){
            if(inputUser[i] == '1' || inputUser[i] == '2' || inputUser[i] == '3' ||
                inputUser[i] == '4' || inputUser[i] == '5' || inputUser[i] == '6' ||
                inputUser[i] == '7' || inputUser[i] == '8' || inputUser[i] == '9' ||
                inputUser[i] == '0') {
                angka = true;
                op = false;
                jumlahOp = 0;
            }
            else if(inputUser[i] == '+' || inputUser[i] == '-' || inputUser[i] == ':' ||
                    inputUser[i] == 'X' || inputUser[i] == 'x' ){
                jumlahOp = jumlahOp + 1;
                op = true;
            }
            else if(inputUser[i] == 'E' || inputUser[i] == 'e' || inputUser[i] == ' ' ||
                    inputUser[i] == '(' || inputUser[i] == ')' || inputUser[i] == ','){
                if(inputUser[i] == 'E' || inputUser[i] == 'e'){
                    jumlahE = jumlahE + 1;
                }
                error = false;
            }
            else{
                error = true;
                cout<<"Error";
            }
            if(inputUser[i] == ' ' || inputUser[i] == ')' || i == (inputUser.length()-1)){
                if (jumlahE > 1 || jumlahOp > 1){
                    error = true;
                    cout<<"Error";
                }
                else if(angka == true){
                    cout<<"Angka ";
                    angka = false;
                }
                else if( op == true){
                    cout<<"Operator ";
                    op = false;
                }
                jumlahOp = 0;
                jumlahE = 0;
            }
            if(inputUser[i] == '(' && error == false){
                kb = kb + 1;
                cout<<"KurungBuka ";
                error = false;
            }
            if(inputUser[i] == ')' && error == false){
                kt = kt + 1;
                cout<<"KurungTutup ";
                error = false;
            }
        }
    }
    if(error == true){
        cout<<""<<endl;
        cout << "TIDAK VALID" << endl;
    }
    else{
        if(kb != kt){
            cout<<""<<endl;
            cout << "TIDAK VALID" << endl;
        }
        else{
            if(inputUser[inputUser.length()-1] == '+' || inputUser[inputUser.length()-1] == '-' ||
               inputUser[inputUser.length()-1] == ':' || inputUser[inputUser.length()-1] == 'X' ||
               inputUser[inputUser.length()-1] == 'x' ){
                cout<<""<<endl;
                cout<<"TIDAK VALID"<<endl;
            }
            else{
                cout<<""<<endl;
                cout << "VALID";
            }
        }
    }
    return 0;
}
