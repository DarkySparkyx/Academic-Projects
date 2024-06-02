#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>

//Dostepne opcje: -l szczegoly -R rekursywne -a Ukryte -t sortuj wedle czasu -r odwrocenie sortowania
#define MAX_PATH_LENGTH 1024

void print_file_info(const char *path, const char *name, int show_details) {
    struct stat file_stat;
    char full_path[MAX_PATH_LENGTH];
    snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, name); //Konstrukcja pelnej sciezki do pliku
    
    if (stat(full_path, &file_stat) == -1) //Obsluga bledow
    {
        perror("stat");
        return;
    }

    if (show_details) //Sprawdzenie flagi
    {
        //Wyswietlenie szczegolowych informacji o pliku
        printf((S_ISDIR(file_stat.st_mode)) ? "d" : "-");
        printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
        printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
        printf((file_stat.st_mode & S_IXUSR) ? "x" : "-"); //Uprawnienia dla wlasciciela
        printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
        printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
        printf((file_stat.st_mode & S_IXGRP) ? "x" : "-"); //Uprawnienia dla grupy
        printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
        printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
        printf((file_stat.st_mode & S_IXOTH) ? "x" : "-"); //Uprawnienia dla reszty
        printf(" %ld ", file_stat.st_nlink); //Wyswietlanie liczby dowiazan
        printf(" %ld ", file_stat.st_size); // Wyswietlanie rozmiaru w bajtach



        //Wyswietlanie czasu ostatniej modyfikacji
        char timebuf[80];
        struct tm *timeinfo;
        timeinfo = localtime(&file_stat.st_mtime);
        strftime(timebuf, sizeof(timebuf), "%b %d %H:%M", timeinfo);
        printf(" %s ", timebuf);
    }
    
    printf("%s\n", name);
}

void list_directory(const char *path, int show_details, int recurse, int include_hidden, int sort_time, int reverse_order) {
    struct dirent **namelist; //TABLICA ELEMENTOW TYPU DIRENT. DIRENT PRZECHOWUJE INFORMACJE O PLIKU
    int n;

    n = scandir(path, &namelist, NULL, alphasort); //scandir alokuje pamiec dla namelist, wpisuje do niej informacje o plikach w PATH, zwraca do n liczbe plikow.
    if (n == -1) {
        perror("scandir"); //Obsluga bledow
        return;
    }

    struct stat file_stat;
    char full_path[MAX_PATH_LENGTH];

    // Sort by time if needed
    if (sort_time) {
        struct dirent **temp_list = namelist; //Utworzenie tymczasowej listy plikow
        namelist = (struct dirent **)malloc(n * sizeof(struct dirent *)); //Alokacja pamieci zalezna od ilosci N plikow
        for (int i = 0; i < n; i++) //Petla iterujaca po wszystkich plikach 
        {
            int best_index = -1;
            time_t best_time = reverse_order ? LONG_MAX : LONG_MIN; //Przypisanie wartosci do best_time zalezene od tego w jaki sposob mamy sortowac
            for (int j = 0; j < n; j++) { //Petla w petli, ktora iteruje po wszystkich plikach i szuka najstarszego lub najmlodszego pliku
                if (!temp_list[j]) continue; //Pominiecie wartosci NULL
                snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, temp_list[j]->d_name); //Utworzenie pelnej sciezki do pliku
                stat(full_path, &file_stat); //Pobranie informacji o pliku
                if ((reverse_order && file_stat.st_mtime < best_time) || (!reverse_order && file_stat.st_mtime > best_time)) {
                    best_time = file_stat.st_mtime; //Wybor najstarszego lub najmlodszego pliku z pozostalych
                    best_index = j;
                }
            }
            namelist[i] = temp_list[best_index]; //Dopis do tablicy wyjsciowej
            temp_list[best_index] = NULL; //Ustawienie wybranej juz wartosci na NULL w celu pozniejszego jej pominiecia
        }
        free(temp_list); //Zwolnienie pamieci
    }

    for (int i = 0; i < n; i++) {
        if (!include_hidden && namelist[i]->d_name[0] == '.') //Jesli NIE mamy zalaczac ukrytych plikow a plik JEST ukryty (nazwa zaczyna sie od kropki) to kasujemy informacje o nim
        {
            free(namelist[i]);
            continue;
        }

        print_file_info(path, namelist[i]->d_name, show_details); // W przeciwnym wypadku wyswietlamy informacje o nim i zwalniamy pamiec.
        free(namelist[i]);
    }
    free(namelist);

    if (recurse) //Hesli mamy wyswietlic zawartosc podkatalagow to wykonujemy ponizszy kod.
    {
        n = scandir(path, &namelist, NULL, alphasort); //Ponownie skanujemy zawwartosc folderu
        for (int i = 0; i < n; i++) //Petla iterujaca po plikach 
        {
            if (namelist[i]->d_name[0] == '.') //Pomijamy ukryte pliki
            {
                free(namelist[i]);
                continue;
            }
            snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, namelist[i]->d_name); //Konstruujemy pelna nazwe pliku
            if (stat(full_path, &file_stat) == -1) //Obsluga bledow
            { 
                perror("stat");
                free(namelist[i]);
                continue;
            }
            if (S_ISDIR(file_stat.st_mode)) //Jesli plik jest katalogiem to wywolujemy ponownie obecna funkcje
            {
                printf("\n%s:\n", full_path);
                list_directory(full_path, show_details, recurse, include_hidden, sort_time, reverse_order);
            }
            free(namelist[i]);
        }
        free(namelist);
    }
}

int main(int argc, char *argv[]) {
    int show_details = 0, recurse = 0, include_hidden = 0, sort_time = 0, reverse_order = 0;
    char *path = ".";

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            for (int j = 1; argv[i][j] != '\0'; j++) {
                switch (argv[i][j]) {
                    case 'l': show_details = 1; break;
                    case 'R': recurse = 1; break;
                    case 'a': include_hidden = 1; break;
                    case 't': sort_time = 1; break;
                    case 'r': reverse_order = 1; break;
                    default: 
                        fprintf(stderr, "Unknown option: %c\n", argv[i][j]);
                        exit(EXIT_FAILURE);
                }
            }
        } else {
            path = argv[i];
        }
    }

    list_directory(path, show_details, recurse, include_hidden, sort_time, reverse_order);
    return 0;
}
