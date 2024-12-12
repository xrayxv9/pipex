# pipex

## useful commands

ps -e : see all the process in usage at the moment 

pidof <name> : see all the Id of the nominated process



## C commands

fork : resons to crash:
    - CHILD_MAX opened : 8192 sub process
    - The system doesn't have enough ressources
===========================================================================================================
 /$$$$$$$\ /$$$$$\ /$$$$$$$\ /$$$$$$$$| /$$$$$$\ 
| $$__  $$|_  $$_/| $$__  $$| $$_____/ /$$__  $$|
| $$  \ $$  | $$  | $$  \ $$| $$      | $$  \__/
| $$$$$$$/  | $$  | $$$$$$$/| $$$$$   |  $$$$$$ 
| $$____/   | $$  | $$____/ | $$__/    \____  $$
| $$        | $$  | $$      | $$       /$$  \ $$
| $$       /$$$$$$| $$      | $$$$$$$$|  $$$$$$/
|__/      |______/|__/      |________/ \______/ 
===========================================================================================================
Pipes.

les pipes servent a connecter des fichiers entre eux

les pipes sont dans la librairie 
#include <unistd.h>

Les pipes servent a transmettre des infos a ecrire ou lire ? 
d'un process a un autre.
De plus, une pipe est unidirectionnel
signifiant que je ne peut pas aller dans les deux sens

pour clarifier aller voir :
	man pipe

pour un petit code de test :
	https://people.cs.rutgers.edu/~pxk/416/notes/c-tutorials/pipe.html

===========================================================================================================
  /$$$$$$  /$$   /$$  /$$$$$$   /$$$$$$$ /$$    /$$ /$$$$$$       
 /$$__  $$|  $$ /$$/ /$$__  $$ /$$_____/|  $$  /$$//$$__  $$      
| $$$$$$$$ \  $$$$/ | $$$$$$$$| $$       \  $$/$$/| $$$$$$$$      
| $$_____/  >$$  $$ | $$_____/| $$        \  $$$/ | $$_____/      
|  $$$$$$$ /$$/\  $$|  $$$$$$$|  $$$$$$$   \  $/  |  $$$$$$$      
 \_______/|__/  \__/ \_______/ \_______/    \_/    \_______/      
===========================================================================================================
execve.

#include <unistd.h>
execute le programme demande au chemin 
Lorsque la commande s'exec, l'environnement se reset
donc la heap, la stack et tout le patatra
j'en deduis donc qu'il vaut mieux potentiollement faire une fork juste avant de faire la commande
cette fonction a besoin du chemin de destination de la commande qu'il souhaite exec

man :
	man execve

===========================================================================================================
                         /$$   /$$               /$$       /$$
                        |__/  | $$              |__/      | $$
 /$$  /$$  /$$  /$$$$$$  /$$ /$$$$$$    /$$$$$$  /$$  /$$$$$$$
| $$ | $$ | $$ |____  $$| $$|_  $$_/   /$$__  $$| $$ /$$__  $$
| $$ | $$ | $$  /$$$$$$$| $$  | $$    | $$  \ $$| $$| $$  | $$
| $$ | $$ | $$ /$$__  $$| $$  | $$ /$$| $$  | $$| $$| $$  | $$
|  $$$$$/$$$$/|  $$$$$$$| $$  |  $$$$/| $$$$$$$/| $$|  $$$$$$$
 \_____/\___/  \_______/|__/   \___/  | $$____/ |__/ \_______/
                                      | $$                    
                                      | $$                    
                                      |__/                    
===========================================================================================================
waitpid

#include <sys/wait.h>

waitpid est utilise pour attendre le changement d'etat d'un child process un child process
si aucun wait n'est fais, le process deviens un process "zombie"


man :
	man waitpid



===========================================================================================================
                     /$$ /$$           /$$      
                    | $$|__/          | $$      
 /$$   /$$ /$$$$$$$ | $$ /$$ /$$$$$$$ | $$   /$$
| $$  | $$| $$__  $$| $$| $$| $$__  $$| $$  /$$/
| $$  | $$| $$  \ $$| $$| $$| $$  \ $$| $$$$$$/ 
| $$  | $$| $$  | $$| $$| $$| $$  | $$| $$_  $$ 
|  $$$$$$/| $$  | $$| $$| $$| $$  | $$| $$ \  $$
 \______/ |__/  |__/|__/|__/|__/  |__/|__/  \__/
===========================================================================================================
unlink.

#include <unistd.h>

commande pour fermer une pipe

man : 
	man 2 unlink



===========
a voir
tenter de faire une cvommande mais seulement dans une fork
de la sorte je verrais si je garde mes valeurs de variables.
bpn courrage ensuite juste voir pour faire ecrire l'output d'une commande dans un file
voir quel et le nom suppose du file, si il dois ou non deja existe
sinon je dois le creer moi meme


NOTE DE FIN DE PAGE:

il n'y a pas plusieurs process qui peuvent etre fais en meme temps
cette impression est seulement du au myltitasking operating system,
en gros c'est lui qui gere qui passe en premier dans les process.



zombie process :
	un process qui est fini mais qui a toujours une place dans la process table

env :
	env est la commande permettant de voir tout les PATH des variables d'environnement
