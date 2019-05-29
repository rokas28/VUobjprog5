# VU objektinio programavimo penkta užduotis  

Šioje užduotyje yra pasitelkiamas std::string konteinerio, o taip pat ir asociatyvių konteinerių naudojimas.  
Užduoties reikalavimus galite pamatyti [čia](https://github.com/objprog/paskaitos2019/wiki/5-oji-u%C5%BEduotis).  
Norint paleisti programą, jums reikia parsisiųsti norimą versiją ir paleisti `CMakeLists.txt` programos paleidimo failą.  
Užduotis yra atlikta naudojant `std::set` ir `std::multiset` tipo asociatyviuosius koteinerius.  
Programą sudaro `main.cpp`, `main.h` ir `word.h`, kuriame yra aprašyta `Word` klasė, turinti žodžio ir jo eilutės parametrus.

### Programov veikimas  

Programa suskaičiuoja daugiau nei du kartus tekste pasikartojančius žodžius ir išveda jų kiekį ir kokiose eilutėse jie buvo paminėti.
Taip pat programa parodo visus `URL` adresus, kurie buvo įrašyti tekste.  
- Pavyzdinis tekstas:
```
Mr. and Mrs. Dursley, of number four, Privet Drive, were proud to 
say thatthey were perfectly normal, thank you very much. https://www.vu.lt/
They were the last people you would expect to be involved in anything 
strange or mysterious, because they just did not hold with such nonsense.
Mr. Dursley was the director of a firm called Grunnings, which made
drills. He was a big, beefy man with hardly any neck, although he did
have a very large mustache. Mrs. Dursley was thin and blonde and had
nearly twice the usual amount of neck, which came in very useful as she
spent so much of her time craning over garden fences, spying on the
neighbors. The Dursleys had a small son called Dudley and in their
opinion there was no finer boy anywhere. www.delfi.lt
```
- Gautas rezultatas:
```
URL adresai, kurie yra tekste:
https://www.vu.lt/
www.delfi.lt

Dursley tekste pasikartojo 3 kartus siose eilutese: 1 5 7
Mr tekste pasikartojo 2 kartus siose eilutese: 1 5
Mrs tekste pasikartojo 2 kartus siose eilutese: 1 7
a tekste pasikartojo 4 kartus siose eilutese: 5 6 7 10
and tekste pasikartojo 4 kartus siose eilutese: 1 7 7 10
called tekste pasikartojo 2 kartus siose eilutese: 5 10
did tekste pasikartojo 2 kartus siose eilutese: 4 6
had tekste pasikartojo 2 kartus siose eilutese: 7 10
in tekste pasikartojo 3 kartus siose eilutese: 3 8 10
much tekste pasikartojo 2 kartus siose eilutese: 2 9
neck tekste pasikartojo 2 kartus siose eilutese: 6 8
of tekste pasikartojo 4 kartus siose eilutese: 1 5 8 9
the tekste pasikartojo 4 kartus siose eilutese: 3 5 8 9
to tekste pasikartojo 2 kartus siose eilutese: 1 3
very tekste pasikartojo 3 kartus siose eilutese: 2 7 8
was tekste pasikartojo 4 kartus siose eilutese: 5 6 7 11
were tekste pasikartojo 3 kartus siose eilutese: 1 2 3
which tekste pasikartojo 2 kartus siose eilutese: 5 8
with tekste pasikartojo 2 kartus siose eilutese: 4 6
you tekste pasikartojo 2 kartus siose eilutese: 2 3
```