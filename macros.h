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


#ifndef MACROS_H
#define MACROS_H

////UTILS
#define _STR(s) #s
#define STR(s) _STR(s)

//Concatenate preprocessor tokens A and B WITHOUT   expanding macro definitions
#define _CAT(a,b)    a ## b
//Concatenate preprocessor tokens A and B           EXPANDING macro definitions
#define CAT(a,b)    _CAT(a,b)

#endif
