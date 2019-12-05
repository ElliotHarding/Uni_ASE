#pragma once

namespace Containers
{
	template<class Key, class Item>
	class Dictionary
	{
	public:
		using Key = Key;
		using Item = Item;
		
		Dictionary() :
			m_root(nullptr)
		{
		}

		bool insert(Key k, Item i)
		{
			Node* n = m_root;

			while (n != nullptr)
			{
				if (n->m_key == k)
				{
					n->m_item = i;
					return true;
				}					

				n = n->m_linkedNode;
			}

			return false;
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
					Node* temp ....
				}
				if (n->m_key == k)
					return n;

				n = n->m_linkedNode;
			}

			return nullptr;
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

		Node* m_root;

		Node* getNode(Key k)
		{
			Node* n = m_root;

			while (n != nullptr)
			{
				if (n->m_key == k)
					return n;

				n = n->m_linkedNode;
			}

			return nullptr;
		}
	};
}