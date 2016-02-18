/**
 * @file avl.h
 * @brief Fichero cabecera para avl
 *
*/

#ifndef __AVL_H
#define __AVL_H

#include "bintree.h"
#include <utility>

using namespace std;


typedef int altura;
typedef unsigned int size_type;

template <typename T, class comparar=less<T> >
class avl{
	private:
		altura h(typename bintree<pair<T,altura> >::node n);
		altura h(typename bintree<pair<T,altura> >::const_node n);
		void ajustarAltura(typename bintree<pair<T,altura> >::node in);

		bintree <pair<T,altura> > el_avl;
		unsigned int tama;
		comparar cmp;

	public:
		class iterator;
		class riterator;
		class const_iterator;


		///////////////////////////////////////////////////////////////////////
		/////////////////////// METODOS CLASS AVL //////////////////////////////
		///////////////////////////////////////////////////////////////////////
		typename avl<T,comparar>::iterator begin();
		typename avl<T,comparar>::riterator rbegin();

		typename avl<T,comparar>::iterator end();
		typename avl<T,comparar>::riterator rend();

		typename avl<T,comparar>::iterator find(T clave);
		typename avl<T,comparar>::const_iterator cbegin();
		typename avl<T,comparar>::const_iterator cend();

		avl();

		bool empty();

		size_type size();

		pair<typename avl<T,comparar>::iterator,bool> insert(T in_dato);

		bool erase(T valor);

		avl<T,comparar>& operator=(const avl<T,comparar> &a);

		ostream& mostrarArbol(ostream &os);

		void swap (avl<T,comparar> &avl1);

		void clear();

		avl<T,comparar>::iterator lower_bound(T valor);
		avl<T,comparar>::iterator upper_bound(T valor);


		void rotaizq(typename bintree<pair<T,altura>>::node n);
		void rotaizqdoble(typename bintree<pair<T,altura>>::node n);
		void rotader(typename bintree<pair<T,altura>>::node n);
		void rotaderdoble(typename bintree<pair<T,altura>>::node n);
		void balancear(typename bintree<pair<T,altura>>::node n);


		///////////////////////////////////////////////////////////////////////
		/////////////////////// CLASS AVL::ITERATOR ///////////////////////////
		///////////////////////////////////////////////////////////////////////
		class iterator{
		private:
			typename bintree<pair<T,altura> >::inorder_iterator it_n;
		public:
			iterator();
			iterator(typename bintree<pair<T,altura>>::node n);
			friend avl;
			pair<T,altura> operator*();
			bool operator==(avl<T,comparar>::iterator a);
			bool operator!=(avl<T,comparar>::iterator a);
			typename avl<T,comparar>::iterator operator++();
			avl<T,comparar>::iterator operator=(avl<T,comparar>::iterator a);
			iterator(const avl<T,comparar>::iterator &a);
		};

		///////////////////////////////////////////////////////////////////////
		///////////////// CLASS AVL::CONST_ITERATOR ///////////////////////////
		///////////////////////////////////////////////////////////////////////
		class const_iterator{
		private:
			typename bintree<pair<T,altura> >::const_inorder_iterator it_n;
		public:
			const_iterator();
			const_iterator(typename bintree<pair<T,altura>>::node n);
			friend avl;
			pair<T,altura> operator*();
			bool operator==(avl<T,comparar>::const_iterator a);
			bool operator!=(avl<T,comparar>::const_iterator a);
			typename avl<T,comparar>::const_iterator operator++();
			avl<T,comparar>::const_iterator operator=(avl<T,comparar>::const_iterator a);
			const_iterator(const avl<T,comparar>::const_iterator &a);
		};

		///////////////////////////////////////////////////////////////////////
		///////////////// CLASS AVL::RITERATOR ///////////////////////////
		///////////////////////////////////////////////////////////////////////
		class riterator{
		private:
			typename bintree<pair<T,altura> >::inorder_iterator it_n;
		public:
			/**
				@brief Constructor sin parametros
			*/
			riterator();


			riterator(typename bintree<pair<T,altura>>::node n);
			friend avl;
			pair<T,altura> operator*();
			bool operator==(avl<T,comparar>::riterator a);
			bool operator!=(avl<T,comparar>::riterator a);
			typename avl<T,comparar>::riterator operator++();
			avl<T,comparar>::riterator operator=(avl<T,comparar>::riterator a);
			riterator(const avl<T,comparar>::riterator &a);
		};



};
#include "avl.hxx"
#endif
