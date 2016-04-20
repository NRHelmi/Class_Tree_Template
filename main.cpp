#include "arbre.h"
#include "arbre.cpp" // to avoid link problems
int main()
 {
    cout <<"***test sur des entiers\n";
 	arbre<int> p;
 	p.insert(5);
 	p.insert(8);
 	p.insert(3);
 	p.insert(1);
    p.view();
    p.supprimer(8);
    cout <<"Aprés suppression\n";
    p.view();
   cout <<"***test sur des caracteres\n";
    arbre<char> c;
    c.insert('r');
    c.insert('h');
    c.insert('n');
    c.insert('l');
    c.view();
    cout <<"Aprés suppression\n";
    c.supprimer('n');
    c.view();

 }
