
#include <stdio.h>

class CNode
{
public:
	int value;
	CNode* pLLeaf;
	CNode* pRLeaf;

	CNode(int value) : 
		value(value), 
		pLLeaf(0), 
		pRLeaf(0)
	{
	}
	~CNode()
	{
	}
	void Print()
	{
		printf("Value: %d\n", this->value);
	}
};

class CBinaryTree
{
public:
	CBinaryTree() : 
		pRoot(0)
	{

	}

	void Insert(int value)
	{
		if (!pRoot)
		{
			pRoot = new CNode(value);
		}
		else
		{
			InsertRecursive(pRoot, value);
		}
	}

	void ClearData()
	{
		if (pRoot)
		{
			ClearDataRecursiveDF(pRoot);
		}
	}

	CNode* GetNodeWithValue(int value)
	{
		CNode* result = 0;
		if (pRoot)
		{
			result = GetNodeWithValueRecursive(pRoot, value);
		}
		return result;
	}

	void PrintNodesDF()
	{
		if (pRoot)
		{
			PrintNodesRecursiveDF(pRoot);
		}
	}

	void PrintNodesInorder()
	{
		if (pRoot)
		{
			PrintNodesInorderRecursive(pRoot);
		}
	}

	CNode* pRoot;

	void InsertRecursive(CNode* pNode, int value)
	{
		if (pNode)
		{
			bool isLessTan = (value < pNode->value);
			if (isLessTan)
			{
				if (pNode->pLLeaf == 0)
				{
					pNode->pLLeaf = new CNode(value);
				}
				else
				{
					InsertRecursive(pNode->pLLeaf, value);
				}
			}
			else
			{
				if (pNode->pRLeaf == 0)
				{
					pNode->pRLeaf = new CNode(value);
				}
				else
				{
					InsertRecursive(pNode->pRLeaf, value);
				}
			}
		}
	}

	void ClearDataRecursiveDF(CNode* pNode)
	{
		if (pNode)
		{
			ClearDataRecursiveDF(pNode->pLLeaf);
			ClearDataRecursiveDF(pNode->pRLeaf);
			
			printf("Deleting Nonde: ");
			pNode->Print();

			delete pNode;
			pNode = 0;
		}
	}

	CNode* GetNodeWithValueRecursive(CNode* pNode, int value)
	{
		CNode* result = 0;
		if (pNode)
		{
			if (value == pNode->value)
			{
				return pNode;
			}
			else
			{
				if (result == 0)
				{
					result = GetNodeWithValueRecursive(pNode->pLLeaf, value);
				}
				if (result == 0)
				{
					result = GetNodeWithValueRecursive(pNode->pRLeaf, value);
				}
				
			}
		}
		return result;
	}

	void PrintNodesRecursiveDF(CNode* pNode)
	{
		if (pNode)
		{
			PrintNodesRecursiveDF(pNode->pLLeaf);
			PrintNodesRecursiveDF(pNode->pRLeaf);

			printf("Nonde: ");
			pNode->Print();
		}
	}

	void PrintNodesInorderRecursive(CNode* pNode)
	{
		if (pNode)
		{
			PrintNodesInorderRecursive(pNode->pLLeaf);
			printf("Nonde: ");
			pNode->Print();
			PrintNodesInorderRecursive(pNode->pRLeaf);
		}
	}
};

int main()
{
	CBinaryTree tree = {};

	tree.Insert(3);
	tree.Insert(6);
	tree.Insert(2);
	tree.Insert(5);
	tree.Insert(1);
	tree.Insert(7);
	tree.Insert(8);

	tree.PrintNodesInorder();
	/* 1 2 3 5 6 7 8 */

	CNode* pResult = tree.GetNodeWithValue(5);
	printf("Result node: ");
	pResult->Print();

	tree.ClearData();
	
	return 0;
}