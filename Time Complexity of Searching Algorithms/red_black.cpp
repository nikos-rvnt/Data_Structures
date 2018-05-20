/*
 Red-Black Tree (class) consisted of Red-Black Nodes (struct obj.)
 Based on http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap14.htm
*/

#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "red_black.h"


using namespace std;

RedBlackNode::RedBlackNode(int number)
{
	
	this->num = number;
	this->index = ++ind;
	//this->colour = " ";
	whos = left = right =  NULL;
}

RedBlack::RedBlack()
{
	this->riza = NULL;
}

RedBlackNode* RedBlack::get_r() {
	return riza;
}

RedBlackNode* RedBlack::rb_in(RedBlackNode* riza, RedBlackNode* temp) {
	
	// if NULL rb_node -> num = number  
	if (riza == NULL) {
		//cout << "rere3" << temp->num;
		//riza->num = temp->num;
		//cout << riza->num << "--" << temp->num;
		return temp;
	}

	// number <= rb_node->number put it left
	if (temp->num <= riza->num) {
		//cout << "rere1" << temp;
		riza->left = rb_in(riza->left, temp);
		riza->left->whos = riza;
	}
	// number > rb_node->number put it right  
	else if (temp->num > riza->num) {
		//cout << "rere2" << temp;
		riza->right = rb_in(riza->right, temp);
		riza->right->whos = riza;
	}
	
	return riza;
}

void RedBlack::input(const int &num) {
	
	RedBlackNode* neo_rb = new RedBlackNode(num);
	riza = rb_in(riza, neo_rb);
	//cout << "pisw!";
	rb_repair(riza, neo_rb);
}

void RedBlack::rb_inorder_s(RedBlackNode* r,int numero) {
	
	//int ind = r->index;
	if ((r == NULL) || (r->num == numero)) {
		//if (r!=NULL)
			//cout << r->num << endl;
		return;
	}
	if(r->num!=numero)
		 rb_inorder_s(r->left,numero);
	
	//return r->index;

	if(r->num!=numero)
		 rb_inorder_s(r->right,numero);
}

void RedBlack::rot_l(RedBlackNode *&riza, RedBlackNode *&x) {
	//cout << "lefty " << endl;
	if (x->right == NULL) {
		return;
	}

	RedBlackNode* x_temp = x->right;
	x->right = x_temp->left;

	if (x_temp->left != NULL) {
		x_temp->left->whos = x;
	}
	// link x's parent to x_temp's parent
	x_temp->whos = x->whos;

	if (x->whos == NULL)
		riza = x_temp;
	else if (x == x->whos->left)
		x->whos->left = x_temp;
	else
		x->whos->right = x_temp;

	x_temp->left = x;
	x->whos = x_temp;
	//cout << "lefty " << endl;
}

void RedBlack::rot_r(RedBlackNode *&riza, RedBlackNode *&x) {
	//cout << "righty " << endl;
	if (x->left == NULL) {
		return;
	}

	RedBlackNode* x_temp = x->left;
	x->left = x_temp->right;

	if (x_temp->right != NULL) {
		x_temp->right->whos = x;
	}
	// link x's parent to x_temp's parent
	x_temp->whos = x->whos;

	if (x->whos == NULL)
		riza = x_temp;
	else if (x == x->whos->left)
		x->whos->left = x_temp;
	else
		x->whos->right = x_temp;

	x_temp->right = x;
	x->whos = x_temp;
	//cout << "righty " << endl;
}


void RedBlack::rb_repair(RedBlackNode *&riza, RedBlackNode *&x) {

	if (riza == x){
		strcpy_s(x->colour,"black");
		//cout << " we ";
		return;
	}
	//cout << " ei ";
	
	strcpy_s(x->colour, "red"); static int i = 0;
	//cout << ++i << endl;
	while ((x != riza) && strcmp("red", x->whos->colour) == 0) {

		//cout << ++i << endl;
		RedBlackNode* x_2up = x->whos->whos;

		// if : left child of grandparent of x == parent of x
		if (x_2up->left == x->whos) {

			RedBlackNode*  x_temp = x_2up->right;

			// check if there is a right child
			//if (x_2up->right != NULL)
				
			// Case1: right-child of grandparent's colour == red
			if (x_temp!=NULL && (strcmp(x_temp->colour, "red") == 0)) {
				strcpy_s(x->whos->colour, "black");
				strcpy_s(x_temp->colour, "black");
				strcpy_s(x_2up->colour, "red");
				x = x_2up;
				//cout << " a1 ";
			}
			else {

				// Case2: x == parent's right child
				if (x == x->whos->right) {
					x = x->whos;
					rot_l(riza, x);

				}
				//cout << " a2 ";
				// Case3: x == parent's left child
				strcpy_s(x->whos->colour, "black");
				strcpy_s(x_2up->colour, "red");
				rot_r(riza, x_2up);
				//cout << " a3 ";

			}
		}
		// if : right child of grandparent of x == parent of x
		else {

			RedBlackNode*  x_temp = x_2up->left;

			// check if there is a left child
			//if (x_2up->left != NULL)
			//	x_temp = x_2up->left;

			// Case1: left-child of grandparent's colour == red
			if (x_temp!=NULL && (strcmp(x_temp->colour, "red") == 0)) {
				strcpy_s(x->whos->colour, "black");
				strcpy_s(x_temp->colour, "black");
				strcpy_s(x_2up->colour, "red");
				x = x_2up;
				//cout << " b1 ";
			}
			else {

				// Case2: x == parent's left child
				if (x == x->whos->left) {
					x = x->whos;
					rot_r(riza, x);
				}
				//cout << " b2 ";
				// Case3: x == parent's right child
				strcpy_s(x->whos->colour, "black");
				strcpy_s(x_2up->colour, "red");
				rot_l(riza, x_2up);
				//cout << " b3 ";

			}

		}

	}
	strcpy_s(riza->colour,"black");
	//cout << "H riza : " << riza->colour << endl;
	//cout << " ao ";
	
}


/*
my_rbtree_node_traits::node_ptr my_rbtree_node_traits::get_parent(const_node_ptr n) 
{ 
	return n->parent_; 
}
void my_rbtree_node_traits::set_parent(node_ptr n, node_ptr parent) 
{ 
	n->parent_ = parent; 
}
my_rbtree_node_traits::node_ptr my_rbtree_node_traits::get_left(const_node_ptr n) 
{ 
	return n->left_; 
}
void my_rbtree_node_traits::set_left(node_ptr n, node_ptr left) 
{ 
	n->left_ = left; 
}
my_rbtree_node_traits::node_ptr my_rbtree_node_traits::get_right(const_node_ptr n) 
{ 
	return n->right_; 
}
void my_rbtree_node_traits::set_right(node_ptr n, node_ptr right)
{ 
	n->right_ = right; 
}
my_rbtree_node_traits::color my_rbtree_node_traits::get_color(const_node_ptr n) 
{ 
	return n->color_; 
}
void my_rbtree_node_traits::set_color(node_ptr n, color c) 
{ 
	n->color_ = c; 
}
my_rbtree_node_traits::color my_rbtree_node_traits::black() 
{ 
	return color(0); 
}
my_rbtree_node_traits::color my_rbtree_node_traits::red() 
{ 
	return color(1); 
}


bool node_ptr_compare::operator()(const my_node *a, const my_node *b)
{
	return a->int_ < b->int_;
}
*/