Comment implementer ses classes graphics:

- Creer le .hpp
- Faire hériter la class arcd::LibraryModule à votre classe
- Ajouter les methodes en prototypes
- Creer dans le dossier /src/lib le dossier de la classe graphic (example: sfml, ncurses)
- Creer le makefile compilant la shared lib et la mv dans le dossier soit games/ pour les shared lib game, soit lib/ pour les shared lib graphic
- Creer le .cpp
- Implementer les methodes de la class
- Ajouter 2 fonction extern "C":    entryPoint retournant un pointeur sur votre classe
                                    destroy_object prenant en paramètre un object de votre classe, et le delete

Comment tester ses classes:
- aller dans arcade.cpp
- completer la methode loopFunctions associé à votre type de lib (example: si ILibraryModule-> loopFunctions<Arcade::Graphic>)
- VOUS ÊTES SENSÉ MODIFIER LA LOOPFUNCTION JUSTE UNE FOIS, APRES C'EST SENSÉ MARCHER POUR TOUTES LES LIBS GRAPHICS