#include "conjunto.h"
#include "crimen.h"
#include "fecha.cpp"
#include <iostream>
#include <fstream>

using namespace std;
	
	/** @brief lee un fichero de delitos, linea a linea
	@param[in] s nombre del fichero
        @param[in,out] C conjunto sobre el que se lee
	@return true si la lectura ha sido correcta, false en caso contrario
	*/

bool load(conjunto &  C, const string & s) {
 ifstream fe;
 string cadena;

 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail())    
 {
   cerr << "Error al abrir el fichero " << s << endl;
 } else {
   getline(fe,cadena,'\n'); //leo la cabecera del fichero
   cout << cadena << endl;
    while ( !fe.eof() )
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {
	   cout << "leo:: "<< cadena << endl;
	   // Convertir cadena a crimen
           // crimen aux = cadena;
           // Insertar cadena en el conjunto
           // C.insert(aux);
         }
     }
    fe.close();
    return true;
    } // else
  fe.close();
  return false;
 }

int main()
{
    conjunto ChicagoDB;
    crimen d;
    fecha f;
 
    

    load(ChicagoDB, "crimenes.csv");

   return 0;
}
