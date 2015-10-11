#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;



void generar_aleatorio(vector<int> & V){
  int x,s,i;
  for ( i=0; i<V.size();i++){
    x=i;
    if ( (rand()%2)==0 ) x = -x;
    V[i]=x;
  }
   random_shuffle(V.begin(),V.end());
}

int main(int argc, char * argv[]){

using namespace std::chrono;

high_resolution_clock::time_point t1,t2;
duration<double> time_span;

vector<int> V;
int max = 100000;

srand(0);

for (int t=1000;t<max;t+=1000){
  t1 = high_resolution_clock::now();

  V.resize(t);
  generar_aleatorio(V);
 
  t2 = high_resolution_clock::now();
    V.clear();


  time_span = duration_cast<duration<double>>(t2 - t1);
  cout << t << " " << time_span.count() << endl;
 
}

  
return 0;

} 
