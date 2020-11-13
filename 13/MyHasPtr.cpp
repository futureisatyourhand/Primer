#include<iostream>
//13.27
class HasPtr{
	friend std::ostream &print(std::ostream &os,const HasPtr &ptr);
	public:
		HasPtr(const std::string &s=std::string()):ps(new std::string(s)),i(0),use(new std::size_t(1)){}

		HasPtr(const HasPtr &p):ps(p.ps),i(p.i),use(p.use){++*use;}

		HasPtr &operator=(const HasPtr &);

		~HasPtr();

	private:
		std::string *ps;
		int i;
		std::size_t *use;
};

HasPtr::~HasPtr(){
	if(--*use==0){
		delete ps;
		delete use;
	}
}

HasPtr &HasPtr::operator=(const HasPtr &rhs){
	++*use;
	if(--*use==0){
		delete ps;
		delete use;
	}
	ps=rhs.ps;
	i=rhs.i;
	use=rhs.use;
	return *this;
}

std::ostream &print(std::ostream &os,const HasPtr &ptr){
	os<<*(ptr.ps)<<" "<<ptr.i<<" "<<*(ptr.use)<<std::endl;
	return os;
}


//13.28 a
class TreeNode{
	private:
		std::string value;
		int count;
		TreeNode *left;
		TreeNode *right;
	public:
		TreeNode():value(""),count(0),left(nullptr),right(nullptr){}

		TreeNode(std::string s,int no,TreeNode &p,TreeNode &q):value(s),count(no),left(new TreeNode(p)),right(new TreeNode(q)){}
	
		TreeNode &operator=(const TreeNode &);

		TreeNode(const TreeNode &);
		~TreeNode();
};

TreeNode::~TreeNode(){
	if(left!=nullptr)
		delete left;
	if(right!=nullptr)
		delete right;
}

TreeNode &TreeNode::operator=(const TreeNode &p){
	value=p.value;
	count=p.count;
	if(p.left!=nullptr)
		left=new TreeNode(*p.left);
	else
		left=nullptr;
	if(p.right!=nullptr)
		right=new TreeNode(*p.right);
	else
		right=nullptr;
	return *this;
}
TreeNode::TreeNode(const TreeNode &p){
	value=p.value;
	count=p.count;
	if(p.left!=nullptr)
		left=new TreeNode(*p.left);
	else
		left=nullptr;
	if(p.right!=nullptr)
		right=new TreeNode(*p.right);
	else
		right=nullptr;
}


//11.28 b
class BinTreeNode{
	private:
		TreeNode *root;
	public:
		BinTreeNode():root(new TreeNode()){}

		BinTreeNode(TreeNode &p):root(new TreeNode(p)){}

		BinTreeNode(const BinTreeNode &p);

		BinTreeNode &operator=(const BinTreeNode &);

		~BinTreeNode();
};
BinTreeNode::BinTreeNode(const BinTreeNode &p){
	root=new TreeNode(*p.root);
}
BinTreeNode::~BinTreeNode(){
	delete root;
}
BinTreeNode &BinTreeNode::operator=(const BinTreeNode &p){
	root=new TreeNode(*p.root);
	return *this;
}


int main(int argv,char **argc){
	HasPtr p("beijing");

	print(std::cout,p);

	TreeNode n1, n2, n4, n5;
	TreeNode n6("hello", 3, n4, n5);
	n2 = n6;
	TreeNode n3(n6);

	BinTreeNode b1;
	BinTreeNode b2(n6);
	b1=b2;
	return 0;
}
