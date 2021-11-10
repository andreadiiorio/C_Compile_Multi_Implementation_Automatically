//Copyright Andrea Di Iorio 2021
//This file is part of C_Multi_Implementation_Macros_Auto
//C_Multi_Implementation_Macros_Auto is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//C_Multi_Implementation_Macros_Auto is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//You should have received a copy of the GNU General Public License
//along with C_Multi_Implementation_Macros_Auto.  If not, see <http://www.gnu.org/licenses/>.


#include <stdlib.h>
#include <stdio.h>

#include "implementationMulti.h"
char TRGT_IMPL = 0;
int main(){
    printf("impl 0:\t%d\n",genFunc_0(22)); 
    printf("impl 1:\t%d\n",genFunc_1(22)); 

    genFunc_Interf trgtImplementation    = &genFunc_0; 
    if (TRGT_IMPL)  trgtImplementation  = &genFunc_1;
    printf("impl Target:\t%d\n",trgtImplementation(22)); 
}
