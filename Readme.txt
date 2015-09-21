Auteur : Honoré NINTUNZE

La commande 'make display_stack' compile et lance le code de display_stack.c.

Pour display_satck.c, 
on constate que à chaque appel imbriqué de fonction le contexte de la
fonction appelée est empilé sur la pile 'en dessous' du contexte de la fonction appelante.
'En dessous' parce que la base de la pile possède la plus grande adresse et le sommet de pile
se trouve donc en dessous.

On constate que pour plusieurs appels à la même fonction dans une boucle for par exemple,
on execute la fonction puis le pointeur revient en arrière au début du contexte de la fonction.