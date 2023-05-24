#include <iostream>
#include <string>

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

    return res;
}

int main()
{
    std::string s;
    std::cin >> s;

    std::cout << modify(s);
}