#include "Tree.h"
void Tree::createTree(int n, Knot** root) {
	Knot* nowKnot;
	int nl, nr;
	float x;
	if (n == 0)
		*root = nullptr;
	else {
		nl = n / 2;
		nr = n - nl - 1;
		cin >> x;
		nowKnot = new Knot;
		nowKnot->k = x;
		createTree(nl, &(nowKnot->left));
		createTree(nr, &(nowKnot->right));
		*root = nowKnot;
	}
}
void Tree::averageLeft(Knot** key, float& sum, int& k) {
	if (*key != nullptr)
	{
		averageLeft(&((**key).right), sum, k);
		averageLeft(&((**key).left), sum, k);
		sum += (**key).k;
		k++;
	}
}
void Tree::averageRight(Knot** key, float& sum, int& k) {
	if (*key != nullptr)
	{
		averageRight(&((**key).right), sum, k);
		averageRight(&((**key).left), sum, k);
		sum += (**key).k;
		k++;
	}
}
void Tree::printTree(Knot** key, int l) {
	string space;
	if (l > 0)
		space.append(l * 4, ' ');
	if (*key != nullptr)
	{
		printTree(&((*key)->right), l + 1);
		cout << space;
		cout << (*key)->k << endl;
		printTree(&((**key).left), l + 1);
	}
}
void Tree::deleteTree(Knot** key) {
	if (*key != nullptr)
	{
		deleteTree(&((**key).right));
		deleteTree(&((**key).left));
		(*key) = nullptr;
	}

}
Knot** Tree::getRoot() {
	return &root;
}