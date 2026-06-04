#pragma once
#include "Dictionary.h"
#include "BSTree.h"
#include "Dictionary.h"
#include "BSTree.h"
#include "Pair.h"
#include "LinkedList.h"
#include <stdexcept>


template <typename K, typename V>
class BSTDictionary : public Dictionary<K, V>
{

private:

	BSTree<Pair<K, V>>* diccionario;

public:

	BSTDictionary()
	{
		diccionario = new BSTree<Pair<K, V>>();
	}

	~BSTDictionary()
	{
		delete diccionario;
	}



	void insert(K key, V value)
	{

		if (contains(key))
		{
			throw runtime_error("Llave duplicada");
		}


		Pair<K, V> par(key, value);

		diccionario->insert(par);

	}


	V remove(K key)
	{

		if (!contains(key))
		{
			throw runtime_error("Esta llave no existe");
		}

		Pair<K, V> par(key);
		return diccionario->remove(par).value;
	
	}



	V getValue(K key)
	{

		Pair<K, V> found = diccionario->find(Pair<K, V>(key));
		
		return found.value;
	
	}

	void setValue(K key, V value)
	{

		if (!diccionario->contains(Pair<K, V>(key)))
		{
			throw runtime_error("Esta llave no existe");
		}

		diccionario->remove(Pair<K, V>(key));
		diccionario->insert(Pair<K, V>(key, value));

	}

	bool contains(K key)
	{
		try
		{
			diccionario->find(Pair<K, V>(key));

			return true;
		}

		catch (runtime_error&)
		{
			return false;
		}
	}


	void clear()
	{

		if (isEmpty())
		{
			throw runtime_error("Diccionario vacio");
		}


		diccionario->clear();
	}



	List<K>* getKeys()
	{
		List<Pair<K, V>>* pares = diccionario->getElements();
		List<K>* llave = new LinkedList<K>();

		pares->goToStart();

		while (!pares->atEnd())
		{

			Pair<K, V> parActual = pares->getElement();
			

			parActual = pares->getElement();

			llave->append(parActual.key);

			pares->next();

		}

		delete pares;

		return llave;


	}



	List<V>* getValues()
	{
		List<Pair<K, V>>* pares = diccionario->getElements();

		List<V>* valor = new LinkedList<V>();


		pares->goToStart();

		while (!pares->atEnd())
		{

			Pair<K, V> actual = pares->getElement();

			valor->append(actual.value);

			pares->next();

		}

		delete pares; 

		return valor;
	}

	int getSize()
	{
		return diccionario->getSize();
	}

	bool isEmpty()
	{
		return diccionario->isEmpty();
	}

	void print()
	{
		diccionario->print();
	}

	void update(Dictionary<K, V>* D)
	{
		List<K>* llave = D-> getKeys();

		llave-> goToStart();


		while (!llave-> atEnd())
		{

			K key = llave-> getElement();
			V value = D-> getValue(key);

			if (contains(key))
			{
				setValue(key, value);
			}

			else
			{
				insert(key, value);
			}


			llave->next();

			delete llave;

		}
	}

	void zip(List<K>* keys, List<V>* values)
	{
		keys->goToStart();
		values->goToStart();

		while (!keys->atEnd() && !values->atEnd())
		{

			K key; 
			V value; 
			

			key = keys->getElement();
			value = values->getElement();


			if (contains(key))
			{
				setValue(key, value);
			}
			else
			{
				insert(key, value);
			}


			keys->next();
			values->next();

		}
	}

};

