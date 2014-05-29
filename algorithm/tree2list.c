#include<stdio.h>
#include<stdlib.h>
struct BSTreeNode
{
	int m_nValue;
	BSTreeNode* m_pLeft;
	BSTreeNode* m_pRight;
public:
	BSTreeNode(int i):m_nValue(i),m_pLeft(0),m_pRight(0){}
	BSTreeNode():m_pLeft(0),m_pRight(0){}
};
void AddNode(struct BSTreeNode&root, struct BSTreeNode& node)
{
	if(root.m_nValue == node.m_nValue)
		return;

	if(root.m_nValue > node.m_nValue)
	{
		if(root.m_pLeft == 0)
		{
			root.m_pLeft = &node;
		}else
		{
			AddNode(*root.m_pLeft,node);
		}
	}else if(root.m_nValue < node.m_nValue)
	{
		if(root.m_pRight ==0)
			root.m_pRight = &node;
		else
			AddNode(*root.m_pRight, node);
	}

}
void AddLeft(struct BSTreeNode& bs, struct BSTreeNode& bs1)
{
	bs.m_pLeft = &bs1;
}

void AddRight(struct BSTreeNode& bs, struct BSTreeNode& bs1)
{
	bs.m_pRight = &bs1;
}
//因为左子树得返回最大的指针，
//右子树返回最小的指针。
//所有传入i表示调用的左子树还是右子树。
struct BSTreeNode& Iterator(BSTreeNode& bs, int i)
{
	if(bs.m_pLeft)
	{
		BSTreeNode* p = &(Iterator(*bs.m_pLeft,0));
		bs.m_pLeft = p;
		p->m_pRight = &bs;
	}
	if(bs.m_pRight)
	{
		BSTreeNode *p =&Iterator(*bs.m_pRight,1); 
		bs.m_pRight = p;
		p->m_pLeft = &bs;
	}

	BSTreeNode* pBs= &bs ;
	if(i == 0)
	{
		while(pBs->m_pRight)
			pBs= pBs->m_pRight;
		return *pBs;
	}else
	{
		while(pBs->m_pLeft)
			pBs= pBs->m_pLeft;
		return *pBs;
	}
}
int main()
{
	BSTreeNode bs(10);
	BSTreeNode bs6(6);
	BSTreeNode bs14(14);
	BSTreeNode bs12(12);
	BSTreeNode bs16(16);
	BSTreeNode bs4(4);
	BSTreeNode bs8(8);
	AddNode(bs6,bs4);
	AddNode(bs14,bs16);
	AddNode(bs14,bs12);
	AddNode(bs6,bs8);
	AddNode(bs,bs14);
	AddNode(bs,bs6);
	Iterator(bs,0);
	struct BSTreeNode * pBs = &bs4;
	for(;pBs;pBs = pBs->m_pRight)
		printf("%d=>",pBs->m_nValue);
	return 0;
}
