#include "main.h"
#include "word.h"

int main() {

    multiset<Word> text;
    set<Word> words;
    vector<int> eil;

    string eile;
    int nr = 0;
    std::ifstream df (data);
    while(getline(df,eile)){
        nr++;
        string temp;
        std::regex rgx("\\w+");

        for( std::sregex_iterator it(eile.begin(), eile.end(), rgx), it_end; it != it_end; ++it ){
                words.insert(Word((*it)[0]));
                text.insert(Word((*it)[0],nr));
        }
    }

    for(auto it = words.begin(); it != words.end(); ++it){
        auto n = 0;
        eil.clear();
        for(auto i = text.begin(); i != text.end(); ++i) {
            n = text.count(it->get_text());
            if(it->get_text() == i->get_text()){
                eil.push_back(i->get_eil());
            }
        }
        if(n >= 2){
            cout << it->get_text() << " tekste pasikartojo " << n << " kartus siose eilutese: ";
            for(auto i : eil)cout << i << " ";
            cout << endl;
        }
    }

    return 0;
}