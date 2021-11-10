Andrea Di Iorio

AUTOMATIC MULTIPLE IMPLEMENTATION TEMPLATE
==========================================

C code template for compiling a generic function into multiple one 
varing a configurations based on a MACRO.
The target implementation will be chosen via a global configuration var 
and function pointers.

Use case: **C --> fortran porting**
using a macro for 0,1 offset to add in arrays access

this template will build 2 implementation a sum function that use an OFFSET macro
compile with `make`

#BASE MECHANISM
multiple implementations will be obtanind from a single generic implementation 
with a function witch use a configuring MACRO in the code in a file,  (e.g. OFFSET in a sum)
and in another file it's possible to **have multiple implementation of the function**
using a sequence of:
```
#undef      MACRO                     
#define     MACRO 1                  
#include    "implementationGeneric.c"
...
```
the `#include`s will add the generic implementation source at preprocessor level,
but because of the redefined `MACRO`s there'll be specialized implementations with
a behavior dependent of the MACRO value.

It's needed to have the generic implementation functions names derivated from
the MACRO value.
##FUNCTIONS NAME DERIVATION FROM A MACRO
To have a function name derivated from a MACRO value it's needed
to expand and concatenate the MACRO at preprocessor level
for this it's possibile to use:
```
//Concatenate preprocessor tokens A and B WITHOUT   expanding macro definitions
#define _CAT(a,b)    a ## b
//Concatenate preprocessor tokens A and B           EXPANDING macro definitions
#define CAT(a,b)    _CAT(a,b)
//generic implementation with OFFSET macro derived name
int CAT(genFunc_,OFFSET) (int a){ 
    //GENERIC IMPLEMENTATION USING THE MACRO OFFSET
}
```
see `macros.h`

#SOURCES ORGANIZATION
##GENERIC IMPLEMENTATION
see:    `implementationGeneric.c implementationGeneric.h`

it's needed to have a generic implementation along with its generic header.
the name of the function and of the prototype will be a concatenation of 
a baseFunction name with the configuring macro value:
```
//generic implementation with OFFSET macro derived name
int CAT(genFunc_,OFFSET) (int a){ 
    //GENERIC IMPLEMENTATION USING THE MACRO OFFSET
}
```
It's possible to avoid compiler worning about the missing definition of the 
specific implementations with a generic function prototype 
ans it can be usefull a function pointer definition
to switch among the multiple specific implementations

```
int CAT(genFunc_,OFFSET) (int a);       //derived name prototype
typedef int (*genFunc_Interf) (int);    //generic implementation func pointer
```

##MULTIPLE IMPLEMENTATION DERIVATION
see:    `implementationGeneric.c implementationGeneric.h`
To derive multiple implementation from the generic one dependent from the configuring MACRO
It's possible to redefine the MACRO configuring the generic implementation
and re including the generic implementation source.
```
#define OFFSET 0
#include "implementationGeneric.c"
#undef OFFSET
#define OFFSET 1
#include "implementationGeneric.c"
```
To also have the specific implementations headers it's possible to do the same 
with the generic header
```
#define OFFSET 0
#include "implementationGeneric.h"
#undef OFFSET
#define OFFSET 1
#include "implementationGeneric.h"
```

#MULTIPLE IMPLEMENTATION RUNTIME SWITCH
see:    `main.c`
Exploiting a [global] variable and function pointers it's easy to switch
among the multiple implementation functions
```
genFunc_Interf trgtImplementation    = &genFunc_0;
if (TRGT_IMPL)  trgtImplementation  = &genFunc_1;
printf("impl Target:\t%d\n",trgtImplementation(22));
```
