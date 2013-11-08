/************************************************************************************

	AstroMenace (Hardcore 3D space shooter with spaceship upgrade possibilities)
	Copyright © 2006-2013 Michael Kurinnoy, Viewizard


	AstroMenace is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AstroMenace is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AstroMenace. If not, see <http://www.gnu.org/licenses/>.


	Web Site: http://www.viewizard.com/
	Project: http://sourceforge.net/projects/openastromenace/
	E-mail: viewizard@viewizard.com

*************************************************************************************/


#include "RendererInterface.h"


//------------------------------------------------------------------------------------
// Инициализация работы с VBO
//------------------------------------------------------------------------------------
bool vw_Internal_InitializationVBO()
{
	return true;
}




//------------------------------------------------------------------------------------
// Процедура генерации буферов
//------------------------------------------------------------------------------------
bool vw_BuildVBO(int NumVertices, void *Data, int Stride, unsigned int *VBO)
{
	if (Data == 0) return false;
	if (VBO == 0) return false;

	glGenBuffers( 1, VBO );						// Get A Valid Name
	glBindBuffer( GL_ARRAY_BUFFER, *VBO );	// Bind The Buffer
	// Load The Data
	glBufferData( GL_ARRAY_BUFFER, NumVertices*Stride*sizeof(float), Data, GL_STATIC_DRAW );
	// убираем буфер
	glBindBuffer( GL_ARRAY_BUFFER, 0 );

	if (!glIsBuffer(*VBO)) return false;

	return true;
}


//------------------------------------------------------------------------------------
// Процедура генерации индекс буферов
//------------------------------------------------------------------------------------
bool vw_BuildIBO(int NumIndex, void *Data, unsigned int *IBO)
{
	if (Data == 0) return false;
	if (IBO == 0) return false;

	glGenBuffers( 1, IBO );								// Get A Valid Name
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, *IBO );	// Bind The Buffer
	// Load The Data
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, NumIndex*sizeof(unsigned int), Data, GL_STATIC_DRAW );
	// убираем буфер
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 );

	if (!glIsBuffer(*IBO)) return false;

	return true;
}


//------------------------------------------------------------------------------------
// Установка текущего буфера
//------------------------------------------------------------------------------------
void vw_BindVBO(int target, unsigned int VBO)
{
	switch (target)
	{
		case RI_ARRAY_BUFFER: 			glBindBuffer(GL_ARRAY_BUFFER, VBO); break;
		case RI_ELEMENT_ARRAY_BUFFER: 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO); break;
		default: fprintf(stderr, "Error in vw_BindVBO function call, wrong target.\n"); break;
	}
}





//------------------------------------------------------------------------------------
// Процедура удаления буфера
//------------------------------------------------------------------------------------
void vw_DeleteVBO(unsigned int VBO)
{
	if (glIsBuffer(VBO))	glDeleteBuffers(1, &VBO);
}

