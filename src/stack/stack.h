//  stack.h : partie interface d'un module polymorphe pour la spécification PILE
//    du TDA Pile(T).

#ifndef STACK__H
#define STACK__H

//  Fonctionnement général :
//  - la structure de données ne stocke pas d'objets mais des références vers
//      ces objets. Les références sont du type générique « void * » ;
//  - si des opérations d'allocation dynamique sont effectuées, elles le sont
//      pour la gestion propre de la structure de données, et en aucun cas pour
//      réaliser des copies ou des destructions d'objets ;
//  - les fonctions qui possèdent un paramètre de type « stack * » ou
//      « stack ** » ont un comportement indéterminé lorsque ce paramètre ou sa
//      déréférence n'est pas l'adresse d'un contrôleur préalablement renvoyée
//      avec succès par la fonction stack_empty et non révoquée depuis par la
//      fonction stack_dispose ;
//  - aucune fonction ne peut ajouter NULL à la structure de données ;
//  - les fonctions de type de retour « void * » renvoient NULL en cas d'échec.
//      En cas de succès, elles renvoient une référence actuellement ou
//      auparavant stockée par la structure de données ;
//  - l'implantation des fonctions dont la spécification ne précise pas qu'elles
//      doivent gérer les cas de dépassement de capacité ne doivent avoir
//      affaire avec aucun problème de la sorte.

#include <stdlib.h>
#include <stdbool.h>

//- STANDARD -------------------------------------------------------------------

//  struct stack, stack : type et nom de type d'un contrôleur regroupant les
//    informations nécessaires pour gérer une pile sur des objets quelconques.
typedef struct stack stack;

//  stack_empty : tente d'allouer les ressources nécessaires pour gérer une
//    nouvelle pile initialement vide. Renvoie NULL en cas de dépassement de
//    capacité. Renvoie sinon un pointeur vers le contrôleur associé à la pile.
extern stack *stack_empty(void);

//  stack_dispose : sans effet si *sptr vaut NULL. Libère sinon les ressources
//    allouées à la gestion de la pile associée à *sptr puis affecte NULL à
//    *sptr.
extern void stack_dispose(stack **sptr);

//  stack_push : renvoie NULL si ref vaut NULL. Tente sinon d'empiler ref sur la
//    pile associée à s ; renvoie NULL en cas de dépassement de capacité ;
//    renvoie sinon ref.
extern void *stack_push(stack *s, const void *ref);

//  stack_pop : renvoie NULL si la pile associée à s est vide. Dépile sinon la
//    pile et renvoie la référence qui était au sommet de la pile avant le
//    dépilement.
extern void *stack_pop(stack *s);

//  stack_pop : renvoie NULL si la pile associée à s est vide. Dépile sinon la
//    pile et renvoie la référence qui était au sommet de la pile avant le
//    dépilement.
extern void *stack_pop(stack *s);

//  stack_top : renvoie NULL si la pile associée à s est vide. Renvoie sinon
//    la référence qui est au sommet de la pile.
extern void *stack_top(stack *s);

//  stack_nth : renvoie NULL si la pile associée à s est vide ou si n est
//    supérieur a la hauteur de pile. Renvoie sinon la n-ème référence de la
//    pile.
extern void *stack_nth(stack *s, size_t n);

//  stack_is_empty : renvoie true ou false selon que la pile associée à s est
//    vide ou non.
extern bool stack_is_empty(stack *s);

//  stack_height : renvoie la hauteur de la pile associée à s.
extern size_t stack_height(stack *s);

#endif
