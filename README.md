# IAL
Hledání minimální kostry grafu pomoci Kusákova algoritmu

## Načítání grafu ze souboru

Načítání grafu ze souboru je zajištěno pomocí `readMatrix()` funkce.
Graf je reprezentován maticí, přesněji maticí sousednosti (adjacency matrix).
Taková se nacházejí i ve vstupních soborech, na jejichž jméno se funkce `readMatrix()` doptá uživatele.
Jméno vstupního souboru se zadává i s koncovkou (např. example01.csv) a musí již existovat v adresáři `input/`.
Jednotlivé hodnoty jsou typu Integer.

V adresáři `input/` již existují předpřipravené příklady vstupních souborů a je možno je ihned použít.
Pro podrobnější informace navštivte [input dokumentaci](input/readme.md).

Výsledkem `readMatrix()` funkce je tedy naplnění globálního drourozměrného pole `Graph`, typu Integer, reprezentující 
graf, zrovna načtený v paměti programu. Dále přiřadí počet vrcholu v načteném grafu do globální proměnné `pocet`.
Jelikož je 2D pole `Graph`velikosti podle `MAX` je tedy velikosti `MAX*MAX`. To je obvykle větší matice, než načtená matice,
a tedy funkce `readMatrix()` naplní 2D pole `Graph` pouze z části. Konkrétně sub-matici velikosti `pocet*pocet`, kde  `pocet`
je globální proměná, určující počet vrcholů v grafu. Je automaticky přiřazena funkcí `readMatrix()`, při načítání grafu.
Pokud by vstupní matice byla 3x3 plná jedniček, pak by 2D pole `Graph` po jejim načtení vypadalo následovně.
```
1,1,1,0,0,0,...
1,1,1,0,0,0,...
1,1,1,0,0,0,...
0,0,0,0,...
. . .
. . .
. . .
```
Pokud předem bylo 2D pole `Graph` plné `0`.
