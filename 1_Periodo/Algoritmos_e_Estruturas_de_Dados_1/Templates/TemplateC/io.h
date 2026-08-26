/*
    io.h - v1.0
    PUC-Minas - Ciencia da Computacao
    AED1 - 2026-1
    Biblioteca de apoio para entrada/saida e tipos auxiliares.
    Cobre os Estudos Dirigidos ED01 .. ED10.
*/

#ifndef IO_H
#define IO_H

// ----------------------------------------------- dependencias do sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

// ----------------------------------------------- definicoes globais

/*
    Tamanho padrao para cadeias de caracteres.
*/
#define STR_SIZE   256

/*
    Cadeia de caracteres vazia.
*/
#define STR_EMPTY  ""

/*
    Apelidos para valores booleanos (usados em alguns exemplos).
*/
#ifndef TRUE
#define TRUE  true
#endif
#ifndef FALSE
#define FALSE false
#endif

/*
    Apelidos de tipo para ponteiros usados nos exemplos.
*/
typedef char*  chars;   // cadeia de caracteres (string)
typedef int*   ints;    // arranjo dinamico de inteiros
typedef double* doubles; // arranjo dinamico de reais

// ----------------------------------------------- alocacao de espaco

/*
    IO_new_chars - Reservar espaco para cadeia de caracteres.
    @return referencia para a area reservada (ou NULL)
    @param n - quantidade de caracteres
*/
static inline chars IO_new_chars ( int n )
{
    chars tmp = NULL;
    if ( n > 0 )
    {
        tmp = (chars) malloc ( (n+1) * sizeof(char) );
        if ( tmp != NULL )
        {
            tmp [ 0 ] = '\0';
        } // end if
    } // end if
    return ( tmp );
} // end IO_new_chars ( )

/*
    IO_new_ints - Reservar espaco para arranjo de inteiros.
    @return referencia para a area reservada (ou NULL)
    @param n - quantidade de inteiros
*/
static inline ints IO_new_ints ( int n )
{
    ints tmp = NULL;
    if ( n > 0 )
    {
        tmp = (ints) malloc ( n * sizeof(int) );
    } // end if
    return ( tmp );
} // end IO_new_ints ( )

/*
    IO_new_doubles - Reservar espaco para arranjo de reais.
    @return referencia para a area reservada (ou NULL)
    @param n - quantidade de reais
*/
static inline doubles IO_new_doubles ( int n )
{
    doubles tmp = NULL;
    if ( n > 0 )
    {
        tmp = (doubles) malloc ( n * sizeof(double) );
    } // end if
    return ( tmp );
} // end IO_new_doubles ( )

// ----------------------------------------------- identificacao

/*
    IO_id - Mostrar mensagem de identificacao do programa/metodo.
    @param msg - texto de identificacao
*/
static inline void IO_id ( const char* msg )
{
    printf ( "\n----------------------------------------\n" );
    printf ( "%s\n", msg );
    printf ( "----------------------------------------\n" );
} // end IO_id ( )

// ----------------------------------------------- saida no terminal

/*
    IO_print - Mostrar texto (sem mudar de linha).
    @param msg - texto a mostrar
*/
static inline void IO_print ( const char* msg )
{
    printf ( "%s", msg );
} // end IO_print ( )

/*
    IO_println - Mostrar texto (com mudanca de linha).
    @param msg - texto a mostrar
*/
static inline void IO_println ( const char* msg )
{
    printf ( "%s\n", msg );
} // end IO_println ( )

/*
    IO_printf - Equivalente ao printf padrao (saida formatada).
*/
#define IO_printf  printf

/*
    IO_fprintf - Equivalente ao fprintf padrao (saida formatada em arquivo).
*/
#define IO_fprintf fprintf

// ----------------------------------------------- pausa

/*
    IO_pause - Mostrar mensagem e esperar o usuario teclar ENTER.
    @param msg - texto a mostrar antes da pausa
*/
static inline void IO_pause ( const char* msg )
{
    int c = 0;
    printf ( "\n%s ", msg );
    fflush ( stdout );
    // descarta caracteres ate o fim da linha (incluindo ENTER pendente)
    while ( ( c = getchar() ) != '\n' && c != EOF ) { /* nada */ }
    printf ( "\n" );
} // end IO_pause ( )

// ----------------------------------------------- entrada do teclado

/*
    IO_readint - Ler um valor inteiro do teclado.
    @return valor inteiro lido
    @param msg - texto a mostrar como prompt
*/
static inline int IO_readint ( const char* msg )
{
    int valor = 0;
    int c = 0;
    printf ( "%s", msg );
    fflush ( stdout );
    if ( scanf ( "%d", &valor ) != 1 )
    {
        valor = 0;
        // descarta entrada invalida
        while ( ( c = getchar() ) != '\n' && c != EOF ) { /* nada */ }
    }
    else
    {
        // descarta o resto da linha (inclusive o ENTER)
        while ( ( c = getchar() ) != '\n' && c != EOF ) { /* nada */ }
    } // end if
    return ( valor );
} // end IO_readint ( )

/*
    IO_readdouble - Ler um valor real (double) do teclado.
    @return valor real lido
    @param msg - texto a mostrar como prompt
*/
static inline double IO_readdouble ( const char* msg )
{
    double valor = 0.0;
    int c = 0;
    printf ( "%s", msg );
    fflush ( stdout );
    if ( scanf ( "%lf", &valor ) != 1 )
    {
        valor = 0.0;
        while ( ( c = getchar() ) != '\n' && c != EOF ) { /* nada */ }
    }
    else
    {
        while ( ( c = getchar() ) != '\n' && c != EOF ) { /* nada */ }
    } // end if
    return ( valor );
} // end IO_readdouble ( )

/*
    IO_readchar - Ler um caractere do teclado.
    @return caractere lido
    @param msg - texto a mostrar como prompt
*/
static inline char IO_readchar ( const char* msg )
{
    char valor = '\0';
    int c = 0;
    printf ( "%s", msg );
    fflush ( stdout );
    if ( scanf ( " %c", &valor ) != 1 )
    {
        valor = '\0';
    } // end if
    // descarta o resto da linha
    while ( ( c = getchar() ) != '\n' && c != EOF ) { /* nada */ }
    return ( valor );
} // end IO_readchar ( )

/*
    IO_readbool - Ler um valor logico do teclado.
    Aceita: 0/1, t/f, T/F, true/false (apenas o 1o caractere significativo).
    @return valor logico lido
    @param msg - texto a mostrar como prompt
*/
static inline bool IO_readbool ( const char* msg )
{
    bool valor = false;
    char c = '\0';
    int  k = 0;
    printf ( "%s", msg );
    fflush ( stdout );
    if ( scanf ( " %c", &c ) == 1 )
    {
        if ( c == '1' || c == 't' || c == 'T' || c == 'v' || c == 'V' )
        {
            valor = true;
        } // end if
    } // end if
    while ( ( k = getchar() ) != '\n' && k != EOF ) { /* nada */ }
    return ( valor );
} // end IO_readbool ( )

/*
    IO_readstring - Ler uma palavra (sequencia sem espacos) do teclado.
    @return cadeia de caracteres lida (espaco recem-reservado)
    @param msg - texto a mostrar como prompt
*/
static inline chars IO_readstring ( const char* msg )
{
    chars valor = IO_new_chars ( STR_SIZE );
    int c = 0;
    printf ( "%s", msg );
    fflush ( stdout );
    if ( valor != NULL )
    {
        if ( scanf ( "%255s", valor ) != 1 )
        {
            valor [ 0 ] = '\0';
        } // end if
        while ( ( c = getchar() ) != '\n' && c != EOF ) { /* nada */ }
    } // end if
    return ( valor );
} // end IO_readstring ( )

/*
    IO_readln - Ler uma linha inteira (com espacos, sem o ENTER) do teclado.
    @return cadeia de caracteres lida (espaco recem-reservado)
    @param msg - texto a mostrar como prompt
*/
static inline chars IO_readln ( const char* msg )
{
    chars valor = IO_new_chars ( STR_SIZE );
    int   n = 0;
    printf ( "%s", msg );
    fflush ( stdout );
    if ( valor != NULL )
    {
        if ( fgets ( valor, STR_SIZE, stdin ) == NULL )
        {
            valor [ 0 ] = '\0';
        }
        else
        {
            // remove o '\n' final, se houver
            n = (int) strlen ( valor );
            if ( n > 0 && valor [ n-1 ] == '\n' )
            {
                valor [ n-1 ] = '\0';
            } // end if
        } // end if
    } // end if
    return ( valor );
} // end IO_readln ( )

// ----------------------------------------------- conversoes para cadeia

/*
    IO_toString_d - Converter inteiro em cadeia de caracteres.
    @return cadeia recem-reservada com a representacao do valor
    @param x - valor inteiro
*/
static inline chars IO_toString_d ( int x )
{
    chars tmp = IO_new_chars ( STR_SIZE );
    if ( tmp != NULL )
    {
        snprintf ( tmp, STR_SIZE, "%d", x );
    } // end if
    return ( tmp );
} // end IO_toString_d ( )

/*
    IO_toString_f - Converter real (double) em cadeia de caracteres.
    @return cadeia recem-reservada com a representacao do valor
    @param x - valor real
*/
static inline chars IO_toString_f ( double x )
{
    chars tmp = IO_new_chars ( STR_SIZE );
    if ( tmp != NULL )
    {
        snprintf ( tmp, STR_SIZE, "%lf", x );
    } // end if
    return ( tmp );
} // end IO_toString_f ( )

/*
    IO_toString_c - Converter caractere em cadeia de caracteres.
    @return cadeia recem-reservada com a representacao do valor
    @param x - valor caractere
*/
static inline chars IO_toString_c ( char x )
{
    chars tmp = IO_new_chars ( STR_SIZE );
    if ( tmp != NULL )
    {
        snprintf ( tmp, STR_SIZE, "%c", x );
    } // end if
    return ( tmp );
} // end IO_toString_c ( )

/*
    IO_toString_b - Converter logico em cadeia de caracteres ("true"/"false").
    @return cadeia recem-reservada com a representacao do valor
    @param x - valor logico
*/
static inline chars IO_toString_b ( bool x )
{
    chars tmp = IO_new_chars ( STR_SIZE );
    if ( tmp != NULL )
    {
        snprintf ( tmp, STR_SIZE, "%s", ( x ? "true" : "false" ) );
    } // end if
    return ( tmp );
} // end IO_toString_b ( )

// ----------------------------------------------- manipulacao de cadeias

/*
    IO_concat - Concatenar duas cadeias de caracteres.
    @return cadeia recem-reservada contendo a uniao das duas
    @param a - primeira cadeia
    @param b - segunda cadeia
*/
static inline chars IO_concat ( const char* a, const char* b )
{
    int   na  = ( a != NULL ) ? (int) strlen ( a ) : 0;
    int   nb  = ( b != NULL ) ? (int) strlen ( b ) : 0;
    chars tmp = IO_new_chars ( na + nb + 1 );
    if ( tmp != NULL )
    {
        tmp [ 0 ] = '\0';
        if ( a != NULL ) { strcat ( tmp, a ); }
        if ( b != NULL ) { strcat ( tmp, b ); }
    } // end if
    return ( tmp );
} // end IO_concat ( )

#endif // IO_H