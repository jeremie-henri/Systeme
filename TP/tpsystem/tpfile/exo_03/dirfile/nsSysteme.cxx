/**
 *
 * @File : nsSysteme.cxx
 *
 * 2011
 * @Synopsis : definition des wrappers non inline des fonctions syst
 *
**/

#include <string>
#include <fcntl.h>       // O_CREAT, open()
#include <sys/types.h>   // mode_t
#include <cstddef>       // size_t
#include "CExc.h"
#include "nsSysteme.h"

using namespace std;     // string


int nsSysteme::Open (const char * pathname, int flags, ::mode_t mode)
    throw (CExc)
{
    int Res;
    if (!(flags & O_CREAT)) 
        throw CExc ("Open()",string (" fichier :") + pathname +
                       ". Un parametre de trop");
    if (-1 == (Res = ::open (pathname, flags, mode)))
        throw CExc ("open() ", string (" fichier :") + pathname);

    return Res;

} // Open()

int nsSysteme::Open (const char * pathname, int flags)
    throw (CExc)
{
    int Res;
    if (flags & O_CREAT) 
        throw CExc ("Open()",string (" fichier :") + pathname +
                    ". Il manque un parametre");
    if (-1 == (Res = ::open (pathname, flags)))
        throw CExc ("open() ", string (" fichier :") + pathname);

    return Res;

} // Open()


void nsFctShell::FileCopy (const char * const Destination,
                           const char * const Source, const size_t NbBytes)
                                             throw (nsSysteme::CExc)
{
    //a ecrire    
    //il faut utiliser nsSysteme::Open, nsSysteme::Close, etc... parce que 
    // nous sommes dans ici nsFctShell

} // FileCopy()

