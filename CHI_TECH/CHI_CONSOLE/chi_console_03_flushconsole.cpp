#include <iostream>

#include "chi_console.h"


#include "../CHI_LIB/chi_lib.h"
#include "../ChiPhysics/chi_physics.h"
#include "../ChiTimer/chi_timer.h"
extern ChiPhysics  		chi_physics_handler;
extern ChiTimer        chi_program_timer;

//############################################################################# Flush console
/* This function sends the commands contained in the input buffer to
the lua state from where it is executed.
*/
void CHI_CONSOLE::flushConsole()
{

	return;
}
