/*
 * evaltree.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef EVALTREE_H_
#define EVALTREE_H_

#include <cctype>
#include <string>

#include <sstream>
#include <queue>
#include <stack>
#include "exception.h"

class EvalTree;

class TreeNode {
private:
	char value;
	TreeNode *left, *right;

	bool isOperator() const;
	bool isVariable() const;
	bool isOperand() const;

public:
	TreeNode(char);
	TreeNode(char, TreeNode*, TreeNode*);
	int depth() const;
	void inorder(std::stringstream&) const;
	void postorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;
	void levelOrder(std::stringstream&) const;
	int howManyLeaves() const;
	char minValue() const;
	bool find(char) const;
	double eval(double x) const;
	TreeNode* derive() const;
	void removeChilds();
	TreeNode* copy() const;
	friend class EvalTree;
};

TreeNode::TreeNode(char c) {
	value = c;
	left = NULL;
	right = NULL;
}

TreeNode::TreeNode(char c, TreeNode* le, TreeNode* ri) {
	value = c;
	left = le;
	right = ri;
}

bool TreeNode::isOperator() const {
	if((value=='+')||(value=='-')||(value=='*')||(value=='/')){
		return true;
	}
	return false;
}

bool TreeNode::isVariable() const {
	if((value == 'x')||(value=='y')){
		return true;
	}
	return false;
}

bool TreeNode::isOperand() const {
	if((value>'0')&&(value<'9')){
		return true;
	}
	return false;
}

int TreeNode::depth() const {
	
	int right_count = -1;
    int left_count = -1;
    int higher_count = -1;

	  if(left != 0){
        left_count = left->depth();
    }
	
    if(right != 0){
        right_count = right->depth();
    }
  

	higher_count = (left_count > right_count) ?  left_count:right_count;
	return (higher_count +1);
	/*
	int left_count = -1;
	int right_count = -1;
	int total_count = -1;

	if(left!=NULL){
		left_count = left->depth();
	}
	if(right!=NULL){
		right_count = right->depth();
	}
	
	total_count = (left_count > right_count) ?  left_count:right_count;
	return (total_count +1);
	*/
}

void TreeNode::inorder(std::stringstream &aux) const {
	
	if(left != 0){
        left->inorder(aux);
	}

	aux << value << " ";

	if(right != 0){
        right->inorder(aux);
	}
	
}

void TreeNode::postorder(std::stringstream &aux) const {
	
	if(left!=NULL){
		left->postorder(aux);
	}
	if(right!=NULL){
		right->postorder(aux);
	}

	aux << value << " ";
}

void TreeNode::preorder(std::stringstream &aux) const {
	
	aux << value << " ";

    if(left != 0){
        left->preorder(aux);
	}

	if(right != 0){
        right->preorder(aux);
	}
	
	
	/*
	aux << value << " ";

    if(left != 0){
        left->preorder(aux);
	}

	if(right != 0){
        right->preorder(aux);
	}
*/
}

int TreeNode::howManyLeaves() const {
	
	int counter=0;
	int left_counter = 0;
	int right_counter = 0;
	if(left!=NULL){
		left_counter = left->howManyLeaves();
	}
	if(right!=NULL){
		right_counter = right->howManyLeaves();
	}
	counter = left_counter + right_counter;
	if(counter == 0){
		return 1;
	}
	return counter;

}

char TreeNode::minValue() const {
	
	char mini ='9';
	char auxmini ='9';
	char right_auxmini ='9';
	char left_auxmini ='9';
	if(isOperand()){
		mini = value;
	}
	if(isOperator()){
		if(left!=NULL){
			left_auxmini = left->minValue();
		}
		if(right!=NULL){
			right_auxmini = right->minValue();
		}
		if(right_auxmini<left_auxmini){
			mini = right_auxmini;
		}else{
			mini = left_auxmini;
		}
	}
	return mini;
}

bool TreeNode::find(char val) const {
	
	bool findable = false;
	if(value==val){
		return true;
	}
	if(left!=NULL){
		if(findable || left->find(val)){
			findable = true;
		}else{
			findable = false;
		}
	}
	if(right!=NULL){
		if(findable || right->find(val)){
			findable = true;
		}else{
			findable = false;
		}
	}
	return findable;
	
}

double TreeNode::eval(double x) const {
    double left_value, right_value;
//"x x * 2 x * - 1 +"
    if (isVariable()){
        return x;
    }

    if(isOperand()){
       return value - '0';
    }

    if(isOperator()){
        if(left != 0){
                left_value = left->eval(x);
        }

        if(right !=0){
                right_value = right->eval(x);
        }

        if (value == '*') return left_value * right_value;
        if (value == '+') return left_value + right_value;
        if (value == '-') return left_value - right_value;
        if (value == '/'){
                if(right_value == 0) throw IllegalAction();
                return left_value / right_value;}
    }
	return 0;
}






/*
double TreeNode::eval(double x) const {
    
	double left_value, right_value;
	//"x x * 2 x * - 1 +"
    if (isVariable()){
        return x;
    }

    if(isOperand()){
       return value - '0';
    }

    if(isOperator()){
        if(left != 0){
                left_value = left->eval(x);
        }

        if(right !=0){
                right_value = right->eval(x);
        }

        if (value == '*') return left_value * right_value;
        if (value == '+') return left_value + right_value;
        if (value == '-') return left_value - right_value;
        if (value == '/'){
                if(right_value == 0) {throw IllegalAction();}
                return left_value / right_value;
				}
    }
	return 0;
	
}
*/
void TreeNode::removeChilds() {

}

TreeNode* TreeNode::derive() const {
	return 0;
}

TreeNode* TreeNode::copy() const {
	return 0;
}

class EvalTree {
private:
	TreeNode *root;

	std::queue<std::string> tokenize(std::string);

public:
	EvalTree();
	EvalTree(std::string) throw (IllegalAction);
	~EvalTree();
	bool empty() const;
	int height() const;
	std::string inorder() const;
	std::string postorder() const;
	std::string preorder() const;
	std::string levelOrder() const;
	int howManyLeaves() const;
	char minValue() const throw (IllegalAction);
	bool find(char) const;
	double eval(double) const throw (IllegalAction) ;
	EvalTree* derive() const;
	void removeAll();
	bool isFull() const;
	int internalNodes() const;
	bool isPerfect() const;
	bool isDegenerate() const;
};

EvalTree::EvalTree() {
	root = 0;
}

std::queue<std::string> EvalTree::tokenize(std::string str) {
	int i = 0;
	int length = str.size();
	std::string aux;
	std::queue<std::string> result;

	while (i < length) {
		if (isdigit(str[i])) {
			aux.clear();
			do {
				aux += str[i];
				i++;
			} while(isdigit(str[i]));
			result.push(aux);
		} else if (isspace(str[i])) {
			i++;
		} else {
			aux.clear();
			aux += str[i];
			result.push(aux);
			i++;
		}
	}
	return result;
}

EvalTree::EvalTree(std::string str) throw (IllegalAction) {
	root = 0;
	std::stack<TreeNode*> s;
	std::queue<std::string> tokens = tokenize(str);
	std::string aux;
	TreeNode *left, *right, *newNode;

	while (!tokens.empty()) {
		aux = tokens.front(); tokens.pop();
		if (aux == "+" || aux == "-" || aux == "*" || aux == "/") {
			if (s.empty()) {
				throw IllegalAction();
			}
			left = s.top(); s.pop();
			if (s.empty()) {
				throw IllegalAction();
			}
			right = s.top(); s.pop();
			newNode = new TreeNode(aux[0], left, right);
			s.push(newNode);
		} else if (aux[0] == 'x' || isdigit(aux[0])) {
			newNode = new TreeNode(aux[0]);
			s.push(newNode);
		}
	}
	newNode = s.top(); s.pop();
	if (!s.empty()) {
		throw IllegalAction();
	}
	root = newNode;
}

EvalTree::~EvalTree() {
	removeAll(); 
}

bool EvalTree::empty() const {
	if(root == NULL){
		return true;
	}else{
		return false;
	}
}


int EvalTree::height() const {
	
	
	if(empty()){
		return 0;
	}
	int x = root->depth();
	return x+1;
}

std::string EvalTree::inorder() const {
	std::stringstream aux;

	root->inorder(aux);
	
	return aux.str();
}

std::string EvalTree::preorder() const {
	std::stringstream aux;

	root->preorder(aux);

	return aux.str();
}

std::string EvalTree::postorder() const {
	std::stringstream aux;

	root->postorder(aux);

	return aux.str();
}

std::string EvalTree::levelOrder() const {
	std::stringstream aux;
	std::queue<TreeNode*> que;
	TreeNode *ptr;

	ptr = root;

	que.push(ptr);

	while(!que.empty()){
		ptr = que.front();
		aux << ptr->value << " "; 
		que.pop();
		if(ptr->left!=NULL){
			que.push(ptr->left);
		}
		if(ptr->right!=NULL){
			que.push(ptr->right);
		}
	}

	return aux.str();
}

int EvalTree::howManyLeaves() const {
	if(root == 0){
		return 0;
	}

	return root->howManyLeaves();
}

char EvalTree::minValue() const throw (IllegalAction) {
	if(root == NULL){
		throw IllegalAction();
	}
	return root->minValue();
}

bool EvalTree::find(char c) const {
	if(root == 0){
		return false;
	}
	return root->find(c);
}

double EvalTree::eval(double x) const throw (IllegalAction) {
	if(empty()) throw IllegalAction();
	return root->eval(x);
	/*
	if(empty()){
		throw IllegalAction();
	}
	if(root!=NULL){
		return root->eval(x);
	}
	*/
}

EvalTree* EvalTree::derive() const {
	return 0;
}

void EvalTree::removeAll() {
}
#endif /* EVALTREE_H_ */
