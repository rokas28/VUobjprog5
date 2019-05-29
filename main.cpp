#include "main.h"
#include "word.h"

int main() {

    multiset<Word> text;
    set<Word> words;
    set<string> url;
    vector<int> eil;

    string eile;
    int nr = 0;
    std::ifstream df (data);
    while(getline(df,eile)){
        nr++;
        std::istringstream iss(eile);
        string a;
        while(iss >> a) {
            if (std::regex_match (a, std::regex(R"(^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?$)") )){
                url.insert(a);
            }
            else{
                std::regex rgx("\\w+");
                for( std::sregex_iterator it(a.begin(), a.end(), rgx), it_end; it != it_end; ++it ){
                    words.insert(Word((*it)[0]));
                    text.insert(Word((*it)[0],nr));
                }
            }
        }
    }

    cout << "URL adresai, kurie yra tekste:" << endl;
    for(auto i : url) cout << i << endl;
    cout << endl;

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