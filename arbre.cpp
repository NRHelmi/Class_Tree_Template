#include "arbre.h"

template <class T> noeud<T>::noeud() { droite=NULL;gauche=NULL; }
template <class T> noeud<T>::~noeud() { delete droite; delete gauche; }


template <class T> arbre<T>::arbre(){ racine=NULL; }

template <class T> void arbre<T>::insert(T d)
 {
  noeud<T> *temp, *courant, *pred;
  temp=new noeud<T>;
  temp->gauche=NULL;
  temp->droite=NULL;
  temp->data=d;

  if(!racine)
    racine=temp;
  else
    {
      courant=racine; pred=NULL;
      while(courant)
      {
        pred=courant;
        if(d>courant->data)
          courant=courant->droite;
        else
          courant=courant->gauche;
      }

    if (d>pred->data)
      pred->droite=temp;
    else
      pred->gauche=temp;
    }
 }

template <class T> noeud<T>* arbre<T>::search(T d)
 {
  noeud<T>* temp=racine;
  while(temp)
  {
    if(temp->data=d)
      return temp;
    if(d>temp->data)
      temp=temp->droite;
    else
      temp=temp->gauche;
  }
  return NULL;
 }

template <class T> void arbre<T>::print_nodes(noeud<T>* node)
 {
  if(node)
    if (node->gauche)
      print_nodes(node->gauche);
    cout << node->data<<"\n";
    if (node->droite)
      print_nodes(node->droite);
 }

 template <class T> void arbre<T>::view()
 {
  print_nodes(racine);
 }

template <class T> void arbre<T>::remove(noeud<T>**node,T data)
   {
      if(*node == NULL)
      {
        std::cerr << "ERROR: Node does not exist\n";
      }

      if(data == (*node)->data)
      {
        if((*node)->droite == NULL)
        {
          *node = (*node)->gauche;
        }
        else if((*node)->gauche == NULL)
        {
          *node = (*node)->droite;
        }
        else
        {
          noeud<T> **successor = getSuccessor(&(*node)->gauche);
          (*node)->data = (*successor)->data;
          remove(successor, (*successor)->data);
        }
      }
      else if(data < (*node)->data)
      {
        remove(&(*node)->gauche, data);
      }
      else
      {
        remove(&(*node)->droite, data);
      }
   }


 template <class T>  noeud<T>** getSuccessor(noeud<T> **node)
   {
     noeud<T> **tmp = node;
     while((*tmp)->droite != NULL)
       tmp = &(*tmp)->droite;
     return tmp;
   }


 template <class T> void arbre<T>::supprimer(T d)
 {
  remove(&racine,d);
 }


