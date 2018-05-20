#pragma once
#ifndef RED_BLACK_H
#define RED_BLACK_H
#include <string>

static int ind = 0;

struct RedBlackNode {

	int num;
	int index;
	char colour[10] ;
	RedBlackNode* whos;
	RedBlackNode* left;
	RedBlackNode* right;
	
	RedBlackNode(int num);
};


class RedBlack
{
	private:
		RedBlackNode* riza;

	protected:
		void rot_l(RedBlackNode *&, RedBlackNode *&);
		void rot_r(RedBlackNode *&, RedBlackNode *&);
		void rb_repair(RedBlackNode *&, RedBlackNode *&);
		RedBlackNode* rb_in(RedBlackNode* riza, RedBlackNode* temp);

	public:
		RedBlack();
		RedBlackNode* get_r();
		void input(const int &num);
		void rb_inorder_s(RedBlackNode* riza, int nu);
		//void levelOrder();
};

























/*
struct my_node
{
	my_node(int i = 0) : int_(i) {};
	my_node *parent_, *left_, *right_;
	int color_;
	//other members
	int int_;
};

//Define our own rbtree_node_traits
struct my_rbtree_node_traits
{
	typedef my_node node;
	typedef my_node* node_ptr;
	typedef const my_node* const_node_ptr;
	typedef int color;
	static node_ptr get_parent(const_node_ptr n); 
	static void set_parent(node_ptr n, node_ptr parent);  
	static node_ptr get_left(const_node_ptr n);
	static void set_left(node_ptr n, node_ptr left); 
	static node_ptr get_right(const_node_ptr n);   
	static void set_right(node_ptr n, node_ptr right); 
	static color get_color(const_node_ptr n);
	static void set_color(node_ptr n, color c);   
	static color black();
	static color red();
};

struct node_ptr_compare
{
	bool operator()(const my_node *a, const my_node *b);
};
*/
#endif