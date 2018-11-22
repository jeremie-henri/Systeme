/**
 *
 * @File : 
 *
 * @Author : A. B. Dragut
 *
 * @Synopsis : modelmain
 **/

#include <string>
#include <exception>
#include <iostream>    
#include <sys/types.h> 

#include <unistd.h>     // getdtablesize()
#include <sys/time.h>   // fd_set

#include "nsSysteme.h"
#include "CExc.h"


using namespace nsSysteme;
using namespace std;

int main(int argc, char * argv [])
{
  try {
	pid_t pidFils;
	pid_t pidPere;

	if((pidFils = fork())){
			pidPere = getpid();
			cout << "Processus père: " << pidPere << "Processus fils: " << pidFils << endl;

	}
	else(){
			pidPere = getppid();
			pidFils = getpid();
			cout << "Processus père: " << pidPere << "Processus fils: " << pidFils << endl;
	}

	
  
///code
    return 0;
  }
  catch (const CExc & Exc) {
        cerr <<Exc<< endl;
        return errno;
  }
  catch (const exception & Exc) {
        cerr << "Exception : " << Exc.what () << endl;
        return 1;
  }
  catch (...) {
        cerr << "Exception inconnue recue dans la fonction main()" 
             << endl;
        return 1;
  }


}  //  main()
