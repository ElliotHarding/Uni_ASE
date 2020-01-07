#pragma once
#include <functional>

namespace Containers
{
	template<typename keyTemplate, typename itemTemplate>
	class Dictionary
	{
	public:
		using Key = keyTemplate;
		using Item = itemTemplate;

		//Constructor
		Dictionary() :
			m_root(nullptr)
		{
		}

		~Dictionary()
		{
			if(m_root != nullptr)
				deepDelete(m_root);
		}

		//Copy constructor
		Dictionary(const Dictionary<keyTemplate, itemTemplate>& d)
		{
			m_root = d.deepCopy(d.m_root);
		}

		//Move constructor
		Dictionary(Dictionary&& d)
		{
			m_root = d.deepCopy(d.m_root);
			delete d;
		}

		//Copy assignment operator
		Dictionary& operator=(const Dictionary& d)
		{
			m_root = d.deepCopy(d.m_root);
		}

		//Move assignment operator
		Dictionary& operator=(Dictionary&& d)
		{
			m_root = d.deepCopy(d.m_root);
			delete d;
		}

		bool insert(Key k, Item i)
		{
			Node** n = &m_root;
			
			while (true)
			{
				if (*n==nullptr)
					break;

				if ((*n)->m_key == k)
				{
					(*n)->m_item = i;
					return false;
				}					

				n = &((*n)->m_linkedNode);
			}
			
			*n = new Node(k, i);
			return true;
		}

		Item* lookup(Key k)
		{
			Node* n = m_root;

			while (n != nullptr)
			{
				if (n->m_key == k)
					return &(n->m_item);

				n = n->m_linkedNode;
			}

			return nullptr;
		}

		bool remove(Key k)
		{
			if (!m_root)
				return false;

			Node* n = m_root;

			if (n->m_key == k)
			{
				m_root = n->m_linkedNode;
				delete n;
				n = nullptr;
				return true;
			}

			while (n->m_linkedNode != nullptr)
			{
				if (n->m_linkedNode->m_key == k)
				{
					Node* toDelete = n->m_linkedNode;
					if (n->m_linkedNode->m_linkedNode != nullptr)
					{
						n->m_linkedNode = n->m_linkedNode->m_linkedNode;
					}
					delete toDelete;
					toDelete = nullptr;
					return true;
				}

				n = n->m_linkedNode;
			}

			return false;
		}

		template <typename T>
		void removeIf(std::function<T> p)
		{
			Node* n = m_root;
			while (n != nullptr)
			{
				Key toCheck = n->m_key;
				n = n->m_linkedNode;

				if (p(toCheck))
					remove(toCheck);				
			}
		}

	private:
		struct Node
		{
			Key m_key;
			Item m_item;
			Node* m_linkedNode;

			Node(Key k, Item i) : 
				m_key(k),
				m_item(i),
				m_linkedNode(nullptr)
			{
			}
		};

		Node* m_root = nullptr;

		Node* deepCopy(Node * n) const
		{
			Node* newNode = new Node(n->m_key, n->m_item);

			if (n->m_linkedNode != nullptr)
				newNode->m_linkedNode = deepCopy(n->m_linkedNode);

			return newNode;
		}

		void deepDelete(Node* n)
		{
			if (n->m_linkedNode != nullptr)
				deepDelete(n->m_linkedNode);

			delete n;
			n = nullptr;
		}
	};
}