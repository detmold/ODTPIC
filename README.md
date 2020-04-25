# odds

Odds - https://www.codechef.com/problems/ODTPIC

## Problem

Na wejściu dostajemy: 
- liczbę testów q,n,m i dla każdego testu mamy 
- dla każdego n dostajemy zbiór n liczb, tak samo dla każdego mamy
- dla każdego q dostajemy wartości brzegowe określające offsety lewy, prawy odpowiednio: L1, R1, L2, R2
- Dla każdego q mamy obliczyć ilość liczb nieparzystych po złączeniu dwóch zbiorów n i mamy

Przykład: dla q = 1 , n = 7, m = 6, L1 = 1, R1 = 5, L2 = 2, R2 = 5 mamy 
a = { 3,3,2,4,3,1,3 }
b = { 7,3,5,2,2,4 }
z pierwszego zbioru z przedziału <L1=1,R1=5> nieparzystą ilość razy występują cyfry: {3,2,4}
z drugiego zbioru z przedziału <L2=2,R2=5> nieparzystą ilość razy występują cyfry: {3,5}
Czyli po złączeniu dwóch zbiorów {3,2,4} ^ {3,5} mamy {2,4,5} (3 wystepowało po zlaczeniu parzysta ilość razy)




## Algorytm

0. Zainicjalizować dwie tablice **a** i **b** 10^5 przechowujące bitset<4000> 10^5 - to pojemność zbiorów a, b, 4000 - ilość znaków jakimi mogą być a[i] i b[j]   
1. Robimy iteracje po tablicy **a**, w każdym obrocie pobieramy zmienna **rand_a** do **a[i]** przypisujemy jej wartość zmiennej z poprzedniej iteracji **a[i-1]** i jeśli bit a[i-1].test(rand_a) jest ustawiony to go zerujemy w innym przypadku ustawiamy
2. Po zrobieniu obydwu iteracji na tablcach a i b. W tablicach z bitsetami mamy 0 - parzystość/lub znak nie występuje lub 1- nieparzystość występowania każdego znaku na każdej pozycji
3. Robimy iteracje dla każdego **q**, pobieramy zmienne L1,R1,L2,R2, obliczamy ilosc znakow nieparzystych jako XOR dla pozycji ans1 |= a[L1-1] ^ a[R1] oraz ans2 |= b[L2-1] ^ b[R2]. Nie mozna zrobic prostego przypisania, bo chcemy tu miec nie wartość operacji XOR ale bitset jaki powstal po tej operacji.
```cpp
ans1 |= (a[ rand_edges[0]-1 ] ^ a[ rand_edges[1] ]);
ans2 |= (b[ rand_edges[2]-1 ] ^ b[ rand_edges[3] ]);
ans |= (ans1^ans2);
cout << ans.count() << endl;

```
4. Zeby obliczyc ostateczny wynik robimy ans |= (ans1 ^ ans2) i nastepnie obliczamy ilość 1 w tym bitsecie jako ans.count() co jest ostatecznym wynikiem.
5. Złożoność obliczeniowa algorytmu: **O(N+M+Q)**
 

