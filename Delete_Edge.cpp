#include"delete_edge.h"
bool Graphcnt::Delete_Edge(int v1, int v2)//图上删一条边 
{
	if (v1 != -1 && v2 != -1)
	{
		Edge* p = NodeTable[v1].adj, * q = NULL, * s = p;
		while (p != NULL && p->dest != NodeTable[v2].start)
		{
			q = p; p = p->link;
		}
		if (p != NULL) { //找到被删结点
			if (p == s) NodeTable[v1].adj = p->link;
			else q->link = p->link;
			delete p;
		}
		else
		{
			cout << "There is no edge between two nodes." << endl;//两点间没有边
			return false;
		}
		p = NodeTable[v2].adj; q = NULL; s = p;
		while (p->dest != NodeTable[v1].start)
		{
			q = p; p = p->link;
		}
		if (p == s) NodeTable[v2].adj = p->link;
		else q->link = p->link;
		delete p;
		cout << "Delete successfully." << endl;
		return true;
	}
	else
	{
		cout << "Node error,deletion failed." << endl;
		return false;
	}
}