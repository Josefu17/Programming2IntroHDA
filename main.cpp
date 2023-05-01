#include <iostream>
#include <string>

using namespace std;

char* stringConcatenate(string* str1, string* str2);
double harmonischeReiheRec(int n);
double harmonicRecursion(const int &current,const int &n, double &sum);


/**
 * @brief stringConcatenate concatenates 2 given strings at the addresses of pointers
 * str1 and str2 whilst adding the characher '-' in between.
 * @return a pointer to the address, where the concatenated string is stored
 */
char* stringConcatenate(string* str1, string* str2){
    int size1 = str1->size();
    int size2 = str2->size();
    int size = size1 + size2 + 1;

    char* arr = new char[size];

    int i=0;
    while(i<size){
        for(int j=0; j<size1; j++){
            arr[i++] = str1->at(j);
        }

        arr[i++] = '-';

        for(int j=0; j<size2; j++){
            arr[i++] = str2->at(j);
        }
    }

    return arr;
}

/**
 * @brief harmonischeReiheRec - recursive function to calculate the harmonic sequence for the value @param n
 * @return the calculated value
 */
double harmonischeReiheRec(int n){
    double sum = 0;
    harmonicRecursion(1, n, sum);
    return sum;
}


/**
 * @brief harmonicRecursion - recursive function to do the work for the function harmonischeReiheRec
 * @param current - current step
 * @param n - goal
 * @param sum - calculated sum thus far
 * @return harmonic sequence value for n
 */
double harmonicRecursion(const int &current,const int &n, double &sum){
    if(current > n){
        return sum;
    }
    else{
        sum += 1.0 / current;
        return harmonicRecursion( current+1, n, sum);
    }
}



double harmonischeReiheIter(int n){
    double sum = 0;
    for(int i=1; i <= n; i++){
        sum += 1.0/i;
    }
    return sum;
}






int main()
{

//    string *str1p, *str2p;
//    string str1 = "def";
//    string str2 = "abc";
//    str1p = &str1;
//    str2p = &str2;

//    char* arr = stringConcatenate(str1p, str2p);

//    int size = str1p->size() + str2p->size() + 1;

//    for(int i=0; i<size; i++){
//        cout << arr[i] << " ";
//    }
//    delete[] arr;




    cout << "Harmonische Reihe Wert zu berechnen? " << endl << "\t";
    int input;
    cin >> input;
    cout << harmonischeReiheRec(input) << endl;
    cout << harmonischeReiheIter(input) << endl;



    return 0;
}
