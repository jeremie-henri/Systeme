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
#include <fcntl.h>    /* For O_RDWR */


#include <unistd.h>     // getdtablesize()
#include <sys/time.h>   // fd_set
#include <string.h>

#include "nsSysteme.h"
#include "CExc.h"


using namespace nsSysteme;
using namespace std;

namespace{
	void Derout(int sig){
		cout<<"-------------------------------------"<<endl;

		cout<<"PID: "<< getpid() <<endl
		<<"Nom signal: "<< strsignal(sig) << endl
		<< "Num signal: "<< sig <<endl;

		cout<<"-------------------------------------"<<endl;
		
	}
}



int main(int argc, char * argv [])
{
  try {


    nsFctShell::DerouterSignaux(Derout);

    cout<<"Le pere ouvre trois fichiers a part 0,1,2"<<endl;
    Open ("exo_01_c.txt", O_RDONLY);
    Open ("exo_01_c.txt", O_RDONLY);
    Open ("exo_01_c.txt", O_RDONLY);
    cout<< "le pere ferme le stderr "<<endl;
    nsSysteme::Close (2);

    nsFctShell::TestFdOuverts ();

	pid_t pidFils;
	pid_t pidPere;

	if((pidFils = fork())){
			pidPere = getpid();
			cout<<"-------------------------------------"<<endl;

			cout << "Processus courant: " << pidPere << endl <<"Processus fils: " << pidFils << endl;
			//Derout(8);

	}
	else{

			pidPere = getppid();
			pidFils = getpid();
			cout << "Processus père: " << pidPere << endl << "Processus courant: " << pidFils << endl;
			//Derout(3);

			nsFctShell::TestFdOuverts ();
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
