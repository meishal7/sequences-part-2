/*  Sequence.cpp 
 *  
 *  This program creates two different types of sequences - Arithmetic and Geometric and 
 *  calculates their series. It can calculate the sum of sequence terms no neccesary from 
 *  the first to last element, but beginning from any element depending on sum_seq() function 
 *  arguments. It has one abstract class AbstractSeq and two derived classes ArithmeticSeq 
 *  and GeometricSeq. Each derived class overrides abstract seq() function.
 * 
 *  Author:     Elena Mudrakova
 *  Module:     12
 *  Project:    HW 12, Part 2
 *
 *  Algorithm:
 *  1. Declare abstract class AbstractSeq.
 *  2. Declare abstract void function seq() that accepts initial sequence term int k
 *     and vector of integers.
 *  3. Declare void print_seq() that accepts int k, int m for first and last element 
 *     between what to print the sequence and a vector of int.
 *  4. Declare void sum_seq() that accepts int k, int m for first and last element
 *     to sum the sequence and a vector of int.
 *  5. Declare derived class ArithmeticSeq.
 *  6. Override seq() function so it creates arithmetic sequence.
 *  7. Declare derived class GeometricSeq.
 *  8. Override seq() function so it creates geometric sequence.
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class AbstractSeq{
    public:
        void virtual seq(int k, vector<int> &vec) = 0;
        void print_seq(int k, int m, vector<int>vec){
            for(int i = k; i < m; i++){
                cout << vec[i] << " ";
            }
        }
        void sum_seq(int k, int m, vector<int>vec){
            int sum = 0;
            for(int i = k; i < m; i++){
                sum += vec[i];
            }
            cout << "\nSequense sum is " << sum << "\n";
        }
};

class ArithmeticSeq : public AbstractSeq{
    public:
        void virtual seq(int k, vector<int> &vec){
            
            const int DIFFERENCE = 3;       // Because it's arithmetic sequence, we need int difference
            vec.push_back(k);               // Initialize first vector element
            
            for(int i = 0; i < 9; i++){
                vec[i+1] = vec[i] + DIFFERENCE;
                vec.push_back(vec[i+1]);
            }
        }
};

class GeometricSeq : public AbstractSeq{
    public:
        void virtual seq(int k, vector<int> &vec){
            
            const int RATIO = 2;       // Because it's geometric sequence, we need int ratio
            vec.push_back(k);          // Initialize first vector element
            
            for(int i = 0; i < 9; i++){
                vec[i+1] = vec[i] * RATIO;
                vec.push_back(vec[i+1]);
            }
        }
};


int main(){
    
    vector<int>arithmetic_seq;
    vector<int>geometric_seq;
    
    ArithmeticSeq *ar_seq = new ArithmeticSeq();
    GeometricSeq *geom_seq = new GeometricSeq();
    
    ar_seq->seq(1, arithmetic_seq);
    geom_seq->seq(1, geometric_seq);

    cout << "Arithmetic sequence" << "\n";
    ar_seq->print_seq(0, arithmetic_seq.size(), arithmetic_seq);
    ar_seq->sum_seq(0, arithmetic_seq.size(), arithmetic_seq);
    cout << "Sequence sum from 2nd to 7th element." ;
    ar_seq->sum_seq(1, arithmetic_seq.size()-3, arithmetic_seq);

    cout << "\nGeometric sequence" << "\n";
    geom_seq->print_seq(0, geometric_seq.size(), geometric_seq);
    geom_seq->sum_seq(0, geometric_seq.size(), geometric_seq);
    cout << "Sequence sum from 2nd to 7th element." ;
    geom_seq->sum_seq(2, geometric_seq.size()-3, geometric_seq);



};