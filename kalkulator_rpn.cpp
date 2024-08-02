#include "kalkulator_rpn.h"
#include <cstdio>
#include <cstdlib>

/**********************************************************************************************
* Autor: Kacper Wiącek                                                                        *
* Data utworzenia pliku kalkulator_rpn.c : 19.01.2021r.                                       *
* Data ukończenia pliku : 21.01.2021r.                                                        *
* Wersja ostateczna,                                                                          *
* Modyfikacje: 1.Przygotowanie -> 19.01.2021r. około 17:00                                    *
*             2.Praca nad funckjami kalkulatora -> 20.01.2021r. około 23:00                   *
*             3.Poprawki,ulepszenia -> 21.01.2021r. około 20                                  *
***********************************************************************************************/

/**********************************************************************************************
* Funkcja init iniciuje pusty stos -> ustawia wskaznik na NULL                                *
* \param[in] wsk_stos -> wskaznik na wskaznik, który wskazuje na stos                         *
* \param[out] brak -> funckja void nic nie zwraca                                             *
***********************************************************************************************/

void init(t_stos **wsk_stos){
    *wsk_stos=nullptr;
}

/**********************************************************************************************
* Funkcja push dodaje liczby na szczyt stosu                                                  *
* \param[in] wsk_stos -> wskaznik na wskaznik, który wskazuje na początek stosu               *
* \param[in] liczba -> liczba, którą mamy zamiar dodać do stosu                               *
* \param[out] brak -> funckja void nic nie zwraca                                             *
***********************************************************************************************/

void push(t_stos **wsk_stos, int liczba){
    if(*wsk_stos==nullptr){
        *wsk_stos= static_cast<t_stos *>(malloc(sizeof(t_stos)));
        if(*wsk_stos==nullptr){
            fprintf(stderr,"Blad przydziału pamięci!!\n");
            free(*wsk_stos);
        } else {
        (*wsk_stos)->dane=liczba;
        (*wsk_stos)->nastepny=nullptr;
        }
    }else {
        t_stos *pom = static_cast<t_stos *>(malloc(sizeof(t_stos)));
        if(pom==nullptr){
            fprintf(stderr,"Błąd przydziału pamięci\n");
            free(pom);
        }else{
        pom->dane=liczba;
        pom->nastepny=*wsk_stos;
        *wsk_stos=pom;
        }
    }
}

/**********************************************************************************************
* Funkcja pop usuwa liczbę ze szczytu stosu                                                   *
* \param[in] wsk_stos -> wskaznik na wskaznik, który wskazuje na początek stosu               *
* \param[out] brak -> funckja void nic nie zwraca                                             *
**********************************************************************************************/

void pop(t_stos **wsk_stos){
    if(*wsk_stos!=nullptr){
        t_stos *pom = (*wsk_stos)->nastepny;
        free(*wsk_stos);
        *wsk_stos=pom;
    }else{
        fprintf(stderr,"Stos jest pusty!\n ");
    }
}

/**********************************************************************************************
* Funkcja print wydruk liczby ze szczytu stosu                                                *
* \param[in] wsk_stos ->  wskaznik, który wskazuje na początek stosu                          *
* \param[out] brak -> funckja void nic nie zwraca                                             *
***********************************************************************************************/

void print(const t_stos *wsk_stos){
    if(wsk_stos==nullptr) fprintf(stderr,"Stos jest pusty!!\n");
    else printf("%d\n", wsk_stos->dane);
}

/**********************************************************************************************
* Funkcja full_print wydruk wszystkich liczb ze stosu                                         *
* \param[in] wsk_stos ->  wskaznik, który wskazuje na początek stosu                          *
* \param[out] brak -> funckja void nic nie zwraca                                             *
***********************************************************************************************/

void full_print(t_stos *wsk_stos){
    if(wsk_stos==nullptr) fprintf(stderr,"Stos jest pusty!!\n");
    else {
        t_stos *pom = wsk_stos;
        do{
            printf("%d", pom->dane);
            printf("\n");
            pom=pom->nastepny;
        }while(pom != nullptr);
    }
}

/**********************************************************************************************
* Funkcja clear czyści wszytskie liczby ze stosu                                              *
* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu              *
* \param[out] brak -> funckja void nic nie zwraca                                             *
***********************************************************************************************/

void clear(t_stos **wsk_stos){
    if(*wsk_stos==nullptr) fprintf(stderr,"Stos jest pusty!\n");
    else {
        int liczba_elementow = size(*wsk_stos);
        while(liczba_elementow>0){
            pop(wsk_stos);
            liczba_elementow--;
        }
    }
}

/**********************************************************************************************
* Funkcja riverse zamienia miejscami dwie pierwsze liczby ze stosu                            *
* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu              *
* \param[out] brak -> funckja void nic nie zwraca                                             *
***********************************************************************************************/

void reverse(t_stos **wsk_stos){
    if(*wsk_stos==nullptr) fprintf(stderr,"Stos jest pusty\n");
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n");
    else {
        t_stos *pom= (*wsk_stos)->nastepny;
        int liczba1 = (*wsk_stos)->dane;
        int liczba2= pom->dane;
        pop(wsk_stos);
        pop(wsk_stos);
        push(wsk_stos,liczba1);
        push(wsk_stos,liczba2);}
}

/**********************************************************************************************
* Funkcja duplication robi duplikat liczby ze szczytu stosu i dodaje na sam szczyt            *
* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu              *
* \param[out] brak -> funckja void nic nie zwraca                                             *
***********************************************************************************************/

void duplication(t_stos **wsk_stos){
    if(*wsk_stos==nullptr) fprintf(stderr,"Stos jest pusty!\n");
    else {
        int duplikat = (*wsk_stos)->dane;
        push(wsk_stos,duplikat);
    }
}

/**********************************************************************************************
* Funkcja addition dodaje dwa ostatnio dodane elementy do stosu, i zamiast nich zwraca        *
* wynik dodawania na sam szczyt                                                               *
* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu              *
* \param[out] brak -> funckja void nic nie zwraca                                             *
***********************************************************************************************/

void addition(t_stos **wsk_stos){
    if(*wsk_stos==nullptr) fprintf(stderr,"Nie wprowadzono żadnych liczb całkowitych!\n");
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n");
    else {
        t_stos *pom = (*wsk_stos)->nastepny;
        int liczba1 = (*wsk_stos)->dane;
        int liczba2= pom->dane;
        pop(wsk_stos);
        pop(wsk_stos);
        push(wsk_stos,liczba1+liczba2);
    }
}

/**********************************************************************************************
* Funkcja subtraction odejmuje dwa ostatnio dodane elementy do stosu(drugi od pierwszego)     *
* i zamiast nich zwraca wynik różnicy na sam szczyt                                           *
* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu              *
* \param[out] brak -> funckja void nic nie zwraca                                             *
***********************************************************************************************/

void subtraction(t_stos **wsk_stos){
    if(*wsk_stos==nullptr) fprintf(stderr,"Nie wprowadzono żadnych liczb całkowitych!\n");
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n");
    else {
        t_stos *pom = (*wsk_stos)->nastepny;
        int liczba1 = (*wsk_stos)->dane;
        int liczba2= pom->dane;
        pop(wsk_stos);
        pop(wsk_stos);
        push(wsk_stos,liczba2-liczba1);
    }
}

/**********************************************************************************************
* Funkcja multiplication mnoży dwa ostatnio dodane elementy do stosu i zamiast nich           *
* zwraca wynik iloczynu na sam szczyt                                                         *
* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu              *
* \param[out] brak -> funckja void nic nie zwraca                                             *
***********************************************************************************************/

void multiplication(t_stos **wsk_stos){
    if(*wsk_stos==nullptr) fprintf(stderr,"Nie wprowadzono żadnych liczb całkowitych!\n");
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n");
    else {
        t_stos *pom = (*wsk_stos)->nastepny;
        int liczba1 = (*wsk_stos)->dane;
        int liczba2= pom->dane;
        pop(wsk_stos);
        pop(wsk_stos);
        push(wsk_stos,liczba1*liczba2);
    }
}

/**********************************************************************************************
* Funkcja division dzieli dwa ostatnio dodane elementy(drugi przez pierwszy) do stosu         *
* i zamiast nich zwraca wynik ilorazu na sam szczyt                                           *
* \param[in] wsk_stos ->  wskaznik na wskaznik, który wskazuje na początek stosu              *
* \param[out] brak -> funckja void nic nie zwraca                                             *
***********************************************************************************************/

void division(t_stos **wsk_stos){
    if(*wsk_stos==nullptr) fprintf(stderr,"Nie wprowadzono żadnych liczb całkowitych!\n");
    else if(size(*wsk_stos)<2) fprintf(stderr,"Na stosie jest mniej niż dwie liczby!\n");
    else {
        t_stos *pom = (*wsk_stos)->nastepny;
        int liczba1 = (*wsk_stos)->dane;
        int liczba2= pom->dane;
        if(liczba1==0) fprintf(stderr,"Nie dzielimy przez zero!\n");
        else {
        pop(wsk_stos);
        pop(wsk_stos);
        push(wsk_stos,liczba2/liczba1);}
    }
}

/**********************************************************************************************
* Funkcja size pomocnicza funckja do zliczania ilości liczb w stosie                          *
* \param[in] wsk_stos -> wskaznik, który wskazuje na początek stosu                           *
* \param[out] licznik -> funckja int zwraca liczbę całkowitą -> ilość elementów w stosie      *
***********************************************************************************************/

int size(t_stos *wsk_stos){
    int licznik=0;
    t_stos *pom = wsk_stos;
    while(pom!=nullptr){
        licznik++;
        pom=pom->nastepny;
    }
    return licznik;
}

/*******************************************************************************************************
* Funkcja wykonaj_program wykonuje cały program -> wczytuje dane z stdin oraz wywoływuje inne funkcje  *
* \param[in] wsk_stos -> wskaznik, który wskazuje na początek stosu                                    *
********************************************************************************************************/

void wykonaj_program(t_stos *stos){
    char znak,znak2;
    int liczba;

    init(&stos);

    do{
        znak=getc(stdin);
        if((znak!=' ')&&(znak!='\t')&&(znak!='\n')){
            switch(znak){
                case '+': {
                    addition(&stos);
                    break;
                }
                case '-': {
                    znak=getc(stdin);
                    if((znak<48)||(znak>57)) {
                        ungetc(znak,stdin);
                        subtraction(&stos);
                    }
                    else {
                        ungetc(znak,stdin);
                        scanf("%d",&liczba);
                        znak=getc(stdin);
                            switch(znak) {
                                case '.': {
                                    znak2=getc(stdin);
                                    if((znak2>=48)&&(znak2<=57)) {
                                        fprintf(stderr,"Błąd! Należy wczytać tylko liczby całkowite!\n");
                                        ungetc(znak2,stdin);
                                        scanf("%d",&liczba);
                                    }
                                    else {
                                        ungetc(znak2,stdin);
                                        ungetc(znak,stdin);
                                        push(&stos,(-1)*liczba);
                                    }
                                    break;
                                }
                                default: {
                                    ungetc(znak,stdin);
                                    push(&stos,(-1)*liczba);
                                    break;
                                }
                            }
                    }
                    break;
                }
                case '*': {
                    multiplication(&stos);
                    break;
                }
                case '/': {
                    division(&stos);
                    break;
                }
                case 'P': {
                    pop(&stos);
                    break;
                }
                case 'c': {
                    clear(&stos);
                    break;
                }
                case 'r': {
                    reverse(&stos);
                    break;
                }
                case 'd': {
                    duplication(&stos);
                    break;
                }
                case 'p': {
                    print(stos);
                    break;
                }
                case 'f': {
                    full_print(stos);
                    break;
                }
                case 'q': {
                    free(stos);
                    stos= nullptr;
                    break;
                }
                default: {
                    if((znak>=48)&&(znak<=57)) {
                        ungetc(znak,stdin);
                        scanf("%d",&liczba);
                        znak=getc(stdin);
                            switch(znak){
                                case '.': {
                                    znak2=getc(stdin);
                                    if((znak2>=48)&&(znak2<=57)) {
                                        fprintf(stderr,"Błąd! Należy wczytać tylko liczby całkowite!\n");
                                        ungetc(znak2,stdin);
                                        scanf("%d",&liczba);
                                    }
                                    else {
                                        ungetc(znak2,stdin);
                                        ungetc(znak,stdin);
                                        push(&stos,liczba);
                                    }
                                    break;
                                }
                                default: {
                                   ungetc(znak,stdin);
                                   push(&stos,liczba);
                                   break;
                                }
                            }
                    }else fprintf(stderr,"Niepoprawna opcja!!\n");
                    break;
                }
            }
        }
    }while(znak!='q');
}





