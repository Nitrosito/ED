#include <cassert>
///////////////////////////////////////////////////////////////////////
/////////////////////// CLASS AVL::ITERATOR ///////////////////////////
///////////////////////////////////////////////////////////////////////
template <typename T, class comparar>
avl<T,comparar>::iterator::iterator(){
}

template <typename T,class comparar>
avl<T,comparar>::iterator::iterator(const avl<T,comparar>::iterator &a){
  (*this).it_n = a.it_n;
}

template <typename T,class comparar>
typename avl<T,comparar>::iterator avl<T,comparar>::iterator::operator=(avl<T,comparar>::iterator a){
  it_n = a.it_n;
  return (*this);
}

template <typename T,class comparar>
avl<T,comparar>::iterator::iterator(typename bintree<pair<T,altura> >::node n){
  typename bintree<pair<T,altura>>::inorder_iterator i_it(n);
  (*this).it_n = i_it;
}


template <typename T, class comparar>
pair<T,altura> avl<T,comparar>::iterator::operator*(){
  return (*it_n);
}

template <typename T,class comparar>
bool avl<T,comparar>::iterator::operator==(avl<T,comparar>::iterator a){
  if(it_n == a.it_n)
    return true;
  return false;
}

template <typename T,class comparar>
bool avl<T,comparar>::iterator::operator!=(avl<T,comparar>::iterator a){
  if(it_n == a.it_n)
    return false;
  return true;
}



template <typename T,class comparar>
typename avl<T,comparar>::iterator avl<T,comparar>::iterator::operator++(){
  ++it_n;
  return (*this);
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
////////////////////CLASS AVL::CONST_ITERATOR//////////////////////////
///////////////////////////////////////////////////////////////////////
template <typename T, class comparar>
avl<T,comparar>::const_iterator::const_iterator(){
}

template <typename T,class comparar>
avl<T,comparar>::const_iterator::const_iterator(const avl<T,comparar>::const_iterator &a){
  (*this).it_n = a.it_n;
}

template <typename T,class comparar>
typename avl<T,comparar>::const_iterator avl<T,comparar>::const_iterator::operator=(avl<T,comparar>::const_iterator a){
  it_n = a.it_n;
  return (*this);
}

template <typename T,class comparar>
avl<T,comparar>::const_iterator::const_iterator(typename bintree<pair<T,altura> >::node n){
  typename bintree<pair<T,altura>>::const_inorder_iterator i_it(n);
  (*this).it_n = i_it;
}


template <typename T, class comparar>
pair<T,altura> avl<T,comparar>::const_iterator::operator*(){
  return (*it_n);
}

template <typename T,class comparar>
bool avl<T,comparar>::const_iterator::operator==(avl<T,comparar>::const_iterator a){
  if(it_n == a.it_n)
    return true;
  return false;
}

template <typename T,class comparar>
bool avl<T,comparar>::const_iterator::operator!=(avl<T,comparar>::const_iterator a){
  if(it_n == a.it_n)
    return false;
  return true;
}



template <typename T,class comparar>
typename avl<T,comparar>::const_iterator avl<T,comparar>::const_iterator::operator++(){
  ++it_n;
  return (*this);
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
/////////////////////// CLASS AVL /////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <typename T, class comparar>
avl<T,comparar>::avl(){
tama=0;
}


template <typename T, class comparar>
typename avl<T,comparar>::iterator avl<T,comparar>::begin(){
  avl<T,comparar>::iterator it;
  it.it_n = el_avl.begin_inorder();
  return it;
}

template <typename T, class comparar>
typename avl<T,comparar>::iterator avl<T,comparar>::end(){
  avl<T,comparar>::iterator it;
  it.it_n = el_avl.end_inorder();
  return it;
}


template <typename T, class comparar>
typename avl<T,comparar>::const_iterator avl<T,comparar>::cbegin(){
  avl<T,comparar>::const_iterator c_it;
  c_it.it_n = el_avl.begin_inorder();
  return c_it;
}

template <typename T, class comparar>
typename avl<T,comparar>::const_iterator avl<T,comparar>::cend(){
  avl<T,comparar>::const_iterator c_it;
  c_it.it_n = el_avl.end_inorder();
  return c_it;
}

template <typename T, class comparar>
bool avl<T,comparar>::empty(){
  if(tama==0)
    return true;
  return false;
}

template <typename T, class comparar>
size_type avl<T,comparar>::size(){
  return tama;
}
template <typename T, class comparar>
altura avl<T,comparar>::h(typename bintree<pair<T,altura> >::node n){
  if(n.null())
    return -1;
  return (*n).second;
}

template <typename T, class comparar>
altura avl<T,comparar>::h(typename bintree<pair<T,altura> >::const_node n){
  if(n.null())
    return -1;
  return (*n).second;
}

template <typename T, class comparar>
pair<typename avl<T,comparar>::iterator,bool> avl<T,comparar>::insert(T in_dato){
  pair<T,altura> in;
  in.first=in_dato;
  bool encontrado=false;
  pair<avl<T,comparar>::iterator,bool> res;
  bool cambiaaltura=false;
  bool insertado=false;
  typename bintree<pair<T,altura> >::node nodo;
  nodo = el_avl.root();

  if(nodo.null()){ //Inserta si avl es nulo
    in.second=0;
    el_avl = bintree<pair<T,altura>>(in);
    tama++;
    nodo = el_avl.root();
    encontrado=true;
    insertado=true;
  }

  while(!encontrado && !nodo.null()){
    if((*nodo).first==in.first) //nodo == RAIZ
      encontrado=true;

    else if(!cmp((*nodo).first , in.first) && (*nodo).first!=in.first){
      if(nodo.left().null()){
        el_avl.insert_left(nodo,in);
        insertado=true;
        encontrado=true;
        tama++;
      }
      nodo = nodo.left();
    }
      else{
        if(nodo.right().null()){
          el_avl.insert_right(nodo,in);
          encontrado=true;
          insertado=true;
          tama++;
        }
        nodo = nodo.right();
      }
  }

  // ajustamos altura
  ajustarAltura(nodo);

  balancear(nodo);
  typename avl<T,comparar>::iterator resit(nodo);
  res.first=resit;
  res.second=insertado;
  return res;
}

template <typename T, class comparar>
typename avl<T,comparar>::iterator avl<T,comparar>::lower_bound(T valor){
  typename avl<T,comparar>::iterator res,aux;
  res = find(valor);
  if(res != end()) // Si lo encuentra
    return res;
  else{ // Si no lo encuentra, devuelbe el posterior

  }
  for(res=(*this).begin(); res!=(*this).end();++res){
    aux = res;
    ++aux;
    if(cmp(valor,(*res).first)){
      return res;
    }
  }
  return end(); // No encontrado igual o mayor
}

template <typename T, class comparar>
typename avl<T,comparar>::iterator avl<T,comparar>::upper_bound(T valor){
  typename avl<T,comparar>::iterator res,aux;
  for(res=(*this).begin(); res!=(*this).end();++res){
    aux = res;
    ++aux;
    if(cmp(valor,(*res).first)){
      return res;
    }
  }
  return end(); // No encontrado mayor
}


template <typename T, class comparar>
typename avl<T,comparar>::iterator avl<T,comparar>::find(T clave){
  typename bintree<pair<T,altura>>::node n = el_avl.root();
  bool encontrado = false;
  while(!encontrado && !n.null()){
		if((*n).first == clave)
			encontrado = true;
		else{
			if(cmp((*n).first , clave) && (*n).first!=clave)
				n = n.right();
			else
				n = n.left();
		}
	}
  avl<T,comparar>::iterator res(n);
  if(n.null())
    return  res;
  else
    return res;
}

template <typename T, class comparar>
bool avl<T,comparar>::erase(T clave){
  typename bintree<pair<T,altura>>::node nodo;
  bintree<pair<T,altura> > dest;

  nodo = el_avl.root();
  bool encontrado = false;
  while(!encontrado && !nodo.null()){
		if((*nodo).first == clave)
			encontrado = true;
		else{
			if(cmp((*nodo).first , clave))
				nodo = nodo.right();
			else
				nodo = nodo.left();
		}
	}

  if(nodo.null())
    return false; //No encontrado
  else{   // ES ENCONTRADO
    if(nodo.right().null() && nodo.left().null()){	//hoja
      if(nodo.parent().null()){                  //Si es root
        el_avl.clear();
      }
      else {                                  //No es raiz
        if(nodo.parent().left() == nodo){     //es hoja izq
          el_avl.prune_left(nodo.parent(),dest);
        }
        else{                                 //Es hoja derecha
          el_avl.prune_right(nodo.parent(),dest);
        }
          dest.clear(); //Liberamos
      }
      tama--;

    } // FIN CASO HOJA // YA NO ES HOJA //
    else if(nodo.left().null() || nodo.right().null()){ // 1 Hijo
      if(!nodo.left().null()) //Hijo en izq
        el_avl.prune_left(nodo,dest);
      else //Hijo en derecha
        el_avl.prune_right(nodo,dest);

      if(nodo.parent().null()) // Si  es raiz
        el_avl = dest;
      else if(nodo.parent().left() == nodo)
        el_avl.insert_left(nodo.parent(),dest);
      else  el_avl.insert_right(nodo.parent(),dest);
      tama--;
    } // fin 1 hijo
    else{  //NODO TIENE 2 HIJOS
      typename bintree<pair<T,altura>>::node pred;
      pred = nodo.left(); //Predecesor
      while(!pred.right().null()) //Busqueda pred
        pred=pred.right();

      pair<T,altura> valor_pred((*pred));
      typename bintree<pair<T,altura>>::node nodo_a_borrar = nodo;
      erase( (*pred).first);
      *nodo_a_borrar = valor_pred;
    } //FIN 2 HIJOS
  }// FIN ES ENCONTRADO
  ajustarAltura(nodo);
  balancear(nodo);
}

template <typename T, class comparar>
void avl<T,comparar>::ajustarAltura(typename bintree<pair<T,altura> >::node in){
  typename bintree<pair<T,altura> >::node l,r,n;
  n=in;
  l=n.left();
  r=n.right();
  if(h(n) != max(h(l),h(r))+1 ){
    (*n).second = max(h(l),h(r))+1;
  }

  if(!n.parent().null()){
    n = n.parent();
    bool cambia = true;

    while(!n.null() && cambia){
      l = n.left();
      r = n.right();
      if( h(n) == max(h(l),h(r))+1 ) {
        cambia = false;
      }
      else{
        (*n).second = max(h(l),h(r))+1;
        n = n.parent();
      }
    }
  }
}


template <typename T,class comparar>
avl<T,comparar>& avl<T,comparar>::operator=(const avl<T,comparar> &a){
  avl<T,comparar> aux;
  (*this).el_avl = a.el_avl;
  (*this).tama = a.tama;
  (*this).cmp = a.cmp;
  return *this;
}

template <typename T,class comparar>
void avl<T,comparar>::swap(avl<T,comparar> &avl1){
  el_avl.swap(avl1.el_avl);
}

template <typename T,class comparar>
void avl<T,comparar>::clear(){
  el_avl.clear();
  tama=0;
}

template <typename T,class comparar>
ostream& avl<T,comparar>::mostrarArbol(ostream &os){
  avl<T,comparar>::iterator it;
  cout << "Val|Altura" << endl;
  it= begin();
  for(; it!=(*this).end();++it){
    os << (*it).first << " , " << (*it).second << endl;
  }
  return os;
}

template <typename T,class comparar>
void avl<T,comparar>::rotaizq(typename bintree<pair<T,altura>>::node n){
  typename bintree<pair<T,altura>>::node padre;
  bintree<pair<T,altura>> a,b,c,padrenulo;
  if(n.left().null()) //Si no tiene hijo izq, no se puede rotar
    return;


  if(!n.left().right().null()){ //SI hijo izq, derecha, no es nulo
    el_avl.prune_right(n.left(),a); // podo izq,derecha  n
    el_avl.prune_left(n,b); //podo izq n
    el_avl.insert_left(n,a); // izq n -> a(n.left.righ)
    ajustarAltura(n);
  }
  else{ //hijo izq derecha nulo
    el_avl.prune_left(n,b);  //solo podo izq n
    ajustarAltura(n);
  }

  if(n.parent().null()){ // Si es el NODO RAIZ
    padrenulo.swap(el_avl);
    el_avl.swap(b);
    el_avl.insert_right(el_avl.root(),padrenulo);
    ajustarAltura(el_avl.root());
    return;
  }

    padre = n.parent();

  if(padre.left() == n){ //Es Hijo.izquierda
    el_avl.prune_left(padre,c);
    el_avl.insert_left(padre,b);
    ajustarAltura(padre);

    el_avl.insert_right(padre.left(),c);
    ajustarAltura(padre.left());
  }
  else if(padre.right() == n){ //Es Hijo derecha
    cout << "mierda" << endl;
    el_avl.prune_right(padre,c);
    cout << "mierda1" << endl;

    el_avl.insert_right(padre,b);
    cout << "mierda2" << endl;

    ajustarAltura(padre);
    cout << "mierda3" << endl;

    el_avl.insert_right(padre.right(),c);
    cout << "mierda4" << endl;

    ajustarAltura(padre.right());
  }
}

template <typename T,class comparar>
void avl<T,comparar>::rotader(typename bintree<pair<T,altura>>::node n){
  typename bintree<pair<T,altura>>::node padre;
  bintree<pair<T,altura>> a,b,c,padrenulo;
  if(n.right().null()) //Si no tiene hijo der, no se puede rotar
    return;

  if(!n.right().left().null()){ //SI hijo izq, derecha, no es nulo
    el_avl.prune_left(n.right(),a); // podo izq,derecha  n
    el_avl.prune_right(n,b); //podo izq n
    el_avl.insert_right(n,a); // izq n -> a(n.left.righ)
    ajustarAltura(n);
  }
  else{ //hijo izq derecha nulo
    el_avl.prune_right(n,b);  //solo podo izq n
    ajustarAltura(n);
  }

  if(n.parent().null()){ // Si es el NODO RAIZ
    padrenulo.swap(el_avl);
    el_avl.swap(b);
    el_avl.insert_left(el_avl.root(),padrenulo);
    ajustarAltura(el_avl.root());
    return;
  }

  padre = n.parent();

  if((*padre.right()).first == (*n).first){ //Es Hijo.izquierda
    el_avl.prune_right(padre,c);
    el_avl.insert_right(padre,b);
    ajustarAltura(padre);
    el_avl.insert_left(padre.right(),c);
    ajustarAltura(padre.right());
  }
  else if(padre.left() == n){ //Es Hijo derecha
    el_avl.prune_left(padre,c);
    el_avl.insert_left(padre,b);
    ajustarAltura(padre);
    el_avl.insert_left(padre.left(),c);
    ajustarAltura(padre.left());
  }
}

template <typename T,class comparar>
void avl<T,comparar>::rotaizqdoble(typename bintree<pair<T,altura>>::node n){
  rotader(n.left());
  rotaizq(n);
}

template <typename T,class comparar>
void avl<T,comparar>::rotaderdoble(typename bintree<pair<T,altura>>::node n){
  cout << " antes de rotar izq" << endl;
 cout << (*n.right()).first << " , " << (*n).second <<  endl;
 cout << "foh" << endl;

  rotaizq(n.right());
  cout << " despues de rotar izq" << endl;
  rotader(n);
}

template <typename T,class comparar>
void avl<T,comparar>::balancear(typename bintree<pair<T,altura>>::node n){
  int fe;
  int ladonodohijo, ladonodopadre; // 0 = izq, 1 = derecha
  if(n.parent().null()) // si padre nulo no hago nada
    return;

  if(n.parent().parent().null()) // si padre de padre es nulo
      return;


  // de donde procede hijo
  if(!n.parent().left().null()){ // Si izq no nula
    if(n.parent().left() == n)
      ladonodohijo = 0; // nodo hijo esta en izq
    else // Si nodo no esta en izq esta en derecha
      ladonodohijo = 1;
  }
  else // viene de la derecha fijo
    ladonodohijo=1;

  n=n.parent();
  if(n.parent().null())
    return;

  if(!n.parent().left().null()){ // Si izq no nula
    if(n.parent().left() == n)
      ladonodopadre = 0; // nodo hijo esta en izq
    else // Si nodo no esta en izq esta en derecha
      ladonodopadre = 1;
  }
  else
    ladonodopadre=1;

  n=n.parent();
  while(n!=el_avl.root()){
  fe = h(n.left()) - h(n.right());
  if( fe < -1 || fe > 1){ // Hay que rotar
    if(ladonodohijo == 0 && ladonodopadre == 0)
      rotaizq(n);
    else if(ladonodohijo == 0 && ladonodopadre ==1)
      rotaderdoble(n);
    else if(ladonodohijo == 1 && ladonodopadre == 0)
      rotaizqdoble(n);
    else if(ladonodohijo == 1 && ladonodopadre ==1)
      rotader(n);
  }
  ladonodohijo = ladonodopadre; // Seteo a hijo con padre
  if(!n.parent().null()){
    // Averiguo de donde viene padre
    if(!n.parent().left().null()){ // Si izq no nula
      if(n.parent().left() == n)
        ladonodopadre = 0; // nodo hijo esta en izq
      else // Si nodo no esta en izq esta en derecha
        ladonodopadre = 1;
    }
    else
      ladonodopadre=1;
  }

      n = n.parent();

  } // while ACABA AQUI
  fe = h(n.left()) - h(n.right());
  if(fe < -1 || fe > 1){
    if(ladonodohijo == 0 && ladonodopadre == 0)
      rotaizq(n);
    else if(ladonodohijo == 0 && ladonodopadre ==1)
      rotaderdoble(n);
    else if(ladonodohijo == 1 && ladonodopadre == 0)
      rotaizqdoble(n);
    else if(ladonodohijo == 1 && ladonodopadre ==1)
      rotader(n);
  }
}



///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
/////////////////////// CLASS AVL::RITERATOR ///////////////////////////
///////////////////////////////////////////////////////////////////////
// para reverse, operador--BINTREE
// begin en reverse = bucle desde inicio hasta fin (auxiliar iteras hasta != null) de bintree
template <typename T, class comparar>
avl<T,comparar>::riterator::riterator(){
}

template <typename T,class comparar>
avl<T,comparar>::riterator::riterator(const avl<T,comparar>::riterator &a){
  (*this).it_n = a.it_n;
}

template <typename T,class comparar>
typename avl<T,comparar>::riterator avl<T,comparar>::riterator::operator=(avl<T,comparar>::riterator a){
  it_n = a.it_n;
  return (*this);
}

template <typename T,class comparar>
avl<T,comparar>::riterator::riterator(typename bintree<pair<T,altura> >::node n){
  typename bintree<pair<T,altura>>::inorder_iterator i_it(n);
  (*this).it_n = i_it;
}


template <typename T, class comparar>
typename avl<T,comparar>::riterator avl<T,comparar>::rbegin(){
  avl<T,comparar>::riterator it;
  avl<T,comparar>::riterator aux;
  aux.it_n = el_avl.begin_inorder();
  while(aux.it_n != el_avl.end_inorder()){
    it = aux;
    ++aux.it_n;
  }
  return it;
}

template <typename T, class comparar>
typename avl<T,comparar>::riterator avl<T,comparar>::rend(){
  avl<T,comparar>::riterator it;
  it.it_n = el_avl.begin_inorder();
  return it;
}

template <typename T, class comparar>
pair<T,altura> avl<T,comparar>::riterator::operator*(){
  return (*it_n);
}

template <typename T,class comparar>
bool avl<T,comparar>::riterator::operator==(avl<T,comparar>::riterator a){
  if(it_n == a.it_n)
    return true;
  return false;
}

template <typename T,class comparar>
bool avl<T,comparar>::riterator::operator!=(avl<T,comparar>::riterator a){
  if(it_n == a.it_n)
    return false;
  return true;
}



template <typename T,class comparar>
typename avl<T,comparar>::riterator avl<T,comparar>::riterator::operator++(){
  ++it_n;
  return (*this);
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
