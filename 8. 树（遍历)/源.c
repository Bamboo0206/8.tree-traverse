#include<stdio.h>
#include<stdlib.h>
#define null -1
void PreOrderTraversal(int root);
int tree[2][100];
struct node {
	int data;
	struct node *nextPtr;
};
main()
{
	int size, i, root, check[100] = { 0 };
	char lc, rc;
	scanf_s("%d", &size);
	getchar();
	for (i = 0; i<size; i++)
	{
		scanf_s("%c", &lc);
		getchar();
		scanf_s("%c", &rc);
		getchar();
		if (lc == '-') tree[0][i] = null;
		else
		{
			tree[0][i] = lc - '0';
			check[tree[0][i]] = 1;
		}
		if (rc == '-') tree[1][i] = null;
		else
		{
			tree[1][i] = rc - '0';
			check[tree[1][i]] = 1;
		}

	}
	for (i = 0; i<size; i++)
		if (check[i] == 0) root = i;
	//PreOrderTraversal(root);

	struct node *head,*temp,*rear;
	head = (struct node*)malloc(sizeof(struct node));
	head->data = root;
	head->nextPtr = NULL;
	rear = head;
	while (head)
	{
		temp = head;
		head = head->nextPtr;
		if (rear == temp)
			rear = NULL;
		root = temp->data;//出队
		free(temp);
		temp = NULL;
		if (tree[0][root] == null&&tree[1][root] == null)
			printf("%d ", root);//访问该节点
		if (tree[0][root] != null)//左儿子入队
		{
			temp= (struct node*)malloc(sizeof(struct node));
			temp->data = tree[0][root];
			temp->nextPtr = NULL;
			if (rear != NULL)
			{
				rear->nextPtr = temp;
				rear = rear->nextPtr;
			}
			else//之前队列是空的，后来加入了一个节点
			{
				head = temp;
				rear = head;
			}
		}
		if (tree[1][root] != null)//右儿子入队
		{
			temp = (struct node*)malloc(sizeof(struct node));
			temp->data = tree[1][root];
			temp->nextPtr = NULL;
			if (rear != NULL)
			{
				rear->nextPtr = temp;
				rear = rear->nextPtr;
			}
			else//之前队列是空的，后来加入了一个节点
			{
				head = temp;
				rear = head;
			}
		}
	}

	system("pause");
	return 0;
}
//层序遍历
/*void PreOrderTraversal(int root)
{
	if (root != null)
	{

		if (tree[0][root] == null&&tree[1][root] == null)
		{
			printf("%d ", root);
			//return;
		}
	PreOrderTraversal(tree[0][root]);
	PreOrderTraversal(tree[1][root]);
	}
}*///先序遍历
