#include <iostream>
#include <iomanip>
#include <cmath>
//Use setprecision(n) defined in the header <iomanip> to set the precision parameter of the output stream.
using namespace std;

const double e=2.72;

// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is

// Function: sigmoid activation function
// Input: double x: the input of sigmoid activation function
// Ouput: the output of sigmoid activation function
double sigmoid(double x)
{
// ==========================
  double sigmoid_o = 1/(1+pow(e, -x));
  return sigmoid_o;
// ==========================
}

// Function: tanh activate function
// Input: double x: the input of tanh activation function
// Ouput: double: the output of tanh activation function.
double tanh(double x)
{
  // ==========================
  double tanh_o = 2*sigmoid(2*x)-1;
  return tanh_o;
  // ==========================
}

// Function: compute the next hidden value in an RNN cell
// Input: double x: current input value
//        double h: current hidden status in RNN cell
// Ouput: double: next hidden value in RNN cell
double ComputeH(double x, double h)
{
  // ==========================
  double H = tanh(0.5*x-2*h);
  return H;
  // ==========================
}

// Function: compute the output value at current time step
// Input: double x: current input value
//        double h: current hidden status in RNN cell
// Ouput: double: current output value
double ComputeO(double x, double h)
{
  // ==========================
  double O = sigmoid(0.1*x+1.5*h);
  return O;
  // ==========================

}

// Function: print the values stored in a 1D-array to screen
// Input: double xs[100]: the value of the sequence
//        int seq_len: the length of the sequence
void PrintSeqs(double xs[100], int seq_len)
{
  for (int i=0; i<seq_len; ++i){
    cout<<fixed<<setprecision(10)<<xs[i]<<" ";

  }
}

// Function: main function
int main()
{
  
  int T;
  float h0; //first line input
  float xs[100];//contains x
  double hs[101];//contains h
  double os[101];//contains o
  double new_hs[100];
  double new_os[100];

  cin >> T >> h0;
  for (int i=0; i<T; ++i){ //second line input 
    float temp;
    cin >> temp;
    xs[i] = temp;
  }
  hs[0] = h0;

  
  for (int i=0; i<101; ++i){
    os[i+1] = ComputeO(xs[i],hs[i]);
    hs[i+1] = ComputeH(xs[i],hs[i]); 
    if (i<100){
      new_os[i] = os[i+1];
      new_hs[i] = hs[i+1];
    }
  }
  
  PrintSeqs(new_hs, T);
  cout<<endl;
  PrintSeqs(new_os, T);
  cout<<endl;
}
