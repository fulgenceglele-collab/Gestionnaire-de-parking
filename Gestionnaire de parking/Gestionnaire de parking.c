#include <stdio.h>

#define MAX_PLACES 5

int main(void) {
    int parking[MAX_PLACES] = {0};
    int choix = 0;

    while (choix != 4) {
        puts("\n=== GESTIONNAIRE DE PARKING ===");
        puts("1. Afficher l'etat du parking");
        puts("2. Garer un vehicule");
        puts("3. Liberer une place");
        puts("4. Quitter");
        fputs("Votre choix : ", stdout);

        if (scanf("%d", &choix) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            choix = 0;
        }

        switch (choix) {
            case 1: {
                puts("\nEtat du parking :");
                for (int i = 0; i < MAX_PLACES; i++) {
                    fputs("Place ", stdout);
                    putchar('1' + i);
                    fputs(" : ", stdout);
                    if (parking[i] == 0) {
                        puts("libre");
                    } else {
                        puts("occupee");
                    }
                }
                break;
            }
            case 2: {
                int place_trouvee = 0;
                for (int i = 0; i < MAX_PLACES; i++) {
                    if (parking[i] == 0) {
                        parking[i] = 1;
                        fputs("\nVehicule gare avec succes sur la place ", stdout);
                        putchar('1' + i);
                        puts(" !");
                        place_trouvee = 1;
                        break;
                    }
                }
                if (!place_trouvee) {
                    puts("\nDesole, le parking est complet !");
                }
                break;
            }
            case 3: {
                int num_place;
                fputs("\nEntrez le numero de la place a liberer (1 a ", stdout);
                putchar('0' + MAX_PLACES);
                fputs(") : ", stdout);

                if (scanf("%d", &num_place) != 1) {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                    puts("Numero de place invalide !");
                    break;
                }

                if (num_place >= 1 && num_place <= MAX_PLACES) {
                    if (parking[num_place - 1] == 1) {
                        parking[num_place - 1] = 0;
                        fputs("La place ", stdout);
                        putchar('0' + num_place);
                        puts(" est maintenant libre.");
                    } else {
                        puts("Cette place etait deja libre.");
                    }
                } else {
                    puts("Numero de place invalide !");
                }
                break;
            }
            case 4:
                puts("\nFermeture du gestionnaire de parking. Au revoir !");
                break;
            default:
                puts("\nChoix invalide, veuillez reessayer.");
        }
    }

    return 0;
}
