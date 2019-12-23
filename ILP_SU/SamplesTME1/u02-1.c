#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object print;


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp3; 
  ILP_Object ilptmp4; 
  ILP_Object ilptmp5; 
ilptmp3 = ILP_Integer2ILP(0); 
ilptmp4 = ILP_Integer2ILP(0); 
ilptmp5 = ILP_Integer2ILP(0); 

  {
    ILP_Object a1 = ilptmp3;
    ILP_Object b2 = ilptmp4;
    ILP_Object c3 = ilptmp5;
{ 
  ILP_Object ilptmp6; 
{ 
  ILP_Object ilptmp7; 
  ILP_Object ilptmp8; 
{ 
  ILP_Object ilptmp9; 
  ILP_Object ilptmp10; 
ilptmp9 = b2; 
ilptmp10 = b2; 
ilptmp7 = ILP_Times(ilptmp9, ilptmp10);
} 
{ 
  ILP_Object ilptmp11; 
  ILP_Object ilptmp12; 
{ 
  ILP_Object ilptmp13; 
  ILP_Object ilptmp14; 
ilptmp13 = ILP_Integer2ILP(4); 
ilptmp14 = a1; 
ilptmp11 = ILP_Times(ilptmp13, ilptmp14);
} 
ilptmp12 = c3; 
ilptmp8 = ILP_Times(ilptmp11, ilptmp12);
} 
ilptmp6 = ILP_Minus(ilptmp7, ilptmp8);
} 

  {
    ILP_Object discr4 = ilptmp6;
{ 
  ILP_Object ilptmp15; 
{ 
  ILP_Object ilptmp16; 
  ILP_Object ilptmp17; 
ilptmp16 = discr4; 
ilptmp17 = ILP_Integer2ILP(0); 
ilptmp15 = ILP_Equal(ilptmp16, ilptmp17);
} 
  if ( ILP_isEquivalentToTrue(ilptmp15 ) ) {
{ 
  ILP_Object ilptmp18; 
ilptmp18 =  ILP_String2ILP("discriminant nul : une seule racine"); 
return ILP_print(ilptmp18);
}

  } else {
{ 
  ILP_Object ilptmp19; 
{ 
  ILP_Object ilptmp20; 
  ILP_Object ilptmp21; 
ilptmp20 = discr4; 
ilptmp21 = ILP_Integer2ILP(0); 
ilptmp19 = ILP_GreaterThan(ilptmp20, ilptmp21);
} 
  if ( ILP_isEquivalentToTrue(ilptmp19 ) ) {
{ 
  ILP_Object ilptmp22; 
ilptmp22 =  ILP_String2ILP("discriminant positif : deux racines"); 
return ILP_print(ilptmp22);
}

  } else {
{ 
  ILP_Object ilptmp23; 
ilptmp23 =  ILP_String2ILP("discriminant négatif : aucune racine"); 
return ILP_print(ilptmp23);
}

  }
}

  }
}

  }
}

  }
}

} 

static ILP_Object ilp_caught_program () {
  struct ILP_catcher* current_catcher = ILP_current_catcher;
  struct ILP_catcher new_catcher;

  if ( 0 == setjmp(new_catcher._jmp_buf) ) {
    ILP_establish_catcher(&new_catcher);
    return ilp_program();
  };
  return ILP_current_exception;
}

int main (int argc, char *argv[]) 
{ 
  ILP_START_GC; 
  ILP_print(ilp_caught_program()); 
  ILP_newline(); 
  return EXIT_SUCCESS; 
} 
