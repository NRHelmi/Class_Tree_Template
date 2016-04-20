#ifndef ARBRE_H
#define ARBRE_H

#include <stdio.h>
#include <iostream>
 using namespace std;

 template <class T> class noeud
 {
 public:
 	T data;
 	noeud *droite,*gauche;
    noeud();
    ~noeud();
 };

 template <class T> class arbre
 {
 private:
 	noeud<T> *racine;
 public:
 	arbre();
 	void insert(T);
 	noeud<T>* search(T);
 	void print_nodes(noeud<T>*);
 	void view();
 	void remove(noeud<T> **,T);
 	void supprimer(T);
 };
 
 #endif