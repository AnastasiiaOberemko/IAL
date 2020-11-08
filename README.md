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
