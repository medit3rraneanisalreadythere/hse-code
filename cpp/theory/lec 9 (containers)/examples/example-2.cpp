#include <iostream>
#include <string>
#include <list>
#include <map>
#include <set>


int main () {
    std::list<std::set<std::string>> groups;
    std::map<std::string, decltype(groups)::iterator> book;

    while (true) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "add") {
            std::string first, second;
            std::cin >> first >> second;

            if (book.contains(first) && book.contains(second)) {
                if (book[first] != book[second]) {
                    const decltype(groups)::iterator it = book[second];

                    for (const std::string& word : *book[second])
                        book[word] = book[first];

                    book[first]->merge(*it);
                    groups.erase(it);
                }
            }

            else if (!book.contains(first) && !book.contains(second)) {
                groups.push_back({ first, second });
                book[first] = book[second] = std::prev(groups.end());
            }

            else {
                std::string& old_word = book.contains(first) ? first : second;
                std::string& new_word = book.contains(first) ? second : first;

                book[old_word]->insert(new_word);
                book[new_word] = book[old_word];
            }
        }

        else if (cmd == "get") {
            std::string word;
            std::cin >> word;

            if (!book.contains(word))
                std::cout << "no such word!" << std::endl;

            else {
                std::cout << "{ ";
                for (const std::string &str: *book[word])
                    std::cout << str << " ";
                std::cout << "}" << std::endl;
            }
        }

        else if (cmd == "print")
            for (const std::set<std::string>& group : groups) {
                std::cout << "{ ";
                for (const std::string& str : group)
                    std::cout << str << " ";
                std::cout << "}" << std::endl;
            }

        else
            break;
    }
}
