#pragma once
#include "Dictionary.h"
#include "BSTree.h"


template <typename K, typename V>
class BSTDictionary : public Dictionary<K, V>
{

private:

	BSTree<Pair<K, V>> diccionario;

public:

	BSTDictionary()
	{
	}

	~BSTDictionary()
	{
	}

	void insert(K key, V value)
	{

		diccionario.insert(Pair<K, V>(key, value));

	}

	V remove(K key)
	{

		Pair<K, V> removed = diccionario.remove(Pair<K, V>(key));
		return removed.value;

	}

	V getValue(K key)
	{

		Pair<K, V> found = diccionario.find(Pair<K, V>(key));
		return found.value;
	
	}

	void setValue(K key, V value)
	{

		if (!diccionario.contains(Pair<K, V>(key)))
		{
			throw runtime_error("Key not found");
		}

		diccionario.remove(Pair<K, V>(key));
		diccionario.insert(Pair<K, V>(key, value));

	}

	bool contains(K key)
	{
		Pair<K, V> pair(key);

		if (diccionario.contains(pair))
		{
			return true;
		}

		return false;
	}

	void clear()
	{
		diccionario.clear();
	}

	List<K>* getKeys()
	{
		List<Pair<K, V>>* pares = diccionario.getElements();
		List<K>* llave = new List<K>();

		pares->goToStart();

		while (!pares->atEnd())
		{

			Pair<K, V> parActual;
			

			parActual = pares->getElement();

			llave->append(parActual.key);

			pares->next();

		}

		return llave;
	}

	List<V>* getValues()
	{
		List<Pair<K, V>>* pares = diccionario.getElements();

		List<V>* valor = new LinkedList<V>();


		pares->goToStart();

		while (!pares->atEnd())
		{

			Pair<K, V> actual;

				
			actual = pares->getElement();

			valor->append(actual.value);

			pares->next();

		}

		return valor;
	}

	int getSize()
	{
		return diccionario.getSize();
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


			keys->next();

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

