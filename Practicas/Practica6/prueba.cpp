#include <iostream>
#include <functional>
#include "avl.h"
using namespace std;

int main(){
  avl<int,less<int> > arbolico;
    cout << "inserto 16" << endl;
    arbolico.insert(16);
    arbolico.mostrarArbol(cout);
    cout << "inserto 14" << endl;
    arbolico.insert(14);
    arbolico.mostrarArbol(cout);
    cout << "inserto 18" << endl;
    arbolico.insert(18);
    arbolico.mostrarArbol(cout);
    cout << "inserto 12" << endl;
    arbolico.insert(12);
    arbolico.mostrarArbol(cout);
    cout << "inserto 15" << endl;
    arbolico.insert(15);
    arbolico.mostrarArbol(cout);
    cout << "inserto 10" << endl;
    arbolico.insert(10);
    arbolico.mostrarArbol(cout);
    cout << "inserto 17" << endl;
    arbolico.insert(17);
    arbolico.mostrarArbol(cout);
    cout << "inserto 20" << endl;
    arbolico.insert(20);
    arbolico.mostrarArbol(cout);

    cout << "inserto 19" << endl;
    arbolico.insert(19);
    arbolico.mostrarArbol(cout);

    cout << "\n Arbolico empty? : ";
    arbolico.empty()? cout << "SI" << endl : cout << "NO" << endl;
    cout << "Size de arbolico : " << arbolico.size() << endl;
    avl<int,less<int>>::iterator avl_iterator;
   cout << "\n --- probando find 16 ---" << endl;
   avl_iterator = arbolico.find(16);
   (avl_iterator==arbolico.end())? cout << "NO ENCONTRADO" << endl : cout << "ENCONTRADO" << endl;


    cout << "--- probando erase 20 --- " << endl;
    arbolico.erase(20);
    avl_iterator = arbolico.find(20);
    (avl_iterator==arbolico.end())? cout << "BORRADO CON EXITO" << endl : cout << "NO SE HA BORRADO" << endl;

      arbolico.mostrarArbol(cout);


      cout << "--- LOWER BOUND (15)  --- ";
      avl<int,less<int>>::iterator lb;
      lb = arbolico.lower_bound(15); cout << (*lb).first << endl;

      cout << "--- LOWER BOUND (11)  --- ";
      lb = arbolico.lower_bound(11); cout << (*lb).first << endl;

      cout << "--- UPPER BOUND (10)  --- ";
      lb = arbolico.upper_bound(10); cout << (*lb).first << endl;

      cout << "--- UPPER BOUND (16)  --- ";
      lb = arbolico.upper_bound(16); cout << (*lb).first << endl;


      cout << "*** Probando Reverse Iterator ***" << endl;
      avl<int,less<int>>::riterator rit;
      rit = arbolico.rbegin();
      cout << "rbegin(): " << (*rit).first << endl;
      rit = arbolico.rend();
      cout << "rend(): " << (*rit).first << endl;
      ++rit;
      cout << "++ rit " <<  (*rit).first << endl;

      cout << "*******************************" << endl;

      cout << " Clear " << endl;
      arbolico.clear();
      arbolico.mostrarArbol(cout);




}
