#include "api.hpp"
#include <string>
#include <map>
#include <vector>

std::map<Node, int> leaves;
Node root;

struct Node
{
	bool nullable;
	std::vector<size_t> firstpos;
	std::vector<size_t> lastpos;
	std::vector<size_t> followpos;

	Node (char _c, bool flag, size_t _pos): c(_c), isOperator(flag), pos(_pos)
	{
		if (flag)
		{
			if (_c == '|')
			{
				
			}
		}

		nullable = isNullable();
		countFirstPos();
		countLastPos();
		countFollowPos();
		// undefined = false;
	}
	Node () 
	{
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}

// Rule-of-three
	Node (const Node& t) = default;
	Node& operator= (const Node& t) = default;
	~Node () = default;
	
	char c;
	bool isOperator; // true if c == '*', '|', 'concat'
	size_t pos = 0;

	// bool undefined = true;

	Node* left;
	Node* right;
	Node* parent;

private:
	bool isNullable()
	{

	}

	void countFirstPos()
	{

	}

	void countLastPos()
	{
		
	}

	void countFollowPos()
	{
		
	}
};

void buildTree(const std::string &s)
{
	size_t cpos = 1;
	Node cur;

	for (char t: s)
	{
		if (t == '(')
		{
			(cur.left)->parent = &cur;
			cur = *(cur.left);
		}

		else if (t == '*' || t == '|' || t == '.')
		{
			cur = Node(t, true, cpos);
			cpos++;
			(cur.right)->parent = &cur;
			cur = *(cur.right);
		}

		else if (t == ')')
		{
			cur = *(cur.parent);
		}

		else
		{
			cur = Node(t, false, cpos);
			cpos++;
			cur = *(cur.parent);
		}
	}

	root = cur;
}

std::string modify(const std::string &s)
{
	std::string res = "";
	bool wasMlt = false;
    bool eps = true;

	for (char t: s)
	{
        if (t == '(')
        {
            if (wasMlt)
			{
				res += '.';
			}

            eps = true;
            wasMlt = false;
        }

		else if (t != '*' && t != '|')
		{
			if (wasMlt && t != ')')
			{
				res += '.';
			}

            eps = false;
            wasMlt = true;
		}

        else
        {
            if (eps)
            {
                res += '@';
                eps = false;
            }

            wasMlt = false;
        }

		res += t;
	}
	res += '#';

    return res;
}

DFA re2dfa(const std::string &s) {
	DFA res = DFA(Alphabet(s));
	std::string RE = modify(s);


	// res.create_state("Start", true);
	// res.set_initial("Start");
	return res;
}
