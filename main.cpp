#include "main.h"
#include "word.h"

int main() {
    setlocale(LC_ALL, LOCALE_TYPE);
    multiset<Word> text;
    set<Word> words;
    set<string> url;
    vector<int> eil;

    string eile;
    int nr = 0;
    std::ifstream df(data, std::ios::binary);
    df.imbue(LOCALE);
    while(getline(df,eile)){
        nr++;
        std::istringstream iss(eile);
        string a;
        while(iss >> a) {
            if (std::regex_match (a, std::regex(R"(^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?$)") )){
                url.insert(a);
            }
            else{
                std::regex rgx(R"(^[-ĄČĘĖĮŠŲŪ ąčęėįšųū \n"
                               "QWERTYUIOPASDFGHJKLZXCVBNM qwertyuiopasdfghjklzxcvbnm\n"
                               "1234567890\n "
                               "]+$)");
                for( std::sregex_iterator it(a.begin(), a.end(), rgx), it_end; it != it_end; ++it ){
                    words.insert(Word((*it)[0]));
                    text.insert(Word((*it)[0],nr));
                }
            }
        }
    }

    std::ofstream rf ("rez.txt");
    rf << "URL adresai, kurie yra tekste:" << endl;
    for(auto i : url) rf << i << endl;
    rf << endl;

    vector<int> m;
    vector<string> zdz;
    vector<vector<int> > eill;

    int y = 0;
    for(auto it = words.begin(); it != words.end(); ++it){
        auto n = 0;
        eil.clear();
        for(auto i = text.begin(); i != text.end(); ++i) {
            n = text.count(it->get_text());
            if(it->get_text() == i->get_text()){
                eil.push_back(i->get_eil());
            }
        }
        if(n >= 2 ){
            eill.push_back(eil);
            m.push_back(n);
            zdz.push_back(it->get_text());
            rf << it->get_text() << " tekste pasikartojo " << n << " kartus siose eilutese: ";
            for(auto i : eil){
                rf << i << " ";
            }
            rf << endl;
            y++;
        }
    }

    for(int h =2; h < 50; h++){
        for ( unsigned X = 0; X <= y/2; X++ ) {
            if(m[X]==h) {
                cout << zdz[X] << " pasikartojo " << m[X] << " kartus: ";
                int a = 99999;
                for (auto i: eill[X]){
                    if(i != a){
                        cout << i << " ";
                    }
                    a = i;
                }
                cout << "\t\t" << zdz[X + y / 2] << " pasikartojo " << m[X + y / 2] << " kartus: ";
                for (auto i: eill[X + y / 2]){
                    if(i != a){
                        cout << i << " ";
                    }
                    a = i;
                }
                cout << endl;
            }
        }
    }
    return 0;
}