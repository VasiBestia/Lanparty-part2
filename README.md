Proiectarea algoritmilor Tema
# Grafuri și clasamente

## 1. Descrierea problemei

În cazul unui singur turneu, cum e cel pe care l-am simulat în Tema 1, realizarea clasamentului participanților nu pune probleme: locul întâi este ocupat de câștigătorul finalei, pe ultimul loc se clasează jucătorul/echipa care nu a câștigat niciun meci etc.

Însă atunci când se iau în considerare rezultatele în mai multe competiții, lucrurile se complică: doi jucători pot avea același număr de victorii, însă dacă unul din ei a avut o victorie împotriva unui campion mondial, această victorie ar trebui să conteze mai mult. Din acest motiv, în ultima vreme, atunci când se doresc realizarea clasamentelor (pentru sportivi, spre exemplu), se folosesc metode care analizează proprietățile rețelei [2, 3, 4], pentru a putea distinge între astfel de situații.

### 1.1 Modelarea victoriilor utilizând grafuri

Rețeaua sportivilor este un graf orientat în care fiecare vârf reprezintă un sportiv, iar între doi sportivi i și j există muchie de la i către j dacă cei doi au disputat un meci, iar j a câștigat. În cazul în care cei doi joacă mai multe meciuri, reprezentarea poate fi de multigraf (câte o muchie pentru fiecare meci) sau se pot agrega rezultatele tuturor meciurile disputate de cei doi. De asemenea, graful poate fi ponderat, unde ponderea muchiei reprezintă numărul de victorii ale sportivului j în meciurile cu i.

Figura 1.1, reprodusă aici din lucrarea [5], prezintă în panoul A graful jucătorilor de tenis care au fost clasati numărul 1 în ATP. Nuanța de gri a muchiilor codifică ponderea acestora. Arborele din panoul B corespunde unui singur campionat, cum este cel pe care l-am simulat în Tema 1, și este, practic, un subgraf al grafului mare. Panoul C reprezintă graful asociat acestui campionat.

### 1.2 Calculul clasamentului

În general, metodele bazate pe grafuri pentru calculul clasamentelor utilizează anumite proprietăți ale structurii grafului pentru a determina importanța unui jucător. Metoda pe care o veți implementa se aseamănă cu algoritmul PageRank [1], creat de Google pentru a clasa site-urile web.

Implementarea PageRank utilizează noțiuni pe care le veți învăța abia în Anul II (vectorii proprii ai grafului), însă principiul îl putem descrie pe scurt acum. PageRank se bazează pe conceptul de centralitate, care este o măsură a influenței unui nod dintr-o rețea. Un anumit nod va fi important dacă are multe legături către noduri cu scor mare (adică importante la rândul lor). Concret, legăturile pe care un nod le are cu noduri cu scor mare contribuie mai mult la scorul respectivului nod decât legăturile cu noduri cu scoruri mici.

Această idee este utilizată și în [5] pentru a clasa jucătorii de tenis, metodă pe care o veți implementa și voi. Calculul clasamentului pentru întreg graful presupune rezolvarea unui sistem de ecuații pentru care nu se cunoaște o soluție analitică, dar care poate fi calculată prin metode iterative (mai multe despre subiectul acesta în anul II).

## 2. Cerințe

1. Creati graful turneului (va semăna cu cel din Figura 1.1, panoul C).
2. Calculați prestigiul fiecărei echipe, ca urmare a participării la turneu, utilizând formula din (1), cu q = 0.15. Scrieți într-un fișier prestigiul echipei, pe 4 zecimale, urmat de spațiu și numele echipei.

Bibliografie:

[1] Sergey Brin and Lawrence Page. The anatomy of a large-scale hypertextual web search engine. Computer Networks and ISDN Systems, Proceedings of the Seventh International World Wide Web Conference, 30(1):107–117, 1998. [Link](https://snap.stanford.edu/class/cs224w-readings/Brin98Anatomy.pdf).

[2] Henry E Daniels. Round-robin tournament scores. Biometrika, 56(2):295–299, 1969.

[3] J. W. Moon and N. J. Pullman. On generalized tournament matrices. SIAM Review, 12(3):384–399, 1970.

[4] Shun Motegi and Naoki Masuda. A network-based dynamical ranking system for competitive sports. Scientific Reports, 2(1):2045–2322, 2012.

[5] Filippo Radicchi. Who is the best player ever? a complex network analysis of the history of professional tennis. PloS one, 6(2):e17249, 2011. [Link](https://journals.plos.org/plosone/article?id=10.1371/journal.pone.0017249).
