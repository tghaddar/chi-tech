#include "../../../CHI_LUA/chi_lua.h"

#include "../chi_nptransport.h"
#include "../../../CHI_PHYSICS/chi_physics.h"
extern CHI_PHYSICS chi_physics_handler;

//###################################################################
/**Executes the NPT solver.
\param SolverIndex int Handle to the solver.
 \ingroup LuaNPT
 */
int chiNPTExecute(lua_State* L)
{
  int solver_index = lua_tonumber(L,1);

  //============================================= Get pointer to solver
  chi_physics::Solver* psolver;
  CHI_NPTRANSPORT* solver;
  try{
    psolver = chi_physics_handler.solver_stack.at(solver_index);

    if (typeid(*psolver) == typeid(CHI_NPTRANSPORT))
    {
      solver = (CHI_NPTRANSPORT*)(psolver);
    }
    else
    {
      fprintf(stderr,"ERROR: Incorrect solver-type"
                     "in chiNPTExecute\n");
      exit(EXIT_FAILURE);
    }
  }
  catch(std::out_of_range o)
  {
    fprintf(stderr,"ERROR: Invalid handle to solver"
                   "in chiNPTExecute\n");
    exit(EXIT_FAILURE);
  }

  solver->Execute();

  return 0;
}