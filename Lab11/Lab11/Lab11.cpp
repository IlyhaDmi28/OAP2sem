#include <iostream>
using namespace std;

struct Tree
{
	int data;
	Tree* left, * right;
};

Tree* Root = nullptr;
Tree* This = Root;

void makeTree(int bufvar, unsigned short * id);
void view(Tree* This);

short find(Tree* This, unsigned short id);
//short delEL(Tree* This, bool Left, bool Right, unsigned short id, bool* l, bool* r);
Tree* DeleteNode(Tree* node, int val);
void leaves(Tree* This, bool s, unsigned short *c);

void main()
{
    setlocale(LC_CTYPE, "RUS");
    int bufvar = 1;
	unsigned short id = 0;
    unsigned short choise;
    do {
        cout << "1. Создание дерева\n";
        cout << "2. Вывод элементов дерева\n";
        cout << "3. Поиск элемента\n";
        cout << "4. Удаление элемента\n";
        cout << "5. Количество правых листьев\n";
        cout << "0. ВЫХОД\n" << endl;

        cout << "Выберите пункт: ";
        cin >> choise;
        switch (choise)
        {
        case 1: 
        {
            while (bufvar)
            {
                cout << "Введите элемент(0 - выход): ";
                cin >> bufvar;
				if(bufvar) makeTree(bufvar, &id);
            }
            break;
        }
		case 2: { view(Root); cout << endl; break; }
        case 3: { 
			cout << "Какой элемент вы хотите найти: ";
			unsigned short el;
			cin >> el;
			find(Root, el);
			cout << endl; 
			break; }
        case 4: {
			cout << "Какой элемент вы хотите удалить: ";
			unsigned short el;
			bool l, r;
			cin >> el;
			DeleteNode(Root, el);
			cout << endl;
			break; 
		}
		case 5: {unsigned short t = 0;  leaves(Root, false, &t); cout << "Количество листьев: " << t << endl; break; }
        default: cout << "ВЫБОР СДЕЛАН НЕ КОРРЕКТНО! ПОВТОРИТЕ!\n";
        }
    }
    while (choise);

}

void makeTree(int bufvar, unsigned short* id)
{
	unsigned short id1 = *id;
	if (Root == nullptr)
	{
		Root = new Tree;
		This = Root;
		Root->left = nullptr; Root->right = nullptr;
		This->data = bufvar;
		id1++;
		*id = id1;
		cout << "Введите элемент(0 - выход): ";
		cin >> bufvar;
		if (!bufvar) return;
		makeTree(bufvar, id);
	}
	else
	{
		if (bufvar > This->data)
		{
			if (This->right == nullptr)
			{
				This->right = new Tree;
				This = This->right;
				This->data = bufvar;
				id1++;
				*id = id1;
				This->right = nullptr;
				This->left = nullptr;
				This = Root;
			}
			else
			{
				This = This->right;
				makeTree(bufvar, id);
			}
		}
		else
		{
			if (This->left == nullptr)
			{
				This->left = new Tree;
				This = This->left;
				This->data = bufvar;
				id1++;
				*id = id1;
				This->right = nullptr;
				This->left = nullptr;
				This = Root;
			}
			else
			{
				This = This->left;
				makeTree(bufvar, id);
			}
		}
	}

}

void view(Tree* This) {
	if (This)
	{
		view(This->left);
		if(This->data) cout << This->data << ' ';
		view(This->right);
	}
}

short find(Tree* This, unsigned short id)
{
	if (This)
	{
		id = find(This->left, id);
		id--;
		if (!id)
		{
			cout << This->data << ' ';
		}
		id = find(This->right, id);
	}
	return id;
}

//short delEL(Tree* This, bool Left, bool Right, unsigned short id, bool *l, bool *r)
//{
//	if (This)
//	{
//		id = delEL(This->left, true, false, id, l, r);
//		if (id == 1 && *l) { This->left = nullptr; *l = false; } 
//		if (id == 1 && *r) { This->right = nullptr; *r = false;  }
//		id--;
//		if (id == 0)
//		{
//			if (Left)  *l = true;
//			if (Right) *r = true;
//			return 0;
//		}
//		id = delEL(This->right, false, true, id, l, r);
//	}
//	return id;
//}

Tree* DeleteNode(Tree* node, int val) {
	if (node == NULL)
		return node;

	if (val == node->data) {

		Tree* tmp;
		if (node->right == NULL)
			tmp = node->left;
		else {

			Tree* ptr = node->right;
			if (ptr->left == NULL) {
				ptr->left = node->left;
				tmp = ptr;
			}
			else {

				Tree* pmin = ptr->left;
				while (pmin->left != NULL) {
					ptr = pmin;
					pmin = ptr->left;
				}
				ptr->left = pmin->right;
				pmin->left = node->left;
				pmin->right = node->right;
				tmp = pmin;
			}
		}

		delete node;
		return tmp;
	}
	else if (val < node->data)
		node->left = DeleteNode(node->left, val);
	else
		node->right = DeleteNode(node->right, val);
	return node;
}

void leaves(Tree* This, bool s, unsigned short* c)
{
	unsigned short c1 = *c;
	if (This)
	{
		leaves(This->left, false, c);
		leaves(This->right, true, c);
		if (This->right == nullptr && This->left == nullptr && s) { c1++; *c = c1; };
	}
}
