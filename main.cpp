#include <iostream>
#include <algorithm>
using namespace std;

void RPS(unsigned short int num_reqs, unsigned short int num_props, unsigned short int out_num);

int main (){

    unsigned short int n_reqs = 1;
    unsigned short int n_props = 1;
    unsigned short int out = 1;

    while (out != 0)
    {
        cin >> n_reqs;
        cin >> n_props;

        if (n_reqs > 0){
            RPS (n_reqs, n_props, out);
            out++;
            cout << endl;
        }
        else{
            out = 0;
        }
    }

    return 0;
}

void RPS(unsigned short int num_reqs, unsigned short int num_props, unsigned short int out_num){

    string names_props[num_props];
    float price[num_props];
    float max_price;
    unsigned short int met_reqs[num_props];
    unsigned short int min_mets;
    int pos_result;

    for (int i = 0; i <= num_reqs; i++){
        cin.ignore(80, '\n');
    }

    for (int i = 0; i < num_props; i++)
    {
        cin >> names_props[i];
        cin >> price[i];
        cin >> met_reqs[i];

        for (int j = 0; j <= met_reqs[i]; j++){
            cin.ignore(80, '\n');
        }
    }

    min_mets = *min_element(met_reqs, met_reqs+num_props);
    max_price = *max_element(price, price+num_props);

    pos_result = 0;
    for (int i = 0; i < num_props; i++){
        if (met_reqs[i] == min_mets && max_price > price[i]){
            max_price = price[i];
            pos_result = i;
        }
    }
 
    cout << "RFP #" << out_num << endl;
    cout << names_props[pos_result] << endl;
}